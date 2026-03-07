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

#include "../../Clases/Algoritmos/AlgoritmoMergeSort.h"

bool 
AlgoritmoMergeSort::esPequeño(Instancia* instancia){
  if (instancia->getSize() <= 1) {
    return true;
  }
  return false;
}

Solucion* 
AlgoritmoMergeSort::resolverPequeño(Instancia* instancia){
  std::vector<int> datos;
  for(int i = 0; i < instancia->getSize(); ++i) {
    datos.push_back(instancia->getValue(i));
  }
  Solucion* solucion = new SolucionVector(datos);
  return solucion;
}

std::vector<Instancia*> 
AlgoritmoMergeSort::dividir(Instancia* instancia){
  int mid = instancia->getSize() / 2;
  std::vector<Instancia*> subproblemas;
  Instancia* izquierda = new InstanciaVector(mid);
  for(int i = 0; i < mid; ++i) {
      izquierda->setValue(i, instancia->getValue(i));
  }

  int tamDerecha = instancia->getSize() - mid;
  Instancia* derecha = new InstanciaVector(tamDerecha);
  for(int i = 0; i < tamDerecha; ++i) {
      derecha->setValue(i, instancia->getValue(mid + i));
  }
  subproblemas.push_back(izquierda);
  subproblemas.push_back(derecha);
  return subproblemas;
}

Solucion* 
AlgoritmoMergeSort::combinarSolucion(std::vector<Solucion*>){
  
}
