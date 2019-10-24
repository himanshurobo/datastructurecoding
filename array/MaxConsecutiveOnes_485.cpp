/*
Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.

WrittenBy : Himanshu Srivastava
Problem : .Max Consecutive Ones
TimeComplexity : O(n)


*/


class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int count = 0;
        int maxCount = 0;
        int n = nums.size();
        
        for( int i = 0; i < nums.size(); i++){
            
            if( nums[i] == 1){
                count++;
            }else{
                count = 0;
            }
            
            maxCount = max( maxCount,count);
        }
        
        return maxCount;
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

    cout<<(sol.findMaxConsecutiveOnes(input));

    return 0;
}