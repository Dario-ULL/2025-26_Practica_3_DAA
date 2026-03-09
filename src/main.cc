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
#include "Clases/DivideYVenceras.h"
#include "Clases/LeerFichero.h"
#include "Clases/Escribir.h"
#include "Clases/Algoritmos/AlgoritmoMergeSort.h"
#include "Clases/Algoritmos/AlgoritmoQuickSort.h"
#include "Clases/Algoritmos/AlgoritmoPlanificacion.h"
#include "Clases/Instancias/InstanciaVector.h"
#include "Clases/Instancias/InstanciaPlanificacion.h"

Instancia* generadorVectorEnteros (){
  int vector_size = (rand() % 15) + 5; 
  Instancia* instancia = new InstanciaVector(vector_size);
  for(int it = 0; it < vector_size; it++){
    instancia->setValue(it, rand() % 100); 
  }
  return instancia;
}

int main(int argc, char* argv[]) {
  srand(time(NULL));
  size_t numero_instancias = 5;
  std::vector<Instancia*> vector_instancias(numero_instancias);
  for (size_t it = 0; it < numero_instancias ; it++){
    vector_instancias[it] = generadorVectorEnteros();
  }
  Algoritmo* algoritmo;
  Solucion* solucion;
  Escribir escritor;
  std::string nombreArchivo = "../resultados/resultados1.txt";
  std::ofstream archivo(nombreArchivo);

  /*
  solucion = new SolucionVector();
  // EJEMPLO DE USO CON MERGE SORT
  algoritmo = new AlgoritmoMergeSort();
  solucion = algoritmo->Resolver(vector_instancias[0]);
  escritor.mostrarResultados(archivo, vector_instancias[0], solucion, algoritmo);
  escritor.mostrarResultados(std::cout, vector_instancias[0], solucion, algoritmo);  

  // EJEMPLO DE USO CON QUICK SORT
  algoritmo = new AlgoritmoQuickSort();
  solucion = algoritmo->Resolver(vector_instancias[1]);
  escritor.mostrarResultados(archivo, vector_instancias[1], solucion, algoritmo);
  escritor.mostrarResultados(std::cout, vector_instancias[1], solucion, algoritmo);  
  */

  solucion = new SolucionPlanificacion();
  //EJEMPLO DE USO ALGORITMO PLANIFICACION
  std::string json = "../json/instance_horizon7_employees5_shifts3_000.json";
  LeerFichero lector;
  InstanciaPlanificacion* instanciaOriginal = lector.leerFichero(json);
  std::cout << "archivo leido" << std::endl;
  algoritmo = new AlgoritmoPlanificacion(instanciaOriginal);
  solucion = algoritmo->Resolver(instanciaOriginal);
  escritor.mostrarResultados(archivo, vector_instancias[0], solucion, algoritmo);
  escritor.mostrarResultados(std::cout, vector_instancias[0], solucion, algoritmo);   

  archivo.close();

  return 0;
}