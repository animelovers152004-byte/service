#include <stdio.h> 
int Jobqueue[20]; 
int front = 0; 
int rear = -1; 
int max = 20; 
int IsEmpty() 
{ 
    if (front > rear) 
    { 
        return 1; 
    } 
    else 
    { 
        return 0; 
    } 
} 
 
int IsFull() 
{ 
    if (rear == max - 1) 
    { 
        return 1; 
    } 
    else 
    { 
        return 0; 
    } 
} 
void enqueue() 
{ 
    int J; 
    char ch; 
    do 
    { 
        if (!IsFull()) 
        { 
            printf("Enter the Job NO.: "); 
            scanf("%d", &J); 
            rear++; 
            Jobqueue[rear] = J; 
        } 
        else 
        { 
            printf("\n Queue overflow."); 
        } 
        printf("do you want to add more jobs(y/n) : "); 
        scanf("%s", &ch); 
    } while (ch == 'y'); 
} 
void dequeue() 
{ 
    char cha, ch; 
    printf("\n do you want to delete jobs(y/n) : "); 
    scanf("%s", &cha); 
    if (cha == 'y') 
    { 
        do 
        { 
            if (!IsEmpty()) 
            { 
                printf("\n Deleted Job No : %d", Jobqueue[front]); 
                front++; 
            } 
            else 
            { 
                printf("\n Queue underflow."); 
            } 
            printf("\n do you want to delete more jobs(y/n) : "); 
            scanf("%s", &ch); 
        } while (ch == 'y'); 
    } 
} 
void display() 
{ 
    if (!IsEmpty()) 
    { 
        for (int i = front; i <= rear; i++) 
        { 
            printf("%d ", Jobqueue[i]); 
        } 
    } 
    else 
    { 
        printf("queue is empty"); 
    } 
} 
int main() 
{ 
    enqueue(); 
    display(); 
    dequeue(); 
    display(); 
} 
