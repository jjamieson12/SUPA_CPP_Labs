

#include <string>
#include <vector>
#include <random>
#include "gnuplot-iostream.h"
#pragma once //

class FiniteFunction {
public:
  FiniteFunction(); // Empty constructor
  FiniteFunction(double range_min, double range_max, std::string outfile); // Variable constructor
  ~FiniteFunction(); // Destructor
  
  double rangeMin(); // Low end of the range the function is defined within
  double rangeMax(); // High end of the range the function is defined within
 
  
  void setRangeMin(double RMin);
  void setRangeMax(double RMax);
  void setOutfile(std::string outfile);
  void plotFunction(); // Plot the function using scanFunction
  void plotData(std::vector<double> &points, int NBins, bool isdata = true); // Plot data points
  void generateSamples(int num_samples);

  virtual void printInfo(); // Dump parameter info about the current function (Overridable)
  virtual double callFunction(double x); // Call the function with value x (Overridable)
  void normalize(int Ndiv); // Normalize the function
  double m_sample;

  double integrate(int Ndiv);
  double integral(int Ndiv);
   bool metropolisAccept(double current_value, double proposed_value, double sigma);
  
 //virtual std::vector<double> sampleUsingMetropolis(int num_samples, double sigma);
  std::vector<std::pair<double, double>> scanFunction(int Nscan = 1000);
  

  
  
  
    double m_RMin, m_RMax;


    // Constructor declaration
    FiniteFunction(double range_min, double range_max);

    // Sample using Metropolis
    std::vector<double> sampleUsingMetropolis(int num_samples, double sigma);

  
  double m_Integral;
  double m_NormalizationFactor = 1.0;
  
 //std::vector<double> sampleUsingMetropolis(int num_samples, double sigma, double m_RMin, double m_RMax);

  int m_IntDiv = 0; // Number of divisions for performing integral
    
  
std::vector<double> sample(int num_samples, double sigma);
  
    std::vector<std::pair<double, double>> m_samples;
  
  std::string m_FunctionName;
  std::string m_OutData; // Output filename for data
  std::string m_OutPng; // Output filename for plot
  std::vector<std::pair<double, double>> m_data; // Input data points
  std::vector<std::pair<double, double>> m_function_scan; // Data from scanFunction 
  bool m_plotfunction = true; // Flag to determine whether to plot function
  bool m_plotdatapoints = true; // Flag to determine whether to plot input data
  bool m_plotsamplepoints = true; // Flag to determine whether to plot sampled data

  std::vector<std::pair<double, double>> makeHist(std::vector<double> &points, int Nbins); // Helper function for histogram
  void checkPath(std::string outstring); // Helper function to ensure data and PNG paths are correct
  void generatePlot(Gnuplot &gp); 
  
  double invxsquared(double x); // Default functional form
  
  
  
};


