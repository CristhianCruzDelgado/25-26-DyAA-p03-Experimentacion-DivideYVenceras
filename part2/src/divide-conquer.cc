#include "divide-conquer.h" // declaration
#include "instance.h" // instance
#include "solution.h" // solution

Solution* DivideConquer::solve(Instance* I, int size) const {
  if (!I) throw std::runtime_error("Bad pointer: instance null. DivideConquer::solve");
  if (small(I)) 
    return solveSmall(I);
  else {
    InstanceHalves m = divide(I, size);
    Solution* S1 = solve(m.first, size / 2);
    Solution* S2 = solve(m.second, size / 2);
    Solution* S = combine(S1, S2);
    delete m.first;
    delete m.second;
    delete S1;
    delete S2;
    return S;
  }
}