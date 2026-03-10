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

// Método para mostrar por pantalla/archivo la instancia del problema
void 
Escribir::mostrarResultados(std::ostream& os, Instancia* instancia, Solucion* solucion, Algoritmo* algoritmo) const {
  os << "Resuelto con el algoritmo: " << algoritmo->algoritmo() << std::endl;
  instancia->mostrarValores(os);    
  os << "Solucion: ";
  solucion->mostrarSolucion(os);
}

// Método para mostrar por pantalla/archivo la solucion del problema
void 
Escribir::mostrarResultados(std::ostream& os, Solucion* solucion, Algoritmo* algoritmo) const {
  os << "Resuelto con el algoritmo: " << algoritmo->algoritmo() << std::endl;
  os << "Solucion: ";
  solucion->mostrarSolucion(os);
}