/*

In a list of songs, the i-th song has a duration of time[i] seconds. 

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. 
 Formally, we want the number of indices i < j with (time[i] + time[j]) % 60 == 0.

 

Example 1:

Input: [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
Example 2:

Input: [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.
 

Note:

1 <= time.length <= 60000
1 <= time[i] <= 500

WrittenBy : Himanshu Srivastava
Problem : Pairs of Songs With Total Durations Divisible by 60
TimeComplexity : O(n)


*/

#include"../header.hpp"

class Solution {
public:
    int numPairsDivisibleBy602(vector<int>& time) {
        int res = 0;
        vector<int> m(60);
        for (auto t : time) {
            int a = ( (60 - t % 60)%60);
            cout<<t<<"-->"<<a<<endl;
            res += m[(60 - t % 60) % 60];
            ++m[t % 60];
        }
        
        return res;
        
    }
int numPairsDivisibleBy601(vector<int>& time) {

        vector<int> rem(60, 0);

        // Count remainders
        for (int ele : time) {
            rem[ele % 60]++;
        }

        long long count = 0; // Use long long to prevent overflow

        // Count pairs where both elements have remainder 0
        count += static_cast<long long>(rem[0]) * (rem[0] - 1) / 2;
        // Count pairs where both elements have remainder 30
        count += static_cast<long long>(rem[30]) * (rem[30] - 1) / 2;

        // Count pairs where the remainders add up to 60
        for (int i = 1; i < 30; i++) {
            count += static_cast<long long>(rem[i]) * rem[60 - i];
        }

        return static_cast<int>(count); // Return as int if needed
        
    }

    int numPairsDivisibleBy60(vector<int>& time) {
            unordered_map<int, int> m;

        // Count remainders
        for (int i = 0; i < time.size(); i++) {
            time[i] %= 60;
            m[time[i]]++;
        }

        long long count = 0; // Use long long to prevent overflow

        for (auto it : m) {
            int remainder = it.first;
            int freq = it.second;
            if (remainder == 0 || remainder == 30) {
                count += static_cast<long long>(freq) * (freq - 1) / 2;
            } else if (remainder < 30 && m.count(60 - remainder)) {
                count += static_cast<long long>(freq) * m[60 - remainder];
            }
        }

        return static_cast<int>(count); // Return as int if needed
    }
};

void displayInt(vector<int>input){
    cout<<"Displaying size "<<input.size()<<endl;
    for (std::vector<int>::size_type i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main(){

    Solution sol;

    vector<int>input{30,20,150,100,40};

    cout<<(sol.numPairsDivisibleBy60(input));

    return 0;
}
