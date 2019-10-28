/*

X is a good number if after rotating each digit individually by 180 degrees, we get a valid number that is different from X.  Each digit must be rotated - we cannot choose to leave it alone.

A number is valid if each digit remains a digit after rotation. 0, 1, and 8 rotate to themselves; 2 and 5 rotate to each other; 6 and 9 rotate to each other, and the rest of the numbers do not rotate to any other number and become invalid.

Now given a positive number N, how many numbers X from 1 to N are good?

Example:
Input: 10
Output: 4
Explanation: 
There are four good numbers in the range [1, 10] : 2, 5, 6, 9.
Note that 1 and 10 are not good numbers, since they remain unchanged after rotating.

WrittenBy : Himanshu Srivastava
Problem : Rotated Digits
TimeComplexity : O(n)

*/

class Solution {
public:
    int rotatedDigits(int N) {
        int res = 0;
                                //0  1  2  3  4  5  6  7  8  9
        vector<int> must_have = { 0, 0, 1, 0, 0, 1, 1, 0, 0, 1};
        vector<int> cant_have = { 0, 0, 0, 1, 1, 0, 0, 1, 0, 0};
        for (int i = 1; i <= N; ++i) {
            int m = 0, c = 0, num = i;
            while (num) {
                int digit = num % 10;
                if (cant_have[digit]){
                    ++c;
                    break;
                }
                if (must_have[digit]) ++m;
                num /= 10;
            }
            if (c) continue;   // if you have cant_have number
            if (!m) continue;  // if you don't have must_have number 
            res++;
        }
        return res;
        
    }
};


void displayInt(vector<string>input){
    cout<<"Displaying size "<<input.size()<<endl;
    for (std::vector<string>::size_type i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main(){

    Solution sol;

    vector<string>input{"abcabcbb"}

    displayInt(sol.rotatedDigits(input));

    return 0;
}