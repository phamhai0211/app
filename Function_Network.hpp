#pragma once
#include <iostream>
#include <string>
#include <thread>
#include <winsock2.h>
#include <windows.h>
#include <boost/asio.hpp>
#include <stdlib.h>
#include "Libarary_Id.h"
#include "Class_Logger.hpp"
#include "Function_Message.hpp"

using namespace std;
using boost::asio::ip::tcp;
////////// variables ////////////                      
thread HandleClient[10];
//SOCKET ClientConn[10];
tcp::socket ClientConn[10];
char lftxt[20] = "../Logs/ChatLogs";
logfile lf(lftxt);


////////////////////////////////////////////////// Function NetworkCom //////////////////////////////////////////////////////////////////////////////////////////////////
void NetworkCom(int loc);

void NetworkCom(int loc)
{
	int flag = 0;
	char datatemp[512] = " ";
	char msgtemp[512] = " ";
	AuthDataParsed AuthData;

	boost::asio::streambuf buf;
	boost::system::error_code error;

	boost::asio::read(ClientConn[loc], buf, boost::asio::transfer_exactly(sizeof(AuthData)), error);

	if (!error) {
		std::istream is(&buf);
		is.read(reinterpret_cast<char*>(&AuthData), sizeof(AuthData));
		IDStore(AuthData.ID, loc);

		std::cout << ">>" << "ID # " << AuthData.ID << " sID # " << AuthData.sID << std::endl;
	}
	else {
		std::cerr << "Error reading authentication data from client: " << error.message() << std::endl;
		return;
	}

	/*do
	{
		flag = recv(ClientConn[loc], datatemp, 512, 0);
	} while (flag <= 0);
	flag = 0;

	AuthDataParser(datatemp, AuthData);
	IDStore(AuthData.ID, loc);

	std::cout << ">>" << "ID # " << AuthData.ID << " sID # " << AuthData.sID << std::endl;*/

	/*while (ClientConn[loc] != INVALID_SOCKET)
	{
		flag = recv(ClientConn[loc], msgtemp, 512, 0);
		if (flag > 0)
		{
			lf.writeLog(datatemp);
			lf.writeLog(msgtemp);
		}
		flag = 0;

		flag = send(ClientConn[ReturnLocation(AuthData.sID)], msgtemp, 512, 0);
		if (flag > 0)
		{
			lf.writeLog(datatemp);
			lf.writeLog(msgtemp);
		}
		flag = 0;

		if (!strcmp(msgtemp, "EXIT"))
		{
			closesocket(ClientConn[loc]);
			std::cout << "Client " << AuthData.ID << " has disconnected" << std::endl;
			std::cout << "Client " << AuthData.sID << " has disconnected" << std::endl;
			break;
		}
	}*/
	while (ClientConn[loc].is_open())
    {
        // read message from client
        boost::asio::read(ClientConn[loc], buf, boost::asio::transfer_at_least(1), error);
        if (!error) {
            std::istream is(&buf);
            is.getline(msgtemp, 512);
            
            lf.writeLog(datatemp);
            lf.writeLog(msgtemp);
        }
        else {
            std::cerr << "Error reading message from client: " << error.message() << std::endl;
            break;
        }

        // send message to other client
        boost::asio::write(ClientConn[ReturnLocation(AuthData.sID)], boost::asio::buffer(msgtemp, strlen(msgtemp)), error);
        if (!error) {
            lf.writeLog(datatemp);
            lf.writeLog(msgtemp);
        }
        else {
            std::cerr << "Error sending message to other client: " << error.message() << std::endl;
            break;
        }

        // check for client disconnection
        if (!strcmp(msgtemp, "EXIT"))
        {
            ClientConn[loc].close();
            std::cout << "Client " << AuthData.ID << " has disconnected" << std::endl;
            std::cout << "Client " << AuthData.sID << " has disconnected" << std::endl;
            break;
        }
    }
}

/////////////////////////////////////////////////// Function CreateClientThread ///////////////////////////////////////////////////////////////////////////////////////
void CreateClientThread(int location);

void CreateClientThread(int location)
{
	HandleClient[location] = thread(NetworkCom, location);
	HandleClient[location].detach();
}