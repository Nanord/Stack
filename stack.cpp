#include <stdio.h>
#include <conio.h>

struct stack
{
	float x;
	struct stack *next;
};

struct list
{
	struct stack* head;
	struct stack* tail;	
};

struct list create_list(int b);

stack* create_stack(struct list lst);

void delete_element(struct list *lst);

void print_list(struct list lst, struct stack* s);

void clear_list(struct list lst);

void clear_stack(struct stack* s);

int main(int argc, char const *argv[])
{
	struct list lst = {NULL, NULL};
	struct stack *s = NULL;
	int a, b;
	do
	{
		printf("\n1 - создать список\n2 - вывести список\n3 - Выход\n");
		scanf("%d", &a);
		switch (a)
		{
			case 1:
			{ 
				printf("\nВведите кол-во символов:\n");
				scanf("%d", &b);
				printf("\nВведите последовательность вещественных чисел:\n");
				lst = create_list(b);
				s = create_stack(lst); 
				delete_element(&lst);
			}
			break;
			case 2: print_list(lst, s); break;
		}	
	}
	while (a != 3);
	clear_list(lst);
	clear_stack(s);
	return 0;
}

list create_list(int b)
{
	float n;
	struct stack *temp = NULL, *last;
	struct list lst = {NULL, NULL};
	getchar();
	while(b > 0)
	{
		temp = lst.head;
		scanf("%f", &n);
		last = new struct stack;
		last->next = NULL;
		last->x = n;
		if(lst.tail != NULL)
		{
			lst.tail->next = last;
			lst.tail = last;
		}
		if(lst.head == NULL)
		{
			lst.head = last;
			lst.tail = last;
		}
		b--;
	}
	return lst;
}

stack* create_stack(struct list lst)
{
	stack *temp = lst.head, *head = NULL, *tmp;
	while(temp != NULL)
	{
		if (temp->x < 0)
		{
			tmp = head;
			head = new struct stack;
			head->x = temp->x;
			head->next = tmp;
		}
		temp = temp->next;
	}
	return head;
}

void delete_element(struct list *lst)
{
	struct stack *temp = lst->head, *d_temp = NULL, *cur;
	while(temp != NULL)
	{
		cur = temp->next;
		if(temp->x < 0)
		{
			if(lst->head == temp)
			{
				if(lst->head == lst->tail)
				{
					lst->tail = NULL;
				}
				lst->head = cur;
				delete temp;
				temp = cur;
			}
			else
			{
				d_temp->next = temp->next;
				delete temp;
				temp = d_temp;
			}
		}
		d_temp = temp;
		temp = cur;
	}
}

void print_list(struct list lst, struct stack *cur2)
{
	struct stack *temp = lst.head;
	printf("Динамический список:\n");
	while(temp != NULL)
	{
		printf("%f\t", temp->x);
		temp = temp->next;
	}
	printf("\n\nСтек:\n");
	while(cur2 != NULL)
	{
		printf("%f\t", cur2->x);
		cur2 = cur2->next;
	}
}

void clear_list(struct list lst)
{
	struct stack *temp = lst.head, *del;
	while(temp != NULL)
	{
		del = temp;
		temp = temp->next;
		delete del;
	}
}

void clear_stack(struct stack *head)
{
	struct stack *temp;
	while(head != NULL)
	{
		temp = head;
		head = head->next;
		delete temp;
	}
}