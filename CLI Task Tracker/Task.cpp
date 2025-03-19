/*
 * Task.cpp
 *
 * Created On: 2025-03-09
 * Created By: Edward Cromwell
 *
 * Description: This is the implementation file for the Task class.
 *
 */

#include "Task.h"

using std::string;
using std::ostream;
using std::format;

int Task::next_task_ID = 0;

Task::Task()
{
	task_ID = next_task_ID;
	task_name = "";
	task_description = "";
	task_status = "to do";
	task_created = time(0);
	task_updated = time(0);
	next_task_ID++;
}

Task::Task(int id, string name, string description, string status, time_t updated, time_t created)
{
	task_ID = id;
	task_name = name;
	task_description = description;
	task_status = status;
	task_created = created;
	task_updated = updated;
	next_task_ID = id + 1;
}

int Task::get_task_ID()
{
	return task_ID;
}

string Task::get_task_name()
{
	return task_name;
}

string Task::get_task_description()
{
	return task_description;
}

string Task::get_task_status()
{
	return task_status;
}

time_t Task::get_task_created()
{
	return task_created;
}

time_t Task::get_task_updated()
{
	return task_updated;
}

void Task::set_task_name(string name)
{
	task_name = name;
	task_updated = time(0);
}

void Task::set_task_description(string description)
{
	task_description = description;
	task_updated = time(0);
}

void Task::set_task_status(string status)
{
	task_status = status;
	task_updated = time(0);
}

ostream& operator<<(ostream& os, const Task& task)
{
	struct tm date_time;

	time_t created = task.task_created;
	localtime_s(&date_time, &created);
	char created_buffer[26];
	asctime_s(created_buffer, sizeof(created_buffer), &date_time);
	created_buffer[sizeof(created_buffer) - 2] = '\0';

	time_t updated = task.task_updated;
	localtime_s(&date_time, &updated);
	char updated_buffer[26];
	asctime_s(updated_buffer, sizeof(updated_buffer), &date_time);

	if (task.task_status == "done")
	{
		os << format("\033[9mTask ID: {}\tName: {}\tStatus: {}\nDescription: {}\033[0m\nCreated: {}\tUpdated: {}",
			task.task_ID, task.task_name, task.task_status, 
			task.task_description, created_buffer, updated_buffer);
	}
	else 
	{
		os << format("Task ID: {}\tName: {}\tStatus: {}\nDescription: {}\nCreated: {}\tUpdated: {}",
			task.task_ID, task.task_name, task.task_status,
			task.task_description, created_buffer, updated_buffer);
	}

	return os;
}


