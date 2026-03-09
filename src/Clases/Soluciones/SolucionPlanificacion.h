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
  ~SolucionPlanificacion() = default;

  std::any getSolution() const override;
  void setSolution(std::any solution) override;
  void mostrarSolucion(std::ostream& os) const override;

 private:
  std::vector<std::vector<int>> matrizAsignacion_;
  int numEmpleados_;
  int horizonte_;
  double calidad_;
};

#endif