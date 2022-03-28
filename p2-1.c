#include <stdio.h>
#define MAX_SIZE 100

float sum(float [], int);
float input[MAX_SIZE], answer;

int i;

void main(void)
{
for(i=0; i < MAX_SIZE; i++)
input[i] = i;
/* for checking call by reference */
printf("address of input = %p\n", input);
answer = sum(input, MAX_SIZE);//값을 받아와 함수내에서만 사용 그렇기에 함수밖으로 나오면 값은 변경이 없음
printf("The sum is: %f\n", answer);
printf("%d\n",&input[0]);
}

float sum(float list[], int n)
{
printf("value of list = %p\n", list);
printf("address of list = %p\n\n", &list);
int i;
float tempsum = 0;
for(i = 0; i < n; i++)
tempsum += list[i];
return tempsum;
}