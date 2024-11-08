#include <iostream>
#include <string>

using namespace std;

/*
    Pizza parlor accepting a maximum M orders. Orders are served on a first-come, 
    first-served basis. Once placed, an order cannot be cancelled. 
    Write a C++ program to simulate the system using a circular queue.
*/

const int MAX_SIZE = 5;

class CircularQueue {
private:
    string orders[MAX_SIZE]; 
    int front; 
    int rear; 
    int size; 
public:
    CircularQueue() {
        front = -1; 
        rear = -1; 
        size = 0; 
    }

    void addOrder(const string& order) {
        if (size == MAX_SIZE) { 
            cout << "Order queue is full. Cannot add more orders." << endl;
            return;
        }

        if (front == -1) { 
            front = 0; 
        }

        rear = (rear + 1) % MAX_SIZE; 
        orders[rear] = order; 
        size++; 
        cout << "Order added: " << order << endl;
    }

    void serveOrder() {
        if (size == 0) { 
            cout << "No orders to serve." << endl;
            return;
        }

        cout << "Serving order: " << orders[front] << endl;
        front = (front + 1) % MAX_SIZE; 
        size--; 

        if (size == 0) {
            front = -1;
            rear = -1;
        }
    }

    void displayOrders() const {
        if (size == 0) {
            cout << "No orders in the queue." << endl;
            return;
        }

        cout << "Current orders in the queue: ";
        for (int i = 0; i < size; i++) {
            int index = (front + i) % MAX_SIZE; 
            cout << orders[index] << " ";
        }
        cout << endl;
    }
};

int main() {
    CircularQueue queue; 
    int choice;
    string order;

    do {
        cout << "\nPizza Parlor Menu:" << endl;
        cout << "1. Add Order" << endl;
        cout << "2. Serve Order" << endl;
        cout << "3. Display Current Orders" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter order name: ";
                cin >> order;
                queue.addOrder(order);
                break;

            case 2:
                queue.serveOrder();
                break;

            case 3:
                queue.displayOrders();
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