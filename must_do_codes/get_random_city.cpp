// This program selects a random city from a list, with the selection probability weighted by the city's population. The list of cities and their populations are provided, and the program generates 10 random cities, with more populous cities being selected more frequently. The random selection is based on a cumulative distribution of city populations.

// Requirements:

// Cities and populations are given as input.
// Selection is weighted by population size.
// The program outputs 10 randomly selected cities.
// Edge Cases:

// Handle rounding errors in cumulative probability calculations.
// Ensure robustness with varying city and population sizes.


#include <iostream>
#include <vector>
#include <string>
#include <numeric> // For std::accumulate
#include <random>  // For random number generation

using namespace std;

// Function to get a random city based on population distribution
string get_random_city(const vector<string>& cities, const vector<double>& populations) {
    // Calculate total population by summing the individual populations
    double total_population = accumulate(populations.begin(), populations.end(), 0.0);

    // Calculate cumulative probabilities for each city based on its population
    vector<double> cumulative_weights;
    double cumulative_sum = 0.0;
    for (double population : populations) {
        cumulative_sum += population / total_population; // Normalize population
        cumulative_weights.push_back(cumulative_sum);  // Store cumulative probability
    }

    // Generate a random number between 0 and 1
    random_device rd;  // Initialize random device
    mt19937 gen(rd()); // Initialize Mersenne Twister random number generator
    uniform_real_distribution<> dis(0.0, 1.0);  // Uniform distribution between 0 and 1
    double random_value = dis(gen);  // Generate random value

    // Find the city corresponding to the random value using cumulative probabilities
    for (size_t i = 0; i < cumulative_weights.size(); ++i) {
        if (random_value <= cumulative_weights[i]) {
            return cities[i];  // Return the city if the random value is within the cumulative probability
        }
    }

    return cities.back(); // Fallback in case of rounding errors (should rarely happen)
}

int main() {
    // Define cities and their respective populations
    vector<string> cities = {"New York", "Los Angeles", "Chicago", "Houston", "Phoenix"};
    vector<double> populations = {8.4, 4.0, 2.7, 2.3, 1.7}; // Populations in millions

    // Generate a list of 10 random city names based on population distribution
    cout << "Randomly selected cities based on population distribution:" << endl;
    for (int i = 0; i < 10; ++i) {
        cout << get_random_city(cities, populations) << endl;  // Print each randomly selected city
    }

    return 0;  // End of the program
}



