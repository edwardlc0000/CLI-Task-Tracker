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

Task::Task(int id, string name, string description)
{
	task_ID = id;
	task_name = name;
	task_description = description;
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


