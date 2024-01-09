#include <stdio.h>

typedef struct 
{
    char name[30];
    int year;
    int salary;
} employee;

int main(void) {
    employee emp = {"이순신", 2015, 5900};
    employee *p = &emp;

    printf("이름 : %s\n입사 : %d\n연봉 : %d\n", p->name, p->year, p->salary);
    
    return 0;
}