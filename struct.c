#include <stdio.h>

struct student1 {
char lastName;
int studentId;
char grade;
};

typedef struct {
char lastName;
int studentId;
char grade;
} student2;

int main() {
    printf("2019038042 이도경\n");
struct student1 st1 = {'A', 100, 'A'};
printf("st1.lastName = %c\n", st1.lastName);
printf("st1.studentId = %d\n", st1.studentId);
printf("st1.grade = %c\n", st1.grade);
student2 st2 = {'B', 200, 'B'};
printf("\nst2.lastName = %c\n", st2.lastName);
printf("st2.studentId = %d\n", st2.studentId);
printf("st2.grade = %c\n", st2.grade);
student2 st3;
st3 = st2;//구조체의 값이동은 되었다.
printf("\nst3.lastName = %c\n", st3.lastName);
printf("st3.studentId = %d\n", st3.studentId);
printf("st3.grade = %c\n", st3.grade);
/* equality test */
if(st3 == st2) //그러나 등식을 사용하니 오류라고 뜸
printf("equal\n");
else
printf("not equal\n");
return 0;
}
//대입연산은 사용하기 편라하기 때문에 가능하나 등식은 불가능하다 사용할려면 구조체내에 변수 즉 st3.lastName==st2.lastName과 같이 사용해야한다.