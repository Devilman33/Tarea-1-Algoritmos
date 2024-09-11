#include <iostream>
#include <fstream>
#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

// Función para leer datos desde un archivo
vector<int> readArrayFromFile(const string& filename) {
    ifstream inFile(filename);
    vector<int> arr;
    int num;
    
    if (inFile.is_open()) {
        while (inFile >> num) {
            arr.push_back(num);  // Carga los números en el vector
        }
        inFile.close();
        cout << "Datos leídos desde " << filename << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
    
    return arr;
}

// Función de partición para Quicksort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Algoritmo de Quicksort
void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Función de merge para Mergesort
void merge(vector<int>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;
    vector<int> L(n1), R(n2);

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int i = 0; i < n2; i++) R[i] = arr[m + 1 + i];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

// Funcion de MergeSort
void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
}

// Funcion de SelectionSort
void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }
        swap(arr[i], arr[minIdx]);
    }
}

//Funcion de sort estandar de c++
void sortestandar(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

int main() {
    // Leer el dataset desde un archivo
    vector<int> arr = readArrayFromFile("d_desordenado_50000.txt");

    // Medir el tiempo de ejecución de Quicksort
    auto start = chrono::high_resolution_clock::now();
    
    sortestandar(arr);
    
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    
    // Imprimir el tiempo de ejecución
    cout << "Tiempo de ejecución de Quicksort: " << duration.count() << " ms" << endl;
    
    return 0;
}