#include <iostream>
using namespace std;

// Funcion para calcular el factorial
int factorial(int num) {
    int resultado = 1;
    for (int i = 1; i <= num; i++) {
        resultado = i;
    }
    return resultado;
}

// Funcion para calcular la potencia
double potencia(double base, int exponente) {
    double resultado = 1;
    for (int i = 0; i < exponente; i++) {
        resultado= base;
    }
    return resultado;
}

int main() {
    int n;
    cout << "Ingrese el valor de n (mayor que 0): ";
    cin >> n;

    if (n <= 0) {
        cout << "n debe ser mayor que 0." << endl;
        return 1;
    }

    double suma = 0;
    for (int i = 0; i < n; i++) {
        double x;
        cout << "Ingrese el valor de X[" << i << "]: ";
        cin >> x;

        int exponente = 2 * i + 1;
        double numerador = potencia(x, exponente);
        int denom = factorial(exponente);  // Usamos int en lugar de long long
        suma += numerador / denom;
    }

    cout << "Resultado de la sumatoria: " << suma << endl;

    return 0;
}