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

void GaussJordan(vector<vector<double>> A, vector<double> b) {
    int n = static_cast<int>(b.size());

    for (int k = 0; k < n; k++) {
        for (int j = k + 1; j < n; j++) {
            A[k][j] = A[k][j] / A[k][k];
        }
        b[k] = b[k] / A[k][k];
        A[k][k] = 1;
        for (int i = 0; i < n; i++) {
            if (i != k) {
                for (int j = k + 1; j < n; j++) {
                    A[i][j] = A[i][j] - A[i][k] * A[k][j];
                }
                b[i] = b[i] - A[i][k] * b[k];
                A[i][k] = 0;
            }
        }
    }
    printVector(b);

}

int main()
{
    vector<vector<double>> A = { { 3, 2, 4 }, { 1, 1, 2 }, { 4, 3, -2 } };
    vector<double> b = { 1, 2, 3 };
    GaussJordan(A, b);
}