#include <stdio.h>

struct student {
char lastName[13]; /* 13 bytes */
int studentId; /* 4 bytes */
short grade; /* 2 bytes */
};
/* 4/4/4/4/4/4 이련형태일텐데 char형이 13인데 뒤가 int형이므로
4444만들고 4번째사에는 3바이트가 패딩, 인트형 4 채우고 short형은 2바이트가 패딩됨으로써 24바이트가 형성됨*/
int main()
{
struct student pst;
printf("size of student = %ld\n", sizeof(struct student));
printf("size of int = %ld\n", sizeof(int));
printf("size of short = %ld\n", sizeof(short));
return 0;
}