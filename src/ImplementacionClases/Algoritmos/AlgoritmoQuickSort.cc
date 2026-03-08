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

bool 
AlgoritmoQuickSort::esPequeño(Instancia* instancia){
  if (instancia->getSize() <= 2) {
    return true;
  }
  return false;
}

Solucion* 
AlgoritmoQuickSort::resolverPequeño(Instancia* instancia){
  int temp = std::any_cast<int>(instancia->getValue(0));
  int temp2 = std::any_cast<int>(instancia->getValue(1));
  if( temp > temp2){
    instancia->setValue(0, temp2);
    instancia->setValue(1, temp);
  }
  Solucion* solucion = new SolucionVector(instancia->getVector());
  return solucion;
}

std::vector<Instancia*> 
AlgoritmoQuickSort::dividir(Instancia* instancia){
  InstanciaVector* subinstanciaIzq = new InstanciaVector();
  InstanciaVector* subinstanciaDer = new InstanciaVector();
  int pivote_pos = instancia->getSize() / 2;
  int pivote = instancia->getVector()[pivote_pos];

  for(int it = 0; it < instancia->getSize(); it++){
    int valor = instancia->getVector()[it];
    if (valor <= pivote)
      subinstanciaIzq->pushValue(valor);
    else
      subinstanciaDer->pushValue(valor);
  }

  std::vector<Instancia*> subproblemas;
  subproblemas.push_back(subinstanciaIzq);
  subproblemas.push_back(subinstanciaDer);
  return subproblemas;
}

Solucion* 
AlgoritmoQuickSort::combinarSolucion(std::vector<Solucion*> subSoluciones){

  SolucionVector* solucionIzq = static_cast<SolucionVector*>(subSoluciones[0]);
  SolucionVector* solucionDer = static_cast<SolucionVector*>(subSoluciones[1]);
  std::vector<int> resultado;
  int size_izq =  solucionIzq->getSize();

  for(int it = 0; it < size_izq; it++){
    resultado.push_back(solucionIzq->getVector()[it]);
  }
  for(int it = 0; it < solucionDer->getSize(); it++){
    resultado.push_back(solucionIzq->getVector()[it]);
  }
  
  SolucionVector* solucionFinal = new SolucionVector(resultado);
  return solucionFinal;  
}
