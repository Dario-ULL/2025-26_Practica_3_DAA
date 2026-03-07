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

#ifndef ALGORITMO_MERGESORT_H
#define ALGORITMO_MERGESORT_H

#include "../DivideYVenceras.h"

class DivideYVenceras;
class Solucion;
class Instancia;
class SolucionVector;
class InstanciaVector;

class AlgoritmoMergeSort : public DivideYVenceras {
 public:
  AlgoritmoMergeSort() = default;
  ~AlgoritmoMergeSort() = default;

  bool esPequeño(Instancia*) override;
  Solucion* resolverPequeño(Instancia*) override;
  std::vector<Instancia*> dividir(Instancia*) override;
  Solucion* combinarSolucion(std::vector<Solucion*>) override;
 private:


};

#endif