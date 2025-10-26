#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string title;
    bool completed;
};

vector<Task> tasks;

void addTask(string title) {
    tasks.push_back({title, false});
    cout << "Task added!\n";
}

void viewTasks() {
    cout << "\nYour Tasks:\n";
    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].title
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markCompleted(int index) {
    if (index > 0 && index <= tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else cout << "Invalid task number.\n";
}

void removeTask(int index) {
    if (index > 0 && index <= tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed!\n";
    } else cout << "Invalid task number.\n";
}

int main() {
    int choice;
    string title;
    while (true) {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter task: ";
            getline(cin, title);
            addTask(title);
        } else if (choice == 2) viewTasks();
        else if (choice == 3) {
            int index;
            cout << "Enter task number: ";
            cin >> index;
            markCompleted(index);
        } else if (choice == 4) {
            int index;
            cout << "Enter task number: ";
            cin >> index;
            removeTask(index);
        } else if (choice == 5) break;
        else cout << "Invalid choice!\n";
    }
}
