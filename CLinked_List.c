

#include <stdio.h>
#include <stdlib.h>

#include "Linked_List.h"

linkedList_h* createLinkedList(void) {
	linkedList_h* lptr;

	lptr = (linkedList_h*)malloc(sizeof(linkedList_h));
	lptr->head = (listNode*)NULL;
	lptr->tail = (listNode*)NULL;
	lptr->follow = 0;
	return lptr;
}

linkedList_h* createCLinkedList(void) {
	linkedList_h* lptr;

	lptr = (linkedList_h*)malloc(sizeof(linkedList_h));
	lptr->head = (listNode*)NULL;
	lptr->tail = (listNode*)NULL;
	lptr->follow = 0;
	return lptr;
}
int compare_item(elementType first, elementType second) {
	return (first - second);
}

void destroyLinkedList(linkedList_h* L) {
	listNode* p;

	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;  // L->head = p->link;
		free(p);
	}
	free(L);
}


void destroyCLinkedList(linkedList_h* L) {
	listNode* p;

	while (L->head != L->head->link ) {
		p = L->head;
		L->head = L->head->link;  // L->head = p->link;
		free(p);
	}
	free(L->head);
	free(L);
}

void printList(linkedList_h* L) {
	listNode* lptr = L->head;

	printf("Linked List(%d): ",L->follow);
	while (lptr->link != (listNode*)NULL) {
		printf("[%d]", lptr->data);
		lptr = lptr->link;
	}
	printf("[%d] \n", lptr->data);
}

void printCList(linkedList_h* L) {
	listNode* lptr = L->head;

	printf("Linked List(%d): ", L->follow);
	if (lptr == NULL) {
		printf("\n");
		return;
	}
	while (lptr->link != L->head ) {
		printf("[%d]", lptr->data);
		lptr = lptr->link;
	}
	printf("[%d]", lptr->data);
	printf("\n");
}


void insertFirstNode(linkedList_h* L, elementType item) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = L->head; //(1)
	L->head = newNode;  //(2)

	//return 0;삭제
}

void insertFirstCNode(linkedList_h* L, elementType item) {
	listNode* newNode, *temp;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	if(L->head == (listNode*)NULL){
		L->head = newNode;
		newNode->link = newNode;
		L->tail = newNode;
	}
	else {
		newNode->link = L->head;
		L->head = newNode;
		L->tail->link = newNode;
	}
	//return 0;삭제
	printCList(L);
}


void insertLastNode(linkedList_h* L, elementType item) {
	listNode* temp, * newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	newNode->link = (listNode*)NULL;

	temp = L->head;
	if (temp == (listNode*)NULL) {
		L->head = newNode;
		return;
	}

	while (temp->link != (listNode*)NULL) {
		temp = temp->link;
		L->follow++;
	}

	temp->link = newNode;
}

void insertMiddleNode(linkedList_h* L, listNode* pre, elementType item) {
	listNode* newNode;

	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if (L->head == (listNode*)NULL) {
		newNode->link = (listNode*)NULL;
		L->head = newNode;
	}
	else if (pre == (listNode*)NULL) {
		newNode->link = L->head;
		L->head = newNode;
	}
	else {
		newNode->link = pre->link;
		pre->link = newNode;
	}
}

void insertMiddleCNode(linkedList_h* L, int key, elementType item) {
	listNode* pre, * newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	if (L->head == (listNode*)NULL) {
		newNode->link = (listNode*)NULL;
		L->head = newNode;
	}
	else if (L->head->link == L->head) {
		if (compare_item(L->head->data, key) == 0) {
			newNode->link = L->head;
			L->head = newNode;
		}
		else {
			fprintf(stderr, "삽입할 위치가 없습니다.\n");
		}
	}
	else {
		pre = L->head;
		while (compare_item(pre->data, key) != 0 && pre->link != L->head ) {
			pre = pre->link;
			L->follow++;
		}
		if (compare_item(pre->data, key) == 0) {
			newNode->link = pre->link;
			pre->link = newNode;
		}
		else {
			fprintf(stderr, "삽입할 위치가 없습니다.\n");
		}
	}
	printCList(L);
}

