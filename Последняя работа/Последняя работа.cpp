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
}

char pop(char* stack)
{
	if (sp > 0)
	{
		return stack[--sp];
	}
}

void push(char* stack, char a)
{
	stack[sp++] = a;
}

void push(int* stack, int a)
{
	stack[sp++] = a;
}
int empty()
{
	return (sp == 0);
}

#define is_operator(c) (c == '+' || c == '-' || c == '/' || c == '*' || c == '=')
#define is_ident(c) ((c >= '0' && c <= '9'))

char* f(char expr_cls[], char str[])
{
	int i, iter = 0, iter_stack = 0;
	char* stack = (char*)malloc(10 * sizeof(char));
	for (i = 0; i < strlen(expr_cls); i++)
	{
		if (is_ident(expr_cls[i]))
		{
			str[iter] = expr_cls[i];
			iter++;
		}
		if (is_operator(expr_cls[i]) == 1)
		{
			push(stack, expr_cls[i]);
			iter_stack++;
		}
	}
	for (i = 0; i < iter_stack; i++) {
		str[iter] = pop(stack);
	}
	str[iter + 1] = '=';
	str[iter + 2] = 'E';
	return str;
}
int main()
{
	printf("input size of stack\n");
	size_stack = 100;
	int* szst = (int*)malloc(size_stack * sizeof(int));
	printf("List of commands \n summ(+);\n sub(-); \n multip(*); \n div(/); \n exp(^);\n exit(E) \n");
	char p;
	int i = 0;
	char line[100];// = "21+=E";
	scanf_s("%s", line, 100); // 2+2
	char* line2 = (char*)malloc(10);
	f(line, line2);

	int x;
	while (1)
	{
		p = *(line2 + i);
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
