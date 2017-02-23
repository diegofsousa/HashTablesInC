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

Hash *hsl_cria(void);

int main(){
    Hash *hash = hsl_cria();

    return 0;
}

Hash *hsl_cria(void){
    Hash *a = (Hash*)malloc(sizeof(Hash));
    a->dim = 50;
    a->n = 0;
    Aluno * aluno = (Aluno*)malloc(a->dim * sizeof(Aluno));
    a->v = &aluno;
    return a;
}
