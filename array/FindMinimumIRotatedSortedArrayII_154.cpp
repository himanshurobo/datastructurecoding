/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

The array may contain duplicates.

Example 1:

Input: [1,3,5]
Output: 1
Example 2:

Input: [2,2,2,0,1]
Output: 0

WrittenBy : Himanshu Srivastava
Problem : Find Minimum in Rotated Sorted Array II
TimeComplexity : O(logn)

*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int start = 0, end = nums.size() -1;
        
        while( start < end){
            
            int mid = start + (end-start)/2;
            
            if( nums[mid] > nums[end]){                
                start = mid +1;
            }else if ( nums[mid] < nums[start]){
                
                end = mid;
            }else{
                end--;
            }
        }
                
        return nums[start];
        
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

    cout<<(sol.findMin(input));

}