#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void printVector(const vector<double>& vec) {
    cout << "x = [ ";
    for (double val : vec) {
        cout << fixed << setprecision(4) << val << " ";
    }
    cout << "]" << endl;
}

void GaussComPivo(vector<vector<double>> A, vector<double> b) {
    int n = static_cast<int>(A.size());

    for (int i = 0; i < n; i++) {
        int indiceMax = i;
        for (int k = i + 1; k < n; k++) {
            if (abs(A[k][i]) > abs(A[indiceMax][i]))
                indiceMax = k;        
        }

        swap(A[i], A[indiceMax]);
        swap(b[i], b[indiceMax]);

        // Eliminação
        for (int k = i + 1; k < n; k++) {
            double fator = A[k][i] / A[i][i];
            for (int j = i; j < n; j++) {
                A[k][j] -= fator * A[i][j];
            }
            b[k] -= fator * b[i];
        }
    }

    // Substituição
    for (int i = n - 1; i >= 0; i--) {
        for (int j = i + 1; j < n; j++) {
            b[i] -= A[i][j] * b[j];
        }
        b[i] /= A[i][i];
    }

    printVector(b);
}

int main() {
    vector<vector<double>> A = { { 3, 2, 4 }, { 1, 1, 2 }, { 4, 3, -2 } };
    vector<double> b = { 1, 2, 3 };
    GaussComPivo(A, b);
    return 0;
}