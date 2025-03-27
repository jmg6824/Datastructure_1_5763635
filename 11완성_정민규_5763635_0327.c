#include <stdio.h>
#include <stdlib.h>
int main(){
    struct student{
        char name[30];
        int id;
        int score;
    };
    int num;
    printf("몇명의 학생 정보를 입력하시나요?:");
    scanf("%d",&num);

    struct student *group;
    group=(struct student *)malloc(sizeof(struct student)*num);


    for(int i=0;i<num;i++){
        printf("[%d] 학생의 정보를 입력하시오(이름 학번 점수):",i+1);
        scanf("%s %d %d",group[i].name,&group[i].id,&group[i].score);
    }

    int student_id=1;
    int count;
    while(student_id!=0){
        count=0;
        printf("학번을 입력하시오(0이면 종료):");
        scanf("%d",&student_id);
        for(int i=0;i<num;i++){
            if(student_id==group[i].id) {
                printf("%s %d %d\n",group[i].name,group[i].id,group[i].score);
                ++count;
                }
        }
        if(count!=1)    printf("해당 학번의 학생이 없습니다.\n");
    }
    free(group);
    return 0;
}