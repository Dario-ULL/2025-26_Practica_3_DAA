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

#include "../../Clases/Algoritmos/AlgoritmoQuickSort.h"
/*

bool 
AlgoritmoQuickSort::esPequeño(Instancia* instancia){
  if (instancia->getSize() <= 1) {
    return true;
  }
  return false;
}

Solucion* 
AlgoritmoQuickSort::resolverPequeño(Instancia* instancia){
  std::vector<int> datos;
  for(int i = 0; i < instancia->getSize(); ++i) {
    datos.push_back(instancia->getValue(i));
  }
  Solucion* solucion = new SolucionVector(datos);
  return solucion;
}

std::vector<Instancia*> 
AlgoritmoQuickSort::dividir(Instancia* instancia){
  int pivote = instancia->getSize() / 2;
  auto valor_pivote = instancia[pivote];
  std::vector<Instancia*> subproblemas;
  Instancia* izquierda = new InstanciaVector();
  for(int it = 0; it < instancia->getSize(); it++) {
    //if(instancia[it] < valor_pivote)
  }
}

Solucion* 
AlgoritmoQuickSort::combinarSolucion(std::vector<Solucion*> subSoluciones){
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
*/