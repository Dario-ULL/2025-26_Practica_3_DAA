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

#ifndef ESCRIBIR_H
#define ESCRIBIR_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

#include "Instancia.h"
#include "Solucion.h"
#include "Algoritmo.h"

class Instancia;
class Solucion;

class Escribir {
 public:
  Escribir() = default;
  ~Escribir() = default;

  void mostrarResultados(std::ostream&, Instancia*, Solucion*, Algoritmo*) const;
};

#endif