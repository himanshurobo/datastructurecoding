// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]
 

// Constraints:

// 1 <= temperatures.length <= 105
// 30 <= temperatures[i] <= 100



class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        if (n == 0) {
            return vector<int>(0, 0); // Return an empty vector if input is empty
        }

        vector<int> res(n, 0);
        stack<int> s; // Stack to store indices of temperatures
        s.push(0); // Push the index of the first temperature

        for (int i = 0; i < n; ++i) {
            // While there are elements in the stack and the current temperature is greater
            // than the temperature at the index stored at the top of the stack
            while (!s.empty() && temperatures[i] > temperatures[s.top()]) {
                int idx = s.top(); // Get the index of the previous temperature
                s.pop(); // Remove the index from the stack
                res[idx] = i - idx; // Calculate the number of days until a warmer temperature
            }
            s.push(i); // Push the current index onto the stack
        }

        return res;
    }
};

