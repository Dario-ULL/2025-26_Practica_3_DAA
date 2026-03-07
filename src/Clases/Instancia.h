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
#include <vector>
#include <any>

class Instancia {
 public:
  Instancia() = default;
  virtual ~Instancia() = default;
  
  virtual int getSize() const = 0;
  virtual int getValue(int pos) const = 0;
  virtual void setValue(int pos, int valor) = 0;
  virtual void mostrarValores() const = 0;
};

#endif
