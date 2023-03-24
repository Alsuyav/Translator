#include "SynAnalyzer.h"
#include "Node.h"

Node* now;

int SynAnalyzer::iter_check()
{
	if (num_word != count_words - 1)
	{
		num_word++;
		return 0;
	}
	else 
		throw AnError(num_word);
}

void SynAnalyzer::S()
{
	// ���� ��� �����
	if (words[num_word].type == 1)
	{
		Node* temp1 = new Node(words[num_word].elem);
		now->add_child(temp1); // ������ ������� ����
		temp1->add_parent(now);
		now = temp1->get_parent(); // ��������� ������
		num_word++;
	}
	// ���� ��� �� �����
	else
	{
		// ���� ��� (
		if (words[num_word].type == 3)
		{
			Node* temp2 = new Node(words[num_word].elem);
			now->add_child(temp2); // ������ ������� ����
			temp2->add_parent(now);
			iter_check();
			// ���� ��� (
			if (words[num_word].type == 3)
			{
				Node* temp3 = new Node(words[num_word].elem);
				now->add_child(temp3); // ������ ������� ����
				temp3->add_parent(now);
				iter_check();
				A();
			}
			else
			{
				throw AnError(num_word);
			}
			// ���� ��� )
			if (words[num_word].type == 4)
			{
				if (now)
				{
					Node* temp4 = new Node(words[num_word].elem);
					now->add_child(temp4); // ������ ������� ����
					temp4->add_parent(now);
				}
				iter_check();
				// ���� ��� [
				if (words[num_word].type == 5)
				{
					if (now)
					{
						Node* temp5 = new Node(words[num_word].elem);
						now->add_child(temp5); // ������ ������� ����
						temp5->add_parent(now);
					}
					iter_check();
					B();
				}
				else
				{
					throw AnError(num_word);
				}
			}
			else
			{
				throw AnError(num_word);
			}
			// ���� ��� ]
			if (words[num_word].type == 6)
			{
				Node* temp6 = new Node(words[num_word].elem);
				now->add_child(temp6); // ������ ������� ����
				temp6->add_parent(now);
				iter_check();
				// ���� ��� )
				if (words[num_word].type == 4)
				{
					Node* temp7 = new Node(words[num_word].elem);
					if(now)
					{
						now->add_child(temp7); // ������ ������� ����
						temp7->add_parent(now);
						now = temp6->get_parent(); // ��������� ������
					}
					num_word++;
				}
				else
				{
					throw AnError(num_word);
				}
			}
			else
			{
				throw AnError(num_word);
			}
		}
		else
		{
			B();
		}
	}
}

void SynAnalyzer::A()
{
	Node* temp8 = new Node("A");
	now->add_child(temp8); // ������ ������� ����
	temp8->add_parent(now);
	now = temp8; // ���������� ����
	
	// ���� ��� �����
	if (words[num_word].type == 1)
	{
		Node* temp9 = new Node(words[num_word].elem);
		now->add_child(temp9); // ������ ������� ����
		temp9->add_parent(now);
		now = temp8->get_parent(); // ��������� ������
		num_word++;
		if (num_word == count_words)
		{
			num_word--;
		}
	}
	// ���� ��� �� �����
	else
	{
		// ���� ��� (
		if (words[num_word].type == 3)
		{
			if (now)
			{
				Node* temp10 = new Node(words[num_word].elem);
				now->add_child(temp10); // ������ ������� ����
				temp10->add_parent(now);
			}
			iter_check();
			// ���� ��� (
			if (words[num_word].type == 3)
			{
				Node* temp11 = new Node(words[num_word].elem);
				now->add_child(temp11); // ������ ������� ����
				temp11->add_parent(now);
				iter_check();
				A();
			}
			else
			{
				throw AnError(num_word);
			}
			// ���� ��� )
			if (words[num_word].type == 4)
			{
				Node* temp12 = new Node(words[num_word].elem);
				now->add_child(temp12); // ������ ������� ����
				temp12->add_parent(now);
				iter_check();
				// ���� ��� [
				if (words[num_word].type == 5)
				{
					Node* temp13 = new Node(words[num_word].elem);
					now->add_child(temp13); // ������ ������� ����
					temp13->add_parent(now);
					iter_check();
					B();
				}
				else
				{
					throw AnError(num_word);
				}
			}
			else
			{
				throw AnError(num_word);
			}
			// ���� ��� ]
			if (words[num_word].type == 6)
			{
				Node* temp14 = new Node(words[num_word].elem);
				now->add_child(temp14); // ������ ������� ����
				temp14->add_parent(now);
				iter_check();
				// ���� ��� )
				if (words[num_word].type == 4)
				{
					Node* temp15 = new Node(words[num_word].elem);
					now->add_child(temp15); // ������ ������� ����
					temp15->add_parent(now);
					now = (temp14->get_parent())->get_parent(); // ��������� ������
					num_word++;
				}
				else
				{
					throw AnError(num_word);
				}
			}
			else
			{
				throw AnError(num_word);
			}
		}
		else
		{
			throw AnError(num_word);
		}
	}
}

