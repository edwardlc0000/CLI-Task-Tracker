/*
 * Tracker.h
 * 
 * Created On: 2025-03-15
 * Created By: Edward Cromwell
 * 
 * This is the header file for the Tracker class.
 */

#pragma once
#ifndef TRACKER_H
#define TRACKER_H

#include <string>
#include <ctime>
#include <iostream>
#include <filesystem>
#include <cstdlib>
#include <nlohmann\json.hpp>

#include "Task.h"
#include "TaskList.h"

class Tracker
{
	public:

		/*
		 * Requires: Nothing.
		 * Modifies: Mode.
		 * Effects: Default constructor for the Tracker class.
		 */
		Tracker();

		/*
		 * Requires: Nothing
		 * Modifies: Mode.
		 * Effects: Selects the main menu option.
		 */
		void main_menu();

		/*
		 * Requires: Nothing.
		 * Modifies: task_list, mode.
		 * Effects: Selects the file to load a task list from.
		 */
		void file_menu();

		/*
		 * Requires: Nothing.
		 * Modifies: task_list, Task object in task_list.
		 * Effects: Selects the task menu option.
		 */
		void task_menu();

		/*
		 * Requires: Nothing
		 * Modifies: task_list, Task object in task_list.
		 * Effects: Creates a new task and adds it to the task list.
		 */
		void create_task_menu();

		/*
		 * Requires: Nothing
		 * Modifies: task_list, Task object in task_list.
		 * Effects: Removes a task from the task list.
		 */
		void remove_task_menu();

		/*
		 * Requires: Nothing.
		 * Modifies: Task object in task_list.
		 * Effects: Updates a task in the task list.
		 */
		void update_task_menu();

		/*
		 * Requires: Nothing.
		 * Modifies: Task object in task_list.
		 * Effects: Edits a task in the task list.
		 */
		void edit_task_menu();

		/*
		 * Requires: Nothing.
		 * Modifies: Nothing.
		 * Effects: Outputs all tasks in the task list.
		 */
		void view_task_list_menu();

		/*
		 * Requires: Nothing.
		 * Modifies: Contents of a .json.
		 * Effects: Writes the task list to a file.
		 */
		void write_task_list_menu();

	private:
		TaskList task_list;
		string mode;
};

#endif // TRACKER_H
