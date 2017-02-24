#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//A cada vez que redimensiona coloca mais 5 no tamanho
#define TAMREDIMENSIONA 5

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
    hash = hls_insere(hash, 340, "qualquercoisaoutra", "qualquercoisa@gmail.com", '1');
    hash = hls_insere(hash, 450, "qualquercoisaoutra", "qualquercoisa@gmail.com", '1');
    hash = hls_insere(hash, 344, "qualquercoisaoutra", "qualquercoisa@gmail.com", '1');
    hash = hls_insere(hash, 330, "qualquercoisaoutra", "qualquercoisa@gmail.com", '1');
    hash = hls_insere(hash, 349, "11111111111111", "1111111111", '1');

    hsl_busca(hash, 349);


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
    printf("\n[Hash %d gerado para a matricula %d]", mat%tab->dim, mat);
    return mat%tab->dim;
}

//letra c
//Primeiramente, os valores de hash que não são nulos sao colocados numa lista auxiliar,
//A tabela hash é redimensionada e os indices dos hashes são recalculados.
void redimensiona(Hash* tab){
    float porc = (float)tab->n/tab->dim;
    int i;
    if(porc >= 0.75 ){
        printf("\n\nRemapeano a tabela com mais %d espaços...", TAMREDIMENSIONA);
        //Guardando a dimensão da tabela hash
        int auxDim = tab->dim;

        //Guardando os elementos não-nulos em uma lista de struct auxiliar
        int ialuno = 0;
        Aluno alun[tab->n];
        for(i=0;i<auxDim;i++){
            if(tab->v[i] != NULL){
                alun[ialuno] = *tab->v[i];
                ialuno++;
            }
        }

        //Alterando o novo tamanho da tabela hash
        tab->dim += TAMREDIMENSIONA;
        tab->v =(Aluno*)malloc((auxDim + TAMREDIMENSIONA) * sizeof(Aluno));

        //Zerando a quantidade de valores não-nulos
        tab->n = 0;

        //Limpando o lixo de memória de cada elemento da tabelha hash
        for(i=0;i<tab->dim;i++){
            tab->v[i] = NULL;
        }

        //Reinserindo os elementos na tabela hash
        for(i=0;i<ialuno;i++){
            tab = hls_insere(tab, alun[i].mat, alun[i].nome, alun[i].email, alun[i].turma);

        }
    }
}



//letra d
Hash *hls_insere(Hash *tab, int mat, char *n, char *e, char t){
    printf("\nDimensão da tabela: %d", tab->dim);
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
        printf("\n\nExiste!");
        printf("\n%d\n%s\n%s\n%c", tab->v[h]->mat, tab->v[h]->nome, tab->v[h]->email, tab->v[h]->turma);
    }else{
        printf("\nNão existe");
    }
}