void SynAnalyzer::B()
{
	Node* temp16 = new Node("B");
	now->add_child(temp16); // ������ ������� ����
	temp16->add_parent(now);
	now = temp16; // ���������� ����
	// ���� ��� �������������
	if (words[num_word].type == 2)
	{
		Node* temp17 = new Node(words[num_word].elem);
		now->add_child(temp17); // ������ ������� ����
		temp17->add_parent(now);
		now = temp16->get_parent(); // ��������� ������
		num_word++;
		if ((num_word == 0) && num_word == count_words)
		{
			num_word--;
		}
	}
	// ���� ��� �� �������������
	else
	{
		// ���� ��� [
		if (words[num_word].type == 5)
		{
			Node* temp18 = new Node(words[num_word].elem);
			now->add_child(temp18); // ������ ������� ����
			temp18->add_parent(now);
			iter_check();
			// ���� ��� [
			if (words[num_word].type == 5)
			{
				Node* temp19 = new Node(words[num_word].elem);
				now->add_child(temp19); // ������ ������� ����
				temp19->add_parent(now);
				iter_check();
				B();
			}
			else
			{
				throw AnError(num_word);
			}
			// ���� ��� ]
			if (words[num_word].type == 6)
			{
				Node* temp20 = new Node(words[num_word].elem);
				now->add_child(temp20); // ������ ������� ����
				temp20->add_parent(now);
				iter_check();
				// ���� ��� (
				if (words[num_word].type == 3)
				{
					Node* temp21 = new Node(words[num_word].elem);
					now->add_child(temp21); // ������ ������� ����
					temp21->add_parent(now);
					iter_check();
					A();
				}
				else
				{
					throw AnError(num_word);
				}
			}
			else
			{
				throw AnError(num_word);
			}
			// ���� ��� )
			if (words[num_word].type == 4)
			{
				Node* temp22 = new Node(words[num_word].elem);
				now->add_child(temp22); // ������ ������� ����
				temp22->add_parent(now);
				iter_check();
				// ���� ��� ]
				if (words[num_word].type == 6)
				{
					Node* temp23 = new Node(words[num_word].elem);
					now->add_child(temp23); // ������ ������� ����
					temp23->add_parent(now);
					now = (temp22->get_parent())->get_parent(); // ��������� ������
					num_word++;
				}
				else
				{
					throw AnError(num_word);
				}
			}
			else
			{
				throw AnError(num_word);
			}
		}
		else
		{
			throw AnError(num_word);
		}
	}
}

// ��� ������
int SynAnalyzer::SyntAnaliz()
{
	now = root;
	S();
	if (num_word != count_words)
		throw AnError(num_word);
	return 1;
}

// ����������� �-��� ��� ��������� ������
int SynAnalyzer::for_go_tree(Node* r, string& m)
{
	now = r; // ��������� �� ���������
	m = m + now->get_symbol(); // ���������
	int i = 0;
	while (i < 8)
	{
		if (now->get_one_child(i))
		{
			for_go_tree(now->get_one_child(i/*now->get_child_to_process_now()*/), m);
		}
		i++;
	}

	if (!(now->get_parent()))
	{
		return 0;
	}
	now = now->get_parent();
}

// ��������� ������
string SynAnalyzer::go_tree()
{
	string mess = "";
	for_go_tree(root, mess);
	return mess;
}