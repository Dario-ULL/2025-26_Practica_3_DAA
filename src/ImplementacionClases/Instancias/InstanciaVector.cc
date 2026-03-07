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

int 
InstanciaVector::getValue(int pos) const {
  return instaciaVector_[pos];
}

int 
InstanciaVector::getSize() const {
  return instaciaVector_.size();
}

void 
InstanciaVector::setValue(int pos, int valor) {
  instaciaVector_[pos] = valor;
}

void 
InstanciaVector::mostrarValores() const {
  for(int it = 0; it < getSize(); it++){
    std::cout << "[" << instaciaVector_[it] << "] ";
  }
  std::cout << std::endl;
}
