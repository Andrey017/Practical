#include <stdio.h>
#include <stdlib.h>

int *stack;
int sp = 0;


int pop(void){
    if (sp > 0){
        return stack[--sp];
    }
    else {
        printf("-1");
        return 0;
    }
}


void push(int a){
    stack[sp++] = a;
}


int main(int argc, char *argv[])
{
    int k, i;
    k = argc;

    stack =(int *) malloc ( sizeof(int) * k );
    if ( stack == NULL ) exit (1);

    for( i = 1; i < k; i++ )
    {
        switch ( (int) argv[i][0] ){
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
        case '*':
            push(pop() * pop());
            break;
        default:
            push( atoi(argv[i]));
            break;
        }
    }
    return 0;
}
