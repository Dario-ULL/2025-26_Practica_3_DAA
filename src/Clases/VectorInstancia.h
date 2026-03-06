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

#ifndef VECTORINSTANCIA_H
#define VECTORINSTANCIA_H

#include <vector>

class VectorInstancia {
 public:
  VectorInstancia() = default;
  ~VectorInstancia() = default;
 private:
  std::vector<int> vector_;
};

#endif