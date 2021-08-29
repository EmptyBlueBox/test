#include <stdio.h>
#define _CRT_SECURE_NO_WARNINGS

struct queue
{
	int data[1000];
	int head;
	int tail;
};

struct stack
{
	int data[10];
	int top;
};

int main()
{
	struct queue q1, q2;
	struct stack s;
	int i, t;
	int book[10] = { 0 };

	//initializing queues&stacks
	q1.head = 1; q1.tail = 1;
	q2.head = 1; q2.tail = 1;
	s.top = 0;

	//initializing cards for Alice and Bob
	for (i = 1; i <= 6; i++)
	{
		scanf_s("%d", &q1.data[q1.tail]);
		q1.tail++;
	}
	for (i = 1; i <= 6; i++)
	{
		scanf_s("%d", &q2.data[q2.tail]);
		q2.tail++;
	}
	
	while (q1.head < q1.tail && q2.head < q2.tail)
	{
		//Alice
		t = q1.data[q1.head];
		if(book[t] == 0)
		{
			q1.head++;
			s.top++;
			s.data[s.top] = t;
			book[t] = 1;
		}
		else
		{
			q1.head++;
			q1.data[q1.tail] = t;
			q1.tail++;
			while (s.data[s.top] != t)
			{
				book[s.data[s.top]] = 0;
				q1.data[q1.tail]=s.data[s.top];
				q1.tail++;
				s.top--;
				

			}
			book[s.data[s.top]] = 0;
			q1.data[q1.tail] = s.data[s.top];
			q1.tail++;
			s.top--;

		}

		if (q1.head == q1.tail)
			break;

		//Bob
		t = q2.data[q2.head];
		if(book[t] == 0)
		{
			q2.head++;
			s.top++;
			s.data[s.top] = t;
			book[t] = 1;
		}
		else
		{
			q2.head++;
			q2.data[q1.tail] = t;
			q2.tail++;
			while (s.data[s.top] != t)
			{
				book[s.data[s.top]] = 0;
				q2.data[q2.tail] = s.data[s.top];
				q2.tail++;
				s.top--;
				

			}
			book[s.data[s.top]] = 0;
			q2.data[q2.tail] = s.data[s.top];
			q2.tail++;
			s.top--;
			

		}
		if (q2.head == q2.tail)
			break;

	}
	while (q2.head == q2.tail)
	{
		printf("Alice wins\n");
		printf("Alice holds cards of");
		for (i = q1.head; i <= q1.tail - 1; i++)
			printf("%d", s.data[i]);
		if (s.top >= 1)
		{
			printf("\ncards on the table are");
			for (i = 1; i <= s.top; i++)
				printf("%d", s.data[i]);

		}
		else
			printf("\nthere's no cards on the table");

	}
	while (q1.head == q1.tail)
	{
		printf("Bob wins\n");
		printf("Bob holds cards of");
		for (i = q1.head; i <= q1.tail - 1; i++)
			printf("%d", s.data[i]);
		if (s.top >= 1)
		{
			printf("\ncards on the table are");
			for (i = 1; i <= s.top; i++)
				printf("%d", s.data[i]);

		}
		else
			printf("\nthere's no cards on the table");

	}
	getchar(); getchar();
	return 0;


}
