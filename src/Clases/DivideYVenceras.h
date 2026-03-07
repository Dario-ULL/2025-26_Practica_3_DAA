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

#ifndef DIVIDE_Y_VENCERAS_H
#define DIVIDE_Y_VENCERAS_H

#include "Algoritmo.h"

class Algoritmo;
class Instancia;
class Solucion;

class DivideYVenceras : public Algoritmo {
 public:
  DivideYVenceras() = default;
  ~DivideYVenceras() = default;

  Solucion* Resolver(Instancia*) override;
  virtual std::string algoritmo() const = 0;
 protected:
  virtual bool esPequeño(Instancia*) = 0;
  virtual Solucion* resolverPequeño(Instancia*) = 0;
  virtual std::vector<Instancia*> dividir(Instancia*) = 0;
  virtual Solucion* combinarSolucion(std::vector<Solucion*>) = 0;
};

#endif