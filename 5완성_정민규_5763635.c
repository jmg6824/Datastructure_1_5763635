/*
연산을 입력받아 정수와 연산자를 따로 저장하여, 연산자에 따라 다른 함수가 실행되도록 작성하였습니다.
*/

#include <stdio.h>
int plus(int a,int b);    // +연산자일 경우의 함수
int minus(int a,int b);   // -연산자일 경우의 함수
int multiply(int a,int b);// *연산자일 경우의 함수
int divide(int a,int b);  // /연산자일 경우의 함수
int main(){
    int a,b;
    char c;
    printf("연산을 입력하시오:");
    scanf("%d %c %d",&a,&c,&b);
    if(c=='+')     {printf("%d",plus(a,b));}
    else if(c=='-'){printf("%d",minus(a,b));}
    else if(c=='*'){printf("%d",multiply(a,b));}
    else if(c=='/'){printf("%d",divide(a,b));}
    return 0;
}
int plus(int a,int b)    {return a+b;}
int minus(int a,int b)   {return a-b;}
int multiply(int a,int b){return a*b;}
int divide(int a,int b)  {return a/b;}