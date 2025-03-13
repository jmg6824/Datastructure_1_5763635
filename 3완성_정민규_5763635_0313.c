#include <stdio.h>
#include <string.h>

int main(){
    char str[100];
    printf("문자열을 입력하시오:");
    gets(str);

    printf("문자열의 길이:%lu\n",strlen(str));
    
    for(int i=0;i<strlen(str);i++){
        if(str[i]>=65 && str[i]<=90){
            str[i]+=32;
        }
        else if(str[i]>=97 && str[i]<=122){
            str[i]-=32;
        }
    }
    printf("변환된 문자열:");
    puts(str);
    
    return 0;
}