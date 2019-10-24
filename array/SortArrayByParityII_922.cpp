/*

Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.

 

Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.
 

Note:

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000



WrittenBy : Himanshu Srivastava
Problem : Sort Array By Parity II
TimeComplexity : O(n)


*/



class Solution {
    
    void swap (int* a , int* b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
        
        
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        
        int even = 0;
        int odd = 1;
        int n = A.size();
        
        while( even < n ){
            
            while( even < n &&   A[even]%2 == 0 )
                even +=2;
            
            while(odd < n && A[odd]%2 ==1 )
                odd += 2;
            
            
            if(even < n)
                swap( &A[even], &A[odd]);
            
            even += 2;
            odd += 2;            
                
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

    cout<<(sol.sortArrayByParityII(input));

    return 0;
}