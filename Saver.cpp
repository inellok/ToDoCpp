#include "Saver.hpp"
#include <iostream>
#include <fstream>

void loadFromFile(std::vector <TaskList> &all)
{
    std::ifstream load("save.todo");
    if (load.fail())
    {
        std::ofstream newFile("save.todo");
        newFile.close();
    }
    load.open("save.todo");
    
    std::string groupName, taskName;
    bool taskDone;
    int count;

    while (!load.eof())
    {
        TaskList tmp("new");

        getline(load, groupName);
        load >> count;
        load.get();
        for (int i = 0; i < count; ++i)
        {
            getline(load, taskName);
            load >> taskDone;
            load.get();

            tmp.addTask(taskName);
            tmp.setDone(i, taskDone);
        }
        load.get(); //skip \n

        tmp.setName(groupName.c_str());
        all.push_back(tmp);
    }

    if (!load) return;


    load.close();
}

void saveToFile(std::vector <TaskList> &all)
{
    std::ofstream saving;
    int checkIndex = 0;
    saving.open("save.todo");
    if (!saving) return;

        for (auto &x : all)
        {
            const int count = x.getCount();
            saving << x.getName() << std::endl;
            saving << count << std::endl;
            
            for (int i = 0; i < count; ++i)
            {
                saving << x.getTaskName(i) << std::endl;
                if (x.isDone(i)) saving << "1\n"; 
                else saving << "0\n";
            }
            if (checkIndex != all.size() - 1) saving << std::endl;
            ++checkIndex;
        }
    saving.close();
}