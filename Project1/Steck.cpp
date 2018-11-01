#include "Steck.h"
#include<iostream>
using namespace std;


Steck::Steck()
{
	head = NULL;
}

int Steck::Pop()
{
	int temp = head->a;
	ST*ptr_del = head;
	head = head->next;
	delete ptr_del;
	return temp;
}

void Steck::Push(int el)
{
	
	ST*end = new ST;//		|
	end->a = el;//			|-> Данный блок создаёт Узел очереди
	end->next = NULL;//		|
	if (head == NULL)
	{
		head = end;
		head->back = NULL;
	}
	else
	
		while(1)//выполняется всего 1 раз т.к. head->next==NULL всегда!
		{
			if (head->next == NULL)
			{
				head->next = end;// Присваивание Узла
				break;
			}
			ST *temp = head;
			head = head->next;
			head->back = temp;
		}
	while(1)
	{
		if (head->back == NULL)
			break;
		head = head->back;
	}
	
	

}
void Steck::PrintQueue()
{
	ST*print_ptr = head;
	while (print_ptr)
	{
		cout << print_ptr->a << "->";
		print_ptr = print_ptr->next;
	}cout << "NULL";
}
Steck::~Steck()
{
	while (head != NULL)
	{
		ST*ptr = head;
		head = head->next;
		delete ptr;
	}
}
