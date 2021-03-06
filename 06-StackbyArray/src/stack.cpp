#include <iostream>
#include "stack.h"

using namespace std;

void Stack::create()
{
    top = 0;
}
void Stack::close()
{
}

void Stack::print_stack(){
    cout<<"[ ";
    for(int i=top;i>0;i--)
        cout<<element[i-1]<<" ";
    cout<<"]"<<endl;
} 

bool Stack::push(StackDataType newelement)
{
    if (top < STACKSIZE)
    {
        element[top++] = newelement;
        return true;
    }
    return false;
}
StackDataType Stack::pop()
{
    return element[--top];
}
bool Stack::isempty()
{
    return (top == 0);
}
