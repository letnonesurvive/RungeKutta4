#pragma once

#include <vector>

using namespace std;

class RK4Solver
{
private:
    int myLeftBound;
    int myRightBound;
    int myOrder;
    double myStep;

    vector<double> myCoefficients;
    vector<double> myInitialConditions;
    vector<vector<double>> myValues;

    vector<double>& InitInitial();

public:

    RK4Solver() {};

    void SetOrder (int theOrder);

    void SetSegment (int theLeftBound, int theRightBound);

    void SetLinearCoefficients (const vector<double>& theCoefficients);

    void SetInitialConditions (const vector<double>& theInitialConditions);

    void SetStep (double theStep);

    void Solve();

    void WriteData();
};