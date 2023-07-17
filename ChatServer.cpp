#include <iostream>
#include <process.h>
#include <conio.h>
#include "Function_Menu.h"
#include "Function_NetwrokInit.h"
using namespace std;

void CommandHandle(NetworkInit& a);

void CommandHandle(NetworkInit& a)
{
	char command[5];

	cin.ignore();

	while (1)
	{
		if (kbhit())
		{
			cin.getline(command, 20);
		}

		if (!strcmp(command, "quit"))
		{
			a.~NetworkInit();
			break;
		}
	}
}

void RunServer();

void RunServer()
{
	WriteRunCounter();
	char IP[16] = "127.0.0.1";
	u_short PORT ;
	thread CommandHandler;

	system("cls");
	//std::cout << "\n\n\t\tEnter the server ip address: ";
	//std::cin >> IP;
	//std::cout << endl;

	std::cout << "\t\tEnter the server port: ";
	std::cin >> PORT;
	std::cout << endl;


	NetworkInit com(IP, PORT);

	CommandHandler = thread(CommandHandle, ref(com));
	com.AcceptConn();
}

void about();

void about()
{
	system("cls");
	std::cout << "TCP Chat Server" << std::endl;
	system("pause");
}

void help();

void help()
{
	system("cls");
	std::cout << "Press 1 to start server" << std::endl;
	system("pause");
}
main()
{
	do
	{
		switch (Menu())
		{
		case 1:
			RunServer();
			break;
		case 2:
			exit(0);
			break;
		}
	} while (1);
}