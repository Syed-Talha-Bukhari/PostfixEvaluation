#include <iostream>
#include <string>
#include <math.h>
using namespace std;

//Character stack
class charStack
{
private:
    char *array = new char[size]; //stack of length 20
public:
    int top = -1;  //top at -1
    int size = 20; //size is 10
    //To check if stack is empty
    bool isEmpty()
    {
        return top < 0; //top at -1
    }
    //To check if stack is full
    bool isFull()
    {
        return top == size - 1;
    }

    //push element in stack
    void push(char element)
    {
        if (!isFull()) //if not full
        {
            array[++top] = element; //increment top and push
        }
        else //stack full
        {
            cout << "Stack overflow" << endl;
        }
    }
    //pop element from stack
    char pop()
    {
        if (!isEmpty()) //if not empty
        {
            char popElement = array[top--]; //return element and decrement top
            return popElement;
        }
        else
        {
            cout << "Stack is empty" << endl; //if stack empty
            return ' ';
        }
    }

    char peak() //gives peak or top of stack
    {
        if (!isEmpty())
        {
            return array[top];
        }
        else
        {
            return ' '; //stack empty
        }
    }
};

//Integer stack 
class intStack
{
private:
    int *array = new int[size]; //stack of length 20
public:
    int top = -1;  //top at -1
    int size = 20; //size is 10
    //To check if stack is empty
    bool isEmpty()
    {
        return top < 0; //top at -1
    }
    //To check if stack is full
    bool isFull()
    {
        return top == size - 1;
    }

    //push element in stack
    void push(int element)
    {
        if (!isFull()) //if not full
        {
            array[++top] = element; //increment top and push
        }
        else //stack full
        {
            cout << "Stack overflow" << endl;
        }
    }
    //pop element from stack
    int pop()
    {
        if (!isEmpty()) //if not empty
        {
            char popElement = array[top--]; //return element and decrement top
            return popElement;
        }
        else
        {
            cout << "Stack is empty" << endl; //if stack empty
            return -1;
        }
    }

    int peak() //gives peak or top of stack
    {
        if (!isEmpty())
        {
            return array[top];
        }
        else
        {
            return -1; //stack empty
        }
    }
};
