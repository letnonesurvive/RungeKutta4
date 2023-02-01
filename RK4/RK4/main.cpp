#include "RK4Solver.h"

void Init (RK4Solver& theSolver)
{
    int anOrder = 5;

    int A = 0;
    int B = 5;

    vector <double> aCoefficients;
    vector <double> anInitialConditions;
    aCoefficients.reserve (anOrder);
    anInitialConditions.reserve (anOrder);

    aCoefficients = { 243, 405, 270, 90, 15};
    anInitialConditions = { 0, 3, 9, 8, 0 };

    double aStep = 0.01;

    theSolver.SetOrder (anOrder);
    theSolver.SetSegment (A, B);
    theSolver.SetInitialConditions (anInitialConditions);
    theSolver.SetLinearCoefficients (aCoefficients);
    theSolver.SetStep (aStep);
}

int main()
{
    RK4Solver aSolver;

    Init (aSolver);
    aSolver.Solve();
    aSolver.WriteData();
}
