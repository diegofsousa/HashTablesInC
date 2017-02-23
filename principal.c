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

//Questão 10 ED II


Hash *hsl_cria(void);
int hash(Hash *tab, int mat);
Hash *hls_insere(Hash *tab, int mat, char *n, char *e, char t);
void hsl_busca(Hash *tab, int mat);

int main(){
    Hash *hash = hsl_cria();
    hash = hls_insere(hash, 336, "diego", "diego@gmail.com", '1');
    hash = hls_insere(hash, 337, "qualquercoisa", "qualquercoisa@gmail.com", '2');
    hash = hls_insere(hash, 339, "qualquercoisaoutra", "qualquercoisa@gmail.com", '1');
    //hsl_busca(hash, 337);


    return 0;
}


//letra a
Hash *hsl_cria(void){
    Hash *a = (Hash*)malloc(sizeof(Hash));
    a->dim = 4;
    a->n = 0;
    int i=0;

    Aluno * aluno = (Aluno*)malloc(a->dim * sizeof(Aluno));
    a->v = aluno;
    for(i=0;i<a->dim;i++){
        a->v[i] = NULL;
    }

    return a;
}

//letra b
int hash(Hash *tab, int mat){
    printf("\nmatricula %d / dimensão %d", mat, tab->dim);
    printf("\nHash gerado: %d", mat%tab->dim);
    return mat%tab->dim;
}

//letra c
void redimensiona(Hash* tab){
    float porc = (float)tab->n/tab->dim;
    printf("\ntab: %d e dim %d", tab->n, tab->dim);
    printf("\nporc: %f", porc);
    int i;
    if(porc >= 0.75 ){
        printf("\nPrecisou redimensionar");
        tab->v =(Aluno*)realloc(tab->v, 50*sizeof(Hash));
        int auxDim = tab->dim;
        tab->dim += 50;
        int tamAux = 0;
        for(i=0;i<auxDim;i++){
            if(tab->v[i] != NULL){
                tamAux++;
            }
        }
        int ialuno = 0;
        Aluno aluno[tamAux];
        for(i=0;i<auxDim;i++){
            if(tab->v[i] != NULL){
                aluno[ialuno] = *tab->v[i];
            }
            ialuno++;
        }
    }
}

//letra d
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
    tab->n += 1;

    redimensiona(tab);
    return tab;
}

void hsl_busca(Hash *tab, int mat){
    int h = hash(tab, mat);
    if(tab->v[h] != NULL){
        printf("\nExiste!");
        printf("\n%d\n%s\n%s\n%c", tab->v[h]->mat, tab->v[h]->nome, tab->v[h]->email, tab->v[h]->turma);
    }else{
        printf("\nNão existe");
    }
}

