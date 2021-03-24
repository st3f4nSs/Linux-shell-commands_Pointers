#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void citire(int ***matrice, int *n, int **nr_elem_linie) {
    int i, element, nr_elem, cap;

    scanf("%d", n);
    *matrice = (int **) malloc((*n) * sizeof(int *));
    *nr_elem_linie = (int *) malloc((*n) * sizeof(int));
    for (i = 0; i < *n; i++)
        (*nr_elem_linie)[i] = 0;
    for (i = 0; i < *n; i++) {
        cap = 3;
        (*matrice)[i] = calloc(cap, sizeof(int));
        nr_elem = 0;
        scanf("%d", &element);
        while (element) {
            if (nr_elem == cap) {
                cap += 3;
                (*matrice)[i] = realloc((*matrice)[i], cap * sizeof(int));
            }
            (*nr_elem_linie)[i]++;
            (*matrice)[i][nr_elem] = element;
            nr_elem++;
            scanf("%d", &element);
        }
    }
}


float medie_linie(int **matrice, int n, int linie, int nr_elem_linie[]) {
    int j;
    float suma;

    suma = 0;
    for (j = 0; j < nr_elem_linie[linie]; j++)
        suma += matrice[linie][j];
    return suma / nr_elem_linie[linie];
}

void sortare(int ***matrice, int nr_elem_linie[], int n) {
    int i, j, *interschimba = NULL, schimb_linii;

    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (medie_linie(*matrice, n, i, nr_elem_linie) >= medie_linie(*matrice, n, j, nr_elem_linie)) {
                interschimba = (*matrice)[i];
                (*matrice)[i] = (*matrice)[j];
                (*matrice)[j] = interschimba;
                schimb_linii = nr_elem_linie[i];
                nr_elem_linie[i] = nr_elem_linie[j];
                nr_elem_linie[j] = schimb_linii;
            }
}

void afisare(int **matrice, int n, int nr_elem_linie[]) {
    int i, j;

    for (i = n - 1; i >= 0; i--) {
        printf("%-10.3f", medie_linie(matrice, n, i, nr_elem_linie));
        for (j = 0; j < nr_elem_linie[i]; j++)
            printf("%d ", matrice[i][j]);
        printf("\n");
    }
}

void eliberare_memorie(int **matrice, int n, int *nr_elem_linie) {
    int i;

    for (i = 0; i < n; i++)
        free((matrice)[i]);
    free(matrice);
    free(nr_elem_linie);
}

int main() {
    int n, **matrice, *nr_elem_linie;

    citire(&matrice, &n, &nr_elem_linie);
    sortare(&matrice, nr_elem_linie, n);
    afisare(matrice, n, nr_elem_linie);
    eliberare_memorie(matrice, n, nr_elem_linie);
    return 0;
}
