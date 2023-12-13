#include <iostream>

using namespace std;

double InterpolacaoLinear(double x, double x0, double x1, double Fx0, double Fx1) {
    double Px = Fx0 + ((Fx1 - Fx0) / (x1 - x0)) * (x - x0);
    return Px;
}

int main()
{
    double Px = InterpolacaoLinear(0.2, 0.1, 0.6, 1.221, 3.320);
    cout << "F(0.2) = " << Px << endl;
    return 0;
}
