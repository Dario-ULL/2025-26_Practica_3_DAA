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

// Implementación del mergesort para averigua si estamos en la instancia "pequeña"
bool 
AlgoritmoMergeSort::esPequeño(Instancia* instancia) {
  try {
    if (std::any_cast<size_t>(instancia->getSize()) <= 1) {
      return true;
    }
  } catch (const std::bad_any_cast& e) {
    std::cerr << "Error: No se pudo convertir el tamaño de la instancia a size_t. AlgoritmoMergeSort" << e.what() << std::endl;
  }
  return false;
}

// Implementación del mergesort para resolver la instancia "pequeña"
Solucion* 
AlgoritmoMergeSort::resolverPequeño(Instancia* instancia) {
  InstanciaVector* instanciaVector = static_cast<InstanciaVector*>(instancia);
  Solucion* solucion = new SolucionVector(instanciaVector->getVector());
  return solucion;
}

// Implementación del mergesort para dividir la instancia en dos subinstancias
std::vector<Instancia*> 
AlgoritmoMergeSort::dividir(Instancia* instancia) {
  InstanciaVector* instanciaVector = static_cast<InstanciaVector*>(instancia);
  std::vector<int> datos = instanciaVector->getVector();
  int n = datos.size();
  int mitad = n / 2;
  InstanciaVector* subIzq = new InstanciaVector();
  InstanciaVector* subDer = new InstanciaVector();
  for (int i = 0; i < mitad; i++) {
    subIzq->pushValue(datos[i]);
  }
  for (int i = mitad; i < n; i++) {
    subDer->pushValue(datos[i]);
  }
  return {subIzq, subDer};
}

// Implementación del mergesort para combinar las subinstancias
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

// Método que devuelve el tipo de algoritmo
std::string
AlgoritmoMergeSort::algoritmo() const {
  return "Merge Sort";
}