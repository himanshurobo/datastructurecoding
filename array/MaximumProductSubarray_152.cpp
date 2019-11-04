/*
Given an integer array nums, find the contiguous subarray within an array (containing at least one number)
 which has the largest product.

Example 1:

Input: [2,3,-2,4]
Output: 6
Explanation: [2,3] has the largest product 6.
Example 2:

Input: [-2,0,-1]
Output: 0
Explanation: The result cannot be 2, because [-2,-1] is not a subarray.



WrittenBy : Himanshu Srivastava
Problem : Maximum Product Subarray
TimeComplexity : O(n)


*/



class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int maxValue = INT_MIN;
        int n = nums.size();
        int front =1;
        int back = 1;

        for( int i = 0 ; i < n; i++){

            front *= nums[i];
            back *= nums[n-i-1];
            cout<<front<<" "<<back<<endl;
            maxValue = std::max(maxValue,std::max(front,back));

            front = front?front:1;
            back = back?back:1;

        }

        return maxValue;

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

    cout<<(sol.maxProduct(input));

    return 0;
}
