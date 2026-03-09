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

#ifndef ALGORITMO_H
#define ALGORITMO_H

#include "Instancia.h"
#include "Solucion.h"
#include "Soluciones/SolucionVector.h"
#include "Soluciones/SolucionPlanificacion.h"
#include "Instancias/InstanciaVector.h"
#include "Instancias/InstanciaPlanificacion.h"

#include <string>
#include <any>
#include <algorithm>

class Algoritmo {
 public:
  Algoritmo() = default;
  ~Algoritmo() = default;
  virtual Solucion* Resolver(Instancia*) = 0;
  virtual std::string algoritmo() const = 0;
 protected:
  Solucion* solucion_;
};

#endif