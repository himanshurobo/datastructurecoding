
/* 
 WrittenBy : Himanshu Srivastava
 Problem : Two Sum 
 TimeComplexity : O(n)

 */



#include<iostream>
#include <vector>
#include<bits/stdc++.h> 

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> hash;
        vector<int> result;
        for( int i = 0 ; i <nums.size(); i++){
            int diff = target - nums[i];
            
            if( hash.find(diff) != hash.end()){
                result.push_back(hash[diff]);
                result.push_back(i);
            }
            
            hash[nums[i]] = i;
        }
        
        return result;
    }

    void displayInt(vector<int>input){
        cout<<"Displaying size "<<input.size()<<endl;
        for (std::vector<int>::size_type i = 0; i < input.size(); i++) {
            std::cout << input.at(i) << ' ';
        }
    }
};

int main(){

    Solution sol;

    vector<int> input{2, 7, 11, 15};
    int target = 9;

    sol.displayInt(sol.twoSum(input,target));

    return 0;
}