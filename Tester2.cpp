#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>

using namespace std;

// Función para leer matrices desde archivo
vector<vector<int>> readMatrixFromFile(const string& filename) {
    ifstream inFile(filename);
    vector<vector<int>> matrix;
    int n;

    if (inFile.is_open()) {
        inFile >> n;
        matrix.resize(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                inFile >> matrix[i][j];
        
        inFile.close();
    }
    return matrix;
}

// Multiplicación cúbica tradicional
void matrixMultiply(const vector<vector<int>>& A, const vector<vector<int>>& B, vector<vector<int>>& C, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k)
                C[i][j] += A[i][k] * B[k][j];
        }
}

// Multiplicación optimizada con transposición
void transposeMatrix(vector<vector<int>>& B, int n) {
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            swap(B[i][j], B[j][i]);
}

void matrixMultiplyOptimized(const vector<vector<int>>& A, vector<vector<int>>& B, vector<vector<int>>& C, int n) {
    transposeMatrix(B, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < n; ++k)
                C[i][j] += A[i][k] * B[j][k];
        }
}

int main() {
    // Leer las matrices desde archivos
    vector<vector<int>> A = readMatrixFromFile("1matrix900.txt");
    vector<vector<int>> B = readMatrixFromFile("2matrix900.txt");
    
    int n = A.size();
    vector<vector<int>> C(n, vector<int>(n));

    // Medir tiempo de ejecución de la multiplicación cúbica tradicional
    auto start = chrono::high_resolution_clock::now();
    
    matrixMultiply(A, B, C, n);
    
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    
    cout << "Tiempo de ejecución (cúbica tradicional): " << duration.count() << " ms" << endl;

    // Medir tiempo de ejecución de la multiplicación optimizada
    start = chrono::high_resolution_clock::now();
    
    matrixMultiplyOptimized(A, B, C, n);
    
    stop = chrono::high_resolution_clock::now();
    duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    
    cout << "Tiempo de ejecución (optimizada): " << duration.count() << " ms" << endl;

    return 0;
}
