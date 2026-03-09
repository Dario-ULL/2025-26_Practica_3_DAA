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

#include "../../Clases/Instancias/InstanciaVector.h"

InstanciaVector::InstanciaVector() {
  instanciaVector_.resize(0);
}

InstanciaVector::InstanciaVector(int size) : instanciaVector_(size, 0) {}

InstanciaVector::InstanciaVector(std::vector<int> vector) {
  instanciaVector_ = vector;
}

std::vector<int> 
InstanciaVector::getVector() const{
  return instanciaVector_;
}

int
InstanciaVector::getValue(int pos) const {
  try {
    if (pos >= 0 && pos < instanciaVector_.size()) {
      return instanciaVector_[pos];
    } else {
      std::cerr << "Error: Índice fuera de rango." << std::endl;
      return -1;
    }
  } catch (const std::bad_any_cast& e) {
    std::cerr << "Error al convertir la posición: " << e.what() << std::endl;
    return -1;
  }
}

std::any 
InstanciaVector::getSize() const {
  return instanciaVector_.size();
}

void 
InstanciaVector::setValue(int pos, int valor) {
  try {
    if (pos >= 0 && pos < instanciaVector_.size()) {
      instanciaVector_[pos] = valor;
    } else {
      std::cerr << "Error: Índice fuera de rango." << std::endl;
    }
  } catch (const std::bad_any_cast& e) {
    std::cerr << "Error al convertir el valor o la posición: " << e.what() << std::endl;
  }
}

void
InstanciaVector::pushValue(int valor){
  instanciaVector_.push_back(valor);
}

void 
InstanciaVector::mostrarValores(std::ostream& os) const {
  for(size_t it = 0; it < instanciaVector_.size(); it++){
    os << "[" << instanciaVector_[it] << "] ";
  }
  os << std::endl;
}
