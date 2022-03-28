#include <stdio.h>
#include <stdlib.h>
void main()
{
int list[5];
int *plist[5] = {NULL,};
plist[0] = (int *)malloc(sizeof(int));
list[0] = 1;
list[1] = 100;
*plist[0] = 200;
printf("value of list[0] = %d\n", list[0]);
printf("address of list[0] = %p\n", &list[0]);
printf("value of list = %p\n", list); 
printf("address of list (&list) = %p\n", &list);
printf("----------------------------------------\n\n");

printf("value of list[1] = %d\n", list[1]);
printf("address of list[1] = %p\n", &list[1]);
printf("value of *(list+1) = %d\n", *(list + 1));
printf("address of list+1 = %p\n", list+1);
printf("----------------------------------------\n\n");

printf("value of *plist[0] = %d\n", *plist[0]);
printf("&plist[0] = %p\n", &plist[0]);
printf("&plist = %p\n", &plist);
printf("plist = %p\n", plist);
printf("plist[0] = %p\n", plist[0]);//메모리 할당을 해주어 메모리가 존재
printf("plist[1] = %p\n", plist[1]);//plist[1]~plist[4]까지는 메모리 초기화로 인해 메모리 부재
printf("plist[2] = %p\n", plist[2]);
printf("plist[3] = %p\n", plist[3]);
printf("plist[4] = %p\n", plist[4]);
free(plist[0]);
}