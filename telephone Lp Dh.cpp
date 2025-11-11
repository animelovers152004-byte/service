#include <iostream> 
#include <cstring> 
using namespace std; 
 
struct database 
{ 
    char name[10]; 
    char cname[10]; 
    char dname[10]; 
    int cont_no; 
    int tel_no; 
    int mob_no; 
}; 
 
int main() 
{ 
    int n; 
    char ch; 
    database Hash[10]; 
    database Qhash[10]; 
    database Dhash[10]; 
 
    cout << "How many data do you want to store: "; 
    cin >> n; 
 
    for (int i = 0; i < 10; i++) 
    { 
        strcpy(Hash[i].name, "none"); 
        strcpy(Qhash[i].cname, "none"); 
        strcpy(Dhash[i].dname, "none"); 
        Hash[i].tel_no = -1; 
        Qhash[i].mob_no = -1; 
        Dhash[i].cont_no = -1; 
    } 
    cout << endl; 
 
    cout << "***Empty Hash Table***" << endl; 
    cout << "Name Telephone no" << endl; 
    for (int i = 0; i < 10; i++) 
    { 
        cout << Hash[i].name << "   " << Hash[i].tel_no << endl; 
    } 
    cout << endl; 
 
    char Tname[10]; 
    int tel; 
 
    for (int i = 0; i < n; i++) 
    { 
        cout << "Enter client's Name: "; 
        cin >> Tname; 
 
        cout << "Enter Telephone No.: "; 
        cin >> tel; 
 
        int total = 0; 
        for (int j = 0; Tname[j] != '\0'; j++) 
        { 
            total += Tname[j]; 
        } 
        int h = total % 10; 
 
        if (Hash[h].tel_no == -1) 
        { 
            strcpy(Hash[h].name, Tname); 
            Hash[h].tel_no = tel; 
        } 
        else 
        { 
            for (int i = 1; i < 10; i++) 
            { 
                int nh = (h + i) % 10; 
                if (Hash[nh].tel_no == -1) 
                { 
                    strcpy(Hash[nh].name, Tname); 
                    Hash[nh].tel_no = tel; 
                    break; 
                } 
            } 
        } 
 
        if (Qhash[h].mob_no == -1) 
        { 
            strcpy(Qhash[h].cname, Tname); 
            Qhash[h].mob_no = tel; 
        } 
        else 
        { 
            for (int i = 1; i < 10; i++) 
            { 
                int nh = (h + i * i) % 10; 
                if (Qhash[nh].mob_no == -1) 
                { 
                    strcpy(Qhash[nh].cname, Tname); 
                    Qhash[nh].mob_no = tel; 
                    break; 
                } 
            } 
        } 
 
        if (Dhash[h].cont_no == -1) 
        { 
            strcpy(Dhash[h].dname, Tname); 
            Dhash[h].cont_no = tel; 
        } 
        else 
        { 
            int h2 = 7 - (total % 7); 
            for (int i = 1; i < 10; i++) 
            { 
 
                int nh = (h + (i * h2)) % 10; 
                if (Dhash[nh].cont_no == -1) 
                { 
                    strcpy(Dhash[nh].dname, Tname); 
                    Dhash[nh].cont_no = tel; 
                    break; 
                } 
            } 
        } 
    } 
 
    cout << endl; 
    cout << "***Linear Probing Hash Table***" << endl; 
    cout << "Name Telephone no" << endl; 
    for (int i = 0; i < 10; i++) 
    { 
        cout << Hash[i].name << "   " << Hash[i].tel_no << endl; 
    } 
    cout << endl; 
 
    cout << "***Quadratic Probing Hash Table***" << endl; 
    cout << "Name Telephone no" << endl; 
    for (int i = 0; i < 10; i++) 
    { 
        cout << Qhash[i].cname << "   " << Qhash[i].mob_no << endl; 
    } 
    cout << endl; 
 
    cout << "***Double Probing Hash Table***" << endl; 
    cout << "Name Telephone no" << endl; 
    for (int i = 0; i < 10; i++) 
    { 
        cout << Dhash[i].dname << "   " << Dhash[i].cont_no << endl; 
    } 
    do 
    { 
        char Sname[10]; 
        cout << "\nEnter name to search: "; 
        cin >> Sname; 
 
        int total = 0; 
        for (int j = 0; Sname[j] != '\0'; j++) 
        { 
            total += Sname[j]; 
        } 
        int h = total % 10; 
 
        // Linear Probing Search 
        int found = 0; 
        for (int i = 0; i < 10; i++) 
        { 
            int nh = (h + i) % 10; 
            if (strcmp(Hash[nh].name, Sname) == 0) 
            { 
                cout << "\nFound in Linear Probing at index " << nh << ": " << Hash[nh].name << " " << 
Hash[nh].tel_no << endl; 
                found = 1; 
                break; 
            } 
        } 
        if (found == 0) 
            cout << "\nNot found in Linear Probing.\n"; 
 
        // Quadratic Probing Search 
        found = 0; 
        for (int i = 0; i < 10; i++) 
        { 
            int nh = (h + i * i) % 10; 
            if (strcmp(Qhash[nh].cname, Sname) == 0) 
            { 
                cout << "Found in Quadratic Probing at index " << nh << ": " << Qhash[nh].cname << " " << 
Qhash[nh].mob_no << endl; 
                found = 1; 
                break; 
            } 
        } 
        if (found == 0) 
            cout << "Not found in Quadratic Probing.\n"; 
 
        //  Double Hashing Search 
        int h2 = 7 - (total % 7); 
        found = 0; 
        for (int i = 0; i < 10; i++) 
        { 
            int nh = (h + i * h2) % 10; 
            if (strcmp(Dhash[nh].dname, Sname) == 0) 
            { 
                cout << "Found in Double Hashing at index " << nh << ": " << Dhash[nh].dname << " " << 
Dhash[nh].cont_no << endl; 
                found = 1; 
                break; 
            } 
        } 
        if (found == 0) 
            cout << "Not found in Double Hashing.\n"; 
        cout << "DO YOU WANT TO CONTINUE(y/n)"; 
        cin >> ch; 
    } while (ch == 'y'); 
 
    return 0; 
}
