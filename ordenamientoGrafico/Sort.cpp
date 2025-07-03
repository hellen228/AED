#include "Sort.h"
#include <algorithm> 

/*MERGESORT*/
void merge(int* arr, int inicio, int medio, int fin) {
    int n1 = medio - inicio + 1;
    int n2 = fin - medio;
    int* L = new int[n1];
    int* R = new int[n2];

    for (int i = 0; i < n1; ++i)
        L[i] = arr[inicio + i];
    for (int j = 0; j < n2; ++j)
        R[j] = arr[medio + 1 + j];

    int i = 0, j = 0, k = inicio;
    while (i < n1 && j < n2)
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];

    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];

    delete[] L;
    delete[] R;
}

void mergeSort(int* arr, int inicio, int fin) {
    if (inicio < fin) {
        int medio = inicio + (fin - inicio) / 2;
        mergeSort(arr, inicio, medio);
        mergeSort(arr, medio + 1, fin);
        merge(arr, inicio, medio, fin);
    }
}

/*QUICKSORT*/
int particion(int* arr, int inicio, int fin) {
    int pivote = arr[fin];
    int i = inicio - 1;

    for (int j = inicio; j < fin; ++j) {
        if (arr[j] < pivote) {
            ++i;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[fin]);
    return i + 1;
}

void quickSort(int* arr, int inicio, int fin) {
    if (inicio < fin) {
        int pi = particion(arr, inicio, fin);
        quickSort(arr, inicio, pi - 1);
        quickSort(arr, pi + 1, fin);
    }
}

/*BUBBLESORT*/
void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool ordenado = true;
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                ordenado = false;
            }
        }
        if (ordenado) break;
    }
}

/*SELECTIOSORT*/
void selectionSort(int* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        std::swap(arr[i], arr[minIndex]);
    }
}

/*INSERTIONSORT*/
void insertionSort(int* arr, int n) {
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }

        arr[j + 1] = key;
    }
}

/*SHELLSORT*/
void shellSort(int* arr, int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp) {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}

/*COCKTAILSORT*/
void cocktailSort(int* arr, int n) {
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; ++i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        if (!swapped) break;

        --end;
        swapped = false;

        for (int i = end - 1; i >= start; --i) {
            if (arr[i] > arr[i + 1]) {
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
            }
        }

        ++start;
    }
}
