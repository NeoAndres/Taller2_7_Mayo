#include <iostream>
#include <string>

using namespace std;

// Función para calcular el promedio de edad
float calcularPromedioEdad(float sumaEdad, int totalPersonas) {
    if (totalPersonas == 0)
        return 0.0;
    else
        return sumaEdad / totalPersonas;
}

// Procedimiento para mostrar el resumen del piso
void mostrarResumenPiso(int piso, int hombres, int mujeres, float promedioEdad) {
    cout << "Resumen del Piso " << piso << ":" << endl;
    cout << " - Total hombres: " << hombres << endl;
    cout << " - Total mujeres: " << mujeres << endl;
    cout << " - Edad promedio: " << promedioEdad << endl;
}

int main() {
    int pisos, aptosPorPiso, consumoPorApto, personasPorApto;
    int totalHombres, totalMujeres;
    int edad, mayorConsumo = 0;
    char genero;
    float promedioEdad, sumaEdad;

    cout << "Ingrese número de pisos: ";
    cin >> pisos;

    cout << "Ingrese número de apartamentos por piso: ";
    cin >> aptosPorPiso;

    cout << "Ingrese número de personas por apartamento: ";
    cin >> personasPorApto;

    for (int piso = 1; piso <= pisos; piso++) {
        totalHombres = 0;
        totalMujeres = 0;
        sumaEdad = 0.0;

        for (int apto = 1; apto <= aptosPorPiso; apto++) {
            cout << "Ingrese consumo de agua en litros para el apartamento " << apto << ": ";
            cin >> consumoPorApto;

            if (consumoPorApto > mayorConsumo) {
                mayorConsumo = consumoPorApto;
            }

            for (int persona = 1; persona <= personasPorApto; persona++) {
                cout << "Ingrese género de la persona (M/F): ";
                cin >> genero;

                cout << "Ingrese edad de la persona: ";
                cin >> edad;

                sumaEdad += edad;

                if (genero == 'M' || genero == 'm') {
                    totalHombres++;
                } else if (genero == 'F' || genero == 'f') {
                    totalMujeres++;
                }
            }
        }

        promedioEdad = calcularPromedioEdad(sumaEdad, aptosPorPiso * personasPorApto);
        mostrarResumenPiso(piso, totalHombres, totalMujeres, promedioEdad);
    }

    cout << "Mayor consumo de agua en litros en el edificio: " << mayorConsumo << endl;

    return 0;
}
