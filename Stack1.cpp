
#include<iostream>

using namespace std;

#define Max 20

int top = -1;
int stack[Max];

void push(int item)
{
    stack[++top] = item;
}

int pop()
{
    return stack[top--];
}

void display(int stack[])
{
    for(int i=0; stack[i] != 0; i++)
        cout << stack[i] << " ";

    cout << "\n";
}

int main()
{
    push(10);
    push(20);
    push(40);
    push(30);
    display(stack);
    int ele = pop();
    ele = pop();
    display(stack);

    return 0;
}
