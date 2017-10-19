#include <stdio.h>
#include <stdlib.h>

int *stack; /*Create a stack*/
int sp = 0;


int pop(void){  /*Remove the element from the top of the stack by moving the vertex to the next element*/
    if (sp > 0){
        return stack[--sp];
    }
    else {
        printf("-1");
        return 0;
    }
}


void push(int a){   /*Put the element on top of the stack*/
    stack[sp++] = a;
}


int main(int argc, char *argv[])
{
    int k, i;
    k = argc;

    stack =(int *) malloc ( sizeof(int) * k );  /*Selecting memory*/
    if ( stack == NULL ) exit (1);

    for( i = 1; i < k; i++ )
    {
        switch ( (char) argv[i][0] ){   /*Collating operation type*/
        case '\n':
            break;
        case '=':
            printf("\nResult = %d\n", pop());
            break;
        case '+':
            push(pop() + pop());
            break;
        case '-':
            push(-pop() + pop());
            break;
        case 'x':
            push(pop() * pop());
            break;
        case '/':
            push(pop() / pop());
            break;
        default:
            push( atoi(argv[i]));
            break;
        }
    }
    return 0;
}
