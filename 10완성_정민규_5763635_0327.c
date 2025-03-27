#include <stdio.h>
#include <stdlib.h>
int main(){
    printf("첫 번째 2X2 행렬 입력:\n");
    int *array=malloc(sizeof(int)*4);
    for(int i=0;i<4;i++){
        scanf("%d",&array[i]);
    }

    printf("두 번째 2X2 행렬 입력:\n");
    int num;
    for(int i=0;i<4;i++){
        scanf("%d",&num);
        array[i]+=num;
    }
    printf("행렬의 덧셈:\n%d %d\n%d %d",array[0],array[1],array[2],array[3]);
    free(array);
    return 0;
}