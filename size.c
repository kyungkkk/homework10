#include<stdio.h>
#include<stdlib.h>
void main()
{
int **x;
printf("sizeof(x) = %lu\n", sizeof(x));
printf("sizeof(*x) = %lu\n", sizeof(*x));
printf("sizeof(**x) = %lu\n", sizeof(**x));
}
//포인터는 주소값을 저장하는 변수 윈도우체제에 따라 크기값이 나뉨 또한 이중포인터도 특정된변수를 가리키기 때문에 4바이트
