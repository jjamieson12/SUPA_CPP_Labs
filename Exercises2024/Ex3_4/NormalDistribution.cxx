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
/*


// this will generate one sample data file for one dimensional data 
std::vector<double> NormalDistribution::sample(int num_samples, double sigma) {
 

    std::vector<double> samples;  // To store the accepted samples
    
    // Initialize random number generators
    std::random_device rd;
    std::mt19937 gen(rd());
    
    // Uniform distribution for sampling the initial sample x1
    std::uniform_real_distribution<> uniform_dist(m_RMin, m_RMax);
    
    // Normal distribution for proposing new samples (Gaussian centered on current sample)
    std::normal_distribution<> normal_dist(0.0, sigma);

    // Start by sampling an initial value from the uniform distribution
    double current_sample = uniform_dist(gen);

    // Perform Metropolis sampling
    for (int i = 0; i < num_samples; ++i) {
        // Propose a new sample y, drawn from a Gaussian centered on the current sample
        double proposal = current_sample + normal_dist(gen);

        // Ensure the proposal is within bounds [m_RMin, m_RMax]
        if (proposal < m_RMin) proposal = m_RMin;
        if (proposal > m_RMax) proposal = m_RMax;

        // Calculate the acceptance ratio A = min(f(y) / f(xi), 1)
        double A = std::min(callFunction(proposal) / callFunction(current_sample), 1.0);
        
        // Generate a random number T between 0 and 1
        double T = uniform_dist(gen);

        // If T < A, accept the new proposal
        if (T < A) {
            current_sample = proposal;  // Move to the new sample
        }

        // Store the accepted sample
        samples.push_back(current_sample);
    }

    // Save the sampled data to a file (optional)
    std::ofstream output_file("Outputs/data/normal_sampled_data.txt");
    if (!output_file) {
        std::cerr << "Unable to write into the file!" << std::endl;
        return samples;
    }

    // Write the sampled data to the file
    for (const auto& sample : samples) {
        output_file << sample << "\n";  // Save each sample on a new line
    }

    // Close the output file
    output_file.close();

    return samples;
}
*/