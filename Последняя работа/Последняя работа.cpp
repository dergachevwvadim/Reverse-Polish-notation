//#include <stdafx.h>
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>

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

#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '!' || c == '%' || c == '=')
#define is_ident(c) ((c >= '0' && c <= '9')


char f(char expr_cls[])
{
	int i;
	for (i = 0; i < strlen(expr_cls); i++)
	{
		switch (expr_cls[i]) 
		{
			case '+':
			case '-': 
			case '*': 
			case '/':
			return expr_cls[i];
			break;
			default:
			break;
		}
	}
	return 0;
}
int main()
{
	printf("input size of stack\n");
	scanf_s("%d", &size_stack);
	int* szst = (int*)malloc(size_stack * sizeof(int));
	printf("List of commands \n summ(+);\n sub(-); \n multip(*); \n div(/); \n exp(^);\n exit(E) \n");
	char p;
	int i = 0;
	char line[100];// = "21+=E";
	scanf_s("%s", line, 100); // 2+2
	char line2 = f(line); // 22+=E

	while (1)
	{
		p = line[i];
		i++;
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
	getchar();
	return 0;
}