/*

Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.

Note:

The length of both num1 and num2 is < 5100.
Both num1 and num2 contains only digits 0-9.
Both num1 and num2 does not contain any leading zero.
You must not use any built-in BigInteger library or convert the inputs to integer directly.


WrittenBy : Himanshu Srivastava
Problem : Add Strings
TimeComplexity : O(n)


*/


class Solution {
public:
    string addStrings(string num1, string num2) {
        
        int i=num1.size()-1,j=num2.size()-1,carry=0;
    string res="";
    while(i>=0||j>=0)
    {
        if(i>=0) carry+=num1[i--]-'0';
        if(j>=0) carry+=num2[j--]-'0';
        res=to_string(carry%10)+res;
        carry/=10;
    }
    return carry?"1"+res:res;
        
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

    displayInt(sol.addStrings(input));

    return 0;
}