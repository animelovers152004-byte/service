#include <iostream> 
using namespace std; 
int main() 
{ 
    int n, i, j, pass; 
 
    cout << "\nHow many students for Bubble Sort? "; 
    cin >> n; 
    float G[20], temp; 
    cout << "Enter percentage of students:\n"; 
    for (i = 0; i < n; i++) 
    { 
        cin >> G[i]; 
    } 
    cout << "\nBubble Sort: "; 
    for (i = 0; i < n; i++) 
    { 
        cout << G[i] << " "; 
    } 
    cout << endl; 
 
    for (pass = 1; pass < n; pass++) 
    { 
        int comparisons = 0; 
        int swap = 0; 
        for (j = 0; j < n - pass; j++) 
        { 
            comparisons++; 
            if (G[j] > G[j + 1]) 
            { 
                temp = G[j]; 
                G[j] = G[j + 1]; 
                G[j + 1] = temp; 
                swap = 1; 
            } 
        } 
        cout << "Pass " << pass << " Comparisons: " << comparisons << "  Array: "; 
        for (i = 0; i < n; i++) 
        { 
            cout << G[i] << " "; 
        } 
        cout << endl; 
        if (swap == 0) 
            break; 
    } 
    // Selection Sort 
    cout << "\nHow many students for Selection Sort? "; 
    cin >> n; 
 
    float S[20]; 
    cout << "Enter percentage of students:\n"; 
    for (i = 0; i < n; i++) 
    { 
        cin >> S[i]; 
    } 
    cout << "\nSelection Sort: "; 
    for (i = 0; i < n; i++) 
    { 
        cout << S[i] << " "; 
    } 
    cout << endl; 
 
     for (pass = 0; pass < n - 1; pass++) 
    { 
        int minI = pass; 
        int comparisons = 0; 
        for (j = pass + 1; j < n; j++) 
        { 
            comparisons++; 
            if (S[j] < S[minI]) 
            { 
                minI = j; 
            } 
        } 
 
        // Swap the smallest element 
        if (minI != pass) 
        { 
            temp = S[pass]; 
            S[pass] = S[minI]; 
            S[minI] = temp; 
        } 
 
        cout << "Pass " << pass + 1 << " | Comparisons: " << comparisons << " | Array: "; 
        for (i = 0; i < n; i++) 
        { 
            cout << S[i] << " "; 
        } 
        cout << endl; 
    } 
 
    return 0; 
} 
