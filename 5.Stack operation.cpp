#include <iostream>
using namespace std;

struct Node {
    string page;
    Node* next;
};

Node* top = NULL;

// Visit a new page
void visit(string page) {
    Node* newNode = new Node;
    newNode->page = page;
    newNode->next = top;
    top = newNode;
    cout << "Visited: " << page << endl;
}

// Browser Back
void back() {
    if (top == NULL) {
        cout << "No previous page!" << endl;
        return;
    }

    cout << "Back from: " << top->page << endl;

    Node* temp = top;
    top = top->next;
    delete temp;

    if (top != NULL)
        cout << "Current page: " << top->page << endl;
}

// Display history
void display() {
    Node* temp = top;

    cout << "\nBrowser History:\n";
    while (temp != NULL) {
        cout << temp->page << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;
    string page;

    do {
        cout << "\n1. Visit Page";
        cout << "\n2. Back";
        cout << "\n3. Display History";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter page: ";
                cin >> page;
                visit(page);
                break;

            case 2:
                back();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exit";
                break;

            default:
                cout << "Invalid choice!";
        }
    } while (choice != 4);

    return 0;
}
