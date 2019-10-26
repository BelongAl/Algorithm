#include<iostream>
#include<list>

using namespace std;

class Solution {
		struct ListNode {
		int val;
		ListNode *next;
		ListNode(int x) : val(x), next(NULL) {}
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *prev = head;
		ListNode *flow = head;
		int k = n;
		while (n)
		{
			prev = prev->next;
			n--;
		}

		while (prev && prev->next)
		{
			prev = prev->next;
			flow = flow->next;
		}

		if (nullptr == prev)
		{
			head = head->next;
			return head;
		}

		if (k == 1)
		{
			flow->next = nullptr;
		}

		else
		{
			flow->next = flow->next->next;
		}
		return head;
	}
};