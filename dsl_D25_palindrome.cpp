#include <iostream>
#include <cstring>
using namespace std;

#define size 50

class Stack {
public:
    int top;
    char stack[size];

    Stack() { 
        top = -1; 
    }

    int isstack_empty() {
        if (top == -1) {
            return 1;
        } else {
            return 0;
        }
    }

    int isstack_full() {
        if (top == size - 1) {
            return 1;
        } else {
            return 0;
        }
    }

    void push(char chr) {
        if (!isstack_full()) {
            top++;
            stack[top] = chr;
        } else {
            cout << "Stack is already full" << endl;
        }
    }

    char pop() {
        if (!isstack_empty()) {
            char popped = stack[top];
            top--;
            return popped;
        } else {
            cout << "Stack is already empty" << endl;
            return '-';
        }
    }

    void display() {
        for (int iter = 0; iter <= top; iter++) {
            cout << stack[iter] << endl;
        }
    }
};

int main() {
    Stack palin;
    string str;
    cin >> str;

    int i = 0, j = 0;

    while (str[i] != '\0') {
        i++;
    }

    while (str[j] != '\0') {
        palin.push(str[j]);
        j++;
    }

    i = 0;
    j--;

    while (j >= 0) {
        if (palin.pop() != str[i]) {
            cout << "Not a palindrome" << endl;
            return 0;
        }
        i++;
        j--;
    }

    cout << "Palindrome" << endl;
    return 0;
}