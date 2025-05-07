#include <iostream>
#include <string>
using namespace std;

// Función para calcular el porcentaje de reclusos entre 18 y 25 años
double calcularPorcentaje(int cantidad, int total) {
    if (total == 0) return 0.0;
    return (static_cast<double>(cantidad) * 100) / total;
}

// Procedimiento para mostrar los resultados
void mostrarResultados(int totalHurto, int sumaEdadHurto, int totalReclusos, int totalEdad18a25, string nombreMayorEdad, int edadMayor) {
    if (totalHurto > 0) {
        double promedioHurto = static_cast<double>(sumaEdadHurto) / totalHurto;
        cout << "Promedio de edad por hurto: " << promedioHurto << endl;
    } else {
        cout << "No hay reclusos por hurto." << endl;
    }

    if (totalReclusos > 0) {
        double porcentaje = calcularPorcentaje(totalEdad18a25, totalReclusos);
        cout << "Porcentaje de reclusos entre 18 y 25 años: " << porcentaje << "%" << endl;
    } else {
        cout << "No se ingresaron reclusos." << endl;
    }

    if (edadMayor != -1) {
        cout << "Recluso con mayor edad y condenado entre 1 y 5 años: " << nombreMayorEdad << endl;
    } else {
        cout << "No hay reclusos con condena entre 1 y 5 años." << endl;
    }
}

int main() {
    string nombre, nombreMayorEdad = "", delito, respuesta;
    int edad, condena;
    int totalHurto = 0, sumaEdadHurto = 0;
    int totalReclusos = 0, totalEdad18a25 = 0;
    int edadMayor = -1;

    do {
        cout << "Ingrese nombre del recluso: ";
        getline(cin, nombre);

        cout << "Ingrese edad del recluso: ";
        cin >> edad;

        cout << "Ingrese delito (ej: hurto, homicidio, etc): ";
        cin.ignore();
        getline(cin, delito);

        cout << "Ingrese años de condena: ";
        cin >> condena;
        cin.ignore();

        totalReclusos++;

        if (delito == "hurto") {
            totalHurto++;
            sumaEdadHurto += edad;
        }

        if (edad >= 18 && edad <= 25) {
            totalEdad18a25++;
        }

        if (condena >= 1 && condena <= 5) {
            if (edad > edadMayor) {
                edadMayor = edad;
                nombreMayorEdad = nombre;
            }
        }

        cout << "¿Desea ingresar otro recluso? (S/N): ";
        getline(cin, respuesta);

    } while (respuesta != "N" && respuesta != "n");

    // Llamada al procedimiento para mostrar resultados
    mostrarResultados(totalHurto, sumaEdadHurto, totalReclusos, totalEdad18a25, nombreMayorEdad, edadMayor);

    return 0;
}
