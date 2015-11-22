/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * removeEveryKthNode(struct node *head, int k) {
	if (head == NULL || k<0) return NULL;
	int count;
	struct node *p1 = head, *p2 = head->next->next;
	if (k == 1 || k == 0) return NULL;
	while (p2 != NULL)
	{
		count = 1;
		while (count < k - 1)
		{
			p1 = p1->next;
			if (p1->next != NULL)
				p2 = p2->next;
			count++;
		}
		p1->next = p2;
		if (p1 != NULL && p1->next != NULL)
		{
			p1 = p1->next;
			p2 = p2->next->next;
		}
	}
	if (k == 2) p1->next = NULL;
	return head;
}