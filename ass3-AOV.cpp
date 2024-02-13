// Activity on vertex(AOV) network: Sandy is a well organized person.
// Every day he makes a list of things which need to be done and
// enumerates them from 1 to n. However, some things need to be done
// before others. Write a C++ code to find out whether Sandy can solve all
// his duties and if so, print the correct order

#include<iostream>
using namespace std;

class SandyTasks {
    public:
        string task;
        SandyTasks *next;
};

class TopologicalSort {
    private:
        SandyTasks *taskList[10];
        SandyTasks *temp;
        int inDegree[10];
        int taskNum = 0;

    public:
        void addTask(string task) {
            SandyTasks *newTask = new SandyTasks;
            taskList[taskNum] = newTask;
            newTask->task = task;
            newTask->next = NULL;
            taskNum++;
        }
        void prioritizeTask(string task1, string task2) {
            SandyTasks *newTask = new SandyTasks;
            for (int i = 0; i < taskNum; i++) {
                if (taskList[i]->task == task1) {
                    temp = taskList[i];
                    while (temp->next != NULL) {
                        temp = temp->next;
                    }
                    temp->next = newTask;
                    newTask->task = task2;
                    newTask->next = NULL;
                }
            }
        }
        void degreeFind() {
            string degreeElement;
            int degree;
            for (int i = 0; i < taskNum; i++) {
                degree = 0;
                degreeElement = taskList[i]->task;
                for (int j = i+1; j < taskNum; j++) {
                    temp = taskList[j];
                    while (temp->next != NULL) {
                        if (temp->task == degreeElement) {
                            degree++;
                        }
                    }
                }
                inDegree[i] = degree;
                cout<<degreeElement<<" -> "<<degree<<endl;
            }
        }
};

int main() {
    TopologicalSort obj;

    obj.addTask("wakeup");
    obj.addTask("brush");
    obj.addTask("bath");
    obj.addTask("breakfast");
    obj.addTask("job");

    obj.prioritizeTask("wakeup", "brush");
    obj.prioritizeTask("wakeup", "bath");
    obj.prioritizeTask("bath","breakfast");
    obj.prioritizeTask("breakfast", "job");

    obj.degreeFind();

    return 0;
}