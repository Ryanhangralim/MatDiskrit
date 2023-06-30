#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>

using namespace std;

// Function to calculate the Euclidean distance between two cities
double distance(pair<double, double> city1, pair<double, double> city2) {
    double xDiff = city1.first - city2.first;
    double yDiff = city1.second - city2.second;
    return sqrt(xDiff * xDiff + yDiff * yDiff);
}

// Function to calculate the total distance of a tour
double calculateTourDistance(const vector<pair<double, double>>& cities, const vector<int>& tour) {
    double totalDistance = 0.0;
    int numCities = cities.size();

    for (int i = 0; i < numCities - 1; ++i) {
        int cityIndex1 = tour[i];
        int cityIndex2 = tour[i + 1];
        totalDistance += distance(cities[cityIndex1], cities[cityIndex2]);
    }

    // Add the distance from the last city back to the starting city
    totalDistance += distance(cities[tour[numCities - 1]], cities[tour[0]]);

    return totalDistance;
}

// Function to find the shortest tour using brute force
pair<vector<int>, double> bruteForceTSP(const vector<pair<double, double>>& cities) {
    int numCities = cities.size();
    vector<int> tour(numCities);
    for (int i = 0; i < numCities; ++i) {
        tour[i] = i;  // Initialize the tour with the initial ordering of cities
    }

    vector<int> shortestTour;
    double shortestDistance = numeric_limits<double>::max();

    // Generate all permutations of the cities
    do {
        double tourDistance = calculateTourDistance(cities, tour);
        if (tourDistance < shortestDistance) {
            shortestDistance = tourDistance;
            shortestTour = tour;
        }
    } while (next_permutation(tour.begin() + 1, tour.end()));

    return make_pair(shortestTour, shortestDistance);
}

int main() {
    // Example usage
    vector<pair<double, double>> cities = {
        {0.0, 0.0},
        {1.0, 2.0},
        {3.0, 1.0},
        {2.0, 3.0}
        // Add more cities as needed
    };

    pair<vector<int>, double> result = bruteForceTSP(cities);

    cout << "Shortest tour: ";
    for (int cityIndex : result.first) {
        cout << cityIndex << " ";
    }
    cout << endl;

    cout << "Shortest distance: " << result.second << endl;

    return 0;
}
