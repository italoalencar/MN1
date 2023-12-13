#include <iostream>
#include <iomanip>

using namespace std;

double f(double x) {
    return pow(x, 3) - (9 * x) + 3;
}

void Secante(double x0, double x1, double e1, double e2, int iterMax) {
    if (abs(f(x0)) < e1) {
        cout << "\nRaiz: " << x0 << endl;
        return;
    }

    if (abs(f(x1)) < e1 || abs(x1 - x0) < e2) {
        cout << "\nRaiz: " << x1 << endl;
        return;
    }

    double raiz;
    double x2;
    int k = 1;
    while (true) {
        x2 = x1 - (f(x1) / (f(x1) - f(x0))) * (x1 - x0);
        cout << setw(4) << k << setw(12) << x2 << setw(12) << f(x2) << endl;

        if (abs(f(x2)) < e1 || abs(x1 - x0) < e2 || k >= iterMax) {
            raiz = x2;
            break;
        }

        x0 = x1;
        x1 = x2;
        k++;
    }
    cout << "\nRaiz: " << raiz << endl;
}

int main()
{
    cout << "Funcao: f(x) = x^3-9x+3" << endl;
    cout << "x0 = 0; x1 = 1; e1 = e2 =  0.0005\n" << endl;
    cout << setw(4) << "k" << setw(12) << "x2" << setw(12) << "f(x2)" << endl;
    Secante(0, 1, 0.0005, 0.0005, 1000);
    return 0;
}