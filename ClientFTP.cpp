#include <winsock2.h>
#include <iostream>
#include <filesystem>
#include <string>
#include <fstream>

#pragma comment(lib, "ws2_32.lib")
#pragma warning(disable: 4996)
#define _WINSOCK_DEPRECATED_NO_WARNINGS
enum  Request
{
	R_ListOfFiles,
	R_GiveNamaOfLoadedFile,
	R_RecieveFile
};
int main() {

SOCKET Connection;
WSAData wsaData;
WORD DLLVersion = MAKEWORD(2, 1);
if (WSAStartup(DLLVersion, &wsaData) != 0) {
	std::cerr << "Not connected" << std::endl;
	exit(1);
}

SOCKADDR_IN addr;
int sizeofaddr = sizeof(addr);
//addr.sin_addr.s_addr = inet_addr("95.134.123.45");
addr.sin_addr.s_addr = inet_addr("127.0.0.1");
addr.sin_port = htons(5000);
addr.sin_family = AF_INET;

Connection = socket(AF_INET, SOCK_STREAM, NULL);
if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0) {
	std::cerr << "Not connected" << std::endl;
}
else
std::cout << "Connected" << std::endl;
	std::cout << "Enter path to the directory\n";
	std::string path;
	std::getline(std::cin, path);
	int sizeOfString;
	Request list = R_ListOfFiles;
	send(Connection, (char*)&list, sizeof(int), NULL);
	sizeOfString = path.size();
	send(Connection, (char*)&sizeOfString, sizeof(int), NULL);
	send(Connection, path.c_str(), sizeOfString, NULL);
	//int msg_size;
	//------------------------------------------------------
	Request giveNameOfFile = R_GiveNamaOfLoadedFile;
	send(Connection, (char*)&giveNameOfFile, sizeof(int), NULL);
	recv(Connection, (char*)&sizeOfString, sizeof(int), NULL);
	char* recvdata = new char[sizeOfString + 1];
	recvdata[sizeOfString] = '\0';
	recv(Connection, recvdata, sizeOfString, NULL);
	std::string str = recvdata;
	std::cout << str << " will be loaded on server" << std::endl;
	//--------------------------------------------------------
	Request sendFile = R_RecieveFile;
	send(Connection, (char*)&sendFile, sizeof(int), NULL);
	FILE* fd = fopen(str.c_str(), "rb");

	fseek(fd, 0, SEEK_END);
	unsigned long filesize = ftell(fd);
	char* buffer = (char*)malloc(sizeof(char) * filesize);
	rewind(fd);
	fread(buffer, sizeof(char), filesize, fd);
	int sent = 0;
	while (sent < filesize)
	{
		int n = send(Connection, buffer + sent, filesize - sent, 0);
		if (n == -1)
			break;//<-- if ERROR

		sent += n;
	}
	std::cout << "The file was send to the server\n";
	//---------------------------------------------------------------
	return 0;
}
