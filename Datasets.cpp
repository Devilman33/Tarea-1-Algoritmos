#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int T = 1500000;

vector<int> generateRandomArray(int size) {
    vector<int> arr(size);
    srand(time(0));
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % T;  // Genera números aleatorios entre 0 y 999999
    return arr;
}

vector<int> Semi_Random_Array(int size) {
    vector<int> arr(size);
    int mid = size / 2;

    // Primera mitad: Números ordenados
    for (int i = 0; i < mid; ++i) {
        arr[i] = i + 1;  // Generar números en orden ascendente
    }

    // Segunda mitad: Números aleatorios
    srand(time(0));  // Semilla para generar números aleatorios
    for (int i = mid; i < size; ++i) {
        arr[i] = rand() % T;  // Genera números aleatorios entre 0 y 99
    }

    return arr;
}

void saveArrayToFile(const vector<int>& arr, const string& filename) {
    ofstream outFile(filename);
    if (outFile.is_open()) {
        for (int num : arr) {
            outFile << num << " ";
        }
        outFile.close();
        cout << "Dataset guardado en " << filename << endl;
    } else {
        cout << "Error al abrir el archivo." << endl;
    }
}

int main() {
    int size = T;  // Tamaño del dataset
    vector<int> arr = generateRandomArray(size);
    vector<int> arr2 = Semi_Random_Array(size);
    saveArrayToFile(arr, "d_desordenado_1500000.txt");
    saveArrayToFile(arr2, "d_semi_ordenado_1500000.txt");
    return 0;
}
