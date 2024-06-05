#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Cette fonction échange deux entiers
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Il s'agit d'un algorithme de tri par sélection modifié. Il recherche le nombre maximum d'éléments dans le tableau et ses occurrences,
//puis place ces éléments au début du tableau ce qui donne un tri decroissant
void proposedSelectionSort(int A[], int n) {
    int Queue[n];
    int i = 0;

    while (i < n - 1) {
        int Rear = 0;
        int Max = A[i];
        Queue[Rear] = i;

        int j = i + 1;
        while (j < n) {
            if (Max < A[j]) {
                Max = A[j];
                Rear = 0;
                Queue[Rear] = j;
            } else if (Max == A[j]) {
                Rear = Rear + 1;
                Queue[Rear] = j;
            }
            j++;
        }

        int Front = 0;
        while (Front <= Rear) {
            swap(&A[i], &A[Queue[Front]]);
            i++;
            Front++;
        }
    }
}

//Il s’agit de l’algorithme de tri par sélection traditionnel.
//Il recherche à plusieurs reprises l'élément minimum de la partie non triée et l'échange avec le premier élément non trié.
void selectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n - 1; i++) {
        min_idx = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

//Cette fonction remplit un tableau avec des nombres aléatoires compris entre 0 et 1 000.
void fillArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1001;
    }
}

//Cette fonction affiche les éléments d'un tableau.
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n\n\n");
}

//Cette fonction teste à la fois les algorithmes de tri par sélection proposés et classiques sur des tableaux de différentes tailles.
//Il mesure et imprime le temps pris par chaque algorithme.
void testAlgorithms(int sizes[], int num_sizes) {
    for (int i = 0; i < num_sizes; i++) {
        int size = sizes[i];
        int *arr1 = (int *)malloc(size * sizeof(int));
        int *arr2 = (int *)malloc(size * sizeof(int));

        fillArray(arr1, size);
        for (int j = 0; j < size; j++) {
            arr2[j] = arr1[j];
        }

        printf("Tableau de taille: %d non trier\n", size);
        printf("\n");
        printArray(arr1, size);

        clock_t start, end;
        double cpu_time_used;

        // Testing Proposed Selection Sort
        start = clock();
        proposedSelectionSort(arr1, size);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Tri du tableau de taille: %d de fonhction decroissant a pris %f seconds pour etre trier\n", size, cpu_time_used);
        printf("\n");
        printArray(arr1, size);


        start = clock();
        selectionSort(arr2, size);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        printf("Tri du tableau de taille: %d de fonhction croissant a pris %f seconds pour etre trier\n", size, cpu_time_used);
        printf("\n");
        printArray(arr2, size);

        free(arr1);
        free(arr2);
    }
}
//La fonction principale initialise le générateur de nombres aléatoires,
//définit la taille des tableaux et appelle la fonction de test.
int main() {
    srand(time(0));

    int sizes[] = {100, 200, 400, 600, 800, 1000};
    int num_sizes = sizeof(sizes) / sizeof(sizes[0]);

    testAlgorithms(sizes, num_sizes);

    return 0;
}
