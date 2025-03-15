/*
 * Tracker.cpp
 * 
 * Created On: 2025-03-15
 * Created By: Edward Cromwell
 * 
 * Description: This is the implementation file for the Tracker class.
 */

#include "Tracker.h"
#include "Exceptions.h"
#include "Task.h"
#include "TaskList.h"

Tracker::Tracker()
{
	mode = "";
}

void Tracker::main_menu()
{
	cout << "-----------------------------\n";
	cout << "\tCLI Task Tracker\n";
	cout << "-----------------------------\n";
	cout << "1. Read from file.\n";
	cout << "2. Start new task list.\n";
	cout << "3. Exit.\n";
	cout << "Choice -> ";

	int choice;
	cin >> choice;
	string junk;
	getline(cin, junk);

	switch (choice)
	{
		case 1:
			file_menu();
			mode = "file";
			break;
		case 2:
			task_menu();
			mode = "new";
			break;
		default:
			cout << "Exiting program...";
			break;
	}
}

void Tracker::file_menu()
{
	cout << "Enter the file path: ";
	string file_path;
	getline(cin, file_path);

	try
	{
		task_list = TaskList(file_path);
		task_menu();
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
}

void Tracker::task_menu()
{
	cout << "-----------------------------\n";
	cout << "\tTask Menu\n";
	cout << "-----------------------------\n";
	cout << "1. Add task.\n";
	cout << "2. Remove task.\n";
	cout << "3. Update task.\n";
	cout << "4. View task list.\n";
	cout << "5. Save task list.\n";
	cout << "6. Exit.\n";
	cout << "Choice -> ";

	int choice;
	cin >> choice;
	string junk;
	getline(cin, junk);

	switch (choice)
	{
	case 1:
	{
		Task t;
		string name;
		string description;
		string status;

		cout << "Enter the task name: ";
		getline(cin, name);
		t.set_task_name(name);

		cout << "Enter the task description: ";
		getline(cin, description);
		t.set_task_description(description);

		cout << "Enter the task status: ";
		getline(cin, status);
		t.set_task_status(status);

		task_list.add_task(t);
		break;
	}
	case 2:
	{
		int id;

		cout << "Enter the task ID: ";

		cin >> id;
		string junk;
		getline(cin, junk);

		try
		{
			task_list.remove_task(id);
		}
		catch (const std::exception& e)
		{
			cout << "Exception: " << e.what() << endl;
		}

		break;
	}
	case 3:
	{
		string status;
		int id;

		cout << "Enter the task ID: ";

		cin >> id;
		string junk;
		getline(cin, junk);

		cout << "Enter the task status: ";
		getline(cin, status);

		try
		{
			task_list.update_task(id, status);
		}
		catch (const std::exception& e)
		{
			cout << "Exception: " << e.what() << endl;
		}		

		break;
	}
	case 4:
	{
		// View task
		break;
	}
	case 5:
	{
		// Save task list
		break;
	}
	default:
		cout << "Exiting program...\n";
		break;
	}
}