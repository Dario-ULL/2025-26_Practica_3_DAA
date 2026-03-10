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

// Implementación del quicksort para averigua si estamos en la instancia "pequeña"
bool 
AlgoritmoQuickSort::esPequeño(Instancia* instancia) {
  try {
    if (std::any_cast<size_t>(instancia->getSize()) <= 1) {
      return true;
    }
  } catch (const std::bad_any_cast& e) {
    std::cerr << "Error: No se pudo convertir el tamaño de la instancia a size_t. AlgoritmoQuickSort" << e.what() << std::endl;
  }
  return false;
}

// Implementación del quicksort para resolver la instancia "pequeña"
Solucion* 
AlgoritmoQuickSort::resolverPequeño(Instancia* instancia) {   
  InstanciaVector* instanciaVector = static_cast<InstanciaVector*>(instancia);
  if (std::any_cast<size_t>(instanciaVector->getSize()) <= 1) {
    Solucion* solucion = new SolucionVector(instanciaVector->getVector());
    return solucion;
  }
  int temp = instanciaVector->getValue(0);
  int temp2 = instanciaVector->getValue(1);
  if( temp > temp2){
    instanciaVector->setValue(0, temp2);
    instanciaVector->setValue(1, temp);
  }
  Solucion* solucion = new SolucionVector(instanciaVector->getVector());
  return solucion;
}

// Implementación del quicksort para la instancia en dos subinstancias
std::vector<Instancia*> 
AlgoritmoQuickSort::dividir(Instancia* instancia) {
  InstanciaVector* instanciaVector = static_cast<InstanciaVector*>(instancia);
  std::vector<int> datos = instanciaVector->getVector();
  size_t n = datos.size();
  size_t indicePivote = n / 2;
  int valorPivote = datos[indicePivote];
  InstanciaVector* subIzq = new InstanciaVector();
  InstanciaVector* subDer = new InstanciaVector();
  for (size_t i = 0; i < n; i++) {
    if (i == indicePivote) continue; 
    if (datos[i] <= valorPivote) {
      subIzq->pushValue(datos[i]);
    }
    else {
      subDer->pushValue(datos[i]);
    }
  }
  if (std::any_cast<size_t>(subIzq->getSize()) < std::any_cast<size_t>(subDer->getSize())) {
    subIzq->pushValue(valorPivote); 
  } else {
    subDer->pushValue(valorPivote); 
  }
  return {subIzq, subDer};
}

// Implementación del quicksort para combinar las instancias resueltas
Solucion* 
AlgoritmoQuickSort::combinarSolucion(std::vector<Solucion*> subSoluciones) {

  SolucionVector* solucionIzq = static_cast<SolucionVector*>(subSoluciones[0]);
  SolucionVector* solucionDer = static_cast<SolucionVector*>(subSoluciones[1]);
  std::vector<int> resultado;
  int size_izq =  solucionIzq->getSize();

  for(int it = 0; it < size_izq; it++){
    resultado.push_back(solucionIzq->getVector()[it]);
  }
  for(int it = 0; it < solucionDer->getSize(); it++){
    resultado.push_back(solucionDer->getVector()[it]);
  }
  
  SolucionVector* solucionFinal = new SolucionVector(resultado);
  return solucionFinal;  
}

// Método que devuelve el tipo de algoritmo
std::string
AlgoritmoQuickSort::algoritmo() const {
  return "Quick Sort";
}