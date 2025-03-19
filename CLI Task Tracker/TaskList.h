/*
 * TaskList.h
 *
 * Created On: 2025-03-09
 * Created By: Edward Cromwell
 *
 * Description: This is the header file for the TaskList class.
 * 
 */

#pragma once
#ifndef TASKLIST_H
#define TASKLIST_H

#include <fstream>
#include <iostream>
#include <string>
#include <filesystem>
#include <algorithm>
#include <nlohmann\json.hpp>
#include "Exceptions.h"
#include "Task.h"

using std::filesystem::path;
using std::string;

const int MAX_TASKS = 16;

class TaskList
{
	public:
		/*
		 * Requires: Nothing.
		 * Modifies: task_count, file_path.
		 * Effects: Default constructor for the TaskList class.
		 */
		TaskList();

		/*
		 * Requires: file_path references a valid .json file.
		 * Modifies: task_count, file_path.
		 * Effects: Contructor for the TaskList class that takes a file path.
		 */
		TaskList(path read_path);

		/*
		 * Requires: Nothing.
		 * Modifies: Nothing.
		 * Effects: Returns the task_count.
		 */
		int get_task_count();

		/*
		 * Requires: Nothing.
		 * Modifies: Nothing.
		 * Effects: Returns the file_path.
		 */
		path get_file_path();

		/*
		 * Requires: id is a valid integer.
		 * Modifies: Nothing.
		 * Effects: Returns a task from the task list.
		 */
		Task get_task(int id);

		/*
		 * Requires: task is a valid Task object.
		 * Modifies: task_list, task_count.
		 * Effects: Adds a task to the task list.
		 */
		void add_task(Task task);

		/*
		 * Requires: id is a valid integer.
		 * Modifies: task_list, task_count.
		 * Effects: Removes a task from the task list.
		 */
		void remove_task(int id);

		/*
		 * Requires: id is a valid integer.
		 * Modifies: Task object in task_list.
		 * Effects: Updates a task in the task list.
		 */
		void update_task(int id, string status);

		/*
		 * Requires: id is a valid integer.
		 * Modified: Task object in task_list.
		 * Effects: Edits a task in the task list.
		 */
		void edit_task(int id, string name, string description, string status);

		/*
		 * Requires: Nothing.
		 * Modifies: Nothing.
		 * Effects: Prints the task list.
		 */
		void display_task_list();

		/*
		 * Requires: write_path is a valid string.
		 * Modifies: file_path.
		 * Effects: Sets the file path.
		 */
		void set_file_path(path write_path);

		/*
		 * Requires: file_path is a valid file path.
		 * Modifies: file_path.json contents.
		 * Effects: Writes the task list to a file.
		 */
		void write_task_list();

	private:
		Task task_list[MAX_TASKS];
		int task_count;
		path file_path;

};

#endif // TASKLIST_H