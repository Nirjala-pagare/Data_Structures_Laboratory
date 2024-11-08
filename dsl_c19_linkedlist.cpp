#include <iostream>
#include <string>
using namespace std;

struct Node {
    int PRN;
    string name;
    Node* next;
};

class PinnacleClub {
private:
    Node* head;

public:
    PinnacleClub() : head(NULL) {}

    void insertPresident(int PRN, string name) {
        Node* p = new Node();
        p->PRN = PRN;
        p->name = name;
        p->next = head;
        head = p;
        cout << "President added successfully!\n";
    }

    void insertSecretary(int PRN, string name) {
        Node* s = new Node();
        s->PRN = PRN;
        s->name = name;
        s->next = NULL;

        if (head == NULL) {
            head = s;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = s;
        }
        cout << "Secretary added successfully!\n";
    }

    void addMembers(int count) {
        if (head == NULL) {
            int prn;
            string name;
            cout << "Please add a president first.\n";
            cout << "Enter PRN for president: ";
                cin >> prn;
                cout << "Enter name for president: ";
                cin.ignore(); 
                getline(cin, name);
            insertPresident(prn,name);
        }

        Node* current = head;

        for (int i = 1; i <= count; ++i) {
            int PRN;
            string name;
            cout << "Enter PRN for member " << i << ": ";
            cin >> PRN;
            cout << "Enter name for member " << i << ": ";
            cin.ignore(); 
            getline(cin, name);

            Node* newNode = new Node();
            newNode->PRN = PRN;
            newNode->name = name;
            newNode->next = current->next;
            current->next = newNode;
            current = newNode; 

            cout << "Member added successfully!\n";
        }
    }

    void deletePresident() {
        if (head == NULL) {
            cout << "No president to delete.\n";
            return;
        }

        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "President removed successfully!\n";
    }

    
    void deleteSecretary() {
        if (head == NULL) {
            cout << "No secretary to delete.\n";
            return;
        }

        if (head->next == NULL) { 
            delete head;
            head = NULL;
            cout << "Secretary removed successfully!\n";
            return;
        }

        Node* current = head;
        while (current->next->next != NULL) {
            current = current->next;
        }

        delete current->next; 
        current->next = NULL;
        cout << "Secretary removed successfully!\n";
    }

    
    void deleteMember(int PRN) {
        if (head == NULL) {
            cout << "List is empty. No member to delete.\n";
            return;
        }

        if (head->PRN == PRN) {
            deletePresident(); 
            return;
        }

        Node* current = head->next; 
        Node* previous = head;

        while (current != NULL && current->PRN != PRN) {
            previous = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << "No member found with PRN: " << PRN << endl;
        } else {
            previous->next = current->next;
            delete current;
            cout << "Member removed successfully!\n";
        }
    }

    
    int countMembers() {
        int count = 0;
        Node* current = head;
        while (current != NULL) {
            count++;
            current = current->next;
        }
        return count;
    }

    
    void displayMembers() {
        if (head == NULL) {
            cout << "No members in the club.\n";
            return;
        }
        Node* current = head;
        while (current != NULL) {
            cout << "PRN: " << current->PRN << " Name: " << current->name << endl;
            current = current->next;
        }
    }

    
    void concatenate(PinnacleClub& list2) {
        if (head == NULL) {
            head = list2.head;
        } else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = list2.head;
        }
        list2.head = NULL; 
    }

   
    ~PinnacleClub() {
        Node* current = head;
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }
};

int main() {
    PinnacleClub divisionA, divisionB;
    int choice, PRN, numMembers;
    string name;

    do {
        cout << "\n*** Pinnacle Club Management System ***\n";
        cout << "1. Add President\n";
        cout << "2. Add Members\n";
        cout << "3. Add Secretary\n";
        cout << "4. Delete President\n";
        cout << "5. Delete Member\n";
        cout << "6. Delete Secretary\n";
        cout << "7. Display Members\n";
        cout << "8. Count Members\n";
        cout << "9. Concatenate Divisions\n";
        cout << "10. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter PRN for President: ";
                cin >> PRN;
                cout << "Enter name for President: ";
                cin.ignore(); 
                getline(cin, name);
                divisionA.insertPresident(PRN, name);
                break;

            case 2:
                cout << "Enter the number of members to add: ";
                cin >> numMembers;
                divisionA.addMembers(numMembers);
                break;

            case 3:
                cout << "Enter PRN for Secretary: ";
                cin >> PRN;
                cout << "Enter name for Secretary: ";
                cin.ignore(); 
                getline(cin, name);
                divisionA.insertSecretary(PRN, name);
                break;

            case 4:
                divisionA.deletePresident();
                break;

            case 5:
                cout << "Enter PRN of the member to delete: ";
                cin >> PRN;
                divisionA.deleteMember(PRN);
                break;

            case 6:
                divisionA.deleteSecretary();
                break;

            case 7:
                divisionA.displayMembers();
                break;

            case 8:
                cout << "Total number of members: " << divisionA.countMembers() << endl;
                break;

            case 9:
                cout << "Enter the number of members to add to Division B: ";
                cin >> numMembers;
                divisionB.addMembers(numMembers);

                divisionA.concatenate(divisionB);
                cout << "Divisions concatenated successfully.\n";
                break;

            case 10:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 10);

    return 0;
}