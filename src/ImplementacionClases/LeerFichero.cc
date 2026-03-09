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

	// 1. Obtener el horizonte temporal (planningHorizon)
	int horizonte = j["planningHorizon"];
	InstanciaPlanificacion* instancia = new InstanciaPlanificacion(horizonte);

	// 2. Cargar los Turnos (shifts)
	for (const auto& turno : j["shifts"]) {
			instancia->añadirTurno(turno.get<std::string>());
	}

	// 3. Cargar los Empleados (employees)
	// Incluye el nombre y los días de descanso (C[e])
	for (const auto& emp : j["employees"]) {
		instancia->añadirEmpleado(emp["name"], emp["freeDays"]);
	}

	// 4. Cargar la Matriz de Satisfacción (satisfaction)
	// Representa los valores A[e][d][t]
	for (const auto& item : j["satisfaction"]) {
		instancia->setSatisfaccion(
			item["employee"], 
			item["day"], 
			item["shift"], 
			item["value"]
		);
	}

	// 5. Cargar los Requerimientos (requiredEmployees)
	// Representa los valores B[d][t]
	for (const auto& req : j["requiredEmployees"]) {
		instancia->setMinEmpleados(
			req["day"], 
			req["shift"], 
			req["value"]
		);
	}

	return instancia;
}