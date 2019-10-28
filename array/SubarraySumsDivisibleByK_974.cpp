/*

Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.

 

Example 1:

Input: A = [4,5,0,-2,-3,1], K = 5
Output: 7
Explanation: There are 7 subarrays with a sum divisible by K = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
 

Note:

1 <= A.length <= 30000
-10000 <= A[i] <= 10000
2 <= K <= 10000

WrittenBy : Himanshu Srivastava
Problem : Subarray Sums Divisible by K
TimeComplexity : O(n)


*/



class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        
        int prefixSum = 0;
        unordered_map<int, int> rest2cnt;
        rest2cnt[0] = 1;
        int res = 0;
        for (int i = 0; i < A.size(); ++i) {
            prefixSum += A[i];
            // cout<<prefixSum<<" ";
            int rest = ((prefixSum % K) + K)%K;
            // cout<<rest<<endl;
            res += rest2cnt[rest];
            ++rest2cnt[rest];
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

    vector<int>input{7,1,5,3,6,4}

    cout<<(sol.subarraysDivByK(input));

    return 0;
}