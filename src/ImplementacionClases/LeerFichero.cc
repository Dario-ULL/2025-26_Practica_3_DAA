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

#include "../Clases/LeerFichero.h"

Instancia* 
LeerFichero::leerFichero(const std::string& nombreFichero) {
  std::ifstream file(nombreFichero);
  nlohmann::json j;
  file >> j;

  // 1. Crear la instancia con el horizonte temporal
  int horizonte = j["planningHorizon"];
  auto* instancia = new InstanciaPlanificacion(horizonte);

  // 2. Leer Empleados
  for (auto& item : j["employees"]) {
      instancia->añadirEmpleado(item["name"], item["freeDays"]);
  }

  // 3. Leer Matriz de Satisfacción
  for (auto& item : j["satisfaction"]) {
      instancia->setSatisfaccion(
          item["employee"], 
          item["day"], 
          item["shift"], 
          item["value"]
      );
  }

  // 4. Leer Requerimientos de Turnos
  for (auto& item : j["requiredEmployees"]) {
      instancia->setMinEmpleados(
          item["day"], 
          item["shift"], 
          item["value"]
      );
  }

  return instancia;
}