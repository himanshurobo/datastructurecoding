// Efficient Vector Storage and Dot Product Computation
// Problem Statement:
// Given two large vectors A and B that contain frequent consecutive repetitions of numbers, standard storage and computation methods can be inefficient in terms of memory and performance. Design an algorithm that:

// Compresses the vectors into a run-length encoded (RLE) format to reduce memory usage.
// Computes the dot product directly on the compressed format without decompression.
// Ensures scalability for vectors with millions of elements and supports efficient updates to the data structure.
// Objective:
// Optimize both storage and computational efficiency while maintaining accuracy in mathematical operations, particularly for scenarios where large-scale vector computations are required.

#include <iostream>
#include <vector>
#include <utility> // For std::pair

using namespace std;

// Function to compress a vector using Run-Length Encoding (RLE)
vector<pair<int, int>> compress(const vector<int>& vec) {
    vector<pair<int, int>> rle;
    int n = vec.size();
    if (n == 0) return rle;

    int count = 1;
    for (int i = 1; i < n; ++i) {
        if (vec[i] == vec[i - 1]) {
            count++;
        } else {
            rle.emplace_back(vec[i - 1], count);
            count = 1;
        }
    }
    rle.emplace_back(vec[n - 1], count);
    return rle;
}

// Function to calculate the dot product of two compressed vectors
int dot_product(const vector<pair<int, int>>& a_rle, const vector<pair<int, int>>& b_rle) {
    int dot = 0;

    size_t i = 0, j = 0;
    while (i < a_rle.size() && j < b_rle.size()) {
        int value_a = a_rle[i].first, count_a = a_rle[i].second;
        int value_b = b_rle[j].first, count_b = b_rle[j].second;

        int overlap = min(count_a, count_b); // Overlapping segment length
        dot += value_a * value_b * overlap; // Accumulate dot product

        // Adjust counts for the next segment
        a_rle[i].second -= overlap;
        b_rle[j].second -= overlap;

        if (a_rle[i].second == 0) i++;
        if (b_rle[j].second == 0) j++;
    }

    return dot;
}

int main() {
    // Input vectors
    vector<int> a = {1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1};
    vector<int> b = {1, 1, 1, 1, 1, 3, 3, 3, 3, 2, 3, 2, 2, 2, 1, 1, 1, 1, 1};

    // Compress the vectors
    vector<pair<int, int>> a_rle = compress(a);
    vector<pair<int, int>> b_rle = compress(b);

    // Calculate and print the dot product
    int result = dot_product(a_rle, b_rle);
    cout << "Dot Product: " << result << endl;

    return 0;
}
