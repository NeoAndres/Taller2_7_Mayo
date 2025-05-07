
/*
===============================================================================
    PROGRAMA: CALCULADORA DE INTERESES BANCARIOS EN COLOMBIA
===============================================================================

DESCRIPCION:
Este programa permite al usuario simular el rendimiento de una inversion 
bancaria en Colombia, calculando los intereses generados con base en la tasa 
mensual ofrecida por distintas entidades financieras del pais.

FUNCIONALIDADES:
- El usuario puede seleccionar entre varios bancos colombianos con tasas reales
  aproximadas de interes mensual.
- Se solicita al usuario ingresar el monto a invertir y el plazo de inversion
  en meses.
- El sistema calcula el interes simple generado y muestra el total acumulado 
  al final del periodo.
- Adicionalmente, se imprime una simulacion del crecimiento mes a mes de la 
  inversion.
- El usuario puede realizar multiples simulaciones si asi lo desea.

ESTRUCTURAS USADAS:
- Menu interactivo con estructura `do-while`.
- Validaciones con condicionales `if`.
- Seleccion de banco mediante estructura `switch`.
- Simulacion del crecimiento mensual utilizando `for`.

OBJETIVO:
Facilitar al usuario una herramienta educativa y practica para comprender 
como crece una inversion en un banco colombiano, fomentando la cultura 
financiera y el aprendizaje de conceptos basicos de programacion.

AUTOR: Andres Barrera Ayala - Juanjo '-'
FECHA: Mayo de 2025
===============================================================================
*/

#include <iostream>
#include <iomanip>
using namespace std;

// Funcion para calcular el interes simple
double calcularInteres(double monto, double tasa, int meses) {
    return monto * (tasa / 100) * meses;
}

int main() {
    int banco, meses;
    double monto, tasa, interes, total;
    char continuar;

    do {
        cout << "==== CALCULADORA DE INTERESES BANCARIOS (COLOMBIA) ====" << endl;
        cout << "Seleccione un banco:" << endl;
        cout << "1. Banco de Bogota (tasa 1.2% mensual)" << endl;
        cout << "2. Bancolombia (tasa 1.1% mensual)" << endl;
        cout << "3. Davivienda (tasa 1.3% mensual)" << endl;
        cout << "4. Banco Agrario (tasa 1.0% mensual)" << endl;
        cout << "5. BBVA Colombia (tasa 1.15% mensual)" << endl;
        cout << "Ingrese su opcion (1-5): ";
        cin >> banco;

        if (banco < 1 || banco > 5) {
            cout << "Banco no valido. Intente de nuevo.\n" << endl;
            continue;
        }

        cout << "Ingrese el monto a invertir (COP): ";
        cin >> monto;

        if (monto <= 0) {
            cout << "El monto debe ser mayor que cero.\n" << endl;
            continue;
        }

        cout << "Ingrese el tiempo de inversion (en meses): ";
        cin >> meses;

        if (meses <= 0) {
            cout << "El tiempo debe ser mayor que cero.\n" << endl;
            continue;
        }

        // Asignar tasa
        switch (banco) {
            case 1: tasa = 1.2; break;
            case 2: tasa = 1.1; break;
            case 3: tasa = 1.3; break;
            case 4: tasa = 1.0; break;
            case 5: tasa = 1.15; break;
        }

        // Usar el subprograma para calcular el interes
        interes = calcularInteres(monto, tasa, meses);
        total = monto + interes;

        cout << fixed << setprecision(2);
        cout << "\n==== RESULTADOS ====" << endl;
        cout << "Monto invertido: $" << monto << " COP" << endl;
        cout << "Tiempo: " << meses << " meses" << endl;
        cout << "Tasa mensual: " << tasa << "%" << endl;
        cout << "Interes generado: $" << interes << " COP" << endl;
        cout << "Total al finalizar: $" << total << " COP" << endl;

        cout << "\nCrecimiento mensual:" << endl;
        for (int i = 1; i <= meses; i++) {
            double parcial = monto + calcularInteres(monto, tasa, i);
            cout << "Mes " << i << ": $" << parcial << " COP" << endl;
        }

        cout << "\nDesea realizar otro calculo? (s/n): ";
        cin >> continuar;

        cout << "\n------------------------------------------\n";

    } while (continuar == 's' || continuar == 'S');

    cout << "Gracias por usar la calculadora. Hasta pronto!" << endl;
    return 0;
}

