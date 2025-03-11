/*
 * Task.h
 * 
 * Created On: 2025-03-09
 * Created By: Edward Cromwell
 * 
 * Description: This is the header file for the Task class.
 * 
 */


#ifndef TASK_H
#define TASK_H

#include <string>
#include <ctime>

using std::string;

class Task
{
	public:

		/* 
		 * Requires: Nothing.
		 * Modifies: task_ID, task_name, task_description, task_status, task_created, task_updated.
		 * Effects: Default constructor for the Task class.
		 */
		Task();

		/*
		 * Requires: name and description are valid strings.
		 * Modifies: task_ID, task_name, task_description, task_status, task_created, task_updated.
		 * Effects: Constructor for the Task class that takes a name and description.
		 */
		Task(int id, string name, string description);

		/*
		 * Requires: name and description are valid strings.
		 * Modifies: task_ID, task_name, task_description, task_status, task_created, task_updated.
		 * Effects: Constructor for the Task class that takes a name, description, status, time created and time updated.
		 */
		Task(int id, string name, string description, string task_status, time_t task_updated, time_t task_created);

		/*
		 * Requires: Nothing.
		 * Modifies: Nothing.
		 * Effects: Returns the task ID.
		 */
		int get_task_ID();

		/*
		 * Requires: Nothing.
		 * Modifies: Nothing.
		 * Effects: Returns the task name.
		 */
		string get_task_name();

		/*
		 * Requires: Nothing.
		 * Modifies: Nothing.
		 * Effects: Returns the task description.
		 */
		string get_task_description();

		/*
		 * Requires: Nothing.
		 * Modifies: Nothing.
		 * Effects: Returns the task status.
		 */
		string get_task_status();

		/*
		 * Requires: Nothing.
		 * Modifies: Nothing.
		 * Effects: Returns the task_created time.
		 */
		time_t get_task_created();

		/*
		 * Requires: Nothing.
		 * Modifies: Nothing.
		 * Effects: Returns the task_updated time.
		 */
		time_t get_task_updated();

		/*
		 * Requires: name is a valid string.
		 * Modifies: task_name, task_updated time.
		 * Effects: Sets the task name.
		 */
		void set_task_name(string name);

		/*
		 * Requires: description is a valid string.
		 * Modifies: task_description, task_updated time.
		 * Effects: Sets the task description.
		 */
		void set_task_description(string description);

		/*
		 * Requires: status is a valid string.
		 * Modifies: task_status, task_updated time.
		 * Effects: Sets the task status.
		 */
		void set_task_status(string status);

		/*
		 * Requires: time is a valid time.
		 * Modifies: task_updated time.
		 * Effects: Updates the task_updated time.
		 */
		//void set_task_updated(time_t time);

		/*
		 * Requires: time is a valid time.
		 * Modifies: task_created time.
		 * Effects: Updates the task_created time.
		 */
		//void set_task_created(time_t time);

	private:

		int task_ID;
		string task_name;
		string task_description;
		string task_status;
		time_t task_created;
		time_t task_updated;


};


#endif // TASK_H