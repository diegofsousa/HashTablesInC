#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
int hash(Hash *tab, int mat);
Hash *hls_insere(Hash *tab, int mat, char *n, char *e, char t);

int main(){
    Hash *hash = hsl_cria();
    hash = hls_insere(hash, 5, "diego", "diego@gmail.com", '1');


    return 0;
}

Hash *hsl_cria(void){
    Hash *a = (Hash*)malloc(sizeof(Hash));
    a->dim = 50;
    a->n = 0;
    int i=0;

    Aluno * aluno = (Aluno*)malloc(a->dim * sizeof(Aluno));
    a->v = &aluno;
    for(i=0;i<a->dim;i++){
        a->v[i] == NULL;
    }

    return a;
}

int hash(Hash *tab, int mat){
    return(mat%tab->dim);
}


void redimensiona(Hash* tab){
    float porc = tab->n/tab->dim ;
    if(porc < 0.75 ){
        tab =(Hash*)realloc(tab, 50*sizeof(Hash));
        //remapear aqui
    }
}

Hash *hls_insere(Hash *tab, int mat, char *n, char *e, char t){
    int h = hash(tab, mat);
    while(tab->v[h] != NULL){
        if(tab->v[h]->mat == mat)
            break;
        h = (h+1) % tab->dim;
    }
    if(tab->v[h] == NULL){
       tab->v[h] = (Aluno*)malloc(tab->dim * sizeof(Aluno));
       tab->v[h]->mat = mat;
    }
    strcpy(tab->v[h]->nome, n);
    strcpy(tab->v[h]->email, e);
    tab->v[h]->turma = t;
    return tab;
}

