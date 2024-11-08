#include <iostream>
#include <string>

using namespace std;

/*
    A double-ended queue (deque) is a linear list in which additions and deletions may be 
    made at either end. Obtain a data representation mapping a deque into a one-dimensional 
    array. Write a C++ program to simulate deque with functions to add and delete elements 
    from either end of the deque.
*/

const int MAX_SIZE = 100; 

class Deque {
private:
    int deque[MAX_SIZE]; 
    int front; 
    int rear; 
    int size; 

public:
    Deque() {
        front = -1; 
        rear = -1; 
        size = 0; 
    }

    void addFront(int value) {
        if (size == MAX_SIZE) { 
            cout << "Deque is full. Cannot add more elements." << endl;
            return;
        }

        if (front == -1) { 
            front = 0;
            rear = 0; 
        } else {
            front = (front - 1 + MAX_SIZE) % MAX_SIZE; 
        }

        deque[front] = value; 
        size++; 
        cout << "Added " << value << " at the front." << endl;
    }

    void addRear(int value) {
        if (size == MAX_SIZE) { 
            cout << "Deque is full. Cannot add more elements." << endl;
            return;
        }

        if (rear == -1) { 
            front = 0; 
            rear = 0; 
        } else {
            rear = (rear + 1) % MAX_SIZE; 
        }

        deque[rear] = value; 
        size++; 
        cout << "Added " << value << " at the rear." << endl;
    }

    void deleteFront() {
        if (size == 0) { 
            cout << "No elements in the deque to delete." << endl;
            return;
        }

        cout << "Deleted " << deque[front] << " from the front." << endl;
        front = (front + 1) % MAX_SIZE; 
        size--; 

        if (size == 0) {
            front = -1;
            rear = -1;
        }
    }

    void deleteRear() {
        if (size == 0) { 
            cout << "No elements in the deque to delete." << endl;
            return;
        }

        cout << "Deleted " << deque[rear] << " from the rear." << endl;
        rear = (rear - 1 + MAX_SIZE) % MAX_SIZE; 
        size--; 

        if (size == 0) {
            front = -1;
            rear = -1;
        }
    }

    void display() const {
        if (size == 0) {
            cout << "No elements in the deque." << endl;
            return;
        }

        cout << "Elements in the deque: ";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % MAX_SIZE; 
            cout << deque[index] << " ";
        }
        cout << endl;
    }
};

int main() {
    Deque deque; 
    int choice, value;

    do {
        cout << "\nDeque Menu:" << endl;
        cout << "1. Add Element at Front" << endl;
        cout << "2. Add Element at Rear" << endl;
        cout << "3. Delete Element from Front" << endl;
        cout << "4. Delete Element from Rear" << endl;
        cout << "5. Display Elements" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to add at the front: ";
                cin >> value;
                deque.addFront(value);
                break;

            case 2:
                cout << "Enter value to add at the rear: ";
                cin >> value;
                deque.addRear(value);
                break;

            case 3:
                deque.deleteFront();
                break;

            case 4:
                deque.deleteRear();
                break;

            case 5:
                deque.display();
                break;

            case 6:
                cout << "Exiting program." << endl;
                break;

            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}