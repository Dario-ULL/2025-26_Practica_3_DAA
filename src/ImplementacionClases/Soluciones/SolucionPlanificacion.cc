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

#include "../../Clases/Soluciones/SolucionPlanificacion.h"

SolucionPlanificacion::SolucionPlanificacion() : numEmpleados_(0), horizonte_(0), calidad_(0.0) {
  matrizAsignacion_.clear();
}

SolucionPlanificacion::SolucionPlanificacion(int numEmpleados, int horizonte) : numEmpleados_(numEmpleados), horizonte_(horizonte), calidad_(0.0) {
  matrizAsignacion_.resize(numEmpleados, std::vector<int>(horizonte, -1));
}

void
SolucionPlanificacion::asignarTurno(int empIdx, int dia, int turnoIdx) {
  if (empIdx >= 0 && empIdx < numEmpleados_ && dia >= 0 && dia < horizonte_) {
    if (matrizAsignacion_.size() < static_cast<size_t>(numEmpleados_)) {
      matrizAsignacion_.resize(numEmpleados_, std::vector<int>(horizonte_, -1));
    }
    matrizAsignacion_[empIdx][dia] = turnoIdx;
  }
}

int
SolucionPlanificacion::getTurnoAsignado(int empIdx, int dia) const {
  if (empIdx >= 0 && empIdx < numEmpleados_ && dia >=
      0 && dia < horizonte_ && 
      empIdx < static_cast<int>(matrizAsignacion_.size()) && 
      dia < static_cast<int>(matrizAsignacion_[empIdx].size())) {
    return matrizAsignacion_[empIdx][dia];
  }
  return -1;
}

void
SolucionPlanificacion::setCalidad(double calidad) {
  calidad_ = calidad;
}

double
SolucionPlanificacion::getCalidad() const {
  return calidad_;
}

int
SolucionPlanificacion::getHorizonte() const {
  return horizonte_;
}

int 
SolucionPlanificacion::getNumEmpleados() const {
  return numEmpleados_;
}

std::any
SolucionPlanificacion::getSolution() const {
  return matrizAsignacion_;
}

void
SolucionPlanificacion::setSolution(std::any solution) {
  try {
    matrizAsignacion_ = std::any_cast<std::vector<std::vector<int>>>(
      solution
    );
  } catch (const std::bad_any_cast& e) {
    std::cerr << "Error al convertir la solucion: " << e.what() << std::endl;
  }
}

void
SolucionPlanificacion::mostrarSolucion(std::ostream& os) const {
  os << "Matriz de Asignación (Empleados x Días):\n";
  for (size_t empIdx = 0; empIdx < matrizAsignacion_.size(); empIdx++) {
    os << "Empleado " << empIdx << ": ";
    for (size_t dia = 0; dia < matrizAsignacion_[empIdx].size(); dia++) {
      os << "[" << matrizAsignacion_[empIdx][dia] << "] ";
    }
    os << "\n";
  }
  os << "Calidad de la Solución: " << calidad_ << "\n";
}