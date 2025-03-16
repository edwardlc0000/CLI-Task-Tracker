/*
 * Test.h
 * 
 * Created On: 2025-03-11
 * Created By: Edward Cromwell
 * 
 * Description: This is the header file for the test functions.
 * 
 */


#pragma once
#ifndef TEST_H
#define TEST_H

#include <iostream>
#include <cstdlib>
#include "Exceptions.h"
#include "Task.h"
#include "TaskList.h"

using std::cout;
using std::endl;

void start_tests();
void test_task();
void test_task_list();

#endif // !TEST_H



