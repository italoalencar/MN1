#include <iostream>
#include <vector>

using namespace std;

void printVector(const vector<double>& vec) {
	cout << "d = [ ";
	for (double val : vec) {
		cout << val << " ";
	}
	cout << "]" << endl;
}

double CalculaErro(int n, vector<double>& x, vector<double>& v) {
	double normaNum = 0;
	double normaDen = 0;

	double t;
	for (int i = 0; i < n; i++) {

		t = abs(v[i] - x[i]);
		if (t > normaNum) normaNum = t;
		if (abs(v[i]) > normaDen) normaDen = abs(v[i]);

		x[i] = v[i];
	};
	double erro = normaNum / normaDen;
	return erro;
}

void GaussJacobi(vector<vector<double>> A, vector<double> b, double e, int iterMax) {
	int n = static_cast<int>(A.size());
	vector<double> x(n, 0);

	// Construcao da Matriz e vetor de iteracoes
	for (int i = 0; i < n; i++) {
		double r = 1 / A[i][i];
		for (int j = 0; j < n; j++) {
			if (i != j)
				A[i][j] = A[i][j] * r;
		}
		b[i] = b[i] * r;
		//x[i] = b[i];
	}

	cout << "\nX inicial:" << endl;
	printVector(x);

	// Iterações de Jacobi
	int k = 0;
	vector<double> v(n, 0);
	while (true) {
		k++;
		for (int i = 0; i < n; i++) {
			double soma = 0;
			for (int j = 0; j < n; j++) {
				if (i != j) {
					soma = soma + A[i][j] * x[j];
				}
			}
			v[i] = b[i] - soma;
		}
		double erroRelativo = CalculaErro(n, x, v);
		cout << "iteracao: " << k << endl;
		printVector(x);
		if (erroRelativo <= e || k >= iterMax)
			break;
	}
}

int main()
{
	vector<vector<double>> A = { { 10, 2, 2, }, { 1, 10, 2 }, { 2, -7, -10 } };
	vector<double> b = { 28, 7, -17 };
	GaussJacobi(A, b, 0.5, 1000);
	return 0;
}