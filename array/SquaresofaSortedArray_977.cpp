/*

Given an array of integers A sorted in non-decreasing order, return an array of the squares of each number, 
also in sorted non-decreasing order.


Example 1:

Input: [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Example 2:

Input: [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Note:

1 <= A.length <= 10000
-10000 <= A[i] <= 10000
A is sorted in non-decreasing order.


WrittenBy : Himanshu Srivastava
Problem : Squares of a Sorted Array
TimeComplexity : O(n)


*/


class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        
        int left = 0,right = A.size()-1;
        int index = right;
        vector<int> res(A.size(),0);
        while( left <= right){
            
            int aL = abs(A[left]);
            int aR = abs(A[right]);
            
            if( aL > aR ){
                res[index--]= aL*aL;
                left++;
            }else{
                res[index--] = aR*aR;
                right--;
 
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

    vector<int>input{7,1,5,3,6,4}

    cout<<(sol.sortedSquares(input));

    return 0;
}