#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;
#pragma warning(disable: 4996)

SOCKET Connections[100];
int Counter = 0;
enum Request
{
	R_GetListOfFiles,
	//R_ChangeDir,
	//R_GetDir <-- Do I need this?
	//R_SetDir
	R_SendFile,
	R_ReceiveFile
	//R_ChangePort
};

void GetListOfFiles(int index, std::string path)
{
	std::cout << "Getting list of files..." << std::endl<<std::endl;
	for (const auto& entry : fs::directory_iterator(path))
		std::cout << entry.path() << std::endl;
}
// 65564
//
void ReceiveFile(int index, char* filename)
{
	std::cout << "Getting " <<filename<<" from the client..." << std::endl << std::endl;
	size_t datasize;
	FILE* fd = fopen(filename, "wb");
	char* text;
	bool received = true;
	while (!received)
	{
		datasize = recv(Connections[index], text, sizeof(text), 0);
		fwrite(&text, 1, datasize, fd);
	}
	fclose(fd);
}
// func to read file with 2 bites
void SendFile(SOCKET sListen, int index, char* filename)
{
	std::cout << "Sending " << filename << " from the client..." << std::endl << std::endl;
	char buffer[4096];
	FILE* fd = fopen(filename, "rb");
	size_t rret, wret;
	int bytes_read;
	while (!feof(fd)) {
		if ((bytes_read = fread(&buffer, 1, 4096, fd)) > 0)
			send(sListen, buffer, bytes_read, 0);
		else
			break;
	}
	fclose(fd);
}
void RecieveString(int index, char* str) 
{
	int sizeofString;
	recv(Connections[index], (char*)&sizeofString, sizeof(int), NULL);
	str = new char[sizeofString + 1];
	str[sizeofString] = '\0';
	recv(Connections[index], str, sizeofString, NULL);
}
void SendString(int index, char* str) // <-- move this to client side
{
	int sizeOfString = strlen(str);
	send(Connections[index], (char*)&sizeOfString, sizeof(int), NULL);
	send(Connections[index], str, sizeOfString, NULL);
}
void ClientHandler(int index) {
	while (true) {
		Request req;
		recv(Connections[index], (char*)&req, sizeof(int), NULL);
		char* path; // <-- Uninitialised memory
		char* filename; // <-- Uninitialised memory
		SOCKET sListen; // <-- Uninitialised memory
		std::string msgForClient;
		int sizeofString;
		switch (req)
		{
		case R_GetListOfFiles:
			msgForClient = "Please send the path for the directory\n";
			SendString(index, strdup(msgForClient.c_str())); // <-- predicted plase of error
			RecieveString(index, path); //<-- give path without creating copy of var in 57 line
			GetListOfFiles(index, path); //<-- give path without creating copy of var in 57 line
			break;
		case R_ReceiveFile:
			//RecieveString(index, filename);	//<-- give filename without creating copy of in 58 line
			ReceiveFile(index, filename); //<-- give filename without creating copy of in 58 line
			break;
		case R_SendFile://<-- client side request
			// get the msg from the server that the "[file.txt] will be loaded to server"

			RecieveString(index, filename); //<-- give filename without creating copy of in 58 line
			SendFile(sListen, index, filename);// <- how to give sListen and file name without creating copies of vars in 58-59 lines
			break;
		default:
			break;
		}
	}
}
// end with version for windows
// do a version for Linux
int main(int argc, char* argv[]) { // <-- change for get req from enum
	//WSAStartup
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) {
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(7500);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	for (int i = 0; i < 100; i++) {
		newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);

		if (newConnection == 0) {
			std::cout << "Error #2\n";
		}
		else {
			std::cout << "Client Connected!\n";
			std::string msg = "Hello. It`s my first network program!\nIt will load file to the remote sevrer from your PC";
			int msg_size = msg.size();
			send(newConnection, (char*)&msg_size, sizeof(int), NULL);
			send(newConnection, msg.c_str(), msg_size, NULL);

			Connections[i] = newConnection;
			Counter++;
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(i), NULL, NULL);
		}
	}


	system("pause");
	return 0;
}
