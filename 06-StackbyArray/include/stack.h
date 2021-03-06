#pragma once
#define STACKSIZE 5
typedef char StackDataType;
struct Stack
{
    StackDataType element[STACKSIZE];
    int top;

    void create();
    void close();
    bool push(StackDataType);
    StackDataType pop();
    bool isempty();
    void print_stack();
};
