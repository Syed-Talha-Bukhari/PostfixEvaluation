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

//This function assigns precedence to operators
int precedence(char character)
{
    if (character == '+' || character == '-')
        return 1;
    else if (character == '*' || character == '/')
        return 2;
    else if (character == '^')
        return 3;
    else //Not any of these operator
        return -1;
}

//This function checks if character is an operator
bool isOperator(char character)
{
    if (character == '+' || character == '-' || character == '*' || character == '/' || character == '^')
    {
        return true;
    }
    else
    {
        return false;
    }
}

//This function checks the ending brackets
bool endingBraces(char element)
{
    if (element == ')')
        return true;
    return false;
}
//This function checks the starting brackets
bool openingBraces(char element)
{
    if (element == '(')
        return true;
    return false;
}
//This function checks if infix is valid
bool isValid(string infix)
{
    for (int i = 0; i < infix.length(); i++)
    {
        if (isdigit(infix.at(i)))
        { //if character is a digit
            continue;
        }
        else if (isOperator(infix.at(i)))
        { //if character is an operator
            continue;
        }
        else if (endingBraces(infix.at(i)))
        { //if character is closing brace
            continue;
        }
        else if (openingBraces(infix.at(i)))
        { //if character is opening brace
            continue;
        }
        else
        { //For invalid character
            return false;
        }
    }
    return true;
}
//Function checks if brackets pair are matching
bool checkBrackets(string infix, charStack stackObj)
{
    int element = 0;
    bool valid = true; //set valid to true
    char checkBracket;
    while (element < infix.length()) //check for whole stack
    {

        if (openingBraces(infix[element])) //if opening bracket found push in stack
        {
            stackObj.push(infix[element]);
        }
        else if (endingBraces(infix[element])) //if closing bracket found push in stack
        {
            //pop is matching pair formed
            checkBracket = stackObj.pop();
            if (infix[element] == ')' && checkBracket == '(')
            {
                element++;
                continue;
            }

            else
            {
                valid = false; //set valid to false
                break;
            }
        }
        element++; //go to next element
    }

    if (valid == true && !stackObj.isEmpty()) //if stack empty bracket not found
    {
        valid = false; //valid false
    }

    if (valid) //if valid true
        return true;
    else //if invalid expression
        return false;
}

//Function converts infix to postfix expression
string infixToPostfix(charStack stack, string infix)
{
    string postfix;
    for (int element = 0; element < infix.length(); element++)
    {
        if ((infix[element] >= '0' && infix[element] <= '9')) //if character is a number
        {
            postfix += infix[element];
        }
        else if (infix[element] == '(') //if character is opening brace
        {
            stack.push(infix[element]);
        }
        else if (infix[element] == ')') //if character is closing brace
        {
            while ((stack.peak() != '(') && (!stack.isEmpty())) //pop all operators inside braces
            {
                postfix += " "; //insert space
                postfix += stack.peak();
                stack.pop(); 
            }
            stack.pop(); //pop opening brace
        }
        else if (isOperator(infix[element])) //if character is operator
        {
            if (stack.isEmpty()) //if stack empty push operator
            {
                postfix += " ";
                stack.push(infix[element]);
            }
            else //if stack not empty
            {
                if (precedence(infix[element]) > precedence(stack.peak())) //if precedence of operator more than peak
                {
                    postfix += " ";
                    stack.push(infix[element]);
                }
                else if (precedence(infix[element]) == precedence(stack.peak()) && stack.peak() == '^') //if precedence of operator equal to peak and it is ^
                {
                    postfix += " ";
                    stack.push(infix[element]);
                }
                else
                {
                    while (precedence(infix[element]) <= precedence(stack.peak()) && !stack.isEmpty()) //until precedence of operator less than or equal to peak pop it out
                    {
                        postfix += " ";
                        postfix += stack.peak();

                        stack.pop();
                    }
                    postfix += " ";
                    stack.push(infix[element]);
                }
            }
        }
    }
    while (!stack.isEmpty()) //pop operators until stack empty
    {
        postfix += " ";
        postfix += stack.peak();
        stack.pop();
    }
    return postfix;
}

//This function returns length of postfix expression
int arrayLength(string postfix)
{
    int arraySize = 0;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix[i] == ' ')
        {
            arraySize++;
        }
    }
    return arraySize + 1; //length is one more than number of spaces
}

//Function evaluates the postfix expression
int EvaluatePostfix(intStack stack, string postfix, int arraySize)
{
    string arr[arraySize]; //declare array
    string result = "";
    int index = 0;
    for (int i = 0; i < postfix.length(); i++)
    {
        if (postfix.at(i) == ' ') //if space is found increment index
        {
            index += 1;
        }
        else
        {
            arr[index] += postfix.at(i); //add element to array if not space
        }
    }

    for (int element = 0; element < arraySize; element++)
    {

        if (isOperator(arr[element].at(0)))  //Check operators
        {
            int operand2 = stack.pop(); //Pop the numbers
            int operand1 = stack.pop();
            if (arr[element] == "+")
            {
                stack.push(operand1 + operand2);
            }
            else if (arr[element] == "-") 
            {
                stack.push(operand1 - operand2);
            }
            else if (arr[element] == "*")
            {
                stack.push(operand1 * operand2);
            }
            else if (arr[element] == "/")
            {
                stack.push(operand1 / operand2);
            }
            else if (arr[element] == "^")
                stack.push(pow(operand1, operand2));
        }
        else //If operands
        {
            stack.push(stoi(arr[element])); //Convert to stack after conversion to int
        }
    }

    return stack.peak(); //Peak has evaluated value
}

//main method
int main()
{
    string infix, postfix;
    charStack stackChar;//Stack objects
    intStack stackInt;
    cout << "Enter infix expression: " << endl;
    cin >> infix;
    bool validity = checkBrackets(infix, stackChar) && isValid(infix); //Check infix validity
    if (!validity) //if infix invalid
    {
        cout << "Invalid expression" << endl;
    }
    else //if infix valid
    {
        postfix = infixToPostfix(stackChar, infix); //convert to postfix
        cout << "Postfix expression is: " << postfix << endl;
        int arraySize = arrayLength(postfix); //Get array size
        cout << "After evaluation of expression the result is: " << EvaluatePostfix(stackInt, postfix, arraySize) << endl; //Evaluate postfix
    }
    return 0;
}