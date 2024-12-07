

// Name: Quratulain Zahoor
// Date: 19-Nov-2024

#include "NormalDistribution.h"
#include "NegativeCrystalBallDistribution.h"
#include "CauchyLorentzDistribution.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "FiniteFunctions.h"  
#include <filesystem>  


using namespace std;

// Function to read the mystery data from the file with error handling and limit to 500 points
vector<double> readDataFromFile(const string& filename) {
    vector<double> data;
    double value;
    int count = 0;

    // Check if the file exists in the current directory
    if (!std::filesystem::exists(filename)) {
        cout << "Error reported: File '" << filename << "' does not exist in the current directory." << endl;
        return data;  // Return an empty vector as a signal of failure
    }

    // Try to open the file
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error: Could not open file '" << filename << "'." << endl;
        return data;  // Return an empty vector as a signal of failure
    }

    // Read data from the file, limit to 500 points
    while (file >> value && count < 500) {
        data.push_back(value);
        count++;
    }

    // If no valid data was read, output a warning
    if (data.empty()) {
        cout << "Warning: No valid data found in the file '" << filename << "'." << endl;
    } else {
        cout << "File '" << filename << "' successfully read with " << data.size() << " data points." << endl;
    }

    file.close();  // Close the file after reading

    return data;
}

int main() {
     double range_min = -15.0;
    double range_max = 15.0;
    double step_size = 0.1; 
    int num_samples = 500;
    double proposal_stddev = 2.0;
    std::string filename = "Outputs/data/MysteryData16341.txt"; 
    std::string sample_filename = "Outputs/data/normalDist_Sample_data.txt"; 

    
    string output_file = "MysteryPlot";

 
    // Plot the Normal Distribution
        std::cout << "Checking Normal Distributions..." << std::endl;
    double mean = 2.2;
    double stddev = 2.0;
    string output_file1 = "NormalDistribution"; //the png plot
    

    NormalDistribution normalDist(range_min, range_max, output_file1, mean, stddev);
    std::vector<double> sampled_data = normalDist.sample(num_samples, proposal_stddev);
    normalDist.plotFunction();
    cout << "Checking Normal Distributions..." << endl;
    //vector<double> normal = readDataFromFile(filename);

    vector<double> normal = readDataFromFile(filename);
    if (!normal.empty()) {
      normalDist.plotData(normal, 50, true);  
    }
    

    
    // Cauchy-Lorentz Distribution
    double x0 = 2.7;   // Location parameter ,removing it from 0.0
    double gamma = 1.8; // Scale parameter
    string output_file4 = "CauchyLorentzDistribution";
    CauchyLorentzDistribution cld(range_min, range_max, output_file4, x0, gamma, step_size);
    cld.plotFunction();


    //string filename4 = "Outputs/data/CauchyLorentzDistribution.txt";  // Use the correct relative file path
    vector<double> Cauchy = readDataFromFile(filename);
    if (!Cauchy.empty()) {
        cld.plotData(Cauchy, 50, true);  // Use 100 bins for histogram-like plotting, setting 'false' for data
    }

    // Negative Crystal Ball Distribution
    double x_bar = 3.0;   // Mean
    double sigma1 = 2.0;   // Standard deviation./
    double alpha = 2.0;   // Transition parameter
    double n = 2.0;       // Tail parameter
    string output_file2 = "NegativeCrystalBallDistribution";
    NegativeCrystalBallDistribution ncbdDist(range_min, range_max, output_file2, x_bar, sigma1, alpha, n, step_size);
    ncbdDist.plotFunction();

    // Read and plot Negative Crystal Ball Distribution data
   // string filename2 = "Outputs/data/NagetiveCrystalBallDistribution.txt";  // Use the correct relative file path
    vector<double> Crystal = readDataFromFile(filename);
    if (!Crystal.empty()) {
        ncbdDist.plotData(Crystal, 50, true);  // Use 100 bins for histogram-like plotting, setting 'false' for data
        //func.plotSample(mysteryData2, 100, true);  // Use 100 bins for histogram-like plotting, setting 'false' for data

    }

    

    return 0;  // Return 0 to indicate successful execution
}
