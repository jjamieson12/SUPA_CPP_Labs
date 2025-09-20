#include <iostream>
#include <vector>
#include <random>
#include <cmath>
#include <functional>
#include <iomanip>

// Base class for distributions
class Distribution {
protected:
    double range_min, range_max;

public:
    Distribution(double range_min, double range_max) : range_min(range_min), range_max(range_max) {}

    virtual double function(double x) const = 0;

    std::vector<double> metropolis_sampling(int n_samples, double initial, double std_dev) {
        std::vector<double> samples;
        double current = initial;

        // Random number generators
        std::random_device rd;
        std::mt19937 gen(rd());
        std::normal_distribution<> normal_dist(0.0, std_dev);
        std::uniform_real_distribution<> uniform_dist(0.0, 1.0);

        for (int i = 0; i < n_samples; ++i) {
            // Generate candidate point
            double candidate = current + normal_dist(gen);

            // Ensure candidate is within range
            if (candidate >= range_min && candidate <= range_max) {
                double acceptance_prob = std::min(1.0, function(candidate) / function(current));
                // Accept or reject
                if (uniform_dist(gen) < acceptance_prob) {
                    current = candidate;
                }
            }
            samples.push_back(current);
        }

        return samples;
    }

    virtual ~Distribution() = default;
};

// Uniform distribution subclass
class UniformDistribution : public Distribution {
public:
    UniformDistribution(double range_min, double range_max) : Distribution(range_min, range_max) {}

    double function(double x) const override {
        if (x >= range_min && x <= range_max) {
            return 1.0 / (range_max - range_min);
        }
        return 0.0;
    }
};

// Gaussian distribution subclass
class GaussianDistribution : public Distribution {
private:
    double mean, std_dev;

public:
    GaussianDistribution(double mean, double std_dev, double range_min, double range_max)
        : Distribution(range_min, range_max), mean(mean), std_dev(std_dev) {}

    double function(double x) const override {
        double exponent = -0.5 * std::pow((x - mean) / std_dev, 2);
        return (1.0 / (std_dev * std::sqrt(2 * M_PI))) * std::exp(exponent);
    }
};

// Utility function to print samples
void print_samples(const std::vector<double>& samples) {
    for (size_t i = 0; i < samples.size(); ++i) {
        std::cout << std::fixed << std::setprecision(3) << samples[i] << (i % 10 == 9 ? "\n" : "\t");
    }
    std::cout << std::endl;
}

int main() {
    // Parameters
    int n_samples = 50;
    double initial_point = 0.0;
    double std_dev = 2.0;

    // Uniform distribution example
    UniformDistribution uniform_dist(-15.0, 15.0);
    std::vector<double> samples_uniform = uniform_dist.metropolis_sampling(n_samples, initial_point, std_dev);
    std::cout << "Uniform Distribution Samples:" << std::endl;
    print_samples(samples_uniform);

    // Gaussian distribution example
    GaussianDistribution gaussian_dist(0.0, 5.0, -15.0, 15.0);
    std::vector<double> samples_gaussian = gaussian_dist.metropolis_sampling(n_samples, initial_point, std_dev);
    std::cout << "Gaussian Distribution Samples:" << std::endl;
    print_samples(samples_gaussian);

    return 0;
}
