/*
name: Quratulain Zahoor 
Date: 21-Nov-2024
Email: s2718548@ed.ac.uk
*/
/*
Procedure to Run
make
./AnalyseData


*/


//including the libraries
#include <iostream> //this is to use for input/output stream 
#include <vector>  //this includes the vector 
#include "CustomFunctions.h" //this is my header file 

  // this is my error file to be used for chi function
std::vector<std::pair<float, float>> data;  // fill it with data 
float p = 0.0;  // Slope initializion
float q = 0.0;  // Intercept initialization 

//start of the main program
int main() {
    
    std::string fitFunction;                      // String to store fitted function
      
    std::vector<std::pair<float, float>> data;
    
    // Step1: Read data from input file that contains x, y pairs
    std::string filename = "input2D_float.txt";  
    readData(filename, data);
    //now defining for the error function
     std::vector<std::pair<float, float>> errors;
    
    // Step1: Read data from input file that contains x, y pairs
    std::string filename1 = "error2D_float.txt";  
    readData(filename1, errors);
    //std::vector<std::pair<float, float>> data;
    //std::vector<std::pair<float, float>> errors;
    float reducedChiSquared = 0.0f;
    // defining the multiple choices, which user can select what he wants to do, i havent added the saperate print and read functions
     
     // ask the user which function,you can see different options below
     int choice;
     bool keepRunning = true; //the input should be valid to keep it running


     while (keepRunning) {   //list of my input options
         std::cout << "Choose an action:\n";
        

         std::cout << "1. Print data\n";  //you have to enter your choice in order to make it happens
         std::cout << "2. Calculate and print magnitudes\n";
         std::cout << "3. Perform least squares fit\n";
         std::cout << "4. Calculate x^y\n";
         std::cout << "5. Exit\n";
         std::cout << "Enter your choice: ";
         std::cin >> choice;       
         //create multiple cases what ever user choice it will go to the certain case and perform the task
         switch (choice) {
             case 1:  //will print the data once you selected the datasize you wanted to work
                 int n;
                 std::cout << "Enter number of lines to print: ";
                 std::cin >> n;
                 std::cout<<"the  number of lines selected:  "<< n<<std::endl;
                 printData(data, n); 
                 
                 //writeToFile("data.txt", data);  //if someone want to print the data inside the file, but its optional
                 break;
             case 2:
                 {
                     auto magnitudes = calculateMagnitudes(data); //calculating the magnitude from my data
                     printMagnitude(magnitudes);  //print the magnitude inside the terminal
                     writeToFile("magnitudes.txt", magnitudes); //will store the results inside the file
                 }
                 break;
             case 3:
                 leastSquares(data, errors, fitFunction, reducedChiSquared, "fitted_function.txt"); 
                  std::cout << "Fitted Function: " << fitFunction << std::endl;
                  std::cout << "Reduced Chi-Squared: " << reducedChiSquared << std::endl;
                  //writeToFile("Chisquared.txt", reducedChiSquared)//will store the results inside the file
                   break;

            
             case 4:
            

                 calculatePower(data, "x_to_the_y.txt");  //calculating the power
                 break;
             case 5:
                 keepRunning = false; //if the choice is not valid it will take it false and exit when you press 5
                 break;
             default:
                 std::cerr << "Invalid choice. Please try again.\n";  //if you enter the choice>5
           
         }
     }

     return 0;
 }

