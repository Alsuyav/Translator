#pragma once
#include <iostream>
#include <string>

using namespace std;

class Node
{
private:
	enum {MAX_CHILD = 10};
	string symbol;
	Node* child[MAX_CHILD];
	Node* parent;
	int number_of_child;
	int child_to_process_now;
public:
	Node(string s, Node *p)
	{
		number_of_child = 0;
		child_to_process_now = 0;
		symbol = s;
		parent = p;
		for (int i = 0; i < MAX_CHILD; i++)
		{
			child[i] = NULL;
		}
	}

	Node(string s)
	{
		number_of_child = 0;
		child_to_process_now = 0;
		symbol = s;
		parent = NULL;
		for (int i = 0; i < MAX_CHILD; i++)
		{
			child[i] = NULL;
		}
	}

	Node()
	{
		number_of_child = 0;
		child_to_process_now = 0;
		symbol = "S";
		parent = NULL;
		for (int i = 0; i < MAX_CHILD; i++)
		{
			child[i] = NULL;
		}
	}

	string get_symbol() {return symbol;}

	int get_number_of_child() { return number_of_child; }
	int get_child_to_process_now() { return child_to_process_now; }

	Node* get_parent() { return parent; }

	void add_parent(Node* p) { parent = p; }

	Node* get_child_for_record() {return child[number_of_child]; }

	void add_child(Node* temp)
	{
		child[number_of_child] = temp;
		temp->add_parent(child[number_of_child]);
		number_of_child++;
	}

	void get_all_child(Node* arr[MAX_CHILD])
	{
		for (int i = 0; i < MAX_CHILD; i++)
		{
			arr[i] = child[i];
		}
	}
		
	Node* get_one_child(int num)
	{
		return child[num];
	}
		
	

	void increase_child_to_process_now()
	{
		child_to_process_now++;
	}




















};

