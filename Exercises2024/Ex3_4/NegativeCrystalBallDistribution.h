
#pragma once
#include "FiniteFunctions.h"
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>

class NegativeCrystalBallDistribution : public FiniteFunction {
private:
    double m_x_bar;   // Mean
    double m_sigma;   // Standard deviation
    double m_alpha;   // Transition parameter
    double m_n;       // Tail parameter
    double m_step_size;
    double m_range_min;
    double m_range_max;
    
    void computeConstants();
    double A, B, C, D, N;
public:
    // Constructor
    NegativeCrystalBallDistribution(double range_min, double range_max, std::string outfile,
    //NegativeCrytalBallDistribution(double range_min, double range_max, std::string outfile,
                                 double x_bar, double sigma1, double alpha, double n, double step_size);

    // Function to evaluate the PDF at a point x
    double callFunction(double x) override;

    // Setters and Getters
    void setXBar(double x_bar);
    void setSigma(double sigma1);
    void setAlpha(double alpha);
    void setN(double n);
    double getXBar() const;
    double getSigma() const;
    double getAlpha() const;
    double getN() const;
};
