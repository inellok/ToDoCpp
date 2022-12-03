#include <vector>
#include <iostream>
#include "TaskList.hpp"
#include "Task.hpp"

TaskList::TaskList(const char *n) : name(n)
{}

void TaskList::setName(const char *n)
{
    name = n;
}

std::string TaskList::getName() const
{
    return name;
}

void TaskList::print() const
{
    std::cout << std::endl;
    std::cout << '\t' << name << std::endl;
    std::cout << ' ' << "------------------------------" << std::endl;
    const int size = list.size();
    if (list.size() > 0)
    {
        for (int j = 0; j < size; ++j)
        {
            std::cout << j + 1 << ". ";
            list[j].print();
        }
    } else
    {
        std::cout << name << " is empty." << std::endl;
    }
    std::cout << ' ' << "------------------------------" << std::endl;
}

void TaskList::addTask(std::string newName)
{
    Task newTask(newName);
    list.push_back(newTask);
}

void TaskList::clearTasks() //remove tasks that done
{
    const int size = list.size();
    for (int j = 0; j < size; ++j)
    {
        if (list[j].isDone()) list.erase(list.begin() + j);
    }
}

void TaskList::setDone(int i, bool done)
{
    list[i].setDone(done);
}

int TaskList::getOpenedCount() const
{
    int opened = 0;
    for (auto x : list)
    {
        if (!x.isDone()) ++opened;
    }
    return opened;
}

int TaskList::getCount() const
{
    return list.size();
}

void TaskList::toggleTask(int index)
{
    for (int i = 0; i < list.size(); ++i)
    {
        if (i == (index - 1))
        {
            list[i].setDone(!list[i].isDone());
            break;
        }
    }
}

std::string TaskList::getTaskName(int index) const
{
    return list[index].getText();
}

bool TaskList::isDone(int index) const
{
    return list[index].isDone();
}