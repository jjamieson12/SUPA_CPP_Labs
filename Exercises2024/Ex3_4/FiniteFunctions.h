


#include <string>
#include <vector>
#include <random>
#include "gnuplot-iostream.h"
#pragma once // Replacement for IFNDEF

class FiniteFunction {
public:
  FiniteFunction(); // Empty constructor
  FiniteFunction(double range_min, double range_max, std::string outfile); // Variable constructor
  ~FiniteFunction(); // Destructor
  
  double rangeMin(); // Low end of the range the function is defined within
  double rangeMax(); // High end of the range the function is defined within
  double integral(int Ndiv = 1000); 
  
  void setRangeMin(double RMin);
  void setRangeMax(double RMax);
  void setOutfile(std::string outfile);
  void plotFunction(); // Plot the function using scanFunction
  void plotData(std::vector<double> &points, int NBins, bool isdata = true); // Plot data points
  void generateSamples(int num_samples);

  virtual void printInfo(); // Dump parameter info about the current function (Overridable)
  virtual double callFunction(double x); // Call the function with value x (Overridable)
  void normalize(int Ndiv); // Normalize the function
   bool metropolisAccept(double current_value, double proposed_value, double sigma);

  std::vector<double> sampleUsingMetropolis(int num_samples, double sigma);
  std::vector<std::pair<double, double>> scanFunction(int Nscan = 1000);
  
  double m_RMin;
  double m_RMax;
  double m_Integral;
  double m_NormalizationFactor = 1.0;
  int m_IntDiv = 0; // Number of divisions for performing integral
  
  std::string m_FunctionName;
  std::string m_OutData; // Output filename for data
  std::string m_OutPng; // Output filename for plot
  std::vector<std::pair<double, double>> m_data; // Input data points
  std::vector<std::pair<double, double>> m_samples; // Randomly sampled data
  std::vector<std::pair<double, double>> m_function_scan; // Data from scanFunction
  
  bool m_plotfunction = true; // Flag to determine whether to plot function
  bool m_plotdatapoints = true; // Flag to determine whether to plot input data
  bool m_plotsamplepoints = true; // Flag to determine whether to plot sampled data

  virtual double integrate(int Ndiv);
  std::vector<std::pair<double, double>> makeHist(std::vector<double> &points, int Nbins); // Helper function for histogram
  void checkPath(std::string outstring); // Helper function to ensure data and PNG paths are correct
  void generatePlot(Gnuplot &gp); 
  
  double invxsquared(double x); // Default functional form
  
public:
  std::random_device rd;
  std::mt19937 gen; // Random number generator
  
  std::uniform_real_distribution<double> uniform_dist; // Uniform distribution
 // std::normal_distribution<double> normal_dist; // Normal distribution
  
};


//use this sepately inside the drived classes
// Constructor with range and output file initialization
//FiniteFunction::FiniteFunction(double range_min, double range_max, std::string outfile)
  //  : m_RMin(range_min), m_RMax(range_max), m_OutData(outfile), gen(rd()), 
   //   uniform_dist(m_RMin, m_RMax), normal_dist(0.0, 1.0) {}


// Default constructor

//FiniteFunction::FiniteFunction()
  //  : m_RMin(0.0), m_RMax(1.0), m_OutData("output.txt"), gen(rd()), 
   //   uniform_dist(m_RMin, m_RMax), normal_dist(0.0, 1.0) {}






/*

////////////////////////
#include <string>
#include <vector>
#include <random>
#include "gnuplot-iostream.h"
#pragma once //Replacement for IFNDEF

class FiniteFunction{

public:
  FiniteFunction(); //Empty constructor
  FiniteFunction(double range_min, double range_max, std::string outfile); //Variable constructor
  ~FiniteFunction(); //Destructor
  double rangeMin(); //Low end of the range the function is defined within
  double rangeMax(); //High end of the range the function is defined within
  double integral(int Ndiv = 1000); 
  void setRangeMin(double RMin);
  void setRangeMax(double RMax);
  void plotData(std::vector<double> &points, int NBins, bool isdata = true);
 

  std::vector<double> sampleUsingMetropolis(int num_samples, double sigma);
  std::vector< std::pair<double,double> > scanFunction(int Nscan = 1000);
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_real_distribution<double> uniform_dist(m_RMin, m_RMax); // Uniform distribution between m_RMin and m_RMax
  std::normal_distribution<double> normal_dist(0.0, sigma);
   //Scan over function to plot it (slight hack needed to plot function in gnuplot)
  void setRangeMin(double RMin);
  void setRangeMax(double RMax);
  //void checkPath(std::string outfile);
  
  void setOutfile(std::string outfile);
  void plotFunction(); //Plot the function using scanFunction
  //void generatePlot(Gnuplot &gp); 

  //Plot the supplied data points (either provided data or points sampled from function) as a histogram using NBins
  void plotData(std::vector<double> &points, int NBins, bool isdata=true); //NB! use isdata flag to pick between data and sampled distributions
  virtual void printInfo(); //Dump parameter info about the current function (Overridable)
  virtual double callFunction(double x); //Call the function with value x (Overridable)
  //virtual void plotData(std::vector<double>& points, int NBins, bool isdata = true); // Overridable

  void normalize(int Ndiv); // Declare the normalize method

  bool metropolisAccept(double current_value, double proposed_value, double sigma);


  //Protected members can be accessed by child classes but not users
public:
  double m_RMin;
  double m_RMax;
  double m_Integral;
  double m_NormalizationFactor = 1.0;
 // void normalize(int Ndiv); // Declare the normalize method

  //double  m_NormalizationFactor;
  int m_IntDiv = 0; //Number of division for performing integral
  std::string m_FunctionName;
  std::string m_OutData; //Output filename for data
  std::string m_OutPng; //Output filename for plot
  std::vector< std::pair<double,double> > m_data; //input data points to plot
  std::vector< std::pair<double,double> > m_samples; //Holder for randomly sampled data 
  std::vector< std::pair<double,double> > m_function_scan; //holder for data from scanFunction (slight hack needed to plot function in gnuplot)
  bool m_plotfunction = true; //Flag to determine whether to plot function
  bool m_plotdatapoints = true; //Flag to determine whether to plot input data
  bool m_plotsamplepoints = true; //Flag to determine whether to plot sampled data 
  double integrate(int Ndiv);
  std::vector< std::pair<double, double> > makeHist(std::vector<double> &points, int Nbins); //Helper function to turn data points into histogram with Nbins
  void checkPath(std::string outstring); //Helper function to ensure data and png paths are correct
  void generatePlot(Gnuplot &gp); 

public:
  double invxsquared(double x); //The default functional form
  

};
*/