/**
 ** Universidad de La Laguna
 * Degree: Ingeniería Informática
 * Signature: Diseño y Análisis de Algoritmos
 * Practice 03: Planifiación de empleados
 * Authors: 
 *   Cristhian Adoney Cruz Delgado
 *   Michelangelo Da Cruz Bochicchio
 * Emails: 
 *   alu0101648293@ull.edu.es
 *   alu0101651217@ull.edu.es
 * Description: plans employee schedules
 */

#include "loader.h"
#include "loader-employee-day-shift.h"
#include "instance.h"
#include "employees-days-shifts.h"
#include "algorithm.h"
#include "plan-employees.h"
#include "solution.h"
#include "schedule.h"
#include "saver.h"
#include "saver-schedule.h"

#include <iostream>
#include <stdexcept>

const char* HELP_MESSAGE = "\nHelp: This program plans employee schedules. \
                            \nTry: ./planificar-empleados                          ~ Executable \
                            \ntest/instance_horizonX_employeesX_shifX_00[0|1].json ~ Input File \
                            \nsltn/solution_horizonX_employeesX_shifX_00[0|1].json ~ Output file\n";

int main(int argc, char* argv[]) {
  try {
    if (argc == 2 && std::string(argv[1]) == "--help") {
      std::cout << HELP_MESSAGE; 
      return 0;
    }
    if (argc != 3) throw std::invalid_argument("Missing arguments");

    Loader* lo = new LoaderEmployeeDayShift();
    Instance* in = lo->load(std::string(argv[1]));
    Algorithm* al = new PlanEmployees(); 
    in->setAlgorithm(al);
    Solution* so = in->execute();
    Saver* sa = new SaverSchedule();
    sa->save(in, so, std::string(argv[2]));

    delete lo;
    delete in;
    delete al;
    delete so;
    delete sa;

  } catch (const std::exception& e) {
    std::cerr << "\nerror: " << e.what() << "\n";
    return -1;
  } catch (...) {
    std::cerr << "\nerror: ...\n";
    return -1;
  }
  return 0;
}