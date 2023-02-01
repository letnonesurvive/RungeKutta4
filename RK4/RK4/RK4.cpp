#include <iostream>
#include <vector>
#include <string>
#include <fstream>

#include "RK4Solver.h"

using namespace std;

inline double f (double theArgument)
{
    return theArgument;
}

inline double f (const vector<double>& theValues, 
                 const vector<double>& theCoefficients, 
                 double theStep = 0, 
                 const vector<double>& theK = {})
{
    double aRes = 0;
    auto aSize = theValues.size();
    bool isEmpty = theK.empty();

    if (isEmpty) {
        for (size_t i = 0; i < aSize; ++i) 
            aRes = aRes - theCoefficients[i] * theValues[i];
    } else {
         for (size_t i = 0; i < aSize; ++i) {
            aRes = aRes - theCoefficients[i] * (theValues[i] + theStep * theK[i]);
        }
    }

    return aRes;
}

vector<double>& RK4Solver::InitInitial()
{
    return myInitialConditions;
}

void RK4Solver::SetOrder (int theOrder)
{
    myOrder = theOrder;
}

void RK4Solver::SetSegment (int theLeftBound, int theRightBound) 
{
    myLeftBound = theLeftBound;
    myRightBound = theRightBound;
}

void RK4Solver::SetLinearCoefficients (const vector<double>& theCoefficients)
{
    myCoefficients = theCoefficients;
}

void RK4Solver::SetInitialConditions (const vector<double>& theInitialConditions) 
{
    myInitialConditions = theInitialConditions;
}

void RK4Solver::SetStep (double theStep) 
{
    myStep = theStep;
}

void RK4Solver::Solve()
{
    vector <double> aCurrentValues;
    vector <double> aNewValues;

    aCurrentValues.reserve (myOrder);
    aNewValues.reserve (myOrder);
    aCurrentValues = InitInitial();

    myValues.push_back (aCurrentValues);

    auto aLoopSize = static_cast<int> ((myRightBound - myLeftBound) / myStep);

    for (int anIndex = 0; anIndex < aLoopSize; ++anIndex) { // loop on a grid
        vector<double> k1, k2, k3, k4;
        k1.reserve(myOrder);
        k2.reserve(myOrder);
        k3.reserve(myOrder);
        k4.reserve(myOrder);

        for (int i = 0; i < myOrder; ++i) { // k1
            if (i == myOrder - 1) {
                k1.push_back (f (aCurrentValues, myCoefficients));
            } else {
                k1.push_back (f (aCurrentValues[i + 1]));
            } 
        }

        for (int i = 0; i < myOrder; ++i) { // k2
            if (i == myOrder - 1) {
                k2.push_back (f (aCurrentValues, myCoefficients, myStep / 2, k1));
            } else {
                k2.push_back (f (aCurrentValues[i + 1] + myStep * k1[i] / 2));
            } 
        }

        for (int i = 0; i < myOrder; ++i) { //k3
            if (i == myOrder - 1) {
                k3.push_back (f (aCurrentValues, myCoefficients, myStep / 2, k2));
            } else {
                k3.push_back (f (aCurrentValues[i + 1] + myStep * k2[i] / 2));
            } 
        }

        for (int i = 0; i < myOrder; ++i) { //k4
            if (i == myOrder - 1) {
                k4.push_back (f (aCurrentValues, myCoefficients, myStep, k3));
            } else {
                k4.push_back (f (aCurrentValues[i + 1] + myStep * k3[i]));
            } 
        }

        for (int i = 0; i < myOrder; ++i) {
            aNewValues.push_back (aCurrentValues[i] + myStep / 6 * (k1[i] + 2*k2[i] + 2*k3[i] + k4[i]));
        }

        myValues.push_back(aNewValues);
        aCurrentValues = aNewValues;
        aNewValues.clear();
    }
}

void RK4Solver::WriteData() 
{
    string aPath = "myData.txt";
    ofstream anFout;

    anFout.open(aPath, ofstream::app);

    if (!anFout.is_open()) {
        cout << "Error open a file" << endl;
    }
    else {
        anFout << "Step = " << myStep << endl;
        anFout << "Segment = [" << myLeftBound << ", " << myRightBound << "]" << endl;
        for (size_t i = 0; i < myValues.size(); ++i) {
            anFout << myValues[i][0] << endl;
        }
    }
}
