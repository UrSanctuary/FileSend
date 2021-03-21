#include <string>
#include <iostream>
#pragma comment(lib,"ws2_32.lib")
#include <WinSock2.h>
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;
#pragma warning(disable: 4996)

SOCKET Connection[100];
int counter = 0;
enum  Request
{
	R_ListOfFiles,
	R_GiveNamaOfLoadedFile,
	R_ReciveFile
};

void GetListOfFiles(int index, char* path)
{

	for (const auto& entry : fs::directory_iterator(path))
		std::cout << entry.path() << std::endl;
}
void ClientHandler(int index) {
	while (true) {
		Request req;
		char* path;
		int sizeofString;
		std::string nameOfFile;
		FILE* fd;
		bool received;
		char* buffer;
		recv(Connection[index], (char*)&req, sizeof(int), NULL);
		switch (req)
		{
		case R_ListOfFiles:
			recv(Connection[index], (char*)&sizeofString, sizeof(int), NULL);
			path = new char[sizeofString + 1];
			path[sizeofString] = '\0';
			recv(Connection[index], path, sizeofString, NULL);
			std::cout << "List of files in directory" << std::endl;
			GetListOfFiles(index, path);
			break;
		case R_GiveNamaOfLoadedFile:
			std::getline(std::cin, nameOfFile);
			sizeofString = nameOfFile.size();
			send(Connection[index], (char*)&sizeofString, sizeof(int), NULL);
			send(Connection[index], nameOfFile.c_str(), sizeofString, NULL);
			std::cout << "The client is reported about loading the file\n";
			break;
		case R_ReciveFile:
			long dataLength;
			recv(Connection[index], (char*)(&dataLength), sizeof(dataLength), 0);//<--err
			buffer = (char*)malloc(sizeof(char)* dataLength);//<--err
			// receive data
			recv(Connection[index], buffer, sizeof(buffer), 0);
				std::cout << "The file was loaded\n";
			break;
			
		default:
			break;
		}
	}
}
int main(int args, char* argv[])
{
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		std::cout << "Error" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeOfAddr = sizeof(addr);
	//addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_addr.s_addr = inet_addr("0.0.0.0");
	addr.sin_port = htons(5000);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	SOCKET newConnection;
	for (int i = 0; i < 100; i++) {


		newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeOfAddr);

		if (newConnection == 0)
		{
			std::cout << "Error #2\n";
		}
		else
		{
			std::cout << "Client connected\n";
		}
		Connection[i] = newConnection;
		counter++;
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(i), NULL, NULL);
	}
	system("pause");
	return 0;
}
