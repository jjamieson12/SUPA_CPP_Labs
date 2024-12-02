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
    return normalizationFactor * exp(exponent);
}


// Method to generate samples for the normal distribution
void NormalDistribution::generateSamples(int num_samples) {
    std::ofstream file("Outputs/data/NormalDistributionSamples.txt");
    if (!file.is_open()) {
        std::cerr << "Error: Could not create the file for samples.\n";
        return;
    }

    // Create random number generator for normal distribution
    std::random_device rd;
    std::mt19937 gen(rd());
    std::normal_distribution<double> distribution(m_mean, m_stddev);

    // Generate samples and write them to the file
    for (int i = 0; i < num_samples; ++i) {
        double sample = distribution(gen);
        file << sample << "\n";
    }

    file.close();
    std::cout << num_samples << " samples generated and written to 'NormalDistributionSamples.txt'.\n";
}

// Setters and Getters
void NormalDistribution::setMean(double mean) { m_mean = mean; }
void NormalDistribution::setStdDev(double stddev) { m_stddev = stddev; }
double NormalDistribution::getMean() const { return m_mean; }
double NormalDistribution::getStdDev() const { return m_stddev; }
