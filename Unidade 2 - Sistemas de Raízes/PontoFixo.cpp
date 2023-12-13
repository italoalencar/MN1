#include <iostream>
# include <iomanip>

using namespace std;

double f(double x) {
    return pow(x, 3) - (9 * x) + 3;
}

double phi(double x) {
    double left = pow(x, 3) / 9;
    double right = 1.0 / 3;
    return left + right;
}

void PontoFixo(double x0, double e1, double e2, int iterMax) {
    if (abs(f(x0)) < e1) {
        cout << "\nRaiz: " << x0 << endl;
        return;
    }

    double x1;
    int k = 1;
    while (true) {
        x1 = phi(x0);
        cout << setw(4) << k << setw(12) << x1 << setw(12) << x0 << setw(12) << (x1 - x0) << setw(12) << f(x1) << endl;
        if (abs(f(x1)) < e1 || abs(x1 - x0) < e2 || k >= iterMax) {
            cout << "\nRaiz: " << x1 << endl;
            return;
        }
        x0 = x1;
        k++;
    }
}

int main()
{
    cout << "Funcao: f(x) = x^3-9x+3; phi(x) = (x^3/9) + 1/3" << endl;
    cout << "x0 = 0.5; e1 = e2 = 1;e1 = e2 = 0.0005\n" << endl;
    cout << setw(4) << "k" << setw(12) << "x1" << setw(12) << "x0" << setw(12) << "(x1-x0)" << setw(12) << "f(x1)" << endl;
    PontoFixo(0.5, 0.0005, 0.0005, 1000);
    return 0;
}