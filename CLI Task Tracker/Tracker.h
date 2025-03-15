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
#include <nlohmann\json.hpp>

#include "Task.h"
#include "TaskList.h"

using std::string;
using std::filesystem::path;
using std::cout;
using std::cin;
using std::endl;
using json = nlohmann::json;

class Tracker
{
	public:

		/*
		 * Requires: Nothing.
		 * Modifies: 
		 * Effects: Default constructor for the Tracker class.
		 */
		Tracker();

		/*
		 * Requires: Nothing
		 * Modifies: 
		 * Effects: Selects the main menu option.
		 */
		void main_menu();

		/*
		 * Requires: Nothing.
		 * Modifies: 
		 * Effects: Selects the file to load a task list from.
		 */
		void file_menu();

		/*
		 * Requires: Nothing.
		 * Modifies: 
		 * Effects: Selects the task menu option.
		 */
		void task_menu();

	private:
		TaskList task_list;
		string mode;
};

#endif // TRACKER_H
