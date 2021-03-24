#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void citire(char ***matrice, int *n) {
    int i, dim_sir;
    char sir_citit[200];

    scanf("%d", n);
    *matrice = (char **) malloc((*n) * sizeof(char *));
    getchar();
    for (i = 0; i < *n; i++) {
        fgets(sir_citit, 200, stdin);
        dim_sir = strlen(sir_citit);
        (*matrice)[i] = malloc((dim_sir + 2) * sizeof(char));
        strcpy((*matrice)[i], sir_citit);
    }
}

int este_numar(char sir[]) {
    int i, dimensiune;

    dimensiune = strlen(sir);
    for (i = 0; i < dimensiune; i++)
        if (!(sir[i] >= 48 && sir[i] <= 57))
            return 0;
    return 1;
}

void modificare(char **matrice, int n) {
    int i, j, val, dimensiune_sir;
    char *p, aux[201], construire_sir[201];

    for (i = 0; i < n; i++) {
        dimensiune_sir = 0;
        strcpy(aux, matrice[i]);
        p = strtok(aux, " \n");
        while (p != NULL) {
            if (!este_numar(p)) {
                construire_sir[dimensiune_sir++] = p[0];
                for (j = 1; j < strlen(p); j++) {
                    val = (p[j] + p[0]) % 256;
                    construire_sir[dimensiune_sir++] = val;
                }
                construire_sir[dimensiune_sir++] = ' ';
            } else {
                for (j = 0; j < strlen(p); j++)
                    construire_sir[dimensiune_sir++] = p[j];
                construire_sir[dimensiune_sir++] = ' ';
            }
            p = strtok(NULL, " \n");
        }
        construire_sir[dimensiune_sir - 1] = '\0';
        printf("%s\n", construire_sir);
        strcpy(construire_sir, "");
    }
}

void eliberare_memorie(char **matrice, int n) {
    int i;

    for (i = 0; i < n; i++)
        free((matrice)[i]);
    free(matrice);
}

int main() {
    char **matrice;
    int n;

    citire(&matrice, &n);
    modificare(matrice, n);
    eliberare_memorie(matrice, n);
    return 0;
}
