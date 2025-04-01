#include <stdio.h>
int fib1(int n);
int fib2(int n);
int main(){
    int way=1;
    int seq=0;
    int n;
    while(1){
    printf("피보나치 수열 밥법 선택(1:재귀적, 2:순환적:, 0:종료):");
    scanf("%d",&way);
    if(way==0)  break;

    printf("정수N을 입력하세요(종료하려면 0 입력):");
    scanf("%d",&n);
    if(n==0)    break;

    if(way==1)      {seq=fib1(n);printf("F(%d)=%d (재귀적 방법)\n",n,seq);}//재귀적
    else if(way==2) {seq=fib2(n);printf("F(%d)=%d (순환적 방법)\n",n,seq);}//순환적
    }
    return 0;   
}

int fib1(int n){
    if(n==0)    return 0;
    else if(n==1)   return 1;
    else return (fib1(n-1)+fib1(n-2));
}

int fib2(int n){
    if(n==0) return 0;
    else if(n==1)   return 1;
    else {
        int tmp,cur=1,last=0;
        for (int i=2;i<=n;i++) {
            tmp = last;
            last = cur;
            cur += tmp;
        }
        return cur;
    }
}