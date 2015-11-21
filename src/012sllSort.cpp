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


void sll_012_sort(struct node *head){
	struct node* lists[3] = { NULL, NULL, NULL };

	/* Distribute the cells across the lists. */
	while (head!= NULL) {
		/* Cache a pointer to the next cell in the list, since we will be
		* rewiring this linked list.
		*/
		struct node* Next = head->next;

		/* Prepend this cell to the list it belongs to. */
		head->next = lists[head->data];
		lists[head->data] = head;

		/* Advance to the next cell in the list. */
		head = Next;
	}
}