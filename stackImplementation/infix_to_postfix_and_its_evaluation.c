#include <stdio.h>
#include <string.h> // for strlen()
#include <stdlib.h> // for exit()
#include <math.h>   // for pow() for ^ operation

#define MAXSIZE 100

//NOTE THIS CODE WORKS ONLY FOR SINGLE DIGIT OPERANDS

char infix[MAXSIZE];
char postfix[MAXSIZE];

float stack[MAXSIZE]; // declaring stack array as float cuz using it as char will not result decimal values truncation
int top = -1;

int isFull()
{
    return top == MAXSIZE - 1;
}
int isEmpty()
{
    return top == -1;
}
void push(float value)
{
    if (isFull())
    {
        printf("\nStack Overflow\n");
    }
    else
    {
        stack[++top] = value;
    }
}
float pop()
{
    if (isEmpty())
    {
        printf("\nStack Underflow\n");
    }
    else
    {
        return stack[top--];
    }
}

int isDigit(char ch)
{ // to check if character is digit
    return (ch >= '0' && ch <= '9');
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}
/* infix to postfix conversion algorithm:
Scan the symbols of the expression fromleft to right andforeachsymbol, do the following:
1. If symbol is operand
    Print that symbol onto the screen.
2. If symbol is left parenthesis
    Push it on the stack
3. If symbol is right parenthesis
    Pop all operators from the stack upto the first left parenthesis and print themonthescreen. Discard the left and the right parenthesis
4. If symbol is an operator
    If the precedence of the operators in the stack are greater than or equal to thecurrentoperator, then pop the operators out of the stack and print them onto the screen, and pushthecurrent operator onto the stack
Else
    Push the current operator onto the stack
*/
void infix_to_postfix()
{
    int postfix_pointer = 0; // places numbers and operators in postfix expression array
    char current_element, sub_stack_popper;
    for (int i = 0; i < strlen(infix); i++) // this loop traverses the infix expression and places elements in postfix expression
    {
        current_element = infix[i];

        switch (current_element)
        {
        case '(':
            push(current_element);
            break;
        case ')':
            while ((sub_stack_popper = pop()) != '(')
            // here the '(' stored in the stack is popped out so top goes out of the sub-stack but it will never get written to psotfix array cuz  the condition != '(' will never let it enter the while loop when '(' is encountered, this way we discard both parentheses
            {
                postfix[postfix_pointer++] = sub_stack_popper;
            }
            break;
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
            while (!isEmpty() && isOperator(stack[top]) && (precedence(stack[top]) >= precedence(current_element)))
            //this loop pops out all the operators from stack which have precedence greater than or equal to current operator
            //here isOperator(stack[top]) is used to ensure that we don't pop out '(' or any non-operator character from stack
            {
                postfix[postfix_pointer++] = pop();
            }
            push(current_element);
            break;

        default:
            if (isDigit(current_element))
            {
                postfix[postfix_pointer++] = current_element;
            }
            else
            {
                printf("Invalid character in expression: %c\n", current_element);
                exit(-1);
            }
            break;
        }
    }
    while (!isEmpty()) // popping out remaining operators from stack
    {
        postfix[postfix_pointer++] = pop();
    }
    postfix[postfix_pointer] = '\0'; // Null-terminate the postfix string
}

void print_postfix()
{
    printf("Postfix Expression: %s\n", postfix);
}

/* postfix evaluation algorithm:
Scan the symbols of the given postfix expressionfromlefttoright and for each symbol, do the following:
• If symbol is an operand
    • Push it on the stack
• If symbol is an operator
    • Pop two symbols out of the stack and apply the operator on thesesymbols where first popped symbol is thesecond operand and second popped symbol is the first operand
    • Push the result on the stack
At the end of the expression, the stack will contain only one element which is the final result of the expression.
*/

float performOperation(float a, float b, char op)
{
    switch (op)
    {
    case '+':
        return a + b;
        break;
    case '-':
        return a - b;
        break;
    case '*':
        return a * b;
        break;
    case '/':
        if (b == 0)
        {
            printf("Error: Division by zero\n");
            exit(-1);
        }
        return a / b;
        break;
    case '^':
        return pow(a, b);
        break;

    default:
        break;
    }
}

void evaluate_postfix()
{
    // Function to evaluate postfix expression can be implemented here

    for (int i = 0; i < strlen(postfix); i++)
    {

        if (postfix[i] == ' ')
        {
            continue; // to skip the spaces if given in the input string of expression
        }

        else if (isDigit(postfix[i]))
        {
            push((float)(postfix[i] - '0'));
            // convert char to float cuz lets say postfix[i] = '2' , '2' - '0' = 50 - 48 = 2 (ascii values)
        }

        else if (isOperator(postfix[i]))
        {
            //first popped element is the second operand and second popped symbol is the first operand
            float operand2 = pop();
            float operand1 = pop();
            float result = performOperation(operand1, operand2, postfix[i]);
            push(result);
        }
        else
        {
            printf("Invalid character in postfix expression: %c\n", postfix[i]);
            exit(-1);
        }
    }
    float final_result = pop(); // stack is now empty cuz all the operations are done and final result is obtained
    printf("Result of Postfix Evaluation: %.4f\n", final_result);
}

int main()
{

    printf("Enter an infix expression: ");
    gets(infix);

    infix_to_postfix();
    print_postfix();
    evaluate_postfix();

    return 0;
}