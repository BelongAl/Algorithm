#include<iostream>

using namespace std;

struct list_node {
	int val;
	struct list_node * next;

	list_node(int data):
		val(data),
		next(nullptr)
	{}
};

list_node * reverse_list(list_node * head, int L, int R)
{
	//////在下面完成代码
	int i = 1;
	list_node *a = nullptr;
	list_node *b = nullptr;
	list_node *c = head;
	while (true && c)
	{
		if (i == L)
		{
			list_node *LNode = b;
			list_node *LNode1 = c;
			a = nullptr;
			b = nullptr;
			for (i = L; i <= R; i++)
			{
				if (nullptr == c)
				{
					return nullptr;
				}
				a = b;
				b = c;
				c = c->next;
				b->next = a;
			}
			if (nullptr == c)
			{
				if (nullptr != LNode)
				{
					LNode->next = b;
					return head;
				}
				else
				{
					return b;
				}
			}
			else
			{
				if (nullptr == LNode)
				{
					LNode1->next = c;
					return b;
				}
				LNode->next = b;
				LNode1->next = c;
				return head;
			}
		}
		a = b;
		b = c;
		c = c->next;
		i++;
	}
	return nullptr;
}


int main()
{
	list_node *l1 = new list_node(1);
	list_node *l2 = new list_node(2);
	list_node *l3 = new list_node(3);
	list_node *l4 = new list_node(4);
	list_node *l5 = new list_node(5);
	list_node *l6 = new list_node(6);
	list_node *l7 = new list_node(7);
	list_node *l8 = new list_node(8);
	l1->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	l5->next = l6;
	l6->next = l7;
	l7->next = l8;
	l1 = reverse_list(l1, 1, 8);

	return 0;

}