#include <stdio.h>
#include <stdlib.h>
#include "function.h"

void printList(Node *head);
void freeList(Node*);

int main() {
	Node *head = NULL;
	Node *temp;
	int data;

	while(1){
		scanf("%d", &data);
		if (data >= 0) {
			insert_increase_list(&head, data);
		} else break;
	}

	printList(head);
	freeList(head);
	return 0;
}

void freeList(Node *head) {
	Node *temp;
	for(temp=head; temp!=NULL; temp=head) {
		head = head->next;
		free(temp);
	}
}

void printList(Node *head) {
	Node *temp;
	for(temp = head; temp!=NULL; temp=temp->next) {
		printf("%d ", temp->data);
	}
	printf("\n");
}
