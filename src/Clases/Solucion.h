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

#ifndef SOLUCION_H
#define SOLUCION_H

#include <iostream>
#include <fstream>
#include <vector>
#include <any>

class Solucion {
 public:
  Solucion() = default;
  ~Solucion() = default;
  
  virtual void mostrarSolucion(std::ostream&) const = 0;
 protected:
  virtual void setSolution(std::any solution) = 0;
  virtual std::any getSolution() const = 0;
};

#endif