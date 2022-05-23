#include <stdio.h>
#include <malloc.h>
#include <math.h>

int size_stack;
int sp = 0;
bool FLAG = 0;
int pop(int* stack)

{
	if (sp > 0)
	{
		return stack[--sp];
	}
	else
	{
		//	fprintf(stderr, "Error POP\n");
		//	return 0;
	}
}
void push(int* stack, int a)
{
	stack[sp++] = a;
}
int empty()
{
	return (sp == 0);
}

int main()
{
	printf("input size of stack\n");
	scanf_s("%d", &size_stack);
	int* szst = (int*)malloc(size_stack * sizeof(int));
	int i;
	printf("List of commands \n summ(+);\n sub(-); \n multip(*); \n div(/); \n exp(^);\n exit(E) \n");
	char p;
	while (1)
	{
		p = getchar();
		if (p == 'E')
		{
			printf("Exit\n");
			break;
		}
		if (p >= 48 && p <= 57)
		{
			push(szst, p - 48);
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
			push(szst, pop(szst) + pop(szst));
			break;
		}
		case '-':
		{
			push(szst, -pop(szst) + pop(szst));
			break;
		}
		case '*':
		{
			push(szst, pop(szst) * pop(szst));
			break;
		}
		case '/':
		{
			push(szst, pop(szst) / pop(szst));
			break;
		}
		case '=':
		{
			printf("Result = %d\n", pop(szst));
			break;
		}


		if (FLAG)
			break;

		
		default:
		{
			if (p >= 48 && p <= 57)
				continue;
			else
				printf("Error\n");
		}
		}

		if (FLAG)
		{
			free(szst);
			break;
		}
	}
}