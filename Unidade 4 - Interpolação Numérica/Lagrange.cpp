#include <iostream>
#include <vector>

using namespace std;

double Lagrange(double x, vector<double> xi, vector<double> yi) {
    int n = static_cast<int>(xi.size());

    double Px = 0;
    for (int k = 0; k < n; k++) {
        double Lk = 1;
        for (int j = 0; j < n; j++) {
            if (j != k)
                Lk = Lk * ((x - xi[j]) / (xi[k] - xi[j]));
        }
        Px = Px + yi[k] * Lk;
    }
    return Px;
}

int main()
{  
    vector<double> xi = { 0.1, 0.6, 0.8 };
    vector<double> yi = { 1.221, 3.320, 4.953 };
    double Px = Lagrange(0.2, xi, yi);
    cout << "P(0.2)  = " << Px << endl;
    return 0;
}