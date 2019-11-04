/*
An array is monotonic if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j, A[i] <= A[j].  An array A is monotone decreasing 
if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.

 

Example 1:

Input: [1,2,2,3]
Output: true
Example 2:

Input: [6,5,4,4]
Output: true
Example 3:

Input: [1,3,2]
Output: false
Example 4:

Input: [1,2,4,5]
Output: true
Example 5:

Input: [1,1,1]
Output: true



WrittenBy : Himanshu Srivastava
Problem : Monotonic Array
TimeComplexity : O(n)
*/


class Solution {
public:
    bool isMonotonic(vector<int>& A) {
        
        bool isIncreasing = true;
        bool isDecreasing = true;

        int right = A.size();
        int left = 0;
        
        while( left < right-1){
            
            isIncreasing &= A[left] <= A[left+1] ;
            isDecreasing &= A[left] >= A[left+1] ;
            left++;
        }
        
        return isIncreasing | isDecreasing;
        
        
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

    cout<<(sol.isMonotonic(input));

    return 0;
}