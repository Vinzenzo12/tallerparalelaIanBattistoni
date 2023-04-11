#include <iostream>
#include <vector>
#include <complex>
#include <cmath>
using namespace std;
//integrantes : Luz Arely Castro, Vicente Velasquez, Ian Battistoni
// Función para encontrar las raíces de un polinomio de segundo grado
vector<complex<double>> encontrarRaicesPolinomio(double a, double b, double c) {
    vector<complex<double>> raices;
    complex<double> discriminante = sqrt(complex<double>(b * b - 4 * a * c, 0));

    raices.push_back((-b + discriminante) / (2 * a));
    raices.push_back((-b - discriminante) / (2 * a));

    return raices;
}

int main() {
    int grado;
    std::cout << "Ingrese el grado del polinomio: ";
    std::cin >> grado;

    // Crear un array para almacenar los coeficientes del polinomio
    double coeficientes[grado + 1];

    // Ingresar los coeficientes del polinomio
    std::cout << "Ingrese los coeficientes del polinomio, comenzando desde el coeficiente de mayor grado hasta el coeficiente independiente:" << std::endl;
    for (int i = grado; i >= 0; i--) {
        std::cout << "Coeficiente de x^" << i << ": ";
        std::cin >> coeficientes[i];
    }

    // Mostrar los coeficientes ingresados
    std::cout << "Polinomio ingresado: ";
    for (int i = grado; i > 0; i--) {
        std::cout << coeficientes[i] << "x^" << i << " + ";
    }
    std::cout << coeficientes[0] << std::endl;

    // Obtener los coeficientes a, b y c del polinomio
    double a = coeficientes[2];
    double b = coeficientes[1];
    double c = coeficientes[0];

    // Encontrar las raíces del polinomio
    vector<complex<double>> raices = encontrarRaicesPolinomio(a, b, c);

    // Mostrar las raíces encontradas
    if (!raices.empty()) {
        cout << "Raices del polinomio:" << endl;
        for (int i = 0; i < raices.size(); i++) {
            cout << "x" << i + 1 << ": " << raices[i].real();
            if (raices[i].imag() >= 0) {
                cout << " + " << raices[i].imag() << "i" << endl;
            } else {
                cout << " - " << abs(raices[i].imag()) << "i" << endl;
            }
        }
    } else {
        cout << "No se encontraron raices complejas del polinomio." << endl;
    }

    return 0;
}
