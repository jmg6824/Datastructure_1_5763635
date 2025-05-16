
#include <stdio.h>
#include <stdlib.h>
#include "Linked_List.c"
#include "Linked_List.h"

int main() {

	// linkedList_h mylist;
	// mylist.head = (listNode*)NULL;

	/*linkedList_h* mylist;
	mylist = createLinkedList();

	insertFirstNode(mylist, 1);
	insertFirstNode(mylist, 2);
	insertFirstNode(mylist, 3);
	insertFirstNode(mylist, 4);
	insertFirstNode(mylist, 5);

	insertLastNode(mylist, 6);
	insertLastNode(mylist, 7);
	insertLastNode(mylist, 8);

	insertMiddleNode(mylist, mylist->head->link->link, 9);

	insertNthNode(mylist, 2, 20);

	printList(mylist);
	destroyLinkedList(mylist);

	printf(" Destroy unoreder linked list and new oredered linked list\n");
	mylist = createLinkedList();

	ordered_insertNode(mylist, 5);
	ordered_insertNode(mylist, 3);
	ordered_insertNode(mylist, 8);
	ordered_insertNode(mylist, 2);
	ordered_insertNode(mylist, 9);
	ordered_insertNode(mylist, 11);

	printList(mylist);

	deleteNode(mylist, mylist->head->link->link);
	printList(mylist);

	destroyLinkedList(mylist);

	mylist = createCLinkedList();
	insertFirstCNode(mylist, 1);
	insertFirstCNode(mylist, 2);
	insertFirstCNode(mylist, 3);
	insertFirstCNode(mylist, 4);
	insertFirstCNode(mylist, 5);

	printCList(mylist);
	deleteCNode(mylist, mylist->head->link->link);
	printCList(mylist);

	destroyCLinkedList(mylist);
	*/

	linkedList_h* mylist;
	mylist = createLinkedList();
	int menu, item;
	while(1){
		printf("======= Linked List Menu =======\n");
		printf("1) insertFirst (리스트의 제일 앞에 삽입)\n");
		printf("2) insertLast (리스트의 제일 뒤에 삽입)\n");
		printf("3) insertMiddle (특정 값 뒤에 삽입)\n");
		printf("4) insertNthNode (N번째 위치 삽입)\n");
		printf("6) deleteNode (특정 값 삭제)\n");
		printf("7) printt Head/Tail\n");
		printf("0) prgram stop\n");
		printf("select menu: ");
		scanf("%d", &menu);
		if(menu == 1){
			printf("삽입할 값: ");
			scanf("%d", &item);
			insertFirstCNode(mylist, item);
		}
		else if(menu == 2){
			printf("삽입할 값: ");
			scanf("%d", &item);
			insertLastCNode(mylist, item);
		}
		else if(menu == 3){
			printCList(mylist);
			int key;
			elementType item;
			printf("(keys)어떤 값 뒤에? ");
			scanf("%d", &key);
			printf("삽입할 값: ");
			scanf("%d", &item);
			insertMiddleCNode(mylist, key, item);
		}
		else if(menu == 4){
			int loc;
			printCList(mylist);
			printf(" 위치(index, 0부터): ");
			scanf("%d", &loc);
			printf("삽입할 값: ");
			scanf("%d", &item);
			insertNthCNode(mylist, loc, item);
		}
		else if(menu == 6){
			printf("삭제할 값: ");
			scanf("%d", &item);
			deleteCNode_item(mylist, item);
		}
		else if(menu == 7){
			printHead_tail(mylist);
		}
		else if(menu == 0){
			printf("프로그램 종료\n");
			break;
		}
		else{printf("잘못된 입력입니다.\n");}
 	}
	return 0;
}