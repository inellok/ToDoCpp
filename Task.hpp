#include <string>

#pragma once

class Task
{
    std::string task;
    bool done;
public:
    Task(std::string str = "Try to do nothing", bool isDone = false);

    void setDone(bool);
    bool isDone() const;
    void print() const;
    std::string getText() const;
};