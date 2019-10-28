/*

Given an array A of 0s and 1s, consider N_i: the i-th subarray from A[0] to A[i] interpreted as a binary number (from most-significant-bit to least-significant-bit.)

Return a list of booleans answer, where answer[i] is true if and only if N_i is divisible by 5.

Example 1:

Input: [0,1,1]
Output: [true,false,false]
Explanation: 
The input numbers in binary are 0, 01, 011; which are 0, 1, and 3 in base-10.  Only the first number is divisible by 5, so answer[0] is true.
Example 2:

Input: [1,1,1]
Output: [false,false,false]
Example 3:

Input: [0,1,1,1,1,1]
Output: [true,false,false,false,true,false]
Example 4:

Input: [1,1,1,0,1]
Output: [false,false,false,false,false]
 

Note:

1 <= A.length <= 30000
A[i] is 0 or 1

WrittenBy : Himanshu Srivastava
Problem : Binary Prefix Divisible By 5
TimeComplexity : O(n)

*/

class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        
        int sum = 0;
        vector<bool> res;
// Use the fact that (ab + c)%d is same as ((a%d)(b%d) + c%d)%d.
// We now have the relation new_number%5 = ((old_number%5)*2 + d)%5;
        // new_number = old_number*2 + d.
        
        for (auto i : A) {
            sum = (sum * 2 + i) % 5;
            cout<<sum<<endl;
            res.push_back(!sum);
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

    cout<<(sol.prefixesDivBy5(input));

    return 0;
}