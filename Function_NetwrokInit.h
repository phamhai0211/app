#pragma once

#include<iostream>
#include<winsock2.h>
#include<windows.h>
#include<process.h>
#include<thread>
#include<fstream>
#include"boost/asio.hpp"
#include<boost/thread/thread.hpp>
#include<string>
#include<memory>
#include"Function_Network.hpp"
#include"Function_Message.hpp"

using namespace std;
using boost::asio::ip::tcp;
////////////////////////////////// Variables //////   
int ClientStore = 0;                          
char lftxtnio[40] = "../Logs/NetworkInitLogs";  
char lftxtni[50];                             
logfile lfni(lftxtnio);                           

///////////////////////////////////////// Class NetworkInit ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//class NetworkInit
//{
//
//public:
//	NetworkInit(); // default constructor
//
//	NetworkInit(char IP[], u_short PORT) // argumented constructor
//	{
//		lfni.writeLog(IP); // write server ip to log file
//
//		strcpy(lftxtni, "Intializing boost asio socket");
//		lfni.writeLog(lftxtni);
//		std::cout << "Intializing boost asio socket API";
//		for (int i = 0; i < 17; i++)
//		{
//			cout << ".";
//			Sleep(100);
//		}
//
//		try
//		{
//			acceptor_ = tcp::acceptor(io_service_, tcp::endpoint(boost::asio::ip::address::from_string(IP), PORT));
//			std::cout << "done" << std::endl;
//			strcpy(lftxtni, "done");
//			lfni.writeLog(lftxtni);
//		}
//		catch (std::exception& e)
//		{
//			std::cout << "Error starting Boost ASIO API: " << e.what() << std::endl;
//			strcpy(lftxtni, "Error starting Boost ASIO API");
//			lfni.writeLog(lftxtni);
//
//			std::cout << "Shutting down the server" << std::endl;
//			strcpy(lftxtni, "Shutting down the server");
//			lfni.writeLog(lftxtni);
//			lfni.~logfile();
//
//			io_service_.stop();
//			io_context_.stop();
//			exit(0);
//		}
//		/*if (!WSAStartup(MAKEWORD(2, 1), (WSAData*)&NetworkData))
//		{
//			cout << "done" << endl;
//			strcpy(lftxtni, "done");
//			lfni.writeLog(lftxtni);
//		}
//		else
//		{
//			cout << "Error starting Winsock API" << endl;
//			strcpy(lftxtni, "Error starting Winsock API");
//			lfni.writeLog(lftxtni);
//
//			cout << "Shutting down the server" << endl;
//			strcpy(lftxtni, "Shutting down the server");
//			lfni.writeLog(lftxtni);
//			lfni.~logfile();
//
//			closesocket(ListenSocket);
//			for (int i = 0; i < 10; i++)
//			{
//				closesocket(ClientConn[i]);
//			}
//			WSACleanup();
//			exit(0);
//		}*/
//		//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
//		//Address.sin_addr.s_addr = inet_addr(IP);
//		//Address.sin_port = htons(PORT);
//		//Address.sin_family = AF_INET;
//
//		////---------------------------------------Binding Listening Socket--------------------------------------------------------------------------------------------------------------------------		
//		//		//process of binding the socket
//
//		//std::cout << "Binding socket";
//		//strcpy(lftxtni, "Binding socket");
//		//lfni.writeLog(lftxtni);
//		//for (int i = 0; i < 26; i++)
//		//{
//		//	std::cout << ".";
//		//	Sleep(50);
//		//}
//		//ListenSocket = socket(AF_INET, SOCK_STREAM, 0);
//		//if (!bind(ListenSocket, (SOCKADDR*)&Address, sizeof(Address)))
//		//{
//		//	std::cout << "done" << endl;
//		//	strcpy(lftxtni, "done");
//		//	lfni.writeLog(lftxtni);
//		//}
//		//else
//		//{
//		//	std::cout << "Error Binding the port" << std::endl;
//		//	strcpy(lftxtni, "Error Binding the port");
//		//	lfni.writeLog(lftxtni);
//
//		//	std::cout << "Shutting down the server" << endl;
//		//	strcpy(lftxtni, "Shutting down the server");
//		//	lfni.writeLog(lftxtni); // write to log file
//		//	lfni.~logfile();
//
//		//	closesocket(ListenSocket);
//		//	for (int i = 0; i < 10; i++)
//		//	{
//		//		closesocket(ClientConn[i]);
//		//	}
//		//	WSACleanup();
//		//	exit(0);
//		//}
//		//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
//
//
//		//---------------------------------------Intialize listening socket------------------------------------------------------------------------------------------------------------------------		        
//				//initialize the listening socket
//
//		std::cout << "Initializing listening socket";
//		strcpy(lftxtni, "Initalizing listening socket");
//		lfni.writeLog(lftxtni);
//
//		for (int i = 0; i < 11; i++)
//		{
//			cout << ".";
//			Sleep(100);
//		}
//
//		for (int i = 0; i < 10; i++)
//		{
//			ClientConn[i] = tcp::socket(io_context_);
//
//			if (ClientConn[i].is_open())
//			{
//				cout << "Socket intialized " << i << endl;
//			}
//			else
//			{
//				cout << "Error in initialising  listening socket " << i << endl;
//				strcpy(lftxtni, "Error in initialising  listening socket ");
//				lfni.writeLog(lftxtni);
//				lfni.~logfile();
//			}
//			Sleep(200);
//		}
//		/*if (!listen(ListenSocket, SOMAXCONN))
//		{
//			cout << "done" << endl;
//			strcpy(lftxtni, "done");
//			lfni.writeLog(lftxtni);
//		}
//		else
//		{
//			cout << "Error in starting listening socket" << endl;
//			strcpy(lftxtni, "Error in starting listening socket");
//			lfni.writeLog(lftxtni);
//
//			cout << "Shutting down the server" << endl;
//			strcpy(lftxtni, "Shutting down the server");
//			lfni.writeLog(lftxtni);
//			lfni.~logfile();
//			closesocket(ListenSocket);
//			for (int i = 0; i < 10; i++)
//			{
//				closesocket(ClientConn[i]);
//			}
//			WSACleanup();
//			exit(0);
//		}*/
//		//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------		
//
//		/*AddressSize = sizeof(Address);
//		for (int i = 0; i < 10; i++)
//		{
//			ClientConn[i] = INVALID_SOCKET;
//			ClientConn[i] = socket(AF_INET, SOCK_STREAM, 0);
//
//			if (ClientConn[i] == INVALID_SOCKET)
//			{
//				cout << "Error in initialising  listening socket " << i << endl;
//				strcpy(lftxtni, "Error in initialising  listening socket ");
//				lfni.writeLog(lftxtni);
//				lfni.~logfile();
//			}
//			else
//			{
//				cout << "Socket intialized " << i << endl;
//			}
//			Sleep(200);
//		}*/
//
//		system("pause");
//		system("cls");
//
//		cout << "\t\tTCP Chat Server" << endl << endl; // display of server information
//		cout << "\t\t----------------------------------------" << endl;
//		cout << "\t\t IP Address :" << IP << endl;
//		cout << "\t\t Port Number:" << PORT << endl;
//		cout << "\t\t----------------------------------------" << endl;
//	}
//	//--------------------------------------------Intitalize all client handler sockets--------------------------------------------------------------------------------------------------------		
//
//	void AcceptConn()
//	{
//		for (;;)
//		{
//			//if ((ClientConn[ClientStore] = accept(ListenSocket, (SOCKADDR*)&Address, &AddressSize)))
//			//{
//			//	cout << "Client connected " << endl;
//			//	send(ClientConn[ClientStore], "Enter your id and id of client with whom you want to chat", 57, 0); // send necessary instructions to the client
//			//	CreateClientThread(ClientStore); // call function to create new client managing thread
//			//	ClientStore++;		  	//increment the client counter
//			//}
//			tcp::socket socket(io_context_);
//			acceptor_.accept(socket);
//			std::cout << "Client connected " << std::endl;
//			boost::asio::write(socket, boost::asio::buffer("Enter your id and id of client with whom you want to chat", 57)); // send necessary instructions to the client
//			ClientConn[ClientStore] = std::move(socket);
//			CreateClientThread(ClientStore); // call function to create new client managing thread
//			ClientStore++;
//		}
//	}
//
//	~NetworkInit()
//	{
//		// destructor -- shutdown the winsock api, delete the socket object
//		for (int i = 0; i < 10; i++)
//		{
//			cout << "Closing socket " << i << endl;
//			//closesocket(ClientConn[i]);
//			ClientConn[i].close();
//		}
//		cout << "Shutting down boost asio API" << endl;
//		strcpy(lftxtni, "Shutting down boost API");
//		lfni.writeLog(lftxtni);
//		lfni.~logfile();
//
//		/*closesocket(ListenSocket);
//		WSACleanup();*/
//		acceptor_.close();
//		io_context_.stop();
//		exit(0);
//	}
//
//private:
//	//declarations of winsock library objects necessary for the sockets parts to run
//	boost::asio::io_service io_service_;
//	tcp::acceptor acceptor_;
//	boost::asio::io_context io_context_;
//	tcp::socket socket_;
//	/*boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), 1234);
//	boost::asio::ip::tcp::acceptor acceptor(io_context, endpoint);*/
//	std::array<tcp::socket, 10> ClientConn;
//	/*WSAData NetworkData;
//	SOCKET ListenSocket;
//	SOCKADDR_IN Address;*/
//	int AddressSize;
//};
class NetworkInit
{
private:
    //declarations of boost library objects necessary for the sockets parts to run
    boost::asio::io_context io_context_;
    tcp::acceptor acceptor_;
    //std::array<tcp::socket, 10> ClientConn; // array of client handler sockets

public:
    NetworkInit(); // default constructor

    NetworkInit(char IP[], u_short PORT) : io_context_(),
        acceptor_(io_context_, tcp::endpoint(boost::asio::ip::address::from_string(IP), PORT)) // argumented constructor
    {
        lfni.writeLog(IP); // write server ip to log file

        strcpy(lftxtni, "Intializing Boost ASIO API");
        lfni.writeLog(lftxtni);
        cout << "Intializing Boost ASIO API";
        for (int i = 0; i < 17; i++)
        {
            cout << ".";
            Sleep(100);
        }
        try
        {
            acceptor_ = tcp::acceptor(io_context_, tcp::endpoint(boost::asio::ip::address::from_string(IP), PORT));
            cout << "done" << endl;
            strcpy(lftxtni, "done");
            lfni.writeLog(lftxtni);
        }
        catch (std::exception& e)
        {
            cout << "Error starting Boost ASIO API: " << e.what() << endl;
            strcpy(lftxtni, "Error starting Boost ASIO API");
            lfni.writeLog(lftxtni);

            cout << "Shutting down the server" << endl;
            strcpy(lftxtni, "Shutting down the server");
            lfni.writeLog(lftxtni);
            lfni.~logfile();

            io_context_.stop();
            exit(0);
        }

        //---------------------------------------Intialize listening socket------------------------------------------------------------------------------------------------------------------------		        

        system("pause");
        system("cls");

        cout << "\t\tTCP Chat Server" << endl << endl; // display of server information
        cout << "\t\t----------------------------------------" << endl;
        cout << "\t\t IP Address :" << IP << endl;
        cout << "\t\t Port Number:" << PORT << endl;
        cout << "\t\t----------------------------------------" << endl;
    }

    //--------------------------------------------Intitalize all client handler sockets--------------------------------------------------------------------------------------------------------		

    void AcceptConn()
    {
        for (;;)
        {
            tcp::socket socket(io_context_);
            acceptor_.accept(socket);
            cout << "Client connected " << endl;
            boost::asio::write(socket, boost::asio::buffer("Enter your id and id of client with whom you want to chat", 57)); // send necessary instructions to the client
            ClientConn[ClientStore] = std::move(socket);
            CreateClientThread(ClientStore); // call function to create new client managing thread
            ClientStore++;		  	//increment the client counter
        }
    }

    ~NetworkInit()
    {
        // destructor -- shutdown the boost asio api, delete the socket object
        for (int i = 0; i < 10; i++)
        {
            cout << "Closing socket " << i << endl;
            ClientConn[i].close();
        }
        cout << "Shutting down Boost ASIO API" << endl;
        strcpy(lftxtni, "Shutting down Boost ASIO API");
        lfni.writeLog(lftxtni);
        lfni.~logfile();

        acceptor_.close();
        io_context_.stop();
        exit(0);
    }
};