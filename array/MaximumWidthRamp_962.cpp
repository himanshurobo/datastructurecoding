/*
Given an array A of integers, a ramp is a tuple (i, j) for which i < j and A[i] <= A[j].  The width of such a ramp is j - i.

Find the maximum width of a ramp in A.  If one doesn't exist, return 0.

 

Example 1:

Input: [6,0,8,2,1,5]
Output: 4
Explanation: 
The maximum width ramp is achieved at (i, j) = (1, 5): A[1] = 0 and A[5] = 5.
Example 2:

Input: [9,8,1,0,1,9,4,0,4,1]
Output: 7
Explanation: 
The maximum width ramp is achieved at (i, j) = (2, 9): A[2] = 1 and A[9] = 1.
 

Note:

2 <= A.length <= 50000
0 <= A[i] <= 50000



WrittenBy : Himanshu Srivastava
Problem : Maximum Width Ramp
TimeComplexity : O(n)

*/


class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        
        stack<int> s;
        s.push(0);
        
        for( int i =1; i < A.size();i++){
            
            if(A[i] < A[s.top()]){
                s.push(i);
            }
        }
        
        
        int res = 0;
        int last = A.size()-1;
        
        
        while( !s.empty() && last >= s.top()){
            
            if( A[last] < A[s.top()]){
                last--;
                continue;
            }
            
            res = max( res, last-s.top());
            s.pop();
            
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

    cout<<(sol.maxWidthRamp(input));

    return 0;
}