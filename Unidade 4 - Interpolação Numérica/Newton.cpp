#include <iostream>
#include <vector>

using namespace std;


double Ordem(vector<double> xi, vector<double> yi, int k) {
    if (k == 0) {
        return yi[0];
    }

    return (Ordem(xi, yi, k-1) - Ordem(xi, yi, k - 1)) / (xi[k] - xi[0]);
}

double Newton(double x, vector<double> xi, vector<double> yi) {
    int n = static_cast<int>(xi.size());
    double Px = 0.0;

    for (int i = 0; i < n; i++) {
        double ordem = Ordem(xi, yi, i);
        for (int j = 0; j < i; j++) {
            ordem *= (x - xi[j]);
        }
        Px += ordem;
    }
    return Px;
}

int main() {
    vector<double> xi = { 0.1, 0.6, 0.8 };
    vector<double> yi = { 1.221, 3.320, 4.953 };
    double Px = Newton(0.2, xi, yi);
    cout << "P(0.2)  = " << Px << endl;
    return 0;
}