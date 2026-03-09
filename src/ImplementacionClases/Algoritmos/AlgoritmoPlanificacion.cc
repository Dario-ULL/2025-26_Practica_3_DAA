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

#include "../../Clases/Algoritmos/AlgoritmoPlanificacion.h"

AlgoritmoPlanificacion::AlgoritmoPlanificacion(InstanciaPlanificacion* instancia) {
  instanciaOriginal_ = instancia;
}

double
AlgoritmoPlanificacion::calcularCalidad(SolucionPlanificacion* solucion, InstanciaPlanificacion* instanciaPlanificacion, int numEmp, int numTurnos) {
  double totalSatisfaccion = 0;
  int totalTurnosCubiertos = 0;
  int horizonte = solucion->getHorizonte();
  for (int d = 0; d < horizonte; ++d) {
    for (int t = 0; t < numTurnos; ++t) {
      int cuentaTurno = 0;
      for (int e = 0; e < numEmp; ++e) {
        if (solucion->getTurnoAsignado(e, d) == t) {
          totalSatisfaccion += instanciaPlanificacion->getSatisfaccion(e, d, t);
          cuentaTurno++;
        }
      }
      if (cuentaTurno >= instanciaPlanificacion->getMinEmpleados(d, t)) {
        totalTurnosCubiertos++;
      }
    }
  }
  // f(x) = SUMA(satisfaccion) + SUMA(turnos_cubiertos) * 100
  double calidad = totalSatisfaccion + (totalTurnosCubiertos * 100);
  return calidad;
}

int 
AlgoritmoPlanificacion::contarDiasTrabajados(SolucionPlanificacion* solucion, int empIdx) {
  int contador = 0;
  for (int dia = 0; dia < solucion->getHorizonte(); ++dia) {
    if (solucion->getTurnoAsignado(empIdx, dia) != -1) {
      contador++;
    }
  }
  return contador;
}

bool 
AlgoritmoPlanificacion::esPequeño(Instancia*instancia) {
  try {
    if (std::any_cast<int>(instancia->getSize()) <= 1) {
      return true;
    }
  } catch (const std::bad_any_cast& e) {
    std::cerr << "Error: No se pudo convertir el tamaño de la instancia a size_t. AlgoritmoPlanificacion" << e.what() << std::endl;
  }
  return false;
}

Solucion* 
AlgoritmoPlanificacion::resolverPequeño(Instancia* instancia) {
  InstanciaPlanificacion* instanciaPlanificacion = static_cast<InstanciaPlanificacion*>(instancia);
  int numEmpleados = instanciaPlanificacion->getNumEmpleados();
  int numTurnos = instanciaPlanificacion->getNumTurnos();
  SolucionPlanificacion* solucion = new SolucionPlanificacion(numEmpleados, 1, numTurnos);
  for (int turnoIdx = 0; turnoIdx < numTurnos; ++turnoIdx) {
    int requeridos = instanciaPlanificacion->getMinEmpleados(0, turnoIdx);
    int asignados = 0;
    std::vector<int> candidatos = instanciaPlanificacion->getEmpleadosOrdenadosPorSatisfaccion(0, turnoIdx);

    for (int empIdx : candidatos) {
      if (asignados >= requeridos) break;
      
      if (solucion->getTurnoAsignado(empIdx, 0) == -1) {
        solucion->asignarTurno(empIdx, 0, turnoIdx);
        asignados++;
      }
    }
  }
  solucion->setCalidad(calcularCalidad(solucion, instanciaPlanificacion, numEmpleados, numTurnos));
  return solucion;
}

