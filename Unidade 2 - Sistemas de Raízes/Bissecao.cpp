#include <iostream>
#include <iomanip>
using namespace std;


double f(double x) {
    return pow(x, 3) - (9*x) + 3;
}

void Bissecao(double a, double b, double e, int iterMax) {
    double Fa = f(a);
    double Fb = f(b);

    if ((Fa * Fb) > 0) {
        cout << "Erro: funcao nao muda de sinal entre a e b." << endl;
        return;
    }

    double x;
    double Fx;
    double intervX = abs(b - a);
    int k = 0;
    while (true) {
        x = (a + b) / 2;
        Fx = f(x);
        cout << setw(4) << k << setw(12) << a << setw(12) << Fa
            << setw(12) << b << setw(12) << Fb << setw(12) << x
            << setw(12) << Fx << setw(16) << intervX << endl;

        if (intervX <= e || k >= iterMax)
            break;
        
        if ((Fa * Fx) > 0) {
            a = x;
            Fa = Fx;
        }
        else {
            b = x;
            Fb = Fx;
        }
        intervX = intervX / 2;
        k++;
    }

    cout << "\nRaiz: " << x << endl;
}

int main()
{
    cout << "Funcao: f(x) = x^3-9x+3" << endl;
    cout << "a = 0; b = 1;e = 0.001\n" << endl;

    cout << setw(4) << "k" << setw(12) << "a" << setw(12) << "Fa"
        << setw(12) << "b" << setw(12) << "Fb" << setw(12) << "x"
        << setw(12) << "Fx" << setw(16) << "intervX" << endl;

    Bissecao(0, 1, 0.001, 1000);

    return 0;
    
}
