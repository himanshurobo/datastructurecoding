/*
Given an array of integers that is already sorted in ascending order, find two numbers such that they 
add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where 
index1 must be less than index2.

Note:

Your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution and you may not use the same element twice.
Example:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore index1 = 1, index2 = 2.


WrittenBy : Himanshu Srivastava
Problem :  Two Sum II - Input array is sorted
TimeComplexity : O(logn)


*/

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int l = 0;
        int r = numbers.size() -1;
        vector<int> res;
        while(l < r){
            if(numbers[l] + numbers[r] == target){
                res.push_back(l+1);
                res.push_back(r+1);
                return res;
            }
            else if(numbers[l] + numbers[r] > target){
                r--;
            }
            else{
                l++;
            }
        }
        
        res.push_back(-1);
        res.push_back(-1);
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

    cout<<(sol.twoSum(input,4));

}