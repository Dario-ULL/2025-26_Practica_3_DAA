/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Diseño y Analisis de Complejidad
 * 
 * @author  Dario Dominguez Gonzalez, Carlos Plata Luis
 * @date    10/03/2026
 * @brief   Implementacion de un simulador de algoritmos de divide y venceras,
 *          utilizando los principios SOLID, el patron de estrategia y el patron Template.
 * @example Ejemplo de uso:
 *          $ make
 *          $ ./Ejecutable
*/

#include <iostream>
#include <vector>
#include <random>
#include <memory>

#include "Clases/Algoritmo.h"
#include "Clases/Instancia.h"
#include "Clases/Instancias/InstanciaVector.h"
#include "Clases/DivideYVenceras.h"
#include "Clases/LeerFichero.h"
#include "Clases/EscribirFichero.h"
#include "Clases/Algoritmos/AlgoritmoMergeSort.h"
#include "Clases/Algoritmos/AlgoritmoQuickSort.h"
#include "Clases/Instancias/InstanciaVector.h"


/// CAMBIAR PARA QUE SEA "TRUE RANDOM"? EL RAND ES DE 10 POR EL MOMENTO, CAMBIAR A 100 ANTES DE ENTREGAR
Instancia* generadorVectorEnteros (){
  int vector_size = rand()%10;
  Instancia* instancia = new InstanciaVector(vector_size);
  for(int it = 0; it < vector_size; it++){
    instancia->setValue(it, rand()%10);
  }
  return instancia;
}

int main(int argc, char* argv[]) {

  std::cout << "Hola" << std::endl;

  /// MODIFICAR PARA PEDIR EL NUMERO DE INSTANCIAS O GENERARLO ALEATORIAMENTE
  size_t numero_instancias = 5;
  std::vector<Instancia*> vector_instancias(numero_instancias);
  for (size_t it = 0; it < numero_instancias ; it++){
    vector_instancias[it] = generadorVectorEnteros();
  }

  /// Muestra el vector de instancias para testeo 
  for (size_t it = 0; it < vector_instancias.size(); it++){
    std::cout << "El vector " << it << " tiene los valores: ";
    vector_instancias[it]->mostrarValores();
  } 
  

  std::cout << "Adios" << std::endl;  
  return 0;
}