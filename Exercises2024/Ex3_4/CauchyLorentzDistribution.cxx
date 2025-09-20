//derived class Cauchy Lorentz Distribution 
#include "CauchyLorentzDistribution.h"
#include <cmath>
#include <iostream>
#include <fstream>
//defining the constructor 
CauchyLorentzDistribution::CauchyLorentzDistribution(double range_min, double range_max, std::string outfile, double x0, double gamma, double step_size)
    : FiniteFunction(range_min, range_max, outfile), m_x0(x0), m_gamma(gamma), m_step_size(step_size) {
   // just the cross check to ensure that gamma value should be greater than 0
    if (gamma <= 0.0) throw std::invalid_argument("gamma value must be greater than 0");
}
// call function 
double CauchyLorentzDistribution::callFunction(double x) {
    double numerator = m_gamma;
    double denominator = M_PI * (m_gamma * m_gamma + std::pow(x - m_x0, 2));
    

    // Print intermediate values for debugging, you can cross check it later (its was just a check)
    std::cout << "x: " << x << ", m_gamma: " << m_gamma << ", m_x0: " << m_x0 << "\n";
    std::cout << "Numerator: " << numerator << ", Denominator: " << denominator << "\n";

    double result =  numerator / denominator;

    // Print the result 
    std::cout << "Result = " << result << "\n";  // printing the result from distribution

    return result;
}
// setter and getter section 
void CauchyLorentzDistribution::setLocation(double x0) { 
    m_x0 = x0;
    std::cout << "Location set to x0 = " << m_x0 << std::endl;
}

void CauchyLorentzDistribution::setScale(double gamma) { 
    m_gamma = gamma;
    std::cout << "Scale set to gamma = " << m_gamma << std::endl;
}

double CauchyLorentzDistribution::getLocation() const { 
    return m_x0; 
}

double CauchyLorentzDistribution::getScale() const {
    return m_gamma;
}

