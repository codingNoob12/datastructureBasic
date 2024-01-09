#include <stdio.h>
#define MAX_DEGREE 50

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
    polynominal L = A.degree > B.degree ? A : B;
    polynominal S = A.degree > B.degree ? B : A;

    C.degree = L.degree;
    int offset = L.degree - S.degree;
    for (int i = L.degree; i >= 0; i--) {
        if (i < offset) {
            C.coefs[i] = L.coefs[i];
            continue;
        }
        C.coefs[i] = L.coefs[i] + S.coefs[i - offset];
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