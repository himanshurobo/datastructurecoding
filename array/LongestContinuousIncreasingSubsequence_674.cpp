
/*

Given an unsorted array of integers, find the length of longest continuous increasing subsequence (subarray).

Example 1:
Input: [1,3,5,4,7]
Output: 3
Explanation: The longest continuous increasing subsequence is [1,3,5], its length is 3. 
Even though [1,3,5,7] is also an increasing subsequence, it's not a continuous one where 5 and 7 are separated by 4. 
Example 2:
Input: [2,2,2,2,2]
Output: 1
Explanation: The longest continuous increasing subsequence is [2], its length is 1. 


WrittenBy : Himanshu Srivastava
Problem : Longest Continuous Increasing Subsequence
TimeComplexity : O(n)
*/


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        
        int len = 0;
        int maxIndex = INT_MIN;
        
        if( nums.size() == 0 ){
            return 0;
        }
        
        if( nums.size() == 1 ){
            return 1;
        }
        
        for( int i = 1 ; i < nums.size(); i++){
            
            if( nums[i-1] < nums[i]){
                len++;
            }else{
                len = 0 ;
            }
            
            maxIndex = max(maxIndex, len+1);
        }
        
        return maxIndex;
        
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

    cout<<(sol.findLengthOfLCIS(input));

    return 0;
}