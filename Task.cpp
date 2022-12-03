#include <string>
#include <iostream>
#include "Task.hpp"

Task::Task(std::string str, bool taskDone) : task(str), done(taskDone)
{}

bool Task::isDone() const
{
    return done;
}

void Task::setDone(bool val)
{
    done = val;
}

void Task::print() const
{
    std::cout << task << " ";
    if (done) std::cout << " [YES]"; else std::cout << " [NO]";
    std::cout << std::endl;
}

std::string Task::getText() const
{
    return task;
}