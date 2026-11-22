#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const int DIAS = 7;

int main() {
    double ventas[DIAS] = { 12500.00, 10800.00, 15200.00, 11600.00, 18400.00, 22500.00, 13000.00 };
    string nombreDia[DIAS] = { "Lunes", "Martes", "Miércoles", "Jueves", "Viernes", "Sábado", "Domingo" };

    cout << "===== VENTAS DEL COLMADO DON PEPE =====" << endl << endl;

    double total = 0;
    for (int i = 0; i < DIAS; i++) {
        total += ventas[i];
    }

    cout << fixed << setprecision(2);
    for (int i = 0; i < DIAS; i++) {
        double porcentaje = (ventas[i] / total) * 100;
        cout << nombreDia[i] << ":  RD$ " << ventas[i] << "  →  " << porcentaje << "%" << endl;
    }

    double mayor = ventas[0];
    double menor = ventas[0];
    int posicionMayor = 0;
    int posicionMenor = 0;

    for (int i = 0; i < DIAS; i++) {
        if (ventas[i] > mayor) {
            mayor = ventas[i];
            posicionMayor = i;
        }
        if (ventas[i] < menor) {
            menor = ventas[i];
            posicionMenor = i;
        }
    }

    double promedio = total / DIAS;
    int contadorSobrePromedio = 0;
    string listaSobrePromedio = "";

    for (int i = 0; i < DIAS; i++) {
        if (ventas[i] > promedio) {
            contadorSobrePromedio++;
            if (contadorSobrePromedio == 1)
                listaSobrePromedio = nombreDia[i];
            else
                listaSobrePromedio = listaSobrePromedio + ", " + nombreDia[i];
        }
    }

    cout << endl << "----------------------------------------" << endl;
    cout << "Total semanal:      RD$ " << total << endl;
    cout << "Promedio diario:   RD$ " << promedio << endl;
    cout << "Mayor venta:       " << nombreDia[posicionMayor] << "  (RD$ " << mayor << ")" << endl;
    cout << "Menor venta:       " << nombreDia[posicionMenor] << "  (RD$ " << menor << ")" << endl;
    cout << "Días sobre el promedio:  " << contadorSobrePromedio << " ->  " << listaSobrePromedio << endl;

    cout << endl << "¡Gracias por usar el sistema de Don Pepe!" << endl;

    return 0;
}