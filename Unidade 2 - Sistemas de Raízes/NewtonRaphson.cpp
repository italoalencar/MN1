#include <iostream>
#include <iomanip>

using namespace std;

double f(double x) {
    return pow(x, 3) - (9 * x) + 3;
}

double d(double x) {
    return (3 * pow(x, 2)) - 9;
}

void NewtonRaphson(double x0, double e1, double e2, double iterMax) {
    if (abs(f(x0)) < e1) {
        cout << "\nRaiz: " << x0 << endl;
        return;
    }

    cout << setw(4) << 0 << setw(12) << x0 << setw(12) << f(x0) << endl;
    double x1;
    double raiz;
    int k = 1;
    while (true) {
        x1 = x0 - (f(x0) / d(x0));
        cout << setw(4) << k << setw(12) << x1 << setw(12) << f(x1) << endl;
        if (abs(f(x1)) < e1 || abs(x1 - x0) < e2 || k >= iterMax) {
            raiz = x1;
            break;
        }
        x0 = x1;
        k++;
    }
    cout << "\nRaiz: " << raiz << endl;
}

int main()
{
    cout << "Funcao: f(x) = x^3-9x+3" << endl;
    cout << "Derivada: f'(x) = 3x^2-9" << endl;
    cout << "x0 = 0; e1 = e2 = 1;e = 0.0001\n" << endl;
    cout << setw(4) << "k" << setw(12) << "x1" << setw(12) << "f(x1)" << endl;
    NewtonRaphson(0.5, 0.0001, 0.0001, 1000);
    return 0;
}