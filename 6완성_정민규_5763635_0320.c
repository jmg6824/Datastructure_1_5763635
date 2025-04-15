//재귀함수를 이용해 해당수가 소수인지를 구분하는 함수를 for문을 통해 여러번 반복하여 구하는 알고리즘을 사용하였다.
/*
is_prime(정수n, n이하의 정수i)
    결과값=0
    i가 0이하일시 결과값=0

    if n%i가 0일시 then 결과값=1
    else 결과값=1
    결과값+=is_prime(정수n, (n이하의 정수 i)-1 )

    return 결과값
*/
/*
O(n)계산
    is_prime(i,i)=is_prime(i,i-1)+c ->c는 is_prime(i,i)를 1회 실행하는데 필요한 시간
                 =is_prime(i,i-2)+2c
                 =is_prime(i,i-3)+3c
                 .
                 .
                 .
                 .
                 =is_prime(i,0)+(i-1)*c
                 =i*i
                 =i^2
                 =O(i^2)
*/
#include <stdio.h>

int is_prime(int n, int i)
{
	int result = 0;	
	if (i <= 0) {return 0;}

	if (n % i == 0) {result = 1;}
    else {result = 0;}
	result += is_prime(n, i - 1);

	return result;
}

int main(){
    int n,c;
    printf("정수 N을 입력하시오:");
    scanf("%d",&n);
    printf("%d이하의 소수:",n);

    for(int i=0;i<n;i++){
        c = is_prime(i, i);
		if (c == 2) {printf("%d ", i);}
    }
    

}
