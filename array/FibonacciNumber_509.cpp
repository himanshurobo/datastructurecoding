/*
The Fibonacci numbers, commonly denoted F(n) form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1. That is,

F(0) = 0,   F(1) = 1
F(N) = F(N - 1) + F(N - 2), for N > 1.
Given N, calculate F(N).

 

Example 1:

Input: 2
Output: 1
Explanation: F(2) = F(1) + F(0) = 1 + 0 = 1.
Example 2:

Input: 3
Output: 2
Explanation: F(3) = F(2) + F(1) = 1 + 1 = 2.
Example 3:

Input: 4
Output: 3
Explanation: F(4) = F(3) + F(2) = 2 + 1 = 3.


WrittenBy : Himanshu Srivastava
Problem : Fibonacci Number
TimeComplexity : O(n)


*/

class Solution {
public:
    
    //Time COmplexity : O(n*n) ( Recusive )
    // Space : O(n)
    int fib1(int N) {
        
        
        if( N == 1 ){
            return 1;
        }
        
        if( N == 0){
            return 0;
        }
                
        return fib(N-1) + fib(N-2);                
        
    }
    
    
    //Time COmplexity : O(n) ( DP)
    // Space : O(n)
    int fib2(int N) {
        if(N < 2)
            return N;
        int memo[N+1];
        memo[0] = 0;
        memo[1] = 1;
        for(int i=2; i<=N; i++)
            memo[i] = memo[i-1] + memo[i-2];
        return memo[N];
    }
    
    
    
    // Time Complexity - O(N)
    // Space Complexity - O(1)

    int fib(int N) {
        if(N < 2) 
            return N;
    	int a = 0, b = 1, c = 0;
        for(int i = 1; i < N; i++)
        {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
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

    cout<<(sol.fib(5));

    return 0;
}