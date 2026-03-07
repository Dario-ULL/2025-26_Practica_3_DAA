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

#include <iostream>
#include "../../Clases/Instancias/InstanciaVector.h"

InstanciaVector::InstanciaVector(){
    vector_.resize(0);
}

InstanciaVector::InstanciaVector(int size){
    vector_.resize(size);
}

void InstanciaVector::mostrarValores(){
    for(int it = 0; it < getSize(); it++){
        std::cout << "[" << vector_[it] << "] ";
    }
    std::cout << std::endl;
}

void InstanciaVector::setValue(int pos, int valor){
    vector_[pos] = valor;
}

int InstanciaVector::getValue(int pos){
    return vector_[pos];
}

int InstanciaVector::getSize(){
    return vector_.size();
}