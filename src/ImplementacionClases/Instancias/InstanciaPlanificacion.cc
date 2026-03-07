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

#include "../../Clases/Instancias/InstanciaPlanificacion.h"

InstanciaPlanificacion::InstanciaPlanificacion(int horizonte) : horizonte_(horizonte) {
  satisfaccion_.resize(0); 
  requerimientos_.resize(horizonte);
}

std::any 
InstanciaPlanificacion::getSize() const {
  return std::make_tuple(horizonte_, empleados_.size(), turnos_.size());
}

std::any
InstanciaPlanificacion::getValue(std::any key) const {
  // No se implementa en esta clase, ya que se accede a través de métodos específicos
  return {};
}

void
InstanciaPlanificacion::setValue(std::any key, std::any value) {
  // No se implementa en esta clase, ya que se modifica a través de métodos específicos
}

void
InstanciaPlanificacion::mostrarValores(std::ostream& os) const {
  os << "Planning Horizon: " << horizonte_ << " days\n";
  os << "Employees:\n";
  for (const auto& emp : empleados_) {
    os << "  - " << emp.nombre << " (Free Days: " << emp.diasDescanso << ")\n";
  }
  os << "Shifts:\n";
  for (const auto& turno : turnos_) {
    os << "  - " << turno << "\n";
  }
}

void
InstanciaPlanificacion::setHorizonte(int dias) {
  horizonte_ = dias;
  requerimientos_.resize(dias);
}

void
InstanciaPlanificacion::añadirEmpleado(const std::string& nombre, int diasDescanso) {
  empleados_.push_back({nombre, diasDescanso});
  satisfaccion_.resize(empleados_.size());
  for (auto& diaVec : satisfaccion_) {
    diaVec.resize(horizonte_);
    for (auto& turnoVec : diaVec) {
      turnoVec.resize(turnos_.size(), 0);
    }
  }
}

void
InstanciaPlanificacion::añadirTurno(const std::string& idTurno) {
  turnos_.push_back(idTurno);
  for (auto& dia : satisfaccion_) {
    for (auto& turno : dia) {
      turno.resize(turnos_.size(), 0);
    }
  }
}

void
InstanciaPlanificacion::setSatisfaccion(int empIdx, int dia, int turnoIdx, int valor) {
  if (empIdx < satisfaccion_.size() && dia < horizonte_ && turnoIdx < turnos_.size()) {
    satisfaccion_[empIdx][dia][turnoIdx] = valor;
  }
}

void  
InstanciaPlanificacion::setMinEmpleados(int dia, int turnoIdx, int valor) {
  if (dia < horizonte_ && turnoIdx < turnos_.size()) {
    requerimientos_[dia].resize(turnos_.size(), 0);
    requerimientos_[dia][turnoIdx] = valor;
  }
}

int
InstanciaPlanificacion::getSatisfaccion(int empIdx, int dia, int turnoIdx) const {
  if (empIdx < satisfaccion_.size() && dia < horizonte_ && turnoIdx < turnos_.size()) {
    return satisfaccion_[empIdx][dia][turnoIdx];
  }
  return 0;
}

int
InstanciaPlanificacion::getMinEmpleados(int dia, int turnoIdx) const {
  if (dia < horizonte_ && turnoIdx < turnos_.size()) {
    return requerimientos_[dia][turnoIdx];
  }
  return 0;
}

int
InstanciaPlanificacion::getDiasDescansoEmpleado(int empIdx) const {
  if (empIdx < empleados_.size()) {
    return empleados_[empIdx].diasDescanso;
  }
  return 0;
}

int
InstanciaPlanificacion::getNumEmpleados() const {
  return empleados_.size();
}

int
InstanciaPlanificacion::getNumTurnos() const {
  return turnos_.size();
}
