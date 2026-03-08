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

#include "../Clases/DivideYVenceras.h"

Solucion* DivideYVenceras::Resolver(Instancia* instancia){
  std::cout << "DIVIDE ET IMPERA" << std::endl;
  if (esPequeño(instancia)) {
      std::cout << "small" << std::endl;
    return resolverPequeño(instancia);
  } else {
    std::cout << "DIVIDE" << std::endl;
    std::vector<Instancia*> instanciaDividida = dividir(instancia);
      std::cout << "ET"  << std::endl;
    std::vector<Solucion*> soluciones(instanciaDividida.size());
      std::cout << "IMPERA" << std::endl;
    for (size_t it = 0; it < instanciaDividida.size(); it++) {
      soluciones[it] = Resolver(instanciaDividida[it]);
    }
      std::cout << "combinacion" << std::endl;
    solucion_ = combinarSolucion(soluciones);  
    return solucion_;
  }
}