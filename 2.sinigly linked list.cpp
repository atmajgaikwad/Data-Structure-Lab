#include <iostream>
using namespace std;

struct Node {
    int id;
    string name;
    Node* next;
};

Node* head = NULL;

// Insert employee
void insertEmployee() {
    Node* newNode = new Node;

    cout << "Enter Employee ID: ";
    cin >> newNode->id;
    cout << "Enter Employee Name: ";
    cin >> newNode->name;

    newNode->next = head;
    head = newNode;

    cout << "Employee inserted.\n";
}

// Delete employee
void deleteEmployee() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->id != id) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Employee not found.\n";
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;

    delete temp;
    cout << "Employee deleted.\n";
}

// Search employee
void searchEmployee() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL) {
        if (temp->id == id) {
            cout << "Employee Found!\n";
            cout << "ID: " << temp->id << endl;
            cout << "Name: " << temp->name << endl;
            return;
        }
        temp = temp->next;
    }

    cout << "Employee not found.\n";
}

// Display employees
void display() {
    Node* temp = head;

    while (temp != NULL) {
        cout << "ID: " << temp->id
             << ", Name: " << temp->name << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- Employee Management ---\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: insertEmployee(); break;
            case 2: deleteEmployee(); break;
            case 3: searchEmployee(); break;
            case 4: display(); break;
            case 5: cout << "Exit"; break;
            default: cout << "Invalid choice!";
        }
    } while (choice != 5);

    return 0;
}
