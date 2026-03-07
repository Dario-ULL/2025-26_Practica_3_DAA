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

struct Empleado {
  std::string nombre;
  int diasDescanso;
};

class InstanciaPlanificacion : public Instancia {
 public:
  InstanciaPlanificacion() = default;
  InstanciaPlanificacion(int horizonte);
  ~InstanciaPlanificacion() = default;

  std::any getSize() const override;
  std::any getValue(std::any) const override;
  void setValue(std::any, std::any) override; 
  void mostrarValores(std::ostream&) const override;

  
  void setHorizonte(int dias);
  void añadirEmpleado(const std::string& nombre, int diasDescanso);
  void añadirTurno(const std::string& idTurno);
  void setSatisfaccion(int empIdx, int dia, int turnoIdx, int valor);
  void setMinEmpleados(int dia, int turnoIdx, int valor);

  // Consultas (usadas por el Algoritmo)
  int getSatisfaccion(int empIdx, int dia, int turnoIdx) const;
  int getMinEmpleados(int dia, int turnoIdx) const;
  int getDiasDescansoEmpleado(int empIdx) const;
  int getNumEmpleados() const;
  int getNumTurnos() const;

 private:
  int horizonte_;
  std::vector<Empleado> empleados_;
  std::vector<std::string> turnos_;
  std::vector<std::vector<std::vector<int>>> satisfaccion_;
  std::vector<std::vector<int>> requerimientos_;
};

#endif