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

// Método plantilla para resolver el problema usando divide y vencerás
Solucion* DivideYVenceras::Resolver(Instancia* instancia){
  if (esPequeño(instancia)) {
    return resolverPequeño(instancia);
  } else {
    std::vector<Instancia*> instanciaDividida = dividir(instancia);
    std::vector<Solucion*> soluciones(instanciaDividida.size());
    for (size_t it = 0; it < instanciaDividida.size(); it++) {
      soluciones[it] = Resolver(instanciaDividida[it]);
    }
    solucion_ = combinarSolucion(soluciones);  
    return solucion_;
  }
}