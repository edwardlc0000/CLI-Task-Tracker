/*
 * Start.cpp: This file contains the 'main' function.Program execution begins and ends there.
 * 
 * Created On: 2025-03-09
 * Created By: Edward Cromwell
 * 
 * Description: This is the main file for the CLI Task Tracker program.
 * This program is designed to help users keep track of tasks that they need to complete.
 * The program will allow users to add tasks, remove tasks, and view tasks.
 * The program will allow users to mark the status of tasks.
 * The program will store the tasks in a file so that the tasks can be accessed later.
 * 
 */ 

#include <iostream>
#include "Test.h"
#include "Tracker.h"

using std::string;
using std::cout; 
using std::cin;
using std::endl;
using json = nlohmann::json;

int main()
{
	cout << "------------------------------\n";
	cout << "CLI Task Tracker Start Options\n";
	cout << "------------------------------\n";
	cout << "1. Execute testing functions.\n";
	cout << "2. Launch CLI Task Tracker.\n";
	cout << "3. Exit.\n";
	cout << "Choice -> ";

	int choice;
	cin >> choice;

	string junk;
	getline(cin, junk);

	switch (choice)
	{
		case 1:
			cout << "\nStarting testing functions...\n";
			start_tests();
			break;
		case 2:
			cout << "\nLaunching CLI Task Tracker...\n";
			Tracker().main_menu();
			break;
		default:
			cout << "\nExiting program...";
			break;
	}

	return 0;
}

/* 
 * Run program: Ctrl + F5 or Debug > Start Without Debugging menu
 * Debug program: F5 or Debug > Start Debugging menu
 */ 

/*
 * Tips for Getting Started:
 *   1. Use the Solution Explorer window to add/manage files
 *   2. Use the Team Explorer window to connect to source control
 *   3. Use the Output window to see build output and other messages
 *   4. Use the Error List window to view errors
 *   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
 *   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
 */   
