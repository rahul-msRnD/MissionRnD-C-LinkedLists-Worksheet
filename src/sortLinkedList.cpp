/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

/* function to swap data of two nodes a and b*/
void swap(struct node *a, struct node *b)
{
	int temp = a->num;
	a->num = b->num;
	b->num = temp;
}

struct node * sortLinkedList(struct node *head) {
	if(!head) return NULL;
	int swapped, i;
	struct node *p1;
	struct node *lp = NULL;
	do
	{
		swapped = 0;
		p1 = head;

		while (p1->next != lp)
		{
			if (p1->num > p1->next->num)
			{
				swap(p1, p1->next);
				swapped = 1;
			}
			p1 = p1->next;
		}
		lp = p1;
	} while (swapped);
	return head;
}