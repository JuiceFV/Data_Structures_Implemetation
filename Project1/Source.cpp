#include<iostream>
#include<conio.h>
#include"Steck.h"
using namespace std;
int main()
{
	Steck el1;
	el1.Push(0);
	for (int i(1); i < 5; i++)
	{
		el1.Push(i);
	}
	el1.PrintQueue();
	cout << endl;
	for (int i(0); i < 5; i++)
	{
		cout<<el1.Pop()<<endl;
	}
	_getch();
	return 0;
}