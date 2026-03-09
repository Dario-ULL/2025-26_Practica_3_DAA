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

#ifndef INSTANCIA_H
#define INSTANCIA_H

#include <iostream>
#include <fstream>
#include <vector>
#include <any>
#include <algorithm>

class Instancia {
 public:
  Instancia() = default;
  virtual ~Instancia() = default;
  
  virtual std::any getSize() const = 0;
  virtual std::any getValue(std::any) const = 0;
  virtual void setValue(std::any, std::any) = 0;
  virtual void pushValue(std::any) = 0;
  virtual void mostrarValores(std::ostream&) const = 0;
};

#endif
