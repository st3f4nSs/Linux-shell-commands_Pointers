#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void citire(char ***matrice, int *m, char del[], int *n, int fields[], char out_del[]) {
    int i, dim_sir;
    char sir_citit[200];

    fgets(del, 11, stdin);
    scanf("%d", n);
    for (i = 0; i < *n; i++)
        scanf("%d,", &fields[i]);
    getchar();
    fgets(out_del, 11, stdin);
    out_del[strlen(out_del) - 1] = '\0';
    scanf("%d", m);
    getchar();
    (*matrice) = (char **) malloc((*m) * sizeof(char *));
    for (i = 0; i < *m; i++) {
        fgets(sir_citit, 200, stdin);
        dim_sir = strlen(sir_citit);
        (*matrice)[i] = malloc((dim_sir + 1) * sizeof(char));
        strcpy((*matrice)[i], sir_citit);
    }
}

int index_cuv_exist(int index_cuv, int fields[], int n) {
    int i;

    for (i = 0; i < n; i++)
        if (fields[i] == index_cuv)
            return 1;
    return 0;
}

void modificare(char **matrice, int m, char del[], char out_del[], int fields[], int n) {
    int i, bec, index_cuvant;
    char *p, auxiliar[200];

    for (i = 0; i < m; i++) {
        strcpy(auxiliar, matrice[i]);
        bec = 0;
        index_cuvant = 1;
        p = strtok(auxiliar, del);
        while (p != NULL) {
            if (index_cuv_exist(index_cuvant, fields, n)) {
                if (!bec) {
                    printf("%s", p);
                    bec = 1;
                } else
                    printf("%s%s", out_del, p);
            }
            index_cuvant++;
            p = strtok(NULL, del);
        }
        printf("\n");
        strcpy(auxiliar, "");
    }
}

void eliberare_memorie(char **matrice, int m) {
    int i;

    for (i = 0; i < m; i++)
        free((matrice)[i]);
    free(matrice);
}

int main() {
    char **matrice, del[11], out_del[11];
    int m, n, fields[100];

    citire(&matrice, &m, del, &n, fields, out_del);
    modificare(matrice, m, del, out_del, fields, n);
    eliberare_memorie(matrice, m);
    return 0;
}
