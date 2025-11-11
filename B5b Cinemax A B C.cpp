#include <iostream>
using namespace std;

struct node {
    int status;     
    int seat_no;    
    node *prev, *next;
};

class DLL {
public:
    node *rows[10];
    void creation();
    void display_available();
    void display_occupied();
    void booking();
    void cancellation();
};

void DLL::creation() {
    for (int j = 0; j < 10; j++) {
        rows[j] = NULL;
        node *tail = NULL;
        for (int i = 1; i <= 7; i++) { 
            node *nnode = new node;
            nnode->status = 0;
            nnode->seat_no = i;
            nnode->prev = nnode->next = NULL;

            if (rows[j] == NULL)
                rows[j] = nnode;
            else {
                tail->next = nnode;
                nnode->prev = tail;
            }
            tail = nnode;
        }
    }
}

void DLL::display_available() {
    cout << "\nAvailable seats:\n";
    for (int j = 0; j < 10; j++) {
        cout << "Row " << j + 1 << ": ";
        node *temp = rows[j];
        bool any = false;
        while (temp != NULL) {
            if (temp->status == 0) {
                cout << temp->seat_no << " ";
                any = true;
            }
            temp = temp->next;
        }
        if (!any) cout << "None";
        cout << endl;
    }
}

void DLL::display_occupied() {
    cout << "\nOccupied seats:\n";
    for (int j = 0; j < 10; j++) {
        cout << "Row " << j + 1 << ": ";
        node *temp = rows[j];
        bool any = false;
        while (temp != NULL) {
            if (temp->status == 1) {
                cout << temp->seat_no << " ";
                any = true;
            }
            temp = temp->next;
        }
        if (!any) cout << "None";
        cout << endl;
    }
}

void DLL::booking() {
    int row, seat;
    display_available();
    cout << "\nEnter row number (1–10): ";
    cin >> row;
    cout << "Enter seat number (1–7): ";
    cin >> seat;

    if (row < 1 || row > 10 || seat < 1 || seat > 7) {
        cout << "? Invalid row or seat number.\n";
        return;
    }

    node *temp = rows[row - 1];
    while (temp != NULL && temp->seat_no != seat)
        temp = temp->next;

    if (temp == NULL) {
        cout << "? Seat not found.\n";
        return;
    }

    if (temp->status == 1)
        cout << "? Seat " << seat << " in Row " << row << " is already booked.\n";
    else {
        temp->status = 1;
        cout << "? Seat " << seat << " in Row " << row << " booked successfully!\n";
    }
}

void DLL::cancellation() {
    int row, seat;
    display_occupied();
    cout << "\nEnter row number (1–10): ";
    cin >> row;
    cout << "Enter seat number (1–7): ";
    cin >> seat;

    if (row < 1 || row > 10 || seat < 1 || seat > 7) {
        cout << "? Invalid row or seat number.\n";
        return;
    }

    node *temp = rows[row - 1];
    while (temp != NULL && temp->seat_no != seat)
        temp = temp->next;

    if (temp == NULL) {
        cout << "? Seat not found.\n";
        return;
    }

    if (temp->status == 0)
        cout << "? Seat " << seat << " in Row " << row << " is not booked.\n";
    else {
        temp->status = 0;
        cout << "? Seat " << seat << " in Row " << row << " cancelled successfully!\n";
    }
}

int main() {
    DLL theater;
    theater.creation();

    int choice;
    do {
        cout << "\n========== THEATER SEAT BOOKING SYSTEM ==========\n";
        cout << "1. View available seats\n";
        cout << "2. View occupied seats\n";
        cout << "3. Book a seat\n";
        cout << "4. Cancel a booking\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            theater.display_available();
            break;
        case 2:
            theater.display_occupied();
            break;
        case 3:
            theater.booking();
            break;
        case 4:
            theater.cancellation();
            break;
        case 5:
            cout << "\nThank you for using the system!\n";
            break;
        default:
            cout << "? Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}

