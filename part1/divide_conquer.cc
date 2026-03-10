#include "divide_conquer.h"
#include "instance.h"
#include "solution.h"

Solution* DivideConquer::Solve(const Instance& instance) const { 
  if (Small(instance)) 
    return SolveSmall(instance);
  else {
    InstanceHalves m = Divide(instance);
    Solution* S1 = Solve(*m.first);
    Solution* S2 = Solve(*m.second);
    Solution* S = Combine(S1, S2);

    delete m.first;
    delete m.second;
    delete S1;
    delete S2;
    
    return S;
  }
}