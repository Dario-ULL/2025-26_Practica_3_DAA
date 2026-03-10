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
#include <chrono>
#include <any>
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

// Método para generar vectores de enteros con tamaño y valores aleatorios
Instancia* 
generadorVectorEnteros (){
  int vector_size = (rand() % 15) + 5; 
  InstanciaVector* instancia = new InstanciaVector(vector_size);
  for(int it = 0; it < vector_size; it++){
    instancia->setValue(it, rand() % 100); 
  }
  return instancia;
}

// Método para generar vectores de enteros aleatorios con tamaño fijo
Instancia* 
generadorVectorEnteros (int size){
  int vector_size = size; 
  InstanciaVector* instancia = new InstanciaVector(vector_size);
  for(int it = 0; it < vector_size; it++){
    instancia->setValue(it, rand() % 100); 
  }
  return instancia;
}

// Método para generar un vector de instancias de vectores de enteros
std::vector<Instancia*> 
generadorVectorDeVectores(int size){
  srand(time(NULL));
  size_t numero_instancias = size;
  std::vector<Instancia*> vector_instancias(numero_instancias);
  for (size_t it = 0; it < numero_instancias ; it++){
    vector_instancias[it] = generadorVectorEnteros();
  }
  return vector_instancias;
}

// Método que ejecuta una lista de instancias tanto con QuickSort como con MergeSort,
// muestra las soluciones y compara los tiempos de ejecución
void
compararMergeQuickSort(std::vector<Instancia*> vector_instancias){
  Solucion* solucion;
  Escribir escritor;
  std::string nombreArchivo = "../resultados/resultados1.txt";
  std::ofstream archivo(nombreArchivo);

  Algoritmo* algoritmo_quick = new AlgoritmoQuickSort();
  Algoritmo* algoritmo_merge = new AlgoritmoMergeSort();
  solucion = new SolucionVector();

  
  std::cout << "Instancia \t  Tamaño\t QuickSort \t MergeSort" << std::endl;
  for(size_t it = 0; it < vector_instancias.size(); it++){
    auto instancia_size = std::any_cast<size_t>(vector_instancias[it]->getSize());
    std::cout << "    " << it << "\t\t";
    std::cout << "    " <<  instancia_size << "\t";

    auto start = std::chrono::high_resolution_clock::now();
    solucion = algoritmo_quick->Resolver(vector_instancias[it]);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duracion_quicksort = end - start;

    start = std::chrono::high_resolution_clock::now();
    solucion = algoritmo_merge->Resolver(vector_instancias[it]);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duracion_mergesort = end - start;

    std::cout << "\t " << duracion_quicksort.count()*1000 << "ms";
    std::cout << "\t " << duracion_mergesort.count()*1000 << "ms" << std::endl;
  }
  for(size_t it = 0; it < vector_instancias.size(); it++){

    solucion = algoritmo_quick->Resolver(vector_instancias[it]);
    escritor.mostrarResultados(archivo, vector_instancias[it], solucion, algoritmo_quick);
    escritor.mostrarResultados(std::cout, vector_instancias[it], solucion, algoritmo_quick);  

    solucion = algoritmo_merge->Resolver(vector_instancias[it]);
    escritor.mostrarResultados(archivo, vector_instancias[it], solucion, algoritmo_merge);
    escritor.mostrarResultados(std::cout, vector_instancias[it], solucion, algoritmo_merge);
  }
}

// Método para resolver una instancia de QuickSort y mostrar su tiempo de ejecución
void
resolverQuickSort(std::vector<Instancia*> vector_instancias){

  Algoritmo* algoritmo_quick = new AlgoritmoQuickSort();
  Solucion* solucion;
  Escribir escritor;
  std::string nombreArchivo = "../resultados/resultados1.txt";
  std::ofstream archivo(nombreArchivo);


    for(size_t it = 0; it < vector_instancias.size(); it++){
    auto start = std::chrono::high_resolution_clock::now();
    solucion = algoritmo_quick->Resolver(vector_instancias[it]);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duracion_quicksort = end - start;
    escritor.mostrarResultados(archivo, vector_instancias[it], solucion, algoritmo_quick);
    escritor.mostrarResultados(std::cout, vector_instancias[it], solucion, algoritmo_quick);  

    std::cout << "Se tardó: " << duracion_quicksort.count()*1000 << "ms" << std::endl;
  }
}

