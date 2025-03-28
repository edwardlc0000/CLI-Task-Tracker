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

using std::string;
using std::filesystem::path;
using std::cout;
using std::cin;
using std::endl;
using json = nlohmann::json;

Tracker::Tracker()
{
	mode = "";
}

void Tracker::main_menu()
{
	#ifdef _WIN32
		std::system("cls");
	#else
		std::system("clear");
	#endif

	cout << "-----------------------------\n";
	cout << "\tCLI Task Tracker\n";
	cout << "-----------------------------\n";
	cout << "1. Read from a file.\n";
	cout << "2. Start a new task list.\n";
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
	bool initialized = false;
	do
	{
		#ifdef _WIN32
			std::system("cls");
		#else
			std::system("clear");
		#endif


		cout << "-----------------------------\n";
		cout << "\tFile Menu\n";
		cout << "-----------------------------\n";
		cout << "Enter :b to go back";
		cout << "Enter the file path (.json): ";

		string path_string;
		getline(cin, path_string);

		if (path_string == ":b")
		{
			main_menu();
			return;
		}

		path file_path(path_string);

		try
		{
			task_list = TaskList(file_path);
			initialized = true;
			task_menu();
		}
		catch (const std::exception& e)
		{
			cout << "Exception: " << e.what() << endl;
			system("pause");
		}
	} while (!initialized);
}

void Tracker::task_menu()
{
	int choice;

	do
	{
		#ifdef _WIN32
				std::system("cls");
		#else
				std::system("clear");
		#endif
		cout << "-----------------------------\n";
		cout << "\tTask Menu\n";
		cout << "-----------------------------\n";
		cout << "1. Create task.\n";
		cout << "2. Remove task.\n";
		cout << "3. Update task.\n";
		cout << "4. Edit task.\n";
		cout << "5. View task list.\n";
		cout << "6. Save task list.\n";
		cout << "7. Exit.\n";
		cout << "Choice -> ";

		cin >> choice;
		string junk;
		getline(cin, junk);

	
		switch (choice)
		{
		case 1:
		{
			create_task_menu();
			break;
		}
		case 2:
		{
			remove_task_menu();
			break;
		}
		case 3:
		{
			update_task_menu();
			break;
		}
		case 4:
		{
			edit_task_menu();
			break;
		}
		case 5:
		{
			view_task_list_menu();
			break;
		}
		case 6:
		{
			write_task_list_menu();
			break;
		}
		default:
			cout << "Exiting program...\n";
			break;
		}
	} while (choice >= 1 && choice <= 6);
}

void Tracker::create_task_menu()
{
	Task t;
	string name;
	string description;
	string status;

	cout << "\nEnter the task name: ";
	getline(cin, name);
	t.set_task_name(name);

	cout << "Enter the task description: ";
	getline(cin, description);
	t.set_task_description(description);

	cout << "Enter the task status: ";
	getline(cin, status);
	t.set_task_status(status);

	task_list.add_task(t);
}

void Tracker::remove_task_menu()
{
	int id;

	cout << "\nEnter the task ID: ";
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
		system("pause");
	}
}

void Tracker::update_task_menu()
{
	string status;
	int id;

	cout << "\nEnter the task ID: ";
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
		system("pause");
	}
}

void Tracker::edit_task_menu()
{
	string name;
	string description;
	string status;
	int id;

	cout << "\nEnter the task ID: ";
	cin >> id;
	string junk;
	getline(cin, junk);

	cout << "Enter the task name: ";
	getline(cin, name);

	cout << "Enter the task description: ";
	getline(cin, description);

	cout << "Enter the task status: ";
	getline(cin, status);

	try
	{
		task_list.edit_task(id, name, description, status);
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
		system("pause");
	}
}

void Tracker::view_task_list_menu()
{
	cout << "\nTask List:\n\n";
	task_list.display_task_list();
	system("pause");
}

void Tracker::write_task_list_menu()
{
	string path_string;

	if(mode == "new")
	{
		cout << "\nEnter the file path: ";
		getline(cin, path_string);
		path file_path(path_string);
		try
		{
			task_list.set_file_path(file_path);
		}
		catch (const std::exception& e)
		{
			cout << "Exception: " << e.what() << endl;
			system("pause");
		}

		try
		{
			task_list.write_task_list();
		}
		catch (const std::exception& e)
		{
			cout << "Exception: " << e.what() << endl;
			system("pause");
		}
	}
	else
	{
		try
		{
			task_list.write_task_list();
		}
		catch (const std::exception& e)
		{
			cout << "Exception: " << e.what() << endl;
			system("pause");
		}
	}
}