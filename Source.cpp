#include<iostream>
#include<fstream>
#include<list>
#include<string>
#include<algorithm>
using namespace std;
struct task
{
    string task_title, desc, start_date, ending_date, emp_name;
    bool task_done = 0;
    int prio, emp_id;
};

list <task> emp[200];

void sortt(list<task>& emp, task new_task)
{
    list <task>::iterator it2;
    
        int size_before = emp.size();
        for (it2 = emp.begin(); it2 != emp.end(); it2++)
        {
            if (new_task.prio > it2->prio)
            {
                emp.insert(it2, 1, new_task);
                break;
            }
        }
        if (size_before == emp.size())
        {
            emp.push_back(new_task);
        }
    
}

void input_task()
{
    task new_task;
    ofstream file;
    file.open("Tasks.txt");
    int id, numOfTasks;
    cout << "enter number of tasks you want to add: ";
    cin >> numOfTasks;

    cout << endl;
    for (int i = 0; i < numOfTasks; i++)
    {
        cout << "enter your task title" << "\n";
        cin >> new_task.task_title;

        file << new_task.task_title;

       /* cin.ignore();
        cout << "enter your task Description" << "\n";
        cin.ignore();
        getline(cin, new_task.desc);
        file << new_task.desc;
        cout << "enter your task assigning date" << "\n";
        cin.ignore();
        getline(cin, new_task.start_date);
        file << new_task.start_date;
        cout << "enter your task deadline date" << "\n";
        cin.ignore();
        getline(cin, new_task.ending_date);
        file << new_task.ending_date;*/
        cout << "enter the priority level(1:10) that validate the importance of your task" << "\n";
        cin >> new_task.prio;
        file << new_task.prio;
        /*cout << " enter employee name  " << "\n";
        cin.ignore();
        getline(cin, new_task.emp_name);*/
       /* file << new_task.emp_name;*/
        cout << " Enter employee ID : " << endl;
        cin >> id;

        new_task.emp_id = id;
        file << new_task.emp_id;
        file.close();
        list <task>::iterator it;

        if (emp[id].size() == 0)
        {
            emp[id].push_back(new_task);
        }
        else
        {
            sortt(emp[id], new_task);
        }
    }
    
}



void display_emp_list(int id)
{
    list<task>::iterator it = emp[id].begin();

    while (it != emp[id].end()) {

        cout << " Task Title: " << it->task_title << endl;
        cout << " Employee name: " << it->emp_name << endl;
        cout << " Task's Description: " << it->desc << endl;
        cout << " Strat date: " << it->start_date << endl;
        cout << " Ending date: " << it->ending_date << endl;
        cout << " Level: " << it->prio << endl;
        cout << " Done: " << it->task_done << endl;
        cout << " ////////////////////////////////////////////////" << endl;
        it++;
    }


}
void edit(int id, string name, int t)
{
    list<task>::iterator it;
    for (it = emp[id].begin(); it != emp[id].end(); it++)
    {
        if (it->task_title == name) {
            it->prio = t;
            sortt(emp[id], *it);
            emp[id].erase(it);
            break;
        }
    }
}

void Delete_Task(int id)
{
    emp[id].begin()->task_done = 1;
    emp[id].erase(emp[id].begin());
    cout << "Congratulations! Shatora ya bodyyyyy.\n";
    cout << "The task which should be done :";
    cout << emp[id].begin()->task_title << "\n";

}

int main()
{

    for (;;)
    {
        int number_of_tasks = 0, option, id, index;
        cout << "enter 1 to enter the number of task  " << "\n";
        cout << "1- read information of new task" << "\n";
        cout << "2- display list of tasks of any employee" << "\n";
        cout << "3-  delete and remaining of taskany task" << "\n";
        cout << "4 edit priority" << "\n";
        cin >> option;

        switch (option)
        {
        case 1:
        {
            input_task();
            number_of_tasks++;
            break;
        }
        case 2:
        {
            cout << "enter the id of employee who wants your information" << "\n";
            cin >> id;
            display_emp_list(id);
            break;
        }

        case 3:
        {
            int id;
            cout << "enter the id of task which finished " << "\n";
            cin >> id;
            Delete_Task(id);
            break;
        }
        case 4:
        {
            int newpriority;
            string title;
            cout << "enter the id of employee" << "\n";
            cin >> id;
            cout << "enter the title of the task" << "\n";
            cin >> title;
            cout << "enter the new priority" << "\n";
            cin >> newpriority;
            edit(id, title, newpriority);
        }

        }
    }
    return 0;
}