/* Quratulain Zahoor: 19 Nov,2024
University of Edinburgh
*/

//this is my .cxx file to define the processing for other file, defining function and other stuff
//includes the main header file along with neccesary packages
#include "CustomFunctions.h" //main .h file 
#include <iostream>
#include <sstream>
#include <cmath>  //for complex math
#include <fstream>
#include <vector> //for vectors
#include <string>
#include <iomanip>
#include <limits>



//this is to read the data file. 
//Two files to read: Data and error file 

// function to read the data into the vector , in the right format

void readData(const std::string& filename, std::vector<std::pair<float, float>>& data) {
    std::ifstream inputFile(filename);
    if (!inputFile.is_open()) { //checking if the file is open
        std::cerr << "Error: Could not open file '" << filename << "' for reading.\n";
        return;
    }
    std::string line;
    bool isHeader = true; // skiping the header to avoid any problem later

    while (std::getline(inputFile, line)) {
        if (isHeader) {
            isHeader = false;   //skiping the header here
            continue;
        }

        std::istringstream iss(line);
        std::string xStr, yStr;

        if (std::getline(iss, xStr, ',') && std::getline(iss, yStr)) { //get line to get the line data
            try {
                float x = std::stof(xStr);
                float y = std::stof(yStr);
                data.emplace_back(x, y); // adding prased pair to the vector 
            } catch (const std::exception&) {
                std::cerr << "Warning: Skipping invalid line: " << line << "\n";
            }
        } else {
            std::cerr << "Warning: Skipping malformed line: " << line << "\n";
        }
    }

    if (data.empty()) {
        std::cerr << "Error: No valid data read from file. Check file content and format.\n";
    } else {
        std::cout << "Successfully read " << data.size() << " data points from '" << filename << "'.\n";
    }

    inputFile.close(); //data file has been closed 
}

//now reading the error file, the error file which basically provided above
//filename1 = Error file for calculating the chi function

void readDataerror(const std::string& filename1, std::vector<std::pair<float, float>>& errors) {
    std::ifstream inputFile(filename1);
    if (!inputFile.is_open()) { //checking if the file is open
        std::cerr << "Error: Could not open file '" << filename1 << "' for reading.\n";
        return;
    }
    std::string line;
    bool isHeader = true; // skiping the header to avoid any problem later

    while (std::getline(inputFile, line)) {
        if (isHeader) {
            isHeader = false;   //skiping the header here , in order to get the right processing
            continue;
        }

        std::istringstream iss(line);
        std::string xStr, yStr;

        if (std::getline(iss, xStr, ',') && std::getline(iss, yStr)) { //get line to get the line data
            try {
                float x = std::stof(xStr);
                float y = std::stof(yStr);
                errors.emplace_back(x, y); // adding prased pair to the vector 
            } catch (const std::exception&) {
                std::cerr << "Warning: Skipping invalid line: " << line << "\n";
            }
        } else {
            std::cerr << "Warning: Skipping malformed line: " << line << "\n";
        }
    }

    if (errors.empty()) { //check to see if the file is empty
        std::cerr << "Error: No valid errir data read from file. Check file content and format.\n";
    } else {
        std::cout << "Successfully read  errors points from " << filename1 << "'.\n";
    }

    inputFile.close(); //error file has been closed 
}

//closing the  error file 




// defining the function to calculate the magnitude m = sqrt(a^2+b^2), and then printing the data in the main file

std::vector<float> calculateMagnitudes(const std::vector<std::pair<float, float>>& data) {
    std::vector<float> magnitudes;
    for (const auto& point : data) {
        float magnitude = std::sqrt(point.first * point.first + point.second * point.second);
        magnitudes.push_back(magnitude);
    }
    std::cout << "Calculated magnitudes for " << data.size() << " points.\n";
    return magnitudes; //getting the values
}
//print the magnitude using cout also will be stored in the magnitude
void printMagnitude(const std::vector<float>& magnitudes) {
    for (const auto& magnitude : magnitudes) {
        std::cout << magnitude << std::endl;
    }
}
// writing the magnitude to the file, check the magnitude.txt file 
void writeToFile(const std::string& filename, const std::vector<float>& magnitudes) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file for writing.\n";
        return;
    }

    for (const auto& magnitude : magnitudes) {
        outFile << magnitude << "\n";
    }

    outFile.close();
    std::cout << "Magnitudes saved to " << filename << "\n"; 
}

