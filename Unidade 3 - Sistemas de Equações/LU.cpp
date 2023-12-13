#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void printVector(const vector<double>& vec) {
    cout << " vetor = [ ";
    for (double val : vec) {
        cout << fixed << setprecision(4) << val << " ";
    }
    cout << "]" << endl;
}

void printMatrix(const vector<vector<double>>& mat) {
    for (const auto& row : mat) {
        for (double val : row) {
            cout << fixed << setprecision(4) << setw(8) << val;
        }
        cout << endl;
    }
}

void LU(vector<vector<double>> A, vector<double> b) {
    int n = static_cast<int>(A.size());

    vector<vector<double>> L(n, vector<double>(n, 0.0));
    vector<vector<double>> U = A;

    // Matriz identidade
    for (int i = 0; i < n; i++) {
        L[i][i] = 1.0;
    }

    // Fatoração LU
    for (int i = 0; i < n; i++) {
        for (int k = i + 1; k < n; k++) {
            double fator = U[k][i] / U[i][i];
            L[k][i] = fator;
            for (int j = i; j < n; j++) {
                U[k][j] -= fator * U[i][j];
            }
        }
    }

    cout << "Matriz L:" << endl;
    printMatrix(L);

    cout << "\nMatriz U:" << endl;
    printMatrix(U);

    // Ly = b
    vector<double> y(n, 0.0);
    for (int i = 0; i < n; i++) {
        y[i] = b[i];
        for (int j = 0; j < i; j++) {
            y[i] -= L[i][j] * y[j];
        }
    }

    cout << "\nVetor y:" << endl;
    printVector(y);

    // Ux = y
    vector<double> x(n, 0.0);
    for (int i = n - 1; i >= 0; i--) {
        x[i] = y[i];
        for (int j = i + 1; j < n; j++) {
            x[i] -= U[i][j] * x[j];
        }
        x[i] /= U[i][i];
    }

    cout << "\nVetor x:" << endl;
    printVector(x);
}


int main()
{
    vector<vector<double>> A = { { 3, 2, 4 }, { 1, 1, 2 }, { 4, 3, -2 } };
    vector<double> b = { 1, 2, 3 };
    LU(A, b);
    return 0;
}
