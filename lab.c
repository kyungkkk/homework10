#include <stdio.h>
#include <stdlib.h>
void main()
{
    int *plist[5] = {NULL,};
    
    printf("plist[1] = %p\n", plist[1]);//plist[1]~plist[5]까지 주소값이 초기화 되어있는걸 보니 메모리할당량을 줄일수 있음
printf("plist[2] = %p\n", plist[2]);
printf("plist[3] = %p\n", plist[3]);
printf("plist[4] = %p\n", plist[4]);
}