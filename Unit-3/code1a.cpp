#include <iostream>
#include <queue>
#include <stack>
#include <string>
using namespace std;

queue<string> pendingTasks;
stack<string> completedTasks;

void addTask()
{
    string task;
    cout << "Enter task description: ";
    cin.ignore();
    getline(cin, task);

    pendingTasks.push(task);
    cout << "Task added successfully!" << endl;
}

void processTask()
{
    if (pendingTasks.empty())
    {
        cout << "No pending tasks available." << endl;
        return;
    }

    string task = pendingTasks.front();
    pendingTasks.pop();

    completedTasks.push(task);

    cout << "Processing task: " << task << endl;
    cout << "Task completed successfully!" << endl;
}

void displayPendingTasks()
{
    if (pendingTasks.empty())
    {
        cout << "No pending tasks available." << endl;
        return;
    }

    queue<string> temp = pendingTasks;

    cout << "\nPending Tasks:" << endl;

    while (!temp.empty())
    {
        cout << "- " << temp.front() << endl;
        temp.pop();
    }
}

void displayCompletedTasks()
{
    if (completedTasks.empty())
    {
        cout << "No completed task history available." << endl;
        return;
    }

    stack<string> temp = completedTasks;

    cout << "\nCompleted Task History:" << endl;

    while (!temp.empty())
    {
        cout << "- " << temp.top() << endl;
        temp.pop();
    }
}

void removeLatestHistory()
{
    if (completedTasks.empty())
    {
        cout << "No completed task history available." << endl;
        return;
    }

    cout << "Removed history entry: "
         << completedTasks.top() << endl;

    completedTasks.pop();
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== AUTONOMOUS WAREHOUSE ROBOT =====" << endl;
        cout << "1. Add New Task" << endl;
        cout << "2. Process Next Task" << endl;
        cout << "3. Display Pending Tasks" << endl;
        cout << "4. Display Completed Task History" << endl;
        cout << "5. Remove Latest History Entry" << endl;
        cout << "6. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addTask();
                break;

            case 2:
                processTask();
                break;

            case 3:
                displayPendingTasks();
                break;

            case 4:
                displayCompletedTasks();
                break;

            case 5:
                removeLatestHistory();
                break;

            case 6:
                cout << "Exiting Autonomous Warehouse Robot System."
                     << endl;
                break;

            default:
                cout << "Invalid choice! Please try again."
                     << endl;
        }

    } while (choice != 6);

    return 0;
}
