#pragma once
struct ST
{

	int a;
	ST *next;
	ST *back;
};

class Steck
{
private:
	
	ST * head;
public:
	Steck();
	int Pop();
	void PrintQueue();
	void Push(int);
	~Steck();
};

