/*
int main(){
    print 첫 번째 2X2 행렬 입력
    첫번째 2X2행렬 생성
    첫번째 행렬 채우기

    print 두 번째 2X2 행렬 입력
    두번째 2X2행렬 생성
    두번째 행렬 채우기

    행렬 덧셈 실행

    행렬 출력
}
*/
#include <stdio.h>
int main(){
    printf("첫 번째 2X2 행렬 입력:\n");
    int a[2][2];
    for(int i=0;i<2;i++){
        scanf("%d %d",&a[i][0],&a[i][1]);
    }
    printf("두 번째 2X2 행렬 입력:\n");
    int b[2][2];
    for(int i=0;i<2;i++){
        scanf("%d %d",&b[i][0],&b[i][1]);
    }

    for(int i=0;i<2;i++){
        a[i][0]+=b[i][0];
        a[i][1]+=b[i][1];
    }
    printf("행렬의 덧셈:\n");
    printf("%d %d\n%d %d",a[0][0],a[0][1],a[1][0],a[1][1]);
    return 0;
}