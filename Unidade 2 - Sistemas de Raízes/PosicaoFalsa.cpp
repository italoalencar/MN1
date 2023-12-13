#include <iostream>
#include <iomanip>

using namespace std;

double f(double x) {
    return pow(x, 3) - (9 * x) + 3;
}

double escolha(double a, double b) {
    return (a + b) / 2;
}

void PosicaoFalsa(double a, double b, double e1, double e2, int iterMax) {
    double Fa = f(a);
    double Fb = f(b);

    if ((Fa * Fb) > 0) {
        cout << "Erro: funcao nao muda de sinal entre a e b.";
        return;
    }

    double raiz;
    double intervX = abs(b - a);
    if (intervX < e1) {
        raiz = escolha(a, b);
        cout << "Raiz: " << raiz << endl;
        return;
    }
        
    if (abs(Fa) < e2) {
        raiz = a;
        cout << "Raiz: " << raiz << endl;
        return;
    }
        
    if (abs(Fb) < e2) {
        raiz = b;
        cout << "Raiz: " << raiz << endl;
    }
        
    

    double x;
    double Fx;
    int k = 0;
    while (true) {
        x = (a * Fb - b * Fa) / (Fb - Fa);
        Fx = f(x);
        cout << setw(4) << k << setw(12) << a << setw(12) << Fa
            << setw(12) << b << setw(12) << Fb << setw(12) << x
            << setw(12) << Fx << setw(16) << intervX << endl;

        if (abs(f(x)) < e2 || k >= iterMax) {
            raiz = x;
            break;
        }
        if ((Fa * Fx) > 0) {
            a = x;
            Fa = Fx;
        }
        else {
            b = x;
            Fb = Fx;
        }
        intervX = abs(b - a);
        if (intervX <= e1) {
            raiz = escolha(a, b);
            break;
        }              
        k++;
    }

    cout << "Raiz: " << raiz << endl;
}

int main()
{
    cout << "Funcao: f(x) = x^3-9x+3" << endl;
    cout << "a = 0; b = 1; e1 = e2 = 0.0005\n" << endl;

    cout << setw(4) << "k" << setw(12) << "a" << setw(12) << "Fa"
        << setw(12) << "b" << setw(12) << "Fb" << setw(12) << "x"
        << setw(12) << "Fx" << setw(16) << "intervX" << endl;

    PosicaoFalsa(0, 1, 0.0005, 0.0005, 1000);

    return 0;
}

