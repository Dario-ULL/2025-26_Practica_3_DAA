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
  requerimientos_.assign(horizonte, std::vector<int>());
}

std::any 
InstanciaPlanificacion::getSize() const {
  return horizonte_;
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
InstanciaPlanificacion::pushValue(std::any value) {
  // No se implementa en esta clase, ya que no se representa como un vector simple
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
  // Ajustar matriz A[e][d][t]
  satisfaccion_.resize(empleados_.size());
  for (auto& matrizDia : satisfaccion_) {
    matrizDia.resize(horizonte_);
    for (auto& vectorTurno : matrizDia) {
      vectorTurno.resize(turnos_.size(), 0);
    }
  }
}

void
InstanciaPlanificacion::añadirTurno(const std::string& idTurno) {
  turnos_.push_back(idTurno);
  for (auto& matrizDia : satisfaccion_) {
    for (auto& vectorTurno : matrizDia) {
      vectorTurno.resize(turnos_.size(), 0);
    }
  }
}

void 
InstanciaPlanificacion::setSatisfaccion(int empIdx, int dia, int turnoIdx, int valor) {
  if (empIdx >= 0 && static_cast<size_t>(empIdx) < satisfaccion_.size() && 
    dia >= 0 && dia < horizonte_ && 
    turnoIdx >= 0 && static_cast<size_t>(turnoIdx) < turnos_.size()) {
    satisfaccion_[empIdx][dia][turnoIdx] = valor;
  }
}

void  
InstanciaPlanificacion::setMinEmpleados(int dia, int turnoIdx, int valor) {
  if (dia >= 0 && dia < horizonte_ && turnoIdx >= 0 && (size_t)turnoIdx < turnos_.size()) {
    if (requerimientos_[dia].size() < turnos_.size()) {
      requerimientos_[dia].resize(turnos_.size(), 0);
    }
    requerimientos_[dia][turnoIdx] = valor;
  }
}


std::vector<int> 
InstanciaPlanificacion::getEmpleadosOrdenadosPorSatisfaccion(int dia, int turnoIdx) const {
  std::vector<std::pair<int, int>> empSatisfaccion;
  for (size_t empIdx = 0; empIdx < satisfaccion_.size(); ++empIdx) {
    if (dia >= 0 && dia < horizonte_ && turnoIdx >= 0 && static_cast<size_t>(turnoIdx) < turnos_.size()) {
      empSatisfaccion.emplace_back(empIdx, satisfaccion_[empIdx][dia][turnoIdx]);
    }
  }
  std::sort(empSatisfaccion.begin(), empSatisfaccion.end(), [](const auto& a, const auto& b) {
    return a.second > b.second;
  });
  std::vector<int> empleadosOrdenados;
  for (const auto& pair : empSatisfaccion) {
    empleadosOrdenados.push_back(pair.first);
  }
  return empleadosOrdenados;
}

int 
InstanciaPlanificacion::getHorizonte() const {
  return horizonte_;
}

int
InstanciaPlanificacion::getSatisfaccion(int empIdx, int dia, int turnoIdx) const {
  if (empIdx >= 0 && static_cast<size_t>(empIdx) < satisfaccion_.size() && 
    dia >= 0 && dia < horizonte_ && 
    turnoIdx >= 0 && static_cast<size_t>(turnoIdx) < turnos_.size()) {
    return satisfaccion_[empIdx][dia][turnoIdx];
  }
  return 0;
}

int
InstanciaPlanificacion::getMinEmpleados(int dia, int turnoIdx) const {
  if (dia >= 0 && dia < horizonte_ && 
    turnoIdx >= 0 && static_cast<size_t>(turnoIdx) < turnos_.size()) {
    return requerimientos_[dia][turnoIdx];
  }
  return 0;
}

int
InstanciaPlanificacion::getDiasDescansoRequeridos(int empIdx) const {
  return (empIdx >= 0 && static_cast<size_t>(empIdx) < empleados_.size()) ? empleados_[empIdx].diasDescanso : 0;
}

int
InstanciaPlanificacion::getNumEmpleados() const {
  return empleados_.size();
}

int
InstanciaPlanificacion::getNumTurnos() const {
  return turnos_.size();
}