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

class Instancia;

class InstanciaVector : public Instancia {
 public:
	InstanciaVector();
	InstanciaVector(int size);
	InstanciaVector(std::vector<int>);
	~InstanciaVector() = default;

	std::any getSize() const override;
	std::any getValue(std::any) const override;
	void setValue(std::any, std::any) override;
	void mostrarValores(std::ostream&) const override;
 private:
	std::vector<int> instaciaVector_;
};

#endif