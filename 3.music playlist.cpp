#include <iostream>
using namespace std;

struct Node {
    string song;
    Node* prev;
    Node* next;
};

Node* head = NULL;
Node* current = NULL;

// Add a song
void addSong() {
    Node* newNode = new Node;

    cout << "Enter song name: ";
    cin >> newNode->song;

    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = current = newNode;
    } else {
        Node* temp = head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
        newNode->prev = temp;
    }

    cout << "Song added.\n";
}

// Next song
void nextSong() {
    if (current != NULL && current->next != NULL) {
        current = current->next;
        cout << "Playing: " << current->song << endl;
    } else {
        cout << "No next song.\n";
    }
}

// Previous song
void previousSong() {
    if (current != NULL && current->prev != NULL) {
        current = current->prev;
        cout << "Playing: " << current->song << endl;
    } else {
        cout << "No previous song.\n";
    }
}

// Display playlist
void display() {
    Node* temp = head;

    cout << "\nPlaylist:\n";
    while (temp != NULL) {
        cout << temp->song << endl;
        temp = temp->next;
    }
}

int main() {
    int choice;

    do {
        cout << "\n--- Music Playlist ---\n";
        cout << "1. Add Song\n";
        cout << "2. Next Song\n";
        cout << "3. Previous Song\n";
        cout << "4. Display Playlist\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addSong(); break;
            case 2: nextSong(); break;
            case 3: previousSong(); break;
            case 4: display(); break;
            case 5: cout << "Exit"; break;
            default: cout << "Invalid choice!";
        }
    } while (choice != 5);

    return 0;
}
