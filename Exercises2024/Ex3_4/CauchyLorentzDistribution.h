//defining the CauchyLorentzDistribution derived class 
#pragma once
#include "FiniteFunctions.h"
#include <string>
class  CauchyLorentzDistribution : public FiniteFunction{
private:
    double m_x0, m_gamma, m_step_size = 1.0, m_range_min = -5.0, m_range_max = 4.0;
public: 
    CauchyLorentzDistribution(double range_min, double range_max, std::string outfile, double x0, double gamma, double step_size);
     double callFunction(double x) override;

    void setLocation(double x0);
    void setScale(double gamma =  1.8);
    double getLocation() const;
    double getScale() const;
};

// you need to remove it 
/*

#pragma once
#include "FiniteFunctions.h"
#include <string>

class CauchyLorentzDistribution : public FiniteFunction {
private:
    double m_x0;       // Location parameter
    double m_gamma;    // Scale parameter
    
    double m_step_size = 1.0;
    double m_range_min = -5.0;

    double m_range_max = +4.0;

public:
    // Constructor
    CauchyLorentzDistribution(double range_min, double range_max, std::string outfile, double x0, double gamma, double step_size);
    //~CauchyLorentzDistribution();
   // void plotFunction() ;

    // Override callFunction for the Cauchy-Lorentz formula
    double callFunction(double x) override;

    // Setters and Getters
    void setLocation(double x0);
    void setScale(double gamma= 1.8);
    double getLocation() const;
    double getScale() const;
    

    
};


*/