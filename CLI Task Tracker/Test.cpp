/*
 * Test.cpp
 *
 * Created On: 2025-03-10
 * Created By: Edward Cromwell
 *
 * Description: This is the implementation file for the 
 *				testing functions for this project.
 *
 */

#include "Test.h"


void start_tests()
{
	system("cls");
	cout << "\nStarting testing functions...\n";
	cout << "--------------------------------\n";
	cout << "Testing Task class...\n";
	test_task();

	cout << "--------------------------------\n";
	cout << "Testing TaskList class...\n";
	test_task_list();

	/*cout << "--------------------------------\n";
	cout << "testing tracker class...\n";
	test_tracker();*/

	cout << "\nTests complete.\n";
	cout << "--------------------------------\n";
}


void test_task()
{
	cout << "\nTesting Task class default constructor...\n";
	Task t0;
	cout << "Task 0:\n" << t0 << endl;

	cout << "Testing Task class non-default constructor...\n";
	Task t1(1, "Task 1", "This is the first task", "to do");
	Task t2(2, "Task 2", "This is the second task", "in progress");
	Task t3(3, "Task 3", "This is the third task", "done");
	cout << "Task 1:\n" << t1 << endl;
	cout << "Task 2:\n" << t2 << endl;
	cout << "Task 3:\n" << t3 << endl;

	cout << "Testing Task class set functions...\n";
	t1.set_task_name("Task 1 Updated");
	t2.set_task_description("This is the second task updated.");
	t3.set_task_status("in progress");
	cout << "Task 1:\n" << t1 << endl;
	cout << "Task 2:\n" << t2 << endl;
	cout << "Task 3:\n" << t3 << endl;

	cout << "\nTesting Task class get functions...\n";
	cout << "Task 1 ID: " << t1.get_task_ID() << endl;
	cout << "Task 2 Name: " << t2.get_task_name() << endl;
	cout << "Task 3 Description: " << t3.get_task_description() << endl;
	cout << "Task 1 Status: " << t1.get_task_status() << endl;
	cout << "Task 2 Created: " << t2.get_task_created() << endl;
	cout << "Task 3 Updated: " << t3.get_task_updated() << endl;

	cout << "\nTesting Task class read constructor...\n";
	Task t4(4, "Task 4", "This is the fourth task", "to do", 205304400, 205304400);
	cout << "Task 4:\n" << t4 << endl;
}

void test_task_list()
{
	cout << "\nTesting TaskList class default constructor...\n";
	TaskList tl0;
	cout << "TaskList 0:\n";
	cout << "Task Count: " << tl0.get_task_count() << endl;
	cout << "File Path: " << tl0.get_file_path() << endl;
	
	cout << "\nTesting TaskList class non-default constructor...\n";
	try
	{
		TaskList tl1("test_task_list.json");
		cout << "TaskList 1:\n";
		cout << "Task Count: " << tl1.get_task_count() << endl;
		cout << "File Path: " << tl1.get_file_path() << endl;
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}
	
	cout << "\nTesting TaskList class add_task method...\n";
	Task t5(5, "Task 5", "This is the first in the list", "to do");
	try
	{
		tl0.add_task(t5);
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}

	cout << "Task Count: " << tl0.get_task_count() << endl;

	cout << "\nTesting TaskList class get_task method...\n";
	try
	{
		Task t = tl0.get_task(5);
		cout << "Task 5:\n" << t << endl;
	}
	catch (const std::exception& e) 
	{
		cout << "Exception: " << e.what() << endl;
	}

	cout << "\nTesting TaskList class remove_task method...\n";
	try
	{
		tl0.remove_task(5);
		cout << "Task Count: " << tl0.get_task_count() << endl;
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}

	cout << "\nTesting TaskList class update_task method...\n";
	tl0.add_task(t5);
	tl0.update_task(5, "in progress");
	try
	{
		Task t = tl0.get_task(5);
		cout << "Task 5:\n" << t << endl;
	}
	catch (const std::exception& e)
	{
		cout << "Exception: " << e.what() << endl;
	}

	cout << "\nTesting TaskList class set_file_path method...\n";
	try
	{
		tl0.set_file_path("new_task_list.json");
		cout << "File Path: " << tl0.get_file_path() << endl;
	}
	catch (const std::exception& e) 
	{
		cout << "Exception: " << e.what() << endl;
	}

	cout << "\nTesting TaskList class write_task_list method...\n";
	try
	{
		tl0.write_task_list();
		cout << "Task list written to file.\n";
	}
	catch (const std::exception& e) {
		cout << "Exception: " << e.what() << endl;
	}
}

void test_tracker() {
	cout << "\nTesting Tracker class...\n";

	// Redirect cin and cout for testing
	std::streambuf* orig_cin = cin.rdbuf();
	std::streambuf* orig_cout = cout.rdbuf();
	std::istringstream input;
	std::ostringstream output;
	cin.rdbuf(input.rdbuf());
	cout.rdbuf(output.rdbuf());

	// Test default constructor
	Tracker tracker;
	cout << "Default constructor test passed.\n";

	// Test main_menu
	input.str("1\n2\n3\n4\n");
	tracker.main_menu();
	cout << "Main menu test passed.\n";

	// Test file_menu
	input.str("test_task_list.json\n");
	tracker.file_menu();
	cout << "File menu test passed.\n";

	// Test task_menu
	input.str("1\n2\n3\n4\n");
	tracker.task_menu();
	cout << "Task menu test passed.\n";

	// Restore cin and cout
	cin.rdbuf(orig_cin);
	cout.rdbuf(orig_cout);

	cout << "Tracker class tests completed.\n";
}