// calculating the leastSquare function and also you will see the values printed inside the terminal
void leastSquares(const std::vector<std::pair<float, float>>& data,  //data file
                  const std::vector<std::pair<float, float>>& errors, //error file
                  std::string& fitFunction,  //now fitFunction
                  float& reducedChiSquared,const std::string& filename) { //file to store
                  //now writing the formula
    float sumX = 0;
    float sumY = 0;
    float sumXY = 0;
    float sumX2 = 0;

    for (const auto& vectorPair : data) {
        sumX += vectorPair.first;
        sumY += vectorPair.second;
        sumXY += vectorPair.first * vectorPair.second;
        sumX2 += std::pow(vectorPair.first, 2);
    }

    float n = data.size(); //initializing the n = data.size
    float p = (n * (sumXY - sumX * sumY)) / (n * (sumX2 - std::pow(sumX, 2)));
    float q = (sumX2 * sumY - sumXY * sumX) / (n * sumX2 - std::pow(sumX, 2));

    // Calculation of reduced chi squared
    float chiSquared = 0.0;
    for (int i = 0; i < data.size(); i++) {
        float observed = data[i].second;
        float expected = p * data[i].first + q;
        

        float sigma = errors[i].second; // calculating the sigma here
        //float sigma = errors[i].first; // calculating the sigma here but it gives a very large value
 
        


       
        chiSquared += std::pow((observed - expected), 2) / std::pow(sigma, 2);  //formula to get chi squared
    }

    int degreesOfFreedom = data.size() - 2; // as there are two variables p and q
    reducedChiSquared = chiSquared / static_cast<float>(degreesOfFreedom); 

    std::ostringstream stream;
    stream.precision(2); // Set the number of decimal points
    stream << std::fixed << "y = " << p << " * x + " << q; //printing the values for slope
    fitFunction = stream.str();
    // Open the output file for writing results
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file for writing.\n";
        return;
    }

    // Write the results to the file
    outFile << "Fitted Function: " << fitFunction << std::endl;
    outFile << "Reduced Chi-Squared: " << reducedChiSquared << std::endl;
    outFile.close();  // Close the file after writing

    std::cout << "Fitted Function: " << fitFunction << std::endl;
    std::cout << "Reduced Chi-Squared: " << reducedChiSquared << std::endl;
    std::cout << "Chi-squared results saved to " << filename << "\n";
}


// calculating x^y without using the builtin function (assigment requirements)
double calculatePowerManually(float base, int exponent) {
    if (exponent == 0) return 1.0;
    double result = 1.0;
    bool isNegative = exponent < 0;

    if (isNegative) exponent = -exponent;

    for (int i = 0; i < exponent; ++i) {
        result *= base;
    }

    return isNegative ? 1.0 / result : result;
}

// calculating the power 
void calculatePower(const std::vector<std::pair<float, float>>& data, const std::string& filename) {
    std::ofstream outFile(filename);
    if (!outFile.is_open()) {
        std::cerr << "Error: Could not open file for writing.\n";
        return;
    }

    for (const auto& point : data) {
        int y = static_cast<int>(std::round(point.second));
        double result = calculatePowerManually(point.first, y);
        outFile << point.first << "^" << y << " = " << result << "\n";
        std::cout << point.first << "^" << y << " = " << result << "\n";
    }

    outFile.close();
    std::cout << "x^y results saved to " << filename << "\n";
}
//I have set different files for each task so  after executing .AnalyseData you can see the files 

// you can see my outfile in my folder, for easiness i have defines my Makefile
//do the make
//now you have the filename.txt (for the differnt option you want to calculate)
