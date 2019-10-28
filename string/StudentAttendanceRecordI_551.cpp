/*
You are given a string representing an attendance record for a student. The record only contains the following three characters:
'A' : Absent.
'L' : Late.
'P' : Present.
A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).

You need to return whether the student could be rewarded according to his attendance record.

Example 1:
Input: "PPALLP"
Output: True
Example 2:
Input: "PPALLL"
Output: False

WrittenBy : Himanshu Srivastava
Problem : Student Attendance Record I
TimeComplexity : O(n)



*/

class Solution {
public:
    bool checkRecord(string s) {
        
        int n = s.size();        
        int a = 0;
        int l  = 0;
        for( auto ch : s){
            
            if( ch == 'A'){
                a++;
            }
            if( ch == 'L'){
                l++;
            }else{
                l = 0;
            }
            
            if( a >= 2 || l > 2)
                return false;            
            
        }
        
        return true;
        
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

    displayInt(sol.checkRecord(input));

    return 0;
}