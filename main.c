#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct ElementType {
	int num[3];
} elementType;
typedef struct Name_Element{
	char name[20];
}name_element;
typedef struct ListType {
    int size;
    int last;
    int move;
    elementType *array;
    name_element *name_array;
} listType;

listType* createList(int size) {
    listType* lptr;

    lptr = (listType*)malloc(sizeof(listType));
    lptr->array = (elementType*)malloc(sizeof(elementType) * size);
    lptr->name_array = (name_element*)malloc(sizeof(name_element) * size);
    lptr->size = size;
    lptr->last = -1;
    lptr->move = 0;

    return lptr;
}
void destroyList(listType* list) {
    free(list->array);
    free(list->name_array);
    free(list);
}
void add_number(listType*list, int num[3],char name[20]){
    num[0]=atoi(strtok(name,"-"));
    num[1]=atoi(strtok(NULL,"-"));
    num[2]=atoi(strtok(NULL,"-"));
    list->last++;
    list->array[list->last].num[0] = num[0];
    list->array[list->last].num[1] = num[1];
    list->array[list->last].num[2] = num[2];
    strcpy(list->name_array[list->last].name,name);
}
void delete_number(listType* list, char name[20]){
    int i;
    for(i=0;i<=list->last;i++){
        if(strcmp(list->name_array[i].name,name)==0){
            break;
        }
    }
    if(i>list->last){
        printf("이름이 존재하지 않습니다.\n");
        return;
    }
    else{
        for(int j=i;j<list->last;j++){
            list->array[j]=list->array[j+1];
            list->name_array[j]=list->name_array[j+1];
        }
        list->last--;
        printf("삭제되었습니다.\n");
    }
}
void search_number(listType* list, char name[20]){
    int i;
    for(i=0;i<list->last;i++){
        if(strcmp(list->name_array[i].name,name)==0){
            printf("[%d]전화번호: %d-%d-%d\n",i, list->array[i].num[0], list->array[i].num[1], list->array[i].num[2]);
            return;
        }
    }
}
void print_numberbook(listType* list){
    for(int i=0;i<=list->last;i++){
        printf("이름: %s, 전화번호: %d-%d-%d\n", list->name_array[i].name, list->array[i].num[0], list->array[i].num[1], list->array[i].num[2]);
    }
}


int main(){
    listType* phonebook;
    phonebook = createList(10);
    int num[3];
    char name[20];
    printf("**** 전화번호부 메뉴 ****\n");
    printf("1. 전화번호 등록\n");
    printf("2. 전화번호 삭제\n");
    printf("3. 전화번호 검색\n");
    printf("4. 전화번호부 전체 출력\n");
    printf("0. 종료\n");
    printf("메뉴를 선택하세요: ");

    int choice;
    scanf("%d",&choice);
    while(choice !=0){
        if(choice == 1){    //연락처 추가
            printf("이름을 입력하세요: ");
            scanf("%s",name);
            printf("전화번호를 입력하세요(형식: 010-1234-5678): ");
            scanf("%s",name);

            add_number(phonebook,num,name);
            printf("연락처가 추가되었습니다.\n");
        }    
        else if(choice == 2){   //연락처 삭제
            printf("삭제할 이름을 입력하세요: ");
            scanf("%s",name);
            delete_number(phonebook,name);
        }
        else if(choice==3){     //연락처 검색
            printf("검색할 이름을 입력하세요: ");
            scanf("%s",name);
            search_number(phonebook,name);
        }
        else if(choice==4){     //연락처 출력
            print_numberbook(phonebook);
        }
        else if(choice==0){     //종료
            printf("프로그램을 종료합니다.\n");
            destroyList(phonebook);
            return 0;
        }
        else{
            printf("잘못된 입력입니다. 다시 입력하세요.\n");
        }
        printf("**** 전화번호부 메뉴 ****\n");
        printf("1. 전화번호 등록\n");
        printf("2. 전화번호 삭제\n");
        printf("3. 전화번호 검색\n");
        printf("4. 전화번호부 전체 출력\n");
        printf("0. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d",&choice);
    }
    return 0;
}