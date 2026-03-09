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

#ifndef INSTANCIA_PLANIFICACION_H
#define INSTANCIA_PLANIFICACION_H

#include "../Instancia.h"

class Instancia;

struct Empleado {
  std::string nombre;
  int diasDescanso; // Dato C[e]
};

class InstanciaPlanificacion : public Instancia {
 public:
  InstanciaPlanificacion() : horizonte_(0) {}
  InstanciaPlanificacion(int horizonte);
  virtual ~InstanciaPlanificacion() = default;

  // Métodos obligatorios de la interfaz Instancia (Patrón Template)
  std::any getSize() const override; 
  std::any getValue(std::any key) const override;
  void setValue(std::any key, std::any value);
  void pushValue(std::any value) override;
  void mostrarValores(std::ostream& os) const override;

  // Configuración (Usada por LeerFichero JSON)
  void setHorizonte(int dias);
  void añadirEmpleado(const std::string& nombre, int diasDescanso);
  void añadirTurno(const std::string& idTurno);
  void setSatisfaccion(int empIdx, int dia, int turnoIdx, int valor);
  void setMinEmpleados(int dia, int turnoIdx, int valor);

  // Consultas para el Algoritmo (Datos A, B, C)
  int getSatisfaccion(int empIdx, int dia, int turnoIdx) const;
  int getMinEmpleados(int dia, int turnoIdx) const;
  int getDiasDescansoRequeridos(int empIdx) const;
  int getNumEmpleados() const;
  int getNumTurnos() const;

 private:
  int horizonte_; // D (Días)
  std::vector<Empleado> empleados_; // E (Empleados)
  std::vector<std::string> turnos_;    // T (Turnos)
  std::vector<std::vector<std::vector<int>>> satisfaccion_; // A[e][d][t]
  std::vector<std::vector<int>> requerimientos_;   // B[d][t]
};

#endif