// Método para resolver una instancia de MergeSort y mostrar su tiempo de ejecución
void
resolverMergeSort(std::vector<Instancia*> vector_instancias){

  Algoritmo* algoritmo_merge = new AlgoritmoMergeSort();
  Solucion* solucion;
  Escribir escritor;
  std::string nombreArchivo = "../resultados/resultados1.txt";
  std::ofstream archivo(nombreArchivo);


  for(size_t it = 0; it < vector_instancias.size(); it++){
    auto start = std::chrono::high_resolution_clock::now();
    solucion = algoritmo_merge->Resolver(vector_instancias[it]);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> duracion_mergesort = end - start;

    escritor.mostrarResultados(archivo, vector_instancias[it], solucion, algoritmo_merge);
    escritor.mostrarResultados(std::cout, vector_instancias[it], solucion, algoritmo_merge);  
    
    std::cout << "Se tardó: "  << duracion_mergesort.count()*1000 << "ms" << std::endl;
  }
}

// Método para resolver el problema de planificación, usando un archivo por defecto
void
resolverPlanificador(std::string nombre_fichero){
  std::vector<Instancia*> vector_instancias = generadorVectorDeVectores(5);
  Algoritmo* algoritmo;
  Solucion* solucion;
  Escribir escritor;
  std::string nombreArchivo = "../resultados/resultados1.txt";
  std::ofstream archivo(nombreArchivo);

  solucion = new SolucionPlanificacion();
  //EJEMPLO DE USO ALGORITMO PLANIFICACION
  std::string json = "../json/" + nombre_fichero;
  LeerFichero lector;
  InstanciaPlanificacion* instanciaOriginal = lector.leerFichero(json);
  algoritmo = new AlgoritmoPlanificacion(instanciaOriginal);
  solucion = algoritmo->Resolver(instanciaOriginal);
  escritor.mostrarResultados(archivo, solucion, algoritmo);
  escritor.mostrarResultados(std::cout, solucion, algoritmo);   
  archivo.close();
}

int main(int argc, char* argv[]) {

  std::cout << "Elija el modo de ejecución:" << std::endl;
  std::cout << "1. Modo Normal" << std::endl;
  std::cout << "2. Modo Debug"  << std::endl;
  std::cout << "3. Comparador"  << std::endl;
  std::cout << "4. Planificador"<< std::endl;
  
  int selector_algoritmo;
  int archivo_base;
  int modo;
  std::string nombre_archivo;
  std::cin >> modo;
  std::vector<Instancia*> vector_instancias = generadorVectorDeVectores(5);
  switch (modo){
    case 1:
      std::cout << "Elija el algoritmo a ejecutar" << std::endl;
      std::cout << "1. QuickSort" << std::endl;
      std::cout << "2. MergeSort" << std::endl;

      std::cin >> selector_algoritmo;
      switch (selector_algoritmo){
        case 1:
          resolverQuickSort(vector_instancias);
          break;
        case 2:
          resolverMergeSort(vector_instancias);
          break;
        default:
          std::cout << "Elija uno de los modos disponibles escribiendo el número correspondiente" << std::endl;
          break;
      }
      break;
      
    case 2:
      std::cout << "Elija el algoritmo a ejecutar" << std::endl;
      std::cout << "1. QuickSort" << std::endl;
      std::cout << "2. MergeSort" << std::endl;
      std::cin >> selector_algoritmo;

      std::cout << "Elija el tamaño de la instancia" << std::endl;
      int instancia_size;
      std::cin >> instancia_size;

      switch (selector_algoritmo){
        case 1:
          resolverQuickSort({generadorVectorEnteros(instancia_size)});
          break;
        case 2:
          resolverMergeSort({generadorVectorEnteros(instancia_size)});
          break;
        default:
          std::cout << "Elija uno de los modos disponibles escribiendo el número correspondiente" << std::endl;
          break;
      }
      break;
    case 3:
      compararMergeQuickSort(vector_instancias);
      break;

    case 4:
      std::cout << "1. Usar el archivo por defecto (instance_horizon7_employees5_shifts3_000.json)" << std::endl;
      std::cout << "2. Elegir el archivo a usar" << std::endl;
      std::cin >> archivo_base;
      if (archivo_base == 1)
        resolverPlanificador("instance_horizon7_employees5_shifts3_000.json");
      else{
        std::cout << "Introduzca el nombre del archivo" << std::endl;
        std::cin >> nombre_archivo;
        resolverPlanificador(nombre_archivo);
      }
      //std::string archivo_por_defecto = "instance_horizon7_employees5_shifts3_000.json";
      break;
    default:
      std::cout << "Elija uno de los modos disponibles escribiendo el número correspondiente" << std::endl;
      break;

  }
  return 0;
}