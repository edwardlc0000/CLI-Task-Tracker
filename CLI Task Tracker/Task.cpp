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

Task::Task()
{
	task_ID = 0;
	task_name = "";
	task_description = "";
	task_status = "to do";
	task_created = time(0);
	task_updated = time(0);
}

Task::Task(int id, string name, string description, string status, time_t updated, time_t created)
{
	task_ID = id;
	task_name = name;
	task_description = description;
	task_status = status;
	task_created = created;
	task_updated = updated;
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

ostream& operator<<(ostream& os, Task& task)
{
	struct tm created_date_time;
	time_t created = task.get_task_created();
	localtime_s(&created_date_time, &created);
	vector<char> created_buffer(26);
	asctime_s(created_buffer.data(), created_buffer.size(), &created_date_time);
	created_buffer[created_buffer.size() - 2] = '\0';

	struct tm updated_date_time;
	time_t updated = task.get_task_updated();
	localtime_s(&updated_date_time, &updated);
	vector<char> updated_buffer(26);
	asctime_s(updated_buffer.data(), updated_buffer.size(), &updated_date_time);

	os << format("Task ID: {}\t Name: {}\t Description: {}\t Status: {}\nCreated: {}\t Updated: {}",
		task.get_task_ID(), task.get_task_name(), task.get_task_description(),
		task.get_task_status(), created_buffer.data(), updated_buffer.data());
	return os;
}


