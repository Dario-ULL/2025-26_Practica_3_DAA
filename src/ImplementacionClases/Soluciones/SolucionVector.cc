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

#include "../../Clases/Soluciones/SolucionVector.h"

SolucionVector::SolucionVector () {
  solucionVector_.resize(0);
}

SolucionVector::SolucionVector (std::vector<int> solution) {
  solucionVector_ = solution;
}

void
SolucionVector::setSolution(std::any solution) {
  try {
    solucionVector_ = std::any_cast<std::vector<int>>(solution);
  } catch (const std::bad_any_cast& e) {
    std::cerr << "Error al convertir la solucion: " << e.what() << std::endl;
  }
}

std::any
SolucionVector::getSolution() const {
  return solucionVector_;
}

void
SolucionVector::mostrarSolucion() const {
  std::cout << "La solucion es: ";
  for (size_t it = 0; it < solucionVector_.size(); it++){
    std::cout << solucionVector_[it] << " ";
  }
  std::cout << std::endl;
}