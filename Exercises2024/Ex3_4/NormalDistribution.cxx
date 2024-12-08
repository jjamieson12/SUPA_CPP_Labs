//defining the .cxx for NormalDistribution derived class 
#include "FiniteFunctions.h"
#include "NormalDistribution.h"
#include <cmath>
#include <fstream>
#include <iostream>
//now constructor definiation
NormalDistribution::NormalDistribution(double range_min, double range_max, std::string outfile, double mean, double stddev, double step_size)
    : FiniteFunction(range_min, range_max, outfile), m_mean(mean), m_stddev(stddev), m_step_size(step_size) {}
// Override the callFunction method to implement the Normal Distribution formula
double NormalDistribution::callFunction(double x) {
    //double normalizationFactor = 1.0 / (m_stddev * sqrt(2 * M_PI));

    double normalizationfactor = 1.0 / (m_stddev * sqrt(2 * M_PI));
    double exponent = -0.5 * pow((x - m_mean) / m_stddev, 2);
      return  normalizationfactor * exp(exponent);
       
}
void NormalDistribution::setMean(double mean){m_mean = mean; }
void NormalDistribution::setStdDev(double stddev){m_stddev= stddev; }
double NormalDistribution::getMean () const { return m_mean; }
double NormalDistribution::getStdDev () const { return m_stddev; }



