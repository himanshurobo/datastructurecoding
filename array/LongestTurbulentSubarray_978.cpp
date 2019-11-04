/*

A subarray A[i], A[i+1], ..., A[j] of A is said to be turbulent if and only if:

For i <= k < j, A[k] > A[k+1] when k is odd, and A[k] < A[k+1] when k is even;
OR, for i <= k < j, A[k] > A[k+1] when k is even, and A[k] < A[k+1] when k is odd.
That is, the subarray is turbulent if the comparison sign flips between each adjacent pair of 
elements in the subarray.

Return the length of a maximum size turbulent subarray of A.

 

Example 1:

Input: [9,4,2,10,7,8,8,1,9]
Output: 5
Explanation: (A[1] > A[2] < A[3] > A[4] < A[5])
Example 2:

Input: [4,8,12,16]
Output: 2
Example 3:

Input: [100]
Output: 1
 

Note:

1 <= A.length <= 40000
0 <= A[i] <= 10^9

WrittenBy : Himanshu Srivastava
Problem : Longest Turbulent Subarray
TimeComplexity : O(n)


*/


class Solution {
public:
    int maxTurbulenceSize1(vector<int>& A) {
        
        vector<vector<int>> dp(A.size(), vector<int>(2, 1));
        int res = 1;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i - 1])
                dp[i][0] = dp[i - 1][1] + 1;
            else if (A[i] < A[i - 1]) 
                dp[i][1] = dp[i - 1][0] + 1;
            res = max(res, max(dp[i][0], dp[i][1]));   
        }
        return res;
        
    }
    
    
     int maxTurbulenceSize(vector<int>& A){
         int inc = 1, dec = 1, result = 1;
         int n = A.size();
        for (int i = 1; i < n; i++) {
            if (A[i] < A[i - 1]) {
                dec = inc + 1;
                inc = 1;
            } else if (A[i] > A[i - 1]) {
                inc = dec + 1;
                dec = 1;
            } else {
                inc = 1;
                dec = 1;
            }
            result = max(result, max(dec, inc));
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

    vector<int>input{7,1,5,3,6,4}

    cout<<(sol.maxTurbulenceSize(input));

    return 0;
}