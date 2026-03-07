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
  instaciaVector_.resize(0);
}

InstanciaVector::InstanciaVector(int size) : instaciaVector_(size, 0) {}

InstanciaVector::InstanciaVector(std::vector<int> vector) {
  instaciaVector_ = vector;
}

std::any 
InstanciaVector::getValue(std::any pos) const {
  try {
    int index = std::any_cast<int>(pos);
    if (index >= 0 && index < instaciaVector_.size()) {
      return instaciaVector_[index];
    } else {
      std::cerr << "Error: Índice fuera de rango." << std::endl;
      return std::any();
    }
  } catch (const std::bad_any_cast& e) {
    std::cerr << "Error al convertir la posición: " << e.what() << std::endl;
    return std::any();
  }
}

std::any 
InstanciaVector::getSize() const {
  return instaciaVector_.size();
}

void 
InstanciaVector::setValue(std::any pos, std::any valor) {
  try {
    int index = std::any_cast<int>(pos);
    int value = std::any_cast<int>(valor);
    if (index >= 0 && index < instaciaVector_.size()) {
      instaciaVector_[index] = value;
    } else {
      std::cerr << "Error: Índice fuera de rango." << std::endl;
    }
  } catch (const std::bad_any_cast& e) {
    std::cerr << "Error al convertir el valor o la posición: " << e.what() << std::endl;
  }
}

void 
InstanciaVector::mostrarValores(std::ostream& os) const {
  for(int it = 0; it < instaciaVector_.size(); it++){
    os << "[" << instaciaVector_[it] << "] ";
  }
  os << std::endl;
}
