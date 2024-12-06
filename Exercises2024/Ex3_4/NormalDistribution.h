//#ifndef NORMALDISTRIBUTION_H
//#define NORMALDISTRIBUTION_H
#pragma once
#include <string>
#include "FiniteFunctions.h"

class NormalDistribution : public FiniteFunction {
private:
    double m_mean;    // Mean of the normal distribution
    double m_stddev;  // Standard deviation of the normal distribution
    double m_step_size;
    
public:
    // Constructor with range and output file, mean, and standard deviation
     //double sample(int N, double mean);  
    std::vector<std::pair<double, double>> m_samples;
    NormalDistribution(

        double range_min, double range_max, std::string outfile, double mean = 1.0, double stddev = 3.0, double step_size = 0.1);

    

    // Override the callFunction method
    double callFunction(double x) override;
     std::vector<double> sample(int num_samples, double sigma);

    // Optional: Provide methods to set/get mean and standard deviation
    void setMean(double mean);
    void setStdDev(double stddev);

    double getMean() const;
    double getStdDev() const;    
 
};

