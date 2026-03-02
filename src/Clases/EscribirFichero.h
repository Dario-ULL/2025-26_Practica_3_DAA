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

#ifndef ESCRIBIRFICHERO_H
#define ESCRIBIRFICHERO_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>

class EscribirFichero {
 public:
  EscribirFichero() = default;
  ~EscribirFichero() = default;

  void EscribirArchivo(const std::vector<int>& datos);
  void EscribirArchivo(const std::string& nombreArchivo, const std::vector<int>& datos);
};

#endif