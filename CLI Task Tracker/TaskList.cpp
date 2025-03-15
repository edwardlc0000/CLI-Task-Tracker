/*
 * TaskList.cpp
 *
 * Created On: 2025-03-09
 * Created By: Edward Cromwell
 *
 * Description: This is the implementation file for the TaskList class.
 * 
 */

#include "TaskList.h"
#include "Exceptions.h"
#include "Task.h"

TaskList::TaskList()
{
	task_count = 0;
	file_path = "task list.json";
}

TaskList::TaskList(path read_path)
{
	if (exists(read_path) == false)
	{
		throw file_not_found("The file was not found.");
	}

	ifstream f(read_path);
	json in_list = json::parse(f);
	task_count = 0;
	f.close();

	for (int i = 0; i < in_list.size(); i++)
	{
		Task t(in_list[i]["task_ID"], in_list[i]["task_name"],
			in_list[i]["task_description"], in_list[i]["task_status"], 
			in_list[i]["task_created"], in_list[i]["task_updated"]);
		task_list[i] = t;
		task_count++;
	}

	file_path = read_path;
}

int TaskList::get_task_count()
{
	return task_count;
}

path TaskList::get_file_path()
{
	return file_path;
}

Task TaskList::get_task(int id)
{
	for (int i = 0; i < task_count; i++)
	{
		if (task_list[i].get_task_ID() == id)
		{
			return task_list[i];
		}
	}
	throw task_not_found("The task was not found.");
}

void TaskList::add_task(Task t)
{
	for (int i = 0; i < MAX_TASKS; i++)
	{
		if (task_list[i].get_task_name() == "")
		{
			task_list[i] = t;
			task_count++;
		}
	}
	throw task_list_full("The task list is full.");
}

void TaskList::remove_task(int id)
{
	for (int i = 0; i < task_count; i++)
	{
		if (task_list[i].get_task_ID() == id)
		{
			for (int j = i; j < task_count - 1; j++)
			{
				task_list[j] = task_list[j + 1];
			}
			task_count--;
		}
	}
	throw task_not_found("The task was not found.");
}

void TaskList::update_task(int id, string name, string description, string status)
{
	for (int i = 0; i < task_count; i++)
	{
		if (task_list[i].get_task_ID() == id)
		{
			task_list[i].set_task_name(name);
			task_list[i].set_task_description(description);
			task_list[i].set_task_status(status);
		}
	}
	throw task_not_found("The task was not found.");
}

void TaskList::set_file_path(path write_path)
{
	if (is_directory(write_path.parent_path()) == false)
	{
		throw directory_not_found("The directory was not found.");
	}
	file_path = write_path;
}

void TaskList::write_task_list()
{
	json out_list;
	for (int i = 0; i < task_count; i++)
	{
		json task;
		task["task_ID"] = task_list[i].get_task_ID();
		task["task_name"] = task_list[i].get_task_name();
		task["task_description"] = task_list[i].get_task_description();
		task["task_status"] = task_list[i].get_task_status();
		task["task_created"] = task_list[i].get_task_created();
		task["task_updated"] = task_list[i].get_task_updated();
		out_list.push_back(task);
	}
	ofstream f(file_path);
	f << out_list.dump(4);
	f.close();
}