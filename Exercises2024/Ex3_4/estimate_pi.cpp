/*
Quratulain 
s2718548@ed.ac.uk
SUPA C++ Assignment # 2
Part : 03 Bonus
*/
//adding the required libraries
#include <iostream>
#include <cstdlib>
#include <ctime> 
#include <iomanip>

using namespace std;
//Here , I defined the function to estimate the PI value using monte carlo method
double estimate_pi(double radius, int n){
    int points_inside_circle = 0;
    //Here, generated the n random numbers and checking if they lies inside the circle 
    for (int i = 0; i < n; ++i){
    //generated random points(x,y) withing the square (-r to +r)
    double x = (rand() / static_cast<double>(RAND_MAX)) * 2 * radius - radius;
    double y = (rand() / static_cast<double>(RAND_MAX)) * 2 * radius - radius;
    // cross check if the points lies inside the circle 
    if (x * x + y * y <= radius * radius) {
        ++points_inside_circle;
    }
}
//Estimating Pi 
  return 4.0 * points_inside_circle / n ;
}
 int main (int argc, char *argv[]) {
    if (argc != 3) {
        cerr<<"Usage: " <<argv[0]<< " <radius> <n_random_points" <<endl;
        return 1;
    }
    //get the arg from the command line, put the value of radius 1 and random number = 100000
     double radius = atof(argv[1]);
     int n = atoi(argv[2]);
     //seeding the random numver with the current time 
     srand(static_cast<unsigned int>(time(0)));
     //estimate PI now 
     double pi_estimate = estimate_pi(radius, n);
     //now fixing the decimal points to be printed  to 5 points
     cout << fixed << setprecision(5) << "The Estimated value of PI: " << pi_estimate << endl;
     return 0;

 }




