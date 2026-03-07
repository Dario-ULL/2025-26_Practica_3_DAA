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

#ifndef ALGORITMO_QUICKSORT_H
#define ALGORITMO_QUICKSORT_H

#include "../DivideYVenceras.h"

class DivideYVenceras;
class Solucion;
class Instancia;

class AlgoritmoQuickSort : public DivideYVenceras {
 public:
  AlgoritmoQuickSort() = default;
  ~AlgoritmoQuickSort() = default;

  bool esPequeño() override;
  Solucion* resolverPequeño(Instancia* instancia) override;
  std::vector<Instancia*> dividir(Instancia* instancia) override;
  Solucion* combinarSolucion(std::vector<Solucion*>) override;
};

#endif