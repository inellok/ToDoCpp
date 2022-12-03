#include <iostream>
#include <fstream>
#include <vector>
#include "TaskList.hpp"
#include "Saver.hpp"

void createNewTask(std::vector<TaskList> &all)
{
    std::string name;
    std::cout << "Enter Task Group name: ";
    getline(std::cin, name);
    
    TaskList newTask(name.c_str());
    all.push_back(newTask);
}

void showAllTasks(std::vector<TaskList> & all)
{
    std::cout << std::endl;
    for (auto el : all)
    {
        std::cout << el.getName() << " (" << el.getOpenedCount() << " opened, " << el.getCount() << " all)" << std::endl;
    }
    std::cout << std::endl;
}

void showOpenedTasks(std::vector<TaskList> & all)
{
    std::cout << std::endl;
    for (auto el : all)
    {
        if (el.getOpenedCount() > 0) 
        {
            std::cout << el.getName() << " (" << el.getOpenedCount() << " opened, " << el.getCount() << " all)" << std::endl;
        }
    }
    std::cout << std::endl;
}

void removeTaskList(std::vector<TaskList> &all)
{
    std::string name;
    std::cout << "Enter name of Task Group to delete: ";
    getline(std::cin, name);

    for (std::vector<TaskList>::iterator i = all.begin(); i < all.end(); ++i)
    {
        if (i->getName() == name) 
        {
            all.erase(i);
            break;
        }
    }
}

void printTaskList(std::vector<TaskList> &all)
{
    std::string name;
    std::cout << "Enter name of Task Group to print: ";
    getline(std::cin, name);

    for (auto x : all)
    {
        if (x.getName() == name)
        {
            x.print();
            break;
        }
    }
}

void addNewTask(std::vector<TaskList> &all)
{
    std::string groupName, taskName;
    std::cout << "Enter name of Task Group: ";
    getline(std::cin, groupName);

    
    std::cout << "Enter name of Task: ";
    getline(std::cin, taskName);

    for (auto &x : all)
    {
        if (x.getName() == groupName) 
        {
            x.addTask(taskName);
            break;
        }
    }
}

void toggleTask(std::vector<TaskList> &all)
{
    std::string groupName;
    int taskInd;
    std::cout << "Enter name of Task Group: ";
    getline(std::cin, groupName);

    std::cout << "Enter index of Task to toggle: ";
    std::cin >> taskInd;
    std::cin.get(); //skipping \n shit

    for (auto &x : all)
    {
        if (x.getName() == groupName) 
        {
            x.toggleTask(taskInd);
            break;
        }
    }
}

void clearDoneTask(std::vector <TaskList> &all)
{
    for (std::vector<TaskList>::iterator i = all.begin(); i < all.end(); ++i)
    {
        i->clearTasks();
    }
}

void clearDoneTaskLists(std::vector <TaskList> &all)
{
    for (auto i = all.begin(); i < all.end(); ++i)
    {
        if (i->getOpenedCount() == 0)
        {
            std::cout << "Erasing " << i->getName() << "...\n";
            all.erase(i);
        }
    }
}

void (*actions[10])(std::vector<TaskList>&) =
{
    createNewTask,
    showAllTasks,
    showOpenedTasks,
    removeTaskList,
    printTaskList,
    addNewTask,
    toggleTask,
    clearDoneTask,
    clearDoneTaskLists
};

int main()
{
    std::cout << "Welcome to the To Do application! Here you can manage your tasks!" << std::endl << std::endl;
    std::vector<TaskList> allGroups;

    loadFromFile(allGroups);
    int input = -1;
    while (input != 11)
    {
        std::cout << std::endl <<
            "Commands:\n" <<
            "1 - Create new task group\n" <<
            "2 - Show all task groups\n" <<
            "3 - Show opened task groups\n" <<
            "4 - Remove task group\n" <<
            "5 - Print task group\n" <<
            "6 - Add new task to task group\n" <<
            "7 - Toggle task in task group\n" <<
            "8 - Clear all completed tasks in task group\n" <<
            "9 - Clear task groups that done\n" <<
            "10 - Quit(and save)\n";

        std::cin >> input;
        std::cin.get();

        if (input == 10) break;

        std::cout << std::endl << ".............................." << std::endl;
        actions[input - 1](allGroups);
        std::cout << ".............................." << std::endl << std::endl;

    }
  
    saveToFile(allGroups);
    return 0;
}