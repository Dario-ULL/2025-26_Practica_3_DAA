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

#ifndef SOLUCION_VECTOR_H
#define SOLUCION_VECTOR_H

#include "../Solucion.h"

class Solucion;

class SolucionVector : public Solucion {
 public:
  SolucionVector();
  SolucionVector(std::vector<int>);
  ~SolucionVector() = default;

  std::vector<int> getVector() const;
  int getSize() const;
  int getValue(int) const;

  void setSolution(std::any solution) override;
  std::any getSolution() const override;
  void mostrarSolucion(std::ostream&) const override;
 private:
  std::vector<int> solucionVector_;
};

#endif