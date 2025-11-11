#include <iostream>
using namespace std;

struct member {
    int PRN;
    string name;
    member *next;
};

class SLL {
public:
    member *president, *secretary;

    SLL() {
        president = NULL;
        secretary = NULL;
    }

    void create();
    void display();
    void add();
    void concatenate(SLL &other);
    int count();
};

void SLL::create() {
    char ch;
    do {
        member *nnode = new member;
        cout << "Enter PRN number of member: ";
        cin >> nnode->PRN;
        cout << "Enter name of member: ";
        cin >> nnode->name;
        nnode->next = NULL;

        if (president == NULL) {
            president = nnode;
            secretary = nnode;
        } else {
            secretary->next = nnode;
            secretary = nnode;
        }

        cout << "Do you want to add another member? (y/n): ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');
}

void SLL::display() {
    if (president == NULL) {
        cout << "\nClub is empty.\n";
        return;
    }

    cout << "\nClub Members:\n";
    member *temp = president;
    while (temp != NULL) {
        cout << "PRN: " << temp->PRN << " | Name: " << temp->name << endl;
        temp = temp->next;
    }
}

void SLL::add() {
    char ans;
    do {
        cout << "\nWhere do you want to add the new member? (h=head, t=tail, m=middle): ";
        cin >> ans;

        member *nnode = new member;
        cout << "Enter PRN number of new member: ";
        cin >> nnode->PRN;
        cout << "Enter name of new member: ";
        cin >> nnode->name;
        nnode->next = NULL;

        if (ans == 'h') {  
            nnode->next = president;
            president = nnode;
        } 
        else if (ans == 't') {  
            secretary->next = nnode;
            secretary = nnode;
        } 
        else if (ans == 'm') {  
            int key;
            cout << "After which PRN do you want to insert? ";
            cin >> key;

            member *temp = president;
            while (temp != NULL && temp->PRN != key)
                temp = temp->next;

            if (temp == NULL) {
                cout << "PRN not found. Cannot insert.\n";
                delete nnode;
            } else {
                nnode->next = temp->next;
                temp->next = nnode;
            }
        } else {
            cout << "Invalid choice.\n";
            delete nnode;
        }

        cout << "Do you want to add another member? (y/n): ";
        cin >> ans;

    } while (ans == 'y' || ans == 'Y');
}


int SLL::count() {
    int cnt = 0;
    member *temp = president;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}


void SLL::concatenate(SLL &other) {
    if (president == NULL) {
        president = other.president;
        secretary = other.secretary;
    } else if (other.president != NULL) {
        secretary->next = other.president;
        secretary = other.secretary;
    }
}

int main() {
    SLL clubA, clubB;
    cout << "Welcome to the Pinnacle Club Management System!\n";

    cout << "\n--- Create Club A ---\n";
    clubA.create();
    clubA.display();

    cout << "\n--- Create Club B ---\n";
    clubB.create();
    clubB.display();

    cout << "\n--- Adding Members to Club A ---\n";
    clubA.add();
    clubA.display();

    cout << "\nTotal members in Club A: " << clubA.count() << endl;
    cout << "Total members in Club B: " << clubB.count() << endl;

    cout << "\n--- Concatenating Club B into Club A ---\n";
    clubA.concatenate(clubB);

    cout << "\nAll members after concatenation:\n";
    clubA.display();
    cout << "\nTotal members after concatenation: " << clubA.count() << endl;

    return 0;
}

