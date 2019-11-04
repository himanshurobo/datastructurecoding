/*

Given an array nums, write a function to move all 0's to the end of it while maintaining the relative 
order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.


WrittenBy : Himanshu Srivastava
Problem : . Move Zeroes
TimeComplexity : O(n)


*/



class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int j = 0;
        for( int i = 0 ; i < nums.size(); i++){
            if( nums[i] != 0 ){
                
                nums[j++] = nums[i];
            }
        }
        
        
        while( j < nums.size()){
            nums[j++] = 0;
        }
        
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

    cout<<(sol.moveZeroes(input));

    return 0;