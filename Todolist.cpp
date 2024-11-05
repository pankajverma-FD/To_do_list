#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
public:
    string description;
    bool completed;

    Task(string desc) {
        description = desc;
        completed = false;
    }
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(string description) {
        Task newTask(description);
        tasks.push_back(newTask);
    }

    void viewTasks() {
        for (int i = 0; i < tasks.size(); i++) {
            cout << i + 1 << ". " << tasks[i].description;
            if (tasks[i].completed) {
                cout << " [Completed]";
            }
            cout << endl;
        }
    }

    void markTaskCompleted(int taskIndex) {
        if (taskIndex >= 0 && taskIndex < tasks.size()) {
            tasks[taskIndex].completed = true;
        } else {
            cout << "Invalid task index!" << endl;
        }
    }
};

int main() {
    ToDoList myList;
    int choice;
    string description;
    int taskIndex;

    while (true) {
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task Completed" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                myList.addTask(description);
                break;
            case 2:
                myList.viewTasks();
                break;
            case 3:
                cout << "Enter task number to mark as completed: ";
                cin >> taskIndex;
                myList.markTaskCompleted(taskIndex - 1);
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
