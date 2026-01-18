#include <stdio.h>
#include <string.h> // for strlen()
#include <stdlib.h> // for exit()
#include <math.h>   // for pow() for ^ operation

#define MAXSIZE 100

//NOTE THIS CODE WORKS ONLY FOR SINGLE DIGIT OPERANDS

char infix[MAXSIZE];
char prefix[MAXSIZE];

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

int isRightAssociative(char ch)
{
    return (ch == '^');
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

/* infix to prefix conversion algorithm:
    1. Reverse the infix expression(in code we will traverse it from right to left)
    2. Swap '(' with ')' and vice-versa
    3. Convert the modified expression to postfix
        During postfix conversion:
            -> Pop operators from the stack if they have higher precedence, OR if they have equal precedence and the new operator is right-associative (^). 
            -> Left-associative operators (+, -, *, /) do not cause a pop.
            -> Push the new operator onto the stack. For parentheses (when scanning right to left), push ')' onto the stack, and when '(' is encountered, pop operators until a ')' is found.
    4. Reverse the postfix expression to get prefix(using reversing logic)
*/



void infix_to_prefix()
{
    // Function to convert infix to prefix can be implemented here
    char current_element, sub_stack_popper;
    int prefix_pointer = 0; // places numbers and operators in prefix expression array
    int infix_length = strlen(infix);
    for (int i = infix_length-1; i >= 0; i--)
    {
        current_element = infix[i];

        if (current_element == ' ')
        {
            continue; // to skip the spaces if given in the input string of expression
        }
        else if(current_element == ')'){
            push(current_element);
        }
        else if(current_element == '('){
            while ((sub_stack_popper = pop()) != ')')
            // here the ')' stored in the stack is popped out so top goes out of the sub-stack but it will never get written to prefix array cuz  the condition != ')' will never let it enter the while loop when ')' is encountered, this way we discard both parentheses
            //this will make sub stack seem empty by placing top out of the sub stack, and the parenthesis remained in the stack will be overwritten by next operators pushed in stack
            {
                prefix[prefix_pointer++] = sub_stack_popper;
            }
        }
        else if(isOperator(current_element)){
            while (!isEmpty() && isOperator(stack[top]) && 
                   ( (precedence(stack[top]) > precedence(current_element)) || ( (precedence(stack[top]) == precedence(current_element)) && isRightAssociative(current_element) ) )
                )
                //this loop pops out all the operators from stack which have precedence greater than current operator
                //or if they have equal precedence and the current operator is right-associative (^)
                //here isOperator(stack[top]) is used to ensure that we don't pop out ')' or any non-operator character from stack
            {
                prefix[prefix_pointer++] = pop();
            }
            push(current_element);
        }
        else if(isDigit(current_element)){
            prefix[prefix_pointer++] = current_element;
        }
        else{
            printf("Error: Invalid character in expression\n");
            exit(-1);
        }
    }
    while (!isEmpty())
    {
        prefix[prefix_pointer++] = pop();
    }
    prefix[prefix_pointer] = '\0'; // Null-terminate the prefix string

    //Now since we traversed the infix from right to left using postfix algorithm, the prefix array is in reverse order, so we need to reverse it to get the final prefix expression

    // Reversing the prefix array

    for (int i = 0; i < prefix_pointer / 2; i++)
    {
        char temp = prefix[i];
        prefix[i] = prefix[prefix_pointer-i-1]; 
        prefix[prefix_pointer-i-1] = temp;
        // prefix_pointer-1 cuz its index, cuz prefix pointer is 1 index more than the index of last element cuz last index of array is '\0
        //and again subtracting i to prefix_pointer-1 i.e. prefix_pointer-i-1 to get the correct index from the end
        // lets say prefix array in reverse order is 53*2+ which we need to reverse to get the final prefix expn: +2*35 so we swap 0th index with 5th index, 1st index with 4th index and 2nd index with 3rd index(if the no. of terms is odd middle element remains same) so in total it takes int(prefix_pointer/2) swaps to reverse the array
    }
    
}

void print_prefix()
{
    printf("Prefix Expression: %s\n", prefix);
}


/* prefix evaluation algorithm:
Scan the symbols of the given prefix expression from right to left and for each symbol, do the following:
• If symbol is an operand
    • Push it on the stack
• If symbol is an operator
    • Pop two symbols out of the stack and apply the operator on these symbols where first popped symbol is the first operand and second popped symbol is the second operand
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

void evaluate_prefix()
{
    // Function to evaluate prefix expression can be implemented here

    for (int i = strlen(prefix) - 1; i >= 0; i--)
    {

        if (prefix[i] == ' ')
        {
            continue; // to skip the spaces if given in the input string of expression
        }

        else if (isDigit(prefix[i]))
        {
            push((float)(prefix[i] - '0'));
            // convert char to float cuz lets say prefix[i] = '2' , '2' - '0' = 50 - 48 = 2 (ascii values)
        }

        else if (isOperator(prefix[i]))
        {
            //first popped symbol is the first operand and second popped symbol is the second operand
            float operand1 = pop();
            float operand2 = pop();
            float result = performOperation(operand1, operand2, prefix[i]);
            push(result);
        }
        else
        {
            printf("Invalid character in prefix expression: %c\n", prefix[i]);
            exit(-1);
        }
    }
    float final_result = pop(); // stack is now empty cuz all the operations are done and final result is obtained
    printf("Result of Prefix Evaluation: %.4f\n", final_result);
}

int main(){
    printf("Enter an infix expression: ");
    gets(infix);

    infix_to_prefix();
    print_prefix();
    evaluate_prefix();

    return 0;
}
