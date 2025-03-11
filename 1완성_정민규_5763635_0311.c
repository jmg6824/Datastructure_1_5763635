#include <stdio.h>
int main(){
    printf("정수를 입력하시오:");
    int n;
    scanf("%d",&n);
    int bits[32]={0,};
    
    if(n>=0){                           //양수를 2진수로 표현하기
        for(int i=31;i>=0;i--){       
            bits[i]=n%2;
            n/=2;      
        }
    }
    /*
    else{                               //1의 보수로 음수 표현하기
        for(int i=31;i>=0;i--){       
            bits[i]=n%2;
            n/=2;      
        }
        for(int i=0;i<32;i++){
            if(bits[i]==0) bits[i]=1;
            else           bits[i]=0;
        }
    }
    */
    else{                               //2의 보수로 음수 표현하기
        for(int i=31;i>=0;i--){       
            bits[i]=n%2;
            n/=2;      
        }
        for(int i=0;i<32;i++){
            if(bits[i]==0) bits[i]=1;
            else           bits[i]=0;
        }
        bits[31]+=1;
        for(int i=31;i>0;i--){
            if(bits[i]==2) {bits[i]=0;bits[i-1]+=1;}
        }
    }
    
    printf("입력된 정수의 32비트 표현:");
    for(int i=0;i<32;i++){
        printf("%d",bits[i]);
    }
    return 0;
}