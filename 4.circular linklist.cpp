#include <iostream>
using namespace std;

struct Node {
    string team;
    Node* next;
};

Node* head = NULL;

// Add team
void addTeam() {
    Node* newNode = new Node;

    cout << "Enter team name: ";
    cin >> newNode->team;

    if (head == NULL) {
        head = newNode;
        newNode->next = head;
    } else {
        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }
}

// Round Robin scheduling
void schedule() {
    if (head == NULL) {
        cout << "No teams available.\n";
        return;
    }

    Node* temp = head;

    cout << "\nRound Robin Schedule:\n";

    for (int i = 1; i <= 10; i++) {
        cout << "Round " << i << ": " << temp->team << endl;
        temp = temp->next;
    }
}

// Display teams
void display() {
    if (head == NULL) {
        cout << "No teams available.\n";
        return;
    }

    Node* temp = head;

    cout << "\nTeams:\n";

    do {
        cout << temp->team << endl;
        temp = temp->next;
    } while (temp != head);
}

int main() {
    int choice;

    do {
        cout << "\n--- Tournament ---\n";
        cout << "1. Add Team\n";
        cout << "2. Round Robin Schedule\n";
        cout << "3. Display Teams\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTeam(); break;
            case 2: schedule(); break;
            case 3: display(); break;
            case 4: cout << "Exit"; break;
            default: cout << "Invalid choice!";
        }
    } while (choice != 4);

    return 0;
}
