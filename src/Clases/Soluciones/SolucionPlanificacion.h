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

#ifndef SOLUCION_PLANIFICACION_H
#define SOLUCION_PLANIFICACION_H

#include "../Solucion.h"

class SolucionPlanificacion : public Solucion {
 public:
  SolucionPlanificacion();
  SolucionPlanificacion(int, int);
  ~SolucionPlanificacion() = default;

  void asignarTurno(int, int, int);
  int getTurnoAsignado(int, int) const;
  void setCalidad(double);
  double getCalidad() const;
  int getHorizonte() const;
  int getNumEmpleados() const;

  std::any getSolution() const override;
  void setSolution(std::any) override;
  void mostrarSolucion(std::ostream&) const override;
 private:
  std::vector<std::vector<int>> matrizAsignacion_;
  int numEmpleados_;
  int horizonte_;
  double calidad_;
};

#endif