
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

*/

#include"../header.hpp"

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int res = 0;
    for (auto j = 1, max_i = A[0] - 1; j < A.size(); ++j, --max_i) {
        
        res = max(res, A[j] + max_i);
        max_i = max(max_i, A[j]);
        cout<<j<<" "<<res<<" "<<A[j]<<" "<<max_i<<endl;
      }
  return res;
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

    vector<int>input{8,1,5,2,6};

    cout<<(sol.maxScoreSightseeingPair(input));

    return 0;
}