std::vector<Instancia*> 
AlgoritmoPlanificacion::dividir(Instancia* instancia) {
  InstanciaPlanificacion* instanciaPlanificacion = static_cast<InstanciaPlanificacion*>(instancia);
  int n = std::any_cast<int>(instanciaPlanificacion->getSize());
  int mid = n / 2;
  
  InstanciaPlanificacion* subIzq = new InstanciaPlanificacion(mid);
  InstanciaPlanificacion* subDer = new InstanciaPlanificacion(n - mid);

  for (int i = 0; i < instanciaPlanificacion->getNumTurnos(); ++i) {
    subIzq->añadirTurno("T" + std::to_string(i));
    subDer->añadirTurno("T" + std::to_string(i));
  }
  for (int i = 0; i < instanciaPlanificacion->getNumEmpleados(); ++i) {
    subIzq->añadirEmpleado("E" + std::to_string(i), instanciaPlanificacion->getDiasDescansoRequeridos(i));
    subDer->añadirEmpleado("E" + std::to_string(i), instanciaPlanificacion->getDiasDescansoRequeridos(i));
  }

  for (int dia = 0; dia < n; ++dia) {
    for (int turnoIdx = 0; turnoIdx < instanciaPlanificacion->getNumTurnos(); ++turnoIdx) {
      if (dia < mid) {
        subIzq->setMinEmpleados(dia, turnoIdx, instanciaPlanificacion->getMinEmpleados(dia, turnoIdx));
        for (int empIdx = 0; empIdx < instanciaPlanificacion->getNumEmpleados(); ++empIdx) {
          int valor = instanciaPlanificacion->getSatisfaccion(empIdx, dia, turnoIdx); 
          subIzq->setSatisfaccion(empIdx, dia, turnoIdx, valor);
        }
      } else {
        subDer->setMinEmpleados(dia - mid, turnoIdx, instanciaPlanificacion->getMinEmpleados(dia, turnoIdx));
        for (int empIdx = 0; empIdx < instanciaPlanificacion->getNumEmpleados(); ++empIdx) {
          int valor = instanciaPlanificacion->getSatisfaccion(empIdx, dia, turnoIdx);
          subDer->setSatisfaccion(empIdx, dia - mid, turnoIdx, valor);
        }
      }
    }
  }
  return {subIzq, subDer};
}

Solucion* 
AlgoritmoPlanificacion::combinarSolucion(std::vector<Solucion*> subSoluciones) {
  SolucionPlanificacion* solIzq = static_cast<SolucionPlanificacion*>(subSoluciones[0]);
  SolucionPlanificacion* solDer = static_cast<SolucionPlanificacion*>(subSoluciones[1]);

  int horizonteIzq = solIzq->getHorizonte();
  int horizonteDer = solDer->getHorizonte();
  int numEmpleados = solIzq->getNumEmpleados();
  int numTurnos = instanciaOriginal_->getNumTurnos();
  SolucionPlanificacion* resultado = new SolucionPlanificacion(numEmpleados, horizonteIzq + horizonteDer, numTurnos);

  // 1. Concatenar las asignaciones de ambos lados
  for (int empIdx = 0; empIdx < numEmpleados; ++empIdx) {
    for (int dia = 0; dia < horizonteIzq; ++dia) {
      resultado->asignarTurno(empIdx, dia, solIzq->getTurnoAsignado(empIdx, dia));
    }
    for (int dia = 0; dia < horizonteDer; ++dia) {
      resultado->asignarTurno(empIdx, horizonteIzq + dia, solDer->getTurnoAsignado(empIdx, dia));
    }
  }

  // 2. Repartir turnos si se violan descansos C[e]
  if (resultado->getHorizonte() == instanciaOriginal_->getHorizonte()) {
    for (int empIdx = 0; empIdx < numEmpleados; ++empIdx) {
      int maxDiasTrabajo = resultado->getHorizonte() - instanciaOriginal_->getDiasDescansoRequeridos(empIdx);
      while (contarDiasTrabajados(resultado, empIdx) > maxDiasTrabajo) {
        bool cambioRealizado = false;
        for (int dia = 0; dia < resultado->getHorizonte() && !cambioRealizado; ++dia) {
          int turnoActual = resultado->getTurnoAsignado(empIdx, dia);
          if (turnoActual != -1) {
            for (int sustitutoIdx = 0; sustitutoIdx < numEmpleados; ++sustitutoIdx) {
              if (resultado->getTurnoAsignado(sustitutoIdx, dia) == -1 && contarDiasTrabajados(resultado, sustitutoIdx) < (resultado->getHorizonte() - instanciaOriginal_->getDiasDescansoRequeridos(sustitutoIdx))) {
                resultado->asignarTurno(sustitutoIdx, dia, turnoActual);
                resultado->asignarTurno(empIdx, dia, -1);
                cambioRealizado = true;
                break;
              }
            }
          }
        }
        if (!cambioRealizado) break;
      }
    }
  }
  // 3. Cálculo de calidad final f(x)
  double calidadFinal = calcularCalidad(resultado, instanciaOriginal_, numEmpleados, numTurnos);
  resultado->setCalidad(calidadFinal);
  return resultado;
}

std::string
AlgoritmoPlanificacion::algoritmo() const {
  return "Algoritmo de Planificacion";
}