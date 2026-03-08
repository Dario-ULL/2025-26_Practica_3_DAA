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
#include "Clases/Escribir.h"
#include "Clases/Algoritmos/AlgoritmoMergeSort.h"
//#include "Clases/Algoritmos/AlgoritmoQuickSort.h"
#include "Clases/Instancias/InstanciaVector.h"


/// CAMBIAR PARA QUE SEA "TRUE RANDOM"? EL RAND ES DE 10 POR EL MOMENTO, CAMBIAR A 100 ANTES DE ENTREGAR
Instancia* generadorVectorEnteros (){
  int vector_size = (rand() % 15) + 5; 
  Instancia* instancia = new InstanciaVector(vector_size);
  for(int it = 0; it < vector_size; it++){
    instancia->setValue(it, rand() % 100); 
  }
  return instancia;
}

int main(int argc, char* argv[]) {
  std::cout << "Hola mundo" << std::endl;
  srand(time(NULL));
  size_t numero_instancias = 5;
  std::vector<Instancia*> vector_instancias(numero_instancias);
  for (size_t it = 0; it < numero_instancias ; it++){
    vector_instancias[it] = generadorVectorEnteros();
  }
    std::cout << "1" << std::endl;
  Algoritmo* algoritmo;
  Solucion* solucion;
    std::cout << "4" << std::endl;
  algoritmo = new AlgoritmoMergeSort();
  solucion = new SolucionVector();
    std::cout << "5" << std::endl;
  solucion = algoritmo->Resolver(vector_instancias[0]);
    std::cout << "7" << std::endl;
  Escribir escritor;
    std::cout << "6" << std::endl;
  std::string nombreArchivo = "../resultados/resultados1.txt";
  std::ofstream archivo(nombreArchivo);
    std::cout << "2" << std::endl;
  escritor.mostrarResultados(archivo, vector_instancias[0], solucion, algoritmo);
    std::cout << "3" << std::endl;
  archivo.close();
    std::cout << "4" << std::endl;
  escritor.mostrarResultados(std::cout, vector_instancias[0], solucion, algoritmo);

    std::cout << "Adios mundo" << std::endl;
  return 0;
}