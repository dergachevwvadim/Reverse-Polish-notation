#include <stdio.h>
#include <malloc.h>

int sp = 0;
double stack[100];
int pop(void)
{
    if (sp > 0) 
    {
        return stack[--sp];
    }
    else 
    {
        fprintf(stderr, "Error POP\n");
        return 0;
    }
}
void push(int a) 
{
    stack[sp++] = a;
}
int empty() 
{
    return (sp == 0);
}

int main() 
{


    int i;
    printf("List of commands \n summ(+);\n sub(-); \n multip(*); \n div(/); \n exp(^);\n sqrt(s);\n exit(E) \n");
    char p;
    while (1)
    {
        p = getchar();
        if (p == 'E')
        {
            printf("Exit\n");
            break;
        }
        int x;
        switch (p)
        {
        case '\n':
        {

        }
        case ' ':
        {
            break;
        }
        case '+':
        {
            push(pop() + pop());
            break;
        }
        case '-':
        {
            push(-pop() + pop());
            break;
        }
        case '*':
        {
            push(pop() * pop());
            break;
        }
        case '/':
        {
            push(pop() / pop());
            break;
        }
        case '=':
        {
            printf("Result = %d\n", pop());
            break;
        }
        case 9:
        {
            goto RESULT;
        }
        default:
        {
        }

        }
}
RESULT:
    i = 0;
    while (!empty())
    {
        printf("Stack[%d] = %d\n", i, pop());
        i++;
    }
    return 0;
}