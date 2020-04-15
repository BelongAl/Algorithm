
struct ListNode
{
	ListNode *next;
};

class Solution {
public:
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		ListNode *cur = pHead->next;
		if (cur == nullptr)
		{
			return nullptr;
		}
		ListNode *pre = cur->next;
		if (pre == nullptr)
		{
			return nullptr;
		}
		//���һ��ĳ���
		while (pre != cur)
		{
			pre = pre->next;
			if (pre == nullptr)
			{
				return nullptr;
			}
			pre = pre->next;
			cur = cur->next;
		}
		//Ѱ���뻷�ڵ�
		pre = pHead;
		while (pre != cur)
		{
			pre = pre->next;
			cur = cur->next;
		}
		return pre;
	}
};