#pragma once

typedef int elementType;  

typedef struct ListNode { 
	elementType data;
	struct ListNode* link;
} listNode;

typedef struct {  
	int follow;
	listNode* head;
	listNode* tail;
}linkedList_h; 

extern linkedList_h* createLinkedList(void);
extern linkedList_h* createCLinkedList(void);

extern void destroyLinkedList(linkedList_h* L);
extern void destroyCLinkedList(linkedList_h* L);

extern void printList(linkedList_h* L);
extern void printCList(linkedList_h* L);

extern void insertFirstNode(linkedList_h* L, elementType item);
extern void insertFirstCNode(linkedList_h* L, elementType item);

extern void insertLastNode(linkedList_h* L, elementType item);
extern void insertLastCNode(linkedList_h* L, elementType item);

extern void insertMiddleNode(linkedList_h* L, listNode* pre, elementType item);
extern void insertMiddleCNode(linkedList_h* L, int key, elementType item);

extern void insertNthNode(linkedList_h* L, int loc, elementType item);
extern void insertNthCNode(linkedList_h* L, int loc, elementType item);

extern void printHead_tail(linkedList_h* L);
extern void ordered_insertNode(linkedList_h* L, elementType item);
extern void deleteCNode_item(linkedList_h* L, elementType item);
extern void deleteNode(linkedList_h* L, listNode* p);
extern void deleteCNode(linkedList_h* L, listNode* p);