#pragma once 
#include <string>
#include "FiniteFunctions.h"
//defining the derived class as NormalDistribution and the base class is FiniteFunction
class NormalDistribution : public FiniteFunction {
private:
    double m_mean, m_stddev, m_step_size;  //defining the variables
public: 
    std::vector<std::pair<double, double>> m_samples; //creating the vector pair
NormalDistribution(

        double range_min, double range_max, std::string outfile, double mean = 1.0, double stddev = 3.0, 
        double step_size = 0.1);
        //override call method
        double callFunction(double x) override;
        void setMean (double mean);
        void setStdDev(double stddev);
        double getMean () const;
        double getStdDev() const;
};     

