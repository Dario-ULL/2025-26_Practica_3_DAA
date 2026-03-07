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
  if (std::any_cast<int>(instancia->getSize()) <= 1) {
    return true;
  }
  return false;
}

Solucion* 
AlgoritmoMergeSort::resolverPequeño(Instancia* instancia){
  std::vector<int> datos;
  for(size_t i = 0; i < std::any_cast<size_t>(instancia->getSize()); ++i) {
    datos.push_back(std::any_cast<int>(instancia->getValue(i)));
  }
  Solucion* solucion = new SolucionVector(datos);
  return solucion;
}

std::vector<Instancia*> 
AlgoritmoMergeSort::dividir(Instancia* instancia){
  int mid = std::any_cast<int>(instancia->getSize()) / 2;
  std::vector<Instancia*> subproblemas;
  Instancia* izquierda = new InstanciaVector(mid);
  for(int i = 0; i < mid; ++i) {
      izquierda->setValue(i, instancia->getValue(i));
  }

  int tamDerecha = std::any_cast<int>(instancia->getSize()) - mid;
  Instancia* derecha = new InstanciaVector(tamDerecha);
  for(int i = 0; i < tamDerecha; ++i) {
      derecha->setValue(i, instancia->getValue(mid + i));
  }
  subproblemas.push_back(izquierda);
  subproblemas.push_back(derecha);
  return subproblemas;
}

Solucion* 
AlgoritmoMergeSort::combinarSolucion(std::vector<Solucion*> subSoluciones){
  SolucionVector* solucionIzq = static_cast<SolucionVector*>(subSoluciones[0]);
  SolucionVector* solucionDer = static_cast<SolucionVector*>(subSoluciones[1]);
  std::vector<int> resultado;
  int i = 0, j = 0;
  while (i < solucionIzq->getSize() && j < solucionDer->getSize()) {
    if (solucionIzq->getValue(i) <= solucionDer->getValue(j)) {
      resultado.push_back(solucionIzq->getValue(i++));
    } else {
      resultado.push_back(solucionDer->getValue(j++));
    }
  }
  while (i < solucionIzq->getSize()) {
    resultado.push_back(solucionIzq->getValue(i++));
  }
  while (j < solucionDer->getSize()) {
    resultado.push_back(solucionDer->getValue(j++));
  }
  SolucionVector* solucionFinal = new SolucionVector(resultado);
  return solucionFinal;  
}


std::string
AlgoritmoMergeSort::algoritmo() const {
  return "Merge Sort";
}