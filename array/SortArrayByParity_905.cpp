/*

Given an array A of non-negative integers, return an array consisting of all the even elements of A, 
followed by all the odd elements of A.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [3,1,2,4]
Output: [2,4,3,1]
The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
 

Note:

1 <= A.length <= 5000
0 <= A[i] <= 5000

WrittenBy : Himanshu Srivastava
Problem : Sort Array By Parity
TimeComplexity : O(n)



*/


class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int left = 0;
        int right = A.size()-1;
        int index = 0;
        while( left<=right){
            
            if( A[index]%2==0){
                int temp = A[left];
                A[left] = A[index];
                A[index] = temp;
                index = ++left;
            }else{
                int temp = A[right];
                A[right] = A[index];
                A[index] = temp;
                index = --right;
            }
            
           
        }
        
        return A;
        
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

    cout<<(sol.sortArrayByParity(input));

    return 0;
}