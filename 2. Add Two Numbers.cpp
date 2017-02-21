/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int remain = 0;
		ListNode *l3 = new ListNode(addSingleDigit((*l1).val, (*l2).val, &remain));
		ListNode *tail = l3;

		if (getListLength(l1)>getListLength(l2))
		{
			while (l2->next != NULL)
			{
				l1 = l1->next;
				l2 = l2->next;
				tail->next = new ListNode(addSingleDigit((*l1).val, (*l2).val, &remain));
				tail = tail->next;
			}
			while (l1->next != NULL)
			{
				l1 = l1->next;
				tail->next = new ListNode(addSingleDigit((*l1).val, 0, &remain));
				tail = tail->next;
			}
			if (remain == 1)
			{
				tail->next = new ListNode(1);
				tail = tail->next;
			}

		}
		else
		{
			while (l1->next != NULL)
			{
				l1 = l1->next;
				l2 = l2->next;
				tail->next = new ListNode(addSingleDigit((*l1).val, (*l2).val, &remain));
				tail = tail->next;
			}
			while (l2->next != NULL)
			{
				l2 = l2->next;
				tail->next = new ListNode(addSingleDigit((*l2).val, 0, &remain));
				tail = tail->next;
			}
			if (remain == 1)
			{
				tail->next = new ListNode(1);
				tail = tail->next;
			}
		}

		return l3;
	}
	int getListLength(ListNode* l)
	{
		int length = 1;
		ListNode* tail = l;
		while (tail->next != NULL)
		{
			length++;
			tail = tail->next;
		}
		return length;
	}
	int addSingleDigit(int a, int b, int* remain)
	{
		int sum = a + b + (*remain);

		if (sum>9)
		{
			*remain = 1;
			return sum - 10;
		}

		else
		{
			*remain = 0;
			return sum;
		}

	}
};