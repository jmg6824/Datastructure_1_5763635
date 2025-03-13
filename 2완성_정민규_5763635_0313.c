#include <stdio.h>
int main(){
    printf("실수를 입력하시오:");
    float f;
    scanf("%f",&f);
    printf("부호(1비트):");
    if(f>=0)    printf(" 0\n");
    else        printf(" 1\n");

    int exponent=(int)f;
    int ex[8];
    printf("지수(8비트):");
    for(int i=7;i>=0;i--){
        ex[i]=exponent%2;
        exponent/=2;
    }
    for(int i=0;i<=7;i++){
        printf("%d",ex[i]);
    }
    printf("\n");

    int base[23];
    float b=f-(int)f;
    for(int i=0;i<=23;i++){
        base[i]=b*2;
        b=b*2-base[i];
    }
    printf("기수(23비트):");
    for(int i=0;i<23;i++){
        printf("%d",base[i]);
    }
    return 0;
}