#include<iostream>
#include<string>
using namespace std;

struct node {
    int PRN;
    string name;
    node* next;
};

class SLL {
public:
    node* president, *secretory;

    SLL() {
        president = NULL;
        secretory = NULL;
    }

    void create();   // create list of members
    void display();  // display all members
};

void SLL::create() {
    int tempno;
    string tempname;
    char ch;
    node* nnode;

    do {
        cout << "\nEnter PRN no of new member: ";
        cin >> tempno;
        cout << "Enter name of new member: ";
        cin >> tempname;

        // create new node
        nnode = new node;
        nnode->PRN = tempno;
        nnode->name = tempname;
        nnode->next = NULL;

        if (president == NULL) {
            // first node becomes both president & secretary
            president = secretory = nnode;
        } else {
            // add new node at the end
            secretory->next = nnode;
            secretory = nnode;
        }

        cout << "Address of node is: " << nnode << endl;

        cout << "Do you want to add new member (y/n): ";
        cin >> ch;

    } while (ch == 'y' || ch == 'Y');
}

void SLL::display() {
    if (president == NULL) {
        cout << "\nClub is empty.\n";
    } else {
        node* temp = president;
        cout << "\nClub Members:\n";
        while (temp != NULL) {
            cout << temp->PRN << " - " << temp->name << endl;
            temp = temp->next;
        }
    }
}

int main() {
    SLL L1;
    cout << "Welcome to Pinnacle Club\n";
    L1.create();
    L1.display();
    return 0;
}
