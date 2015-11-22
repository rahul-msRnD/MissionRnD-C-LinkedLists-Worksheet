/*
OVERVIEW:  Given a single linked list of 0s 1s and 2s ,Sort the SLL such that zeroes 
will be followed by ones and then twos.


INPUTS:  SLL head pointer

OUTPUT: Sorted SLL ,Head should Finally point to an sll of sorted 0,1,2


ERROR CASES:

NOTES: Only 0,1,2, will be in sll nodes
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int data;
	struct node *next;
};


void swap1(struct node *a, struct node *b)
{
	int temp = a->data;
	a->data = b->data;
	b->data = temp;
}

void sll_012_sort(struct node *head){
	int swapped, i;
	struct node *p1;
	struct node *lp = NULL;
	do
	{
		swapped = 0;
		p1 = head;

		while (p1->next != lp)
		{
			if (p1->data > p1->next->data)
			{
				swap1(p1, p1->next);
				swapped = 1;
			}
			p1 = p1->next;
		}
		lp = p1;
	} while (swapped);
}


