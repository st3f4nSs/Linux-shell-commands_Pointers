#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void citire(char ***matrice, int *n, char sir_cautat[]) {
    int i, dim_sir;
    char sir[40], sir_citit[200];

    fgets(sir, 40, stdin);
    sir[strlen(sir) -
        1] = '\0';
    strcpy(sir_cautat, sir);
    scanf("%d", n);
    getchar();
    *matrice = (char **) malloc((*n) * sizeof(char *));
    for (i = 0; i < *n; i++) {
        fgets(sir_citit, 200, stdin);
        dim_sir = strlen(sir_citit);
        (*matrice)[i] = malloc((dim_sir + 1) * sizeof(char));
        strcpy((*matrice)[i], sir_citit);
    }
}

void creare_sir(char sir_cautat[], char sir_rosu[]) {

    int k, i;

    k = 0;
    sir_rosu[k++] = '\e';
    sir_rosu[k++] = '[';
    sir_rosu[k++] = '0';
    sir_rosu[k++] = ';';
    sir_rosu[k++] = '3';
    sir_rosu[k++] = '1';
    sir_rosu[k++] = 'm';

    for (i = 0; i < strlen(sir_cautat); i++)
        sir_rosu[k++] = sir_cautat[i];
    sir_rosu[k++] = '\e';
    sir_rosu[k++] = '[';
    sir_rosu[k++] = 'm';
    sir_rosu[k] = '\0';
}

void modificare_lin(char sir[], char sir_cautat[]) {
    char *p, sir_rosu[50], aux[400];

    creare_sir(sir_cautat, sir_rosu);
    p = strstr(sir, sir_cautat);
    while (p != NULL) {
        strcpy(aux, sir_rosu);
        strcat(aux, p + strlen(sir_cautat));
        strcpy(p, aux);
        p = strstr(p + strlen(sir_rosu), sir_cautat);
    }
}

int numar_cuv_caut_linie(char sir[], char sir_cautat[]) {
    int nr_aparitii_cuv;
    char *p;

    nr_aparitii_cuv = 0;
    p = strstr(sir, sir_cautat);
    while (p != NULL) {
        nr_aparitii_cuv++;
        p = strstr(p + strlen(sir_cautat), sir_cautat);
    }
    return nr_aparitii_cuv;
}

void modificare_matrice(char ***matrice, char sir_cautat[], int n, int linii_cuv[], int *dimensiune) {
    int i, nr_ap_cuv, dim_lin;
    char aux[400];

    *dimensiune = 0;
    for (i = 0; i < n; i++) {
        dim_lin = strlen((*matrice)[i]);
        strcpy(aux, (*matrice)[i]);
        nr_ap_cuv = numar_cuv_caut_linie(aux, sir_cautat);
        if (nr_ap_cuv) {
            modificare_lin(aux, sir_cautat);
            linii_cuv[(*dimensiune)++] = i;
            (*matrice)[i] = realloc((*matrice)[i], ((dim_lin + 1) + nr_ap_cuv * 10) * sizeof(char));
            strcpy((*matrice)[i], aux);
        }
    }
}

void afisare(char **matrice, int n, int linii_cuv[], int dimensiune) {
    int i;

    for (i = 0; i < dimensiune; i++)
        printf("%s", matrice[linii_cuv[i]]);
}

void eliberare_memorie(char **matrice, int n) {
    int i;

    for (i = 0; i < n; i++)
        free((matrice)[i]);
    free(matrice);
}

int main() {
    int n, linii_cuv[100], dimensiune;
    char **matrice, sir_cautat[40];

    citire(&matrice, &n, sir_cautat);
    modificare_matrice(&matrice, sir_cautat, n, linii_cuv, &dimensiune);
    afisare(matrice, n, linii_cuv, dimensiune);
    eliberare_memorie(matrice, n);
    return 0;
}
