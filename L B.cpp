#include <iostream> 
#include <algorithm> 
using namespace std; 
 
int main()  
{ 
    int i, n, b; 
    int A[5]; 
    char ch; 
 
    cout << "How many students are present: "; 
    cin >> n; 
 
    for (i = 0; i < n; i++)  
    { 
        cout << "Enter roll no of student: "; 
        cin >> A[i]; 
    } 
 
    // Display array of roll numbers 
    cout << "\nRoll numbers are: "; 
    for (i = 0; i < n; i++)  
    { 
        cout << A[i] << " "; 
    } 
 
    do  
    { 
        cout << "\nEnter key roll no: "; 
        cin >> b; 
 
        // Key is stored in b 
        int match = 0; 
        for (i = 0; i < n; i++)  
        { 
            if (A[i] == b)  
            { 
                match = 1; 
                break; 
            } 
        } 
 
        if (match == 1) 
            cout << "Student is present\n"; 
        else 
            cout << "Student is absent\n"; 
 
        cout << "Do you want to continue (y/n): "; 
        cin >> ch; 
 
    } while (ch == 'y'); 
 
    cout << "\nBinary Search\n"; 
 
    sort(A, A + n); 
 
    cout << "Sorted roll numbers are: "; 
    for (i = 0; i < n; i++)  
    { 
        cout << A[i] << " "; 
    } 
 
    cout << "\nReady to start binary search\n"; 
 
    int start = 0, end = n - 1, flag = 0, mid; 
    char a; 
 
    do  
    { 
        cout << "\nEnter a key roll no for binary: "; 
        cin >> b; 
 
        start = 0; 
        end = n - 1; 
        flag = 0; 
 
        while (start <= end)  
        { 
            mid = (start + end) / 2; 
 
            if (A[mid] == b)  
            { 
                flag = 1; 
                break; 
            }  
            else if (A[mid] < b)  
            { 
                start = mid + 1; 
            }  
            else  
            { 
                end = mid - 1; 
            } 
        } 
 
        if (flag == 1) 
            cout << "Student is present (Binary Search)\n"; 
        else 
            cout << "Student is absent (Binary Search)\n"; 
 
        cout << "Do you want to continue binary search (y/n): "; 
        cin >> a; 
 
    } while (a == 'y'); 
 
    return 0; 
} 
