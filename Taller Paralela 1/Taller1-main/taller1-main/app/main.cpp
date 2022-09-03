#include "Utils.h"
#include <cstdlib>
#include <iostream>
#include <string>


/**
 * Función que muestra los participantes del grupo
 */
void participantes() {
	std::cout << std::endl << " INTEGRANTES:";
	std::cout << std::endl << "- Jose Hervas";
	std::cout << std::endl << "- Carlos Araya";
	std::cout << std::endl << "- Matias rubilar" << std::endl;
}


/**
 * Taller computacional
 * @param argc cantidad de argumentos
 * @param argv argumentos
 * @return El código de salida del programa
 */
int main(int argc, char** argv) {
    int exitCode;

	if (argc == 2) {
		// Procede a hacer el calculo si la cantidad de parametros es correcta
		const std::string polinomio(argv[1]);
		std::vector<Monomio> monomios = Utils::convertir(polinomio);

		// Muestra el Polinomio ingresado
		std::cout << "-> Polinomio: ";
		std::vector<Monomio>::size_type i = 0;
		for (i = 0; i < monomios.size(); i++) {
			Monomio monomio = monomios[i];
			std::cout << monomio.GetCoeficiente() << "x^" << monomio.GetGrado() << " ";
		}
		std::cout << std::endl;

		// Calcula la solucion del polinomio
		double resultado = Utils::newthon_raphson(monomios);
		std::cout << "-> Solución aproximada: " << resultado << std::endl;
		exitCode = EXIT_SUCCESS;
	} else {
		// Muestra mensaje de ayuda
		std::cout << "Argumentos inválidos, ejecute el programa de la siguiente forma:" << std::endl;
		std::cout << argv[0] << " \"[Polinomio]\"" << std::endl;
		exitCode = EXIT_FAILURE;
	}

	// Muestra los integrantes
	participantes();

	return exitCode;
}
