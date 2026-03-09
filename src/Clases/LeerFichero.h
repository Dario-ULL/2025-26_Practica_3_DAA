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

#ifndef LEER_FICHERO_H
#define LEER_FICHERO_H

#include <nlohmann/json.hpp>
#include <fstream>

#include "Instancia.h"
#include "Instancias/InstanciaPlanificacion.h"

class Instancia;
class InstanciaPlanificacion;

class LeerFichero {
 public:
  LeerFichero() = default;
  ~LeerFichero() = default;

  InstanciaPlanificacion* leerFichero(const std::string& nombreFichero);
};

#endif