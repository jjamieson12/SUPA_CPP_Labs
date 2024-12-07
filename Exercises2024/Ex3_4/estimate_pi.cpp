#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

// Function to estimate Pi using Monte Carlo method
double estimate_pi(double radius, int n) {
    int points_inside_circle = 0;

    // Generate n random points and check if they lie inside the circle
    for (int i = 0; i < n; ++i) {
        // Generate random point (x, y) within the square [-radius, radius]
        double x = (rand() / static_cast<double>(RAND_MAX)) * 2 * radius - radius;
        double y = (rand() / static_cast<double>(RAND_MAX)) * 2 * radius - radius;

        // Check if the point is inside the circle
        if (x * x + y * y <= radius * radius) {
            ++points_inside_circle;
        }
    }

    // Estimate Pi using the ratio of points inside the circle to total points
    return 4.0 * points_inside_circle / n;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <radius> <n_random_points>" << endl;
        return 1;
    }

    // Get the radius and number of random points from command line arguments
    double radius = atof(argv[1]);
    int n = atoi(argv[2]);

    // Seed the random number generator with the current time
    srand(static_cast<unsigned int>(time(0)));

    // Estimate Pi
    double pi_estimate = estimate_pi(radius, n);

    // Print the result with 10 decimal places
    cout << fixed << setprecision(10) << "Estimated value of Pi: " << pi_estimate << endl;

    return 0;
}
