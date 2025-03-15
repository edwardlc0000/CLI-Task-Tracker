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
	cout << "\nStarting testing functions...\n";
	test_task();
	test_task_list();
	cout << "\nTests complete.\n";
}


void test_task()
{
	cout << "Testing Task class default constructor...\n";
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
	/*
	TaskList tl("task_list.json");
	Task t1(1, "Task 1", "This is the first task", "to do");
	Task t2(2, "Task 2", "This is the second task", "in progress");
	Task t3(3, "Task 3", "This is the third task", "done");
	tl.add_task(t1);
	tl.add_task(t2);
	tl.add_task(t3);
	cout << "Task List: " << tl << endl;
	tl.remove_task(2);
	cout << "Task List: " << tl << endl;
	tl.remove_task(1);
	cout << "Task List: " << tl << endl;
	tl.remove_task(3);
	cout << "Task List: " << tl << endl;
	*/
}