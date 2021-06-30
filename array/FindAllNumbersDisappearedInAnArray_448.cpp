/*



Given an array of integers where 1 ≤ a[i] ≤ n (n = size of array), some elements appear twice and
 others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime? You may assume the returned list does not 
count as extra space.

Example:

Input:
[4,3,2,7,8,2,3,1]

Output:
[5,6]

WrittenBy : Himanshu Srivastava
Problem :Find All Numbers Disappeared in an Array
TimeComplexity : O(n)

*/

#include<iostream>
#include <vector>
#include<bits/stdc++.h> 
using namespace std;


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        
        for( int i = 0 ; i < nums.size(); i++){            
            int index = abs(nums[i]) -1;
            nums[index] = nums[index] > 0 ? -nums[index]:nums[index];
            // cout<<i<<"<---"<<index<<"-->>"<<nums[index]<<endl;   
              cout<<endl;
            for( int i = 0 ; i < nums.size(); i++){
             cout<< nums[i]<<"->";   
            }      
        }
      
        
        vector<int> res;
        for( int i = 0 ; i < nums.size(); i++){
         
            if( nums[i] > 0){
                cout<<i<<"--->>"<<nums[i]<<endl;
                res.push_back(i+1);
            }
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

    vector<int>input{4,3,2,7,8,2,3,1};
    displayInt(input);
   displayInt(sol.findDisappearedNumbers(input));

    return 0;
}