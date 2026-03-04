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
 * 
 * code_smell/god_class/
 * good_practices/dry/
 * oop_concepts/class_relationships
 */

#include "divide_conquer.h"
#include "instance.h"
#include "solution.h"

#include "instance_part2.h"
#include "solver.h"
#include "divide_conquer_part2.h"
#include "solution_part2.h"

#include <exception>
#include <fstream>
#include <iostream>

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

    Instance* instance = new InstancePart2();
    instance->loadFile(std::string(argv[1]));

    Solver* solver = new Solver(instance);
    solver->setStrategy(new DivideConquerPart2());

    Solution* solution = solver->executeStrategy();
    solution->saveFile(std::string(argv[2]));

    delete instance;
    delete solver;
    delete solution;

  } catch (const std::exception& e) {
    std::cerr << "\nerror: " << e.what() << "\n";
    return -1;
  } catch (...) {
    std::cerr << "\nerror: ...\n";
    return -1;
  }
  return 0;
}
