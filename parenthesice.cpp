#include <iostream> 
using namespace std; 
class wellp 
{ 
public: 
    int max, top; 
    char stack[10]; 
    wellp() 
    { 
        max = 10; 
        top = -1; 
    } 
    int Isempty(); 
    int Isfull(); 
    void push(char); 
    char pop(); 
    char gettop(); 
    void check(char exp[]); 
}; 
int wellp::Isempty() 
{ 
    if (top == -1) 
    { 
        return 1; 
    } 
    else 
    { 
        return 0; 
    } 
} 
int wellp::Isfull() 
{ 
    if (top == max - 1) 
    { 
        return 1; 
    } 
    else 
    { 
        return 0; 
    } 
} 
void wellp::push(char e) 
{ 
    if (!Isfull()) 
    { 
        top++; 
        stack[top] = e; 
    } 
    else 
    { 
        cout << "\nstack overflow"; 
    } 
} 
char wellp::pop() 
{ 
    char temp; 
    if (!Isempty()) 
    { 
        temp = stack[top]; 
        top--; 
        return temp; 
    } 
    else 
    { 
        cout << "\nstack underflow"; 
        return 'u'; 
    } 
} 
char wellp::gettop() 
{ 
    if (!Isempty()) 
    { 
        return (stack[top]); 
    } 
    else 
    { 
        cout << "\n stack is empty"; 
        return -1; 
    } 
} 
void wellp::check(char exp[]) 
{ 
    int i = 0, flag = 0; 
    char ch1; 
    while (exp[i] != '\0') 
    { 
        char ch = exp[i]; 
        if (ch == '(' || ch == '[' || ch == '{') 
        { 
            push(ch); 
        } 
        if (ch == ')' || ch == ']' || ch == '}') 
        { 
            ch1 = pop(); 
        } 
        if (ch == ')' && ch1 != '(' || ch == ']' && ch1 != '[' || ch == '}' && ch1 != '{') 
        { 
            flag = 1; 
            break; 
        } 
        i++; 
    } 
    if (flag == 0 && Isempty()) 
    { 
        cout << "\n well paranthesized"; 
    } 
    else 
    { 
        cout << "\n not well paranthesized"; 
    } 
} 
int main(){ 
    char exp[20]; 
    char choice; 
    do 
    { 
        cout << "enter expression : "; 
        cin >> exp; 
        wellp p1; 
        p1.check(exp); 
        cout << "\n do you want to continue  y/n : "; 
        cin >> choice; 
} while (choice == 'y'); 
} 

