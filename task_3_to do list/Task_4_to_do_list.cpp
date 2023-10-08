#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Task class to represent a single task
class Task {
private:
    string description;
    int priority;
    string dueDate;
public:
    // Constructor
    Task(string description, int priority, string dueDate) {
        this->description = description;
        this->priority = priority;
        this->dueDate = dueDate;
    }
    // Getters
    string getDescription() const {
        return description;
    }
    int getPriority() const {
        return priority;
    }
    string getDueDate() const {
        return dueDate;
    }
};

// ToDoList class to represent the entire to-do list
class ToDoList {
private:
    vector<Task> tasks;
public:
    // Add a task to the list
    void addTask(Task task) {
        tasks.push_back(task);
    }
    // Display all tasks in the list
    void displayTasks() const {
        for (int i = 0; i < tasks.size(); i++) {
            cout << "Task " << i+1 << ":" << endl;
            cout << "Description: " << tasks[i].getDescription() << endl;
            cout << "Priority: " << tasks[i].getPriority() << endl;
            cout << "Due date: " << tasks[i].getDueDate() << endl;
            cout << endl;
        }
    }
    // Get the number of tasks in the list
    int getNumTasks() const {
        return tasks.size();
    }
    // Get a specific task from the list
    Task getTask(int index) const {
        return tasks[index];
    }
    // Sort tasks by priority
    void sortByPriority() {
        sort(tasks.begin(), tasks.end(), [](Task a, Task b) {
            return a.getPriority() > b.getPriority();
        });
    }
};

int main() {
    // Create a new to-do list
    ToDoList toDoList;

    // Get tasks from user input
    int numTasks;
    cout << "How many tasks do you want to add? ";
    cin >> numTasks;
    for (int i = 0; i < numTasks; i++) {
        string description, dueDate;
        int priority;
        cout << "Enter description of task " << i+1 << ": ";
        cin >> description;
        cout << "Enter priority of task " << i+1 << " (1-5): ";
        cin >> priority;
        cout << "Enter due date of task " << i+1 << " (YYYY-MM-DD): ";
        cin >> dueDate;
        Task task(description, priority, dueDate);
        toDoList.addTask(task);
    }

    // Display all tasks in the list
    cout << "Current tasks:" << endl;
    toDoList.displayTasks();

    // Sort tasks by priority
    toDoList.sortByPriority();

    // Display all tasks in the list after sorting
    cout << "Tasks sorted by priority:" << endl;
    toDoList.displayTasks();

    // Get the number of tasks in the list
    int numTasks = toDoList.getNumTasks();

    // Get the highest priority task
    if (numTasks > 0) {
        Task highestPriorityTask = toDoList.getTask(0);
        cout << "Winner: " << highestPriorityTask.getDescription() << endl;
    } else {
        cout << "No winner." << endl;
    }

    return 0;
}
