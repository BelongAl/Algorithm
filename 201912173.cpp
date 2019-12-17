#include<iostream>

using namespace std;

struct ListNode 
{
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) 
	{}
};

class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (nullptr == pListHead){
			return nullptr;
		}
		ListNode *fast = pListHead;
		ListNode *slow = pListHead;
		while (fast && k > 0){
			fast = fast->next;
			k--;
		}
		if (k != 0){
			return nullptr;
		}
		while (fast != nullptr){
			fast = fast->next;
			slow = slow->next;
		}
		cout << slow->val << endl;
		return slow;
	}
};

int main()
{
	ListNode *p1 = new ListNode(1);
	ListNode *p2 = new ListNode(2);
	ListNode *p3 = new ListNode(3);
	ListNode *p4 = new ListNode(4);
	ListNode *p5 = new ListNode(5);
	ListNode *p6 = new ListNode(6);
	p1->next = p2;
	p2->next = p3;
	p3->next = p4;
	p4->next = p5;
	p5->next = p6;
	Solution s;
	s.FindKthToTail(p1,5);
	system("pause");
	return 0;
}

