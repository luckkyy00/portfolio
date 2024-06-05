#include <iostream>
#include <vector>
#include <string>

using namespace std; 

// Class representing a task
class Task {
public:
    // Constructor to initialize task with description
    Task(const string& description) : description(description), completed(false) {}

    // Method to mark task as completed
    void markCompleted() {
        completed = true;
    }

    // Method to get task description
    string getDescription() const {
        return description;
    }

    // Method to check if task is completed
    bool isCompleted() const {
        return completed;
    }

private:
    string description;
    bool completed;
};

// Class representing a to-do list
class TodoList {
public:
    // Method to add a new task to the list
    void addTask(const string& description) {
        tasks.emplace_back(description);
    }

    // Method to mark a task as completed based on index
    void markTaskCompleted(size_t index) {
        if (index < tasks.size()) {
            tasks[index].markCompleted();
        } else {
            cerr << "Invalid task index." << endl;
        }
    }

    // Method to display all tasks in the list
    void showTasks() const {
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getDescription()
                      << (tasks[i].isCompleted() ? " [Completed]" : "") << endl;
        }
    }

private:
    vector<Task> tasks; // Vector to store tasks
};

int main() {
    TodoList todoList;

    char choice;
    do {
        // Display menu options
        cout << "Choose an option:" << endl;
        cout << "1. Add a new task" << endl;
        cout << "2. Mark a task as completed" << endl;
        cout << "3. Show tasks" << endl;
        cout << "4. Quit" << endl;
        cin >> choice;

        switch (choice) {
            case '1': {
                // Add a new task
                cout << "Enter task description: ";
                string description;
                cin.ignore(); // Clear input buffer
                getline(cin, description);
                todoList.addTask(description);
                break;
            }
            case '2': {
                // Mark a task as completed
                cout << "Enter index of task to mark as completed: ";
                size_t index;
                cin >> index;
                todoList.markTaskCompleted(index - 1);
                break;
            }
            case '3':
                // Show all tasks
                cout << "Tasks:" << endl;
                todoList.showTasks();
                break;
            case '4':
                // Exit the program
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
                break;
        }
    } while (choice != '4');

    return 0;
}