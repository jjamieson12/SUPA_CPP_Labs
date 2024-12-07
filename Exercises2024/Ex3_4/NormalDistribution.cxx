
/*
#include "FiniteFunctions.h"
#include "NormalDistribution.h"
#include <cmath>
#include <fstream>
#include <iostream>
#include <random>
#include <vector>

// Constructor
NormalDistribution::NormalDistribution(double range_min, double range_max, std::string outfile, double mean, double stddev, double step_size)
    : FiniteFunction(range_min, range_max, outfile), m_mean(mean), m_stddev(stddev), m_step_size(step_size) {}

// Override the callFunction method to implement the Normal Distribution formula
double NormalDistribution::callFunction(double x) {
    double normalizationFactor = 1.0 / (m_stddev * sqrt(2 * M_PI));
    double exponent = -0.5 * pow((x - m_mean) / m_stddev, 2);
    return normalizationFactor * exp(exponent);
    std::cout<<"printed the normaldistribution:"<< normalizationFactor * exp(exponent)<<std::endl;
}

//

std::vector<double> NormalDistribution::sample(int num_samples, double sigma) {
    std::vector<double> samples;
    
    // Random number generator and distribution setup
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> uniform_dist(rangeMin(), rangeMax());
    std::normal_distribution<> normal_dist(0.0, sigma);  // Normal distribution for proposal step
    
    // Initialize the first sample randomly from the uniform distribution
    double current_sample = uniform_dist(gen);
    
    for (int i = 0; i < num_samples; ++i) {
        // Propose a new sample y from the normal distribution centered at current_sample
        double proposal = current_sample + normal_dist(gen);
        
        // Ensure proposal stays within the valid range
        if (proposal < rangeMin()) proposal = rangeMin();
        if (proposal > rangeMax()) proposal = rangeMax();
        
        // Calculate the acceptance ratio A
        double A = std::min(callFunction(proposal) / callFunction(current_sample), 1.0);
        
        // Generate a random number T between 0 and 1
        double T = uniform_dist(gen);
        std::cout<< "T="<< T <<std::endl;
        
        // Accept or reject the new proposal
        if (T < A) {
            current_sample = proposal;

        }
        
        // Store the accepted sample
        samples.push_back(current_sample);
    }
    
    return samples;
}

// Setters and Getters
void NormalDistribution::setMean(double mean) { m_mean = mean; }
void NormalDistribution::setStdDev(double stddev) { m_stddev = stddev; }

double NormalDistribution::getMean() const { return m_mean; }
double NormalDistribution::getStdDev() const { return m_stddev; }

*/


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

    //return normalizationFactor * exp(exponent);
    // std::cout << "callFunction(" << x << ") -> " <<  normalizationFactor * exp(exponent)<< " with mean = " << m_mean << " and stddev = " << m_stddev << std::endl;
     return normalizationFactor * exp(exponent);
    
}


  //double evaluate(double x) const;
    std::vector<double> sample(int num_samples, double sigma) {
        std::vector<double> samples;
       return samples;
    }


// Setters and Getters
void NormalDistribution::setMean(double mean) { m_mean = mean; }
void NormalDistribution::setStdDev(double stddev) { m_stddev = stddev; }
//void NormalDistribution::setStdDev(double stddev) { m_stddev = 2; }

double NormalDistribution::getMean() const { return m_mean; }
double NormalDistribution::getStdDev() const { return m_stddev; }

