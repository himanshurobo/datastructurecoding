
/*

Given an array A of positive integers, A[i] represents the value of the i-th sightseeing spot, 
and two sightseeing spots i and j have distance j - i between them.

The score of a pair (i < j) of sightseeing spots is (A[i] + A[j] + i - j) : 
the sum of the values of the sightseeing spots, minus the distance between them.

Return the maximum score of a pair of sightseeing spots.

 

Example 1:

Input: [8,1,5,2,6]
Output: 11
Explanation: i = 0, j = 2, A[i] + A[j] + i - j = 8 + 5 + 0 - 2 = 11
 

Note:

2 <= A.length <= 50000
1 <= A[i] <= 1000

WrittenBy : Himanshu Srivastava
Problem :Best Sightseeing Pair
TimeComplexity : O(n)

Problem Analysis: Maintain a left endpoint value curVal, which is decremented by 1 each time it moves to the right, which is equivalent to the effect of the distance on the belt. If the current curVal is less than A[i], the yield of curVal on the digits behind i is definitely Will not be greater than A[i], so update curVal

*/

#include"../header.hpp"

class Solution {
public:


    int maxScoreSightseeingPair1(vector<int>& A) {
        int res = 0;
    for (auto j = 1, max_i = A[0] - 1; j < A.size(); ++j, --max_i) {
        
        res = max(res, A[j] + max_i);
        max_i = max(max_i, A[j]);
        cout<<j<<" "<<res<<" "<<A[j]<<" "<<max_i<<endl;
      }
  return res;
    }

    // The goal is to keep track of:
    // Maximum So far and add it to the cur_cell and maintain maximum result
    // Here, max_so_far contains : A[i] + i
    // Original Given Formula : A[i] + A[j] + i - j
    // Break in two parts : A[i] + i and A[j] -j
    // Keep MAX_VALUE of first part among the elements seen so far
    // Add the current element to max_so_far and check the result is changing or not
    // Also, keep updating the max_so_far at each step
    int maxScoreSightseeingPair(vector<int>& A) {

        int max_so_far = A[0];
        int result = 0;
        for(int i=1;i<A.size();i++){
            result = max(result, max_so_far + A[i] - i);
            max_so_far = max(max_so_far, A[i] + i);
        }   
        return result;

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

    vector<int>input{5,1,8,2,6};

    cout<<(sol.maxScoreSightseeingPair(input));

    return 0;
}