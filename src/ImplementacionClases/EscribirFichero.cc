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

#include "../Clases/EscribirFichero.h"

void 
EscribirFichero::EscribirArchivo(const std::vector<int>& datos) {
  
}

void 
EscribirFichero::EscribirArchivo(const std::string& nombreArchivo, const std::vector<int>& datos) {
  std::ofstream archivo(nombreArchivo);
  if (archivo.is_open()) {
    for (const auto& dato : datos) {
      archivo << dato << std::endl;
    }
    archivo.close();
  } else {
    std::cerr << "No se pudo abrir el archivo para escribir." << std::endl;
  }
}