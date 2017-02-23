#include <stdlib.h>
#include <stdio.h>

typedef struct hash Hash;
typedef struct aluno Aluno;
struct hash{
    int n;
    int dim;
    Aluno **v;
};

struct aluno{
    int mat;
    char nome[80];
    char email[43];
    char turma;
};

int main(){

    return 0;
}
