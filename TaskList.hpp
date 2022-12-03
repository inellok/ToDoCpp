#include <vector>
#include "Task.hpp"

#pragma once

class TaskList
{
    std::vector<Task> list;   
    std::string name;

public:
    TaskList(const char *);
    void setName(const char *);

    std::string getName() const;
    void print() const;
    int getOpenedCount() const;
    int getCount() const;

    void addTask(std::string);
    void clearTasks(); //clear tasks that done
    void setDone(int, bool);
    void toggleTask(int);
    std::string getTaskName(int) const;
    bool isDone(int) const;
};