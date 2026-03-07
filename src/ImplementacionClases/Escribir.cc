/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Diseño y Analisis de Complejidad
 * 
 * @author  Dario Dominguez Gonzalez, Carlos Plata Luis
 * @date    10/03/2026
 * @brief   Implementacion de un simulador de algoritmos de divide y venceras,
 *          utilizando los principios SOLID, el patron de estrategia y el patron Template.
*/

#include "../Clases/Escribir.h"

void 
Escribir::mostrarResultados(std::ostream& os, Instancia* instancia, Solucion* solucion, Algoritmo* algoritmo) const {
  os << "Instancia Inicial: ";
  instancia->mostrarValores(os);
  os << "Resuelto con el algoritmo: " << algoritmo->algoritmo() << std::endl;
  os << "Solucion: ";
  solucion->mostrarSolucion(os);
}