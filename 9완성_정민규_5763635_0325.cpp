//malloc 사용 추천
/*
arrange(배열,배열크기){
    변수 temp생성
    for(i=0;i<배열크기;i++){
        for(j=0;j<배열크기;j++){
            if 배열[i]>배열[j] then
                배열[i]<->배열[j]
        }
    }
}
int main(){
    print 정수의 갯수를 입력하시오
    배열 크기를 정하는 변수 생성 및 입력

    print n개의 정수를 입력하시오
    배열 생성 및 입력

    오름차순으로 정렬
    배열을 출력
}
*/
#include <stdio.h>

void arrange(int li[],int size);

int main(){
    printf("정수의 갯수를 입력하시오:");
    short size;
    scanf("%d",&size);

    printf("%d개의 정수를 입력하시오:\n",size);
    int li[size];
    for(int i=0;i<size;i++){
        scanf("%d",&li[i]);
    }

    arrange(li,size);

    printf("오름차순으로 정렬된 정수들:\n");
    for(int i=0;i<size;i++)    {printf("%d ",li[i]);}
    return 0;
}

void arrange(int li[],int size){
    int temp;
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(li[i]<li[j]){
            temp=li[i];
            li[i]=li[j];
            li[j]=temp;
            }
        }
    }
}