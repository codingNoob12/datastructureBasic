#include <stdio.h>
#define MAX_DEGREE 50
#define MAX(a, b) ((a > b) ? a : b)

typedef struct polynominal
{
    int degree;
    int coefs[MAX_DEGREE];
} polynominal;

polynominal addPoly(polynominal A, polynominal B);
void printPoly(polynominal P);

int main()
{
    polynominal A = {3, {4, 3, 5, 0}};
    polynominal B = {4, {3, 1, 0, 2, 1}};
    polynominal C = addPoly(A, B);
    printf("A(x) = "); printPoly(A);
    printf("B(x) = "); printPoly(B);
    printf("C(x) = "); printPoly(C);

    return 0;
}

polynominal addPoly(polynominal A, polynominal B) {
    polynominal C;
    int a_idx = 0, b_idx = 0, c_idx = 0;
    int a_deg = A.degree, b_deg = B.degree;
    C.degree = MAX(A.degree, B.degree);

    while (a_idx <= A.degree && b_idx <= B.degree) {
        if (a_deg > b_deg) {
            C.coefs[c_idx++] = A.coefs[a_idx++];
            a_deg--;
        }
        else if (a_deg < b_deg) {
            C.coefs[c_idx++] = B.coefs[b_idx++];
            b_deg--;
        }
        else {
            C.coefs[c_idx++] = A.coefs[a_idx++] + B.coefs[b_idx++];
        }
    }

    return C;
}

void printPoly(polynominal P) {
    for (int i = 0; i <= P.degree; i++) {
        printf(" %d x ^%d", P.coefs[i], P.degree - i);
        if (i != P.degree) {
            printf(" + ");
        }
    }
    printf("\n");
}