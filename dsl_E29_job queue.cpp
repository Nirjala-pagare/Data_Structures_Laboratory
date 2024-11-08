#include <iostream>
#include <string>

using namespace std;

/*
    Queues are frequently used in computer programming, and a typical example is the 
    creation of a job queue by an operating system. If the operating system does not use 
    priorities, then the jobs are processed in the order they enter the system. 
    Write a C++ program for simulating a job queue. Write functions to add a job 
    and delete a job from the queue.
*/

const int MAX_SIZE = 100; 
class JobQueue {
private:
    struct Job {
        int jobID;
        string jobName; 
    };

    Job queue[MAX_SIZE]; 
    int front; 
    int rear; 
    int size; 

public:
    // Constructor
    JobQueue() {
        front = 0; 
        rear = -1;
        size = 0; 
    }

    void addJob(int id, const string& name) {
        if (size == MAX_SIZE) { 
            cout << "Queue is full. Cannot add more jobs." << endl;
            return;
        }

        rear++; 
        queue[rear].jobID = id; 
        queue[rear].jobName = name; 
        size++; 
        cout << "Job added: " << name << " (ID: " << id << ")" << endl;
    }

    void deleteJob() {
        if (size == 0) { 
            cout << "No jobs in the queue to delete." << endl;
            return;
        }

        cout << "Job deleted: " << queue[front].jobName << " (ID: " << queue[front].jobID << ")" << endl;
        front++; 
        size--; 
    }

    void displayJobs() const {
        if (size == 0) {
            cout << "No jobs in the queue." << endl;
            return;
        }

        cout << "Jobs in the queue: " << endl;
        for (int i = front; i <= rear; i++) { 
            cout << "Job ID: " << queue[i].jobID << ", Job Name: " << queue[i].jobName << endl;
        }
    }
};

int main() {
    JobQueue queue; 
    int choice, jobID;
    string jobName;

    do {
        cout << "\nJob Queue Menu:" << endl;
        cout << "1. Add Job" << endl;
        cout << "2. Delete Job" << endl;
        cout << "3. Display Jobs" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Job ID: ";
                cin >> jobID;
                cout << "Enter Job Name: ";
                cin >> jobName;
                queue.addJob(jobID, jobName);
                break;

            case 2:
                queue.deleteJob();
                break;

            case 3:
                queue.displayJobs();
                break;

            case 4:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}