void insertLastCNode(linkedList_h* L, elementType item) {
	listNode* newNode;
	
	newNode=(listNode*)malloc(sizeof(listNode));
	newNode->data = item;

	if(L->head == (listNode*)NULL){
		L->head = newNode;
		newNode->link = newNode;
		L->tail = newNode;
	}
	else {
		L->tail->link = newNode;
		newNode->link = L->head;
		L->tail = newNode;
	}
	printCList(L);
}


void insertNthNode(linkedList_h* L, int loc, elementType item) {
	if (L->head == (listNode*)NULL) {
		if (loc == 0) insertFirstNode(L, item);
		else fprintf(stderr,"[insertNthNode: list empty and loc not 0\n");
		return;
	}
	else {
		if (loc == 0) insertFirstNode(L, item);
		else {
			int i = loc; listNode* pre = L->head;
			while (i > 1 && pre->link != (listNode*)NULL) {
				i--, pre = pre->link;
				L->follow++;
			}
			if (i == 1) insertMiddleNode(L, pre, item);
			else fprintf(stderr, "[insertNthNode: location error");

		}
		return;
	}
}
void insertNthCNode(linkedList_h* L, int loc, elementType item) {
	if(L->head ==(listNode*)NULL) return;
	listNode*  newNode,*pre;
	newNode = (listNode*)malloc(sizeof(listNode));
	newNode->data = item;
	pre=L->head;
	while(loc!=0){
		pre=pre->link;
		loc--;
	}
	newNode->link = pre->link;
	L->head=newNode;
	printCList(L);
}	


void ordered_insertNode(linkedList_h* L, elementType item) {
	listNode* pre;

	if (L->head == (listNode*)NULL) insertFirstNode(L, item);
	else {
		if (compare_item(L->head->data, item) > 0)
			insertFirstNode(L, item);
		else {
			pre = L->head;
			while (pre->link != (listNode*)NULL) {
				if (compare_item(pre->data, item) < 0 &&
					compare_item(pre->link->data, item)  > 0) break;
				pre = pre->link;
				L->follow++;
			}
			insertMiddleNode(L, pre, item);
		}
	}
}

void deleteNode(linkedList_h* L, listNode* p) {
	listNode* pre;

	if (L->head == (listNode*)NULL) return;
	/* if (L->head->link == (listNode*)NULL) {
		free(L->head);
		L->head = (listNode*)NULL;
		return;
	} */
	else if (p == (listNode*)NULL) return;
	else {
		pre = L->head;
		while (pre->link != p && p->link != (listNode*)NULL) {
			pre = pre->link;
			L->follow++;
		}
		if (pre->link == p) {
			pre->link = p->link; // 
			free(p);
		}
		else {
			fprintf(stderr, " delete item not in the list\n");
		}
	}
}

void deleteCNode(linkedList_h* L, listNode* p) {
	listNode* pre;

	if (L->head == (listNode*)NULL) return;
	/* if (L->head->link == (listNode*)NULL) {
		free(L->head);
		L->head = (listNode*)NULL;
		return;
	} */
	else if (p == (listNode*)NULL) return;
	else {
		pre = L->head;
		while (pre->link != p && p->link != L->head ) {
			pre = pre->link;
			L->follow++;
		}
		if (pre->link == p) {
			pre->link = p->link; // 
			free(p);
		}
		else {
			fprintf(stderr, " delete item not in the list\n");
		}
	}
	printCList(L);
}

void deleteCNode_item(linkedList_h* L, elementType item){
	listNode* pre, *p;

	if (L->head == (listNode*)NULL) return;
	else if (L->head->link == L->head) {
		if (compare_item(L->head->data, item) == 0) {
			free(L->head);
			L->head = (listNode*)NULL;
		}
		return;
	}
	else {
		pre = L->head;
		p = L->head;
		while (compare_item(p->data, item) != 0 && p->link != L->head ) {
			pre = p;
			p = p->link;
			L->follow++;
		}
		if (compare_item(p->data, item) == 0) {
			pre->link = p->link; // 
			free(p);
		}
		else {
			fprintf(stderr, "삭제할 값이 리스트에 없습니다.\n");
		}
	}
	printCList(L);
}
void printHead_tail(linkedList_h* L) {
	if (L->head == (listNode*)NULL) {
		printf("연결리스트가 비어있습니다.\n");
		return;
	}
	else {
		printf("head: %p, tail: %p\n", L->head, L->tail);
	}
}
