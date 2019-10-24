/*
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true


WrittenBy : Himanshu Srivastava
Problem :Contains Duplicate
TimeComplexity : O(n)
*/


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
//         if( nums.size() == 0){
//             return false;
//         }
        
//         if( nums.size() == 1){
//             return false;
//         }
        
        map<int,int> hash;
        
        for( int i = 0 ; i < nums.size(); i++){
            
            hash[nums[i]]++;
            
            if( hash[nums[i]] > 1 ){
                return true;
            }
        }
        
        return false;
        
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

    cout<<(sol.minSubArrayLen(3,input));

    return 0;
}