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

#include "../../Clases/Algoritmos/AlgoritmoPlanificacion.h"

bool 
AlgoritmoPlanificacion::esPequeño(Instancia*instancia) {
  try {
    if (std::any_cast<size_t>(instancia->getSize()) <= 1) {
      return true;
    }
  } catch (const std::bad_any_cast& e) {
    std::cerr << "Error: No se pudo convertir el tamaño de la instancia a size_t. AlgoritmoPlanificacion" << e.what() << std::endl;
  }
  return false;
}

Solucion* 
AlgoritmoPlanificacion::resolverPequeño(Instancia*) {

}

std::vector<Instancia*> 
AlgoritmoPlanificacion::dividir(Instancia*) {

}

Solucion* 
AlgoritmoPlanificacion::combinarSolucion(std::vector<Solucion*>) {

}

std::string
AlgoritmoPlanificacion::algoritmo() const {
  return "Algoritmo de Planificacion";
}