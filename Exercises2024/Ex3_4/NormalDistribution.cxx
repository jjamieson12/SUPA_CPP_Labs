#include "FiniteFunctions.h"
#include "NormalDistribution.h"
#include <cmath>
#include <fstream>
#include <iostream>

// Constructor
 
NormalDistribution::NormalDistribution(double range_min, double range_max, std::string outfile, double mean, double stddev, double step_size)
    : FiniteFunction(range_min, range_max, outfile), m_mean(mean), m_stddev(stddev), m_step_size(step_size) {}

// Override the callFunction method to implement the Normal Distribution formula
double NormalDistribution::callFunction(double x) {
    double normalizationFactor = 1.0 / (m_stddev * sqrt(2 * M_PI));
    double exponent = -0.5 * pow((x - m_mean) / m_stddev, 2);
<<<<<<< HEAD
    return normalizationFactor * exp(exponent);
}
  
=======
    //return normalizationFactor * exp(exponent);
     std::cout << "callFunction(" << x << ") -> " <<  normalizationFactor * exp(exponent)<< " with mean = " << m_mean << " and stddev = " << m_stddev << std::endl;
     return normalizationFactor * exp(exponent);
    
}

<<<<<<< HEAD
>>>>>>> 26820fc087cc052807e3749fc049cc2effb02692
=======
  //double evaluate(double x) const;
    std::vector<double> sample(int num_samples, double sigma) {
        std::vector<double> samples;
       return samples;
    }

>>>>>>> f1b6b25 (error in fitting the sampling)
// Setters and Getters
void NormalDistribution::setMean(double mean) { m_mean = mean; }
void NormalDistribution::setStdDev(double stddev) { m_stddev = stddev; }
//void NormalDistribution::setStdDev(double stddev) { m_stddev = 2; }

double NormalDistribution::getMean() const { return m_mean; }
double NormalDistribution::getStdDev() const { return m_stddev; }

