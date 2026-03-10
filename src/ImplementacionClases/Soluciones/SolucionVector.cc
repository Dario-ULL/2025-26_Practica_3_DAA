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

// Constructor por defecto
SolucionVector::SolucionVector () {
  solucionVector_.resize(0);
}

// Constructor pasando los valores mediante un vector
SolucionVector::SolucionVector (std::vector<int> solution) {
  solucionVector_ = solution;
}

// Devuelve el vector
std::vector<int>
SolucionVector::getVector() const {
  return solucionVector_;
}

// Devuelve el tamaño de la instancia (el vector)
int 
SolucionVector::getSize() const {
  return solucionVector_.size();
}

// Retorna el valor en la posicion dada
int 
SolucionVector::getValue(int pos) const {
  return solucionVector_[pos];
}

// Cambia los valores de la solucion a los dados por el vector de la solucion nueva
void
SolucionVector::setSolution(std::any solution) {
  try {
    solucionVector_ = std::any_cast<std::vector<int>>(solution);
  } catch (const std::bad_any_cast& e) {
    std::cerr << "Error al convertir la solucion: " << e.what() << std::endl;
  }
}

// Devuelve el vector
std::any
SolucionVector::getSolution() const {
  return solucionVector_;
}

// Muestra los valores de la solucion
void
SolucionVector::mostrarSolucion(std::ostream& os) const {
  for(size_t it = 0; it < solucionVector_.size(); it++){
    os << "[" << solucionVector_[it] << "] ";
  }
  os << std::endl;
}