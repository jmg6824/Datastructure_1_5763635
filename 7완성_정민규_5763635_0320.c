#include <stdio.h>
#include <string.h>
#include <stdlib.h>

double plus(double a,double b);    // +연산자일 경우의 함수
double minus(double a,double b);   // -연산자일 경우의 함수
double multiply(double a,double b);// *연산자일 경우의 함수
double divide(double a,double b);  // /연산자일 경우의 함수

int main(){
    double result=0;
    printf("계산할 수식을 입력하시오(예: 4 * 2 / 3 -10):");
    char c[100];
    char sign1[100];
    gets(c);

    int j=0;
    for(int i=0;i<100;i++){
        if(c[i]=='+'){sign1[j]='+';j++;}
        else if(c[i]=='-'){sign1[j]='-';j++;}
        else if(c[i]=='*'){sign1[j]='*';j++;}
        else if(c[i]=='/'){sign1[j]='/';j++;}
        
    }
    j=0;
    double c1[100];
    char *num;
    if(sign1[j]=='+')         {num=strtok(c,"+");c1[j]=atof(num);++j;}
        else if(sign1[j]=='-'){num=strtok(c,"-");c1[j]=atof(num);++j;}
        else if(sign1[j]=='*'){num=strtok(c,"*");c1[j]=atof(num);++j;}
        else if(sign1[j]=='/'){num=strtok(c,"/");c1[j]=atof(num);++j;}    
    for(int i=1;i<sizeof(sign1);i++){
        if(sign1[j]=='+')         {num=strtok(NULL,"+");c1[j]=atof(num);++j;}
            else if(sign1[j]=='-'){num=strtok(NULL,"-");c1[j]=atof(num);++j;}
            else if(sign1[j]=='*'){num=strtok(NULL,"*");c1[j]=atof(num);++j;}
            else if(sign1[j]=='/'){num=strtok(NULL,"/");c1[j]=atof(num);++j;}
    }
    num=strtok(NULL,"");
    c1[j]=atof(num);
    
    
    result+=c1[0];
    for(int i=0;i<strlen(sign1);i++){
        if(sign1[i]=='+'){result=plus(result,c1[i+1]);}
        else if(sign1[i]=='-'){result=minus(result,c1[i+1]);}
        else if(sign1[i]=='*'){result=multiply(result,c1[i+1]);}
        else if(sign1[i]=='/'){result=divide(result,c1[i+1]);}
    }

    printf("%lf",result);
    return 0;
}

double plus(double a,double b)    {return a+b;}
double minus(double a,double b)   {return a-b;}
double multiply(double a,double b){return a*b;}
double divide(double a,double b)  {return a/b;}