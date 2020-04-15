
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
		//查找换的长度
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
		//寻找入环节点
		pre = pHead;
		while (pre != cur)
		{
			pre = pre->next;
			cur = cur->next;
		}
		return pre;
	}
};