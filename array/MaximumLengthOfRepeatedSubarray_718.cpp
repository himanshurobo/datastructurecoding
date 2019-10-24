/*

Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.

Example 1:

Input:
A: [1,2,3,2,1]
B: [3,2,1,4,7]
Output: 3
Explanation: 
The repeated subarray with maximum length is [3, 2, 1].

WrittenBy : Himanshu Srivastava
Problem : Maximum Length of Repeated Subarray
TimeComplexity : O(n)


*/



class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        
        int m = A.size();
        int n = B.size();
        vector<vector<int>> dp(A.size()+1,vector<int>(n+1, 0));
        
        int maxLen = 0;
        
        for( int i = 1 ; i <= m; i++){
            for( int j = 1 ; j <= n ; j++){
                
                if(A[i-1] == B[j-1]){
                    dp[i][j] = dp[i-1][j-1] +1;
                }else{
                    dp[i][j] = 0;
                }
                maxLen = max(maxLen,dp[i][j]);
            }
        }
        return maxLen;
        
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

    cout<<(sol.findLength(input));

    return 0;
}