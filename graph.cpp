#include <iostream> 
using namespace std; 
 
class Graph 
{ 
    int n, p; 
    string city[5]; 
    int Adjmat[5][5]; 
 
public: 
    Graph() 
    { 
 
        for (int i = 0; i < 5; i++) 
            for (int j = 0; j < 5; j++) 
                Adjmat[i][j] = (i == j) ? 0 : -1; 
    } 
 
    void initialize() 
    { 
        cout << "How many cities : "; 
        cin >> n; 
 
        for (int i = 0; i < n; i++) 
        { 
            cout << "Enter name of city " << i + 1 << ": "; 
            cin >> city[i]; 
        } 
    } 
 
    int cityToIndex(string ct) 
    { 
        for (int i = 0; i < n; i++) 
        { 
            if (city[i] == ct) 
            { 
                return i; 
            } 
        } 
        return -1; 
    } 
 
    void store() 
    { 
        cout << "How many paths are there: "; 
        cin >> p; 
 
        for (int k = 0; k < p; k++) 
        { 
            string s, d; 
            int cost; 
 
            cout << endl 
                 << "Enter Source City: "; 
            cin >> s; 
            int id1 = cityToIndex(s); 
 
            cout << "Enter Destination City : "; 
            cin >> d; 
            int id2 = cityToIndex(d); 
 
            cout << "Enter Cost of path: "; 
            cin >> cost; 
 
            Adjmat[id1][id2] = Adjmat[id2][id1] = cost; 
        } 
    } 
 
    void display() 
    { 
        cout << endl 
             << "Adjacency Matrix Representation of Graph:" << endl; 
 
        for (int i = 0; i < n; i++) 
        { 
            cout << char('A' + i) << " "; 
            for (int j = 0; j < n; j++) 
            { 
                cout << Adjmat[i][j] << " "; 
            } 
            cout << endl; 
        } 
    } 
}; 
 
int main() 
{ 
    Graph g; 
    g.initialize(); 
    g.store(); 
    g.display(); 
 
    return 0;}
