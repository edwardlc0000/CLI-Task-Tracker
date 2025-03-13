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
	cout << "Starting testing functions...\n";
	test_task();
	test_task_list();
	cout << "Tests complete.\n";
}


void test_task()
{
	Task t1(1, "Task 1", "This is the first task", "to do");
	Task t2(2, "Task 2", "This is the second task", "in progress");
	Task t3(3, "Task 3", "This is the third task", "done");
	cout << "Task 1: " << t1 << endl;
	cout << "Task 2: " << t2 << endl;
	cout << "Task 3: " << t3 << endl;
	t1.set_task_status("in progress");
	t2.set_task_status("done");
	t3.set_task_status("to do");
	cout << "Task 1: " << t1 << endl;
	cout << "Task 2: " << t2 << endl;
	cout << "Task 3: " << t3 << endl;
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