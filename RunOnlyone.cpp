#include <iostream>
#include <fstream>

using namespace std;

main()
{
	fstream file;
	file.open("../Logs/RunCounter.txt", ios::out);
	int val = 0;

	file << val;

	file.close();
	cout << " donot run this again";
}