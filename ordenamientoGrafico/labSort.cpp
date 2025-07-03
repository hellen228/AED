#include <iostream>
#include <stdio.h>
#include <random>
#include <chrono>
#include <algorithm>
#include "Sort.h"

using namespace std;
using namespace std::chrono;

int main() {
    const int cantidad = 150000;
    const int paso = 1000;

    int* vectorOriginal = new int[cantidad];
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(1, 1000);

    for (int i = 0; i < cantidad; ++i)
        vectorOriginal[i] = distrib(gen);

    FILE* csv = fopen("tiempos.csv", "w");
    if (!csv) {
        cerr << "No se pudo crear el archivo.\n";
        return 1;
    }
    fprintf(csv, "CantidadDatos,MergeSort,QuickSort,BubbleSort,SelectionSort,InsertionSort,ShellSort,CocktailSort\n");

    for (int n = paso; n <= cantidad; n += paso) {
        int* copiaMerge = new int[n];
        int* copiaQuick = new int[n];
        int* copiaBubble = new int[n];
        int* copiaSelection = new int[n];
        int* copiaInsertion = new int[n];
        int* copiaShell = new int[n];
        int* copiaCocktail = new int[n];
        copy(vectorOriginal, vectorOriginal + n, copiaMerge);
        copy(vectorOriginal, vectorOriginal + n, copiaQuick);
        copy(vectorOriginal, vectorOriginal + n, copiaBubble);
        copy(vectorOriginal, vectorOriginal + n, copiaSelection);
        copy(vectorOriginal, vectorOriginal + n, copiaInsertion);
        copy(vectorOriginal, vectorOriginal + n, copiaShell);
        copy(vectorOriginal, vectorOriginal + n, copiaCocktail);

        auto inicioMerge = high_resolution_clock::now();
        mergeSort(copiaMerge, 0, n - 1);
        auto finMerge = high_resolution_clock::now();
        auto duracionMerge = duration_cast<milliseconds>(finMerge - inicioMerge).count();

        auto inicioQuick = high_resolution_clock::now();
        quickSort(copiaQuick, 0, n - 1);
        auto finQuick = high_resolution_clock::now();
        auto duracionQuick = duration_cast<milliseconds>(finQuick - inicioQuick).count();

        auto inicioBubble = high_resolution_clock::now();
        bubbleSort(copiaBubble, n);
        auto finBubble = high_resolution_clock::now();
        auto duracionBubble = duration_cast<milliseconds>(finBubble - inicioBubble).count();

        auto inicioSelection = high_resolution_clock::now();
        selectionSort(copiaSelection, n);
        auto finSelection = high_resolution_clock::now();
        auto duracionSelection = duration_cast<milliseconds>(finSelection - inicioSelection).count();

        auto inicioInsertion = high_resolution_clock::now();
        insertionSort(copiaInsertion, n);
        auto finInsertion = high_resolution_clock::now();
        auto duracionInsertion = duration_cast<milliseconds>(finInsertion - inicioInsertion).count();

        auto inicioShell = high_resolution_clock::now();
        shellSort(copiaShell, n);
        auto finShell = high_resolution_clock::now();
        auto duracionShell = duration_cast<milliseconds>(finShell - inicioShell).count();

        auto inicioCocktail = high_resolution_clock::now();
        cocktailSort(copiaCocktail, n);
        auto finCocktail = high_resolution_clock::now();
        auto duracionCocktail = duration_cast<milliseconds>(finCocktail - inicioCocktail).count();

        fprintf(csv, "%d,%ld,%ld,%ld,%ld,%ld,%ld,%ld\n", n, duracionMerge, duracionQuick, duracionBubble, duracionSelection, duracionInsertion, duracionShell, duracionCocktail);

        printf("N = %d → Merge: %ld ms | Quick: %ld ms | Bubble: %ld ms | Selection: %ld ms | Insertion: %ld ms | Shell: %ld ms | Cocktail: %ld ms\n",
        n, duracionMerge, duracionQuick, duracionBubble, duracionSelection, duracionInsertion, duracionShell, duracionCocktail);

        if (n == cantidad) {
            FILE* salida = fopen("vector_ordenado_merge.txt", "w");
            for (int i = 0; i < cantidad; ++i)
                fprintf(salida, "%d\n", copiaMerge[i]);
            fclose(salida);
        }

        delete[] copiaMerge;
        delete[] copiaQuick;
        delete[] copiaBubble;
        delete[] copiaSelection;
        delete[] copiaInsertion;
        delete[] copiaShell;
        delete[] copiaCocktail;
    }

    fclose(csv);
    delete[] vectorOriginal;

    return 0;
}
