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

#ifndef INSTANCIA_VECTOR_H
#define INSTANCIA_VECTOR_H

#include "../Instancia.h"
#include <vector>

class InstanciaVector : Instancia {
 public:
   InstanciaVector();
   ~InstanciaVector() = default;
   InstanciaVector(int size);

   void mostrarValores();

   void setValue(int pos, int valor);

   int getValue(int pos);
   int getSize();

private:
   std::vector<int> vector_;

};

#endif