#pragma once
#include<iostream>
#include<process.h>

int Menu();
int Menu()
{

	int option;
	system("cls");
	std::cout << "\t\tTCP Chat Server_______v1.0" << std::endl << std::endl;
	std::cout << "\t\t\t<---::Menu::--->" << std::endl;
	std::cout << "\t\t\t _________________   " << std::endl;
	std::cout << "\t\t\t| 1. Start Server |  " << std::endl;
	std::cout << "\t\t\t| 2. Quit         |  " << std::endl;
	std::cout << "\t\t\t|_________________|  " << std::endl;
	std::cout << "\t\t\tOption: ";
	std::cin >> option;  //take the input of option
	std::cin.ignore();

	return option;
}
