#include <stdio.h>
typedef struct list{
    int row, col,value;

}List;

int main(){
    List l[10];
    int row,col,value,size=0,last=-1;
    printf("행렬을 입력하시오(-1입력시 종료)\n");
    while(1){
        scanf("%d",&row);
        if(row==-1) break;
        scanf("%d %d",&col,&value);
        l[size].row=row;
        l[size].col=col;
        l[size].value=value;
        ++size;
        ++last;
    }
    printf("행렬을 입력하시오(-1입력시 종료)\n");
    while(1){
        scanf("%d",&row);
        if(row==-1) break;
        scanf("%d %d",&col,&value);
        l[size].row=row;
        l[size].col=col;
        l[size].value=value;
        ++size;
        ++last;
    }
    for(int i=0;i<last+1;i++){
        for(int j=i+1;j<last+1;j++){
            if(l[i].row>l[j].row){
                List temp=l[i];
                l[i]=l[j];
                l[j]=temp;
            }
            else if(l[i].row==l[j].row && l[i].col>l[j].col){
                List temp=l[i];
                l[i]=l[j];
                l[j]=temp;
            }
            else if(l[i].row==l[j].row && l[i].col==l[j].col){
                l[i].value+=l[j].value;
                for(int k=j;k<last;k++){
                    l[k]=l[k+1];
                }
                --last;
            }
        }
    }
    printf("두 행렬의 합\nList: size=%d last=%d\n",size*3,last);
    printf("Items:\n");
    for(int i=0;i<last+1;i++){
        printf("[%d] {%d, %d, %d}\n",i,l[i].row,l[i].col,l[i].value);   
    }
    return 0;
}