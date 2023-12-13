#include <iostream>
#include <vector>

using namespace std;

void Polinomios(vector<double> a, double x, double e1, double e2, int iterMax) {
    int n = static_cast<int>(a.size()) - 1;
    double deltax = x;
    double b;
    double c;
    int k = 0;
    while (k < iterMax) {
        b = a[n];
        c = b;
        for (int i = n - 1; i > 0; i--) {
            b = a[i] + (b * x);
            c = b + (c * x);
        }

        b = a[0] + (b * x);
        if (abs(b) < e1) {
            cout << "\nRaiz: " << x << endl;
            return;
        }

        deltax = b / c;
        x = x - deltax;
        if (abs(deltax) < e2) {
            cout << "\nRaiz: " << x << endl;
            return;
        }
    }
    cout << "\nRaiz: " << x << endl;
    cout << "Erro: algoritmo nao convergiu apos " << iterMax << " iteracoes." << endl;
}

int main()
{
    cout << "Funcao: f(x) = x^3-9x+3" << endl;
    cout << "x0 = 0.5; e1 = e2 = 1;e = 0.0001\n" << endl;
    cout << "a = [1, 0, -9, 3]";
    vector<double> a = { 3, -9, 0, 1 };
    Polinomios(a, 0.5, 0.0001, 0.0001, 1000);

    return 0;
}