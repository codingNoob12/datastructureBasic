#include <stdio.h>

typedef struct
{
    char name[30];
    int year;
    int salary;
} employee;


int main(void) {
    employee emp[4] = {
        {"이진호", 2014, 4200},
        {"이한영", 2015, 3300},
        {"이상원", 2015, 3500},
        {"이상범", 2016, 2900}
    };

    for (int i = 0; i < 4; i++) {
        printf("이름 : %s\n입사 : %d\n연봉 : %d\n\n", emp[i].name, emp[i].year, emp[i].salary);
    }

    return 0;
}