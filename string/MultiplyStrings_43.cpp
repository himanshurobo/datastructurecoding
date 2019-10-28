/*

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"

WrittenBy : Himanshu Srivastava
Problem : Multiply Strings
TimeComplexity : O(n)

*/

class Solution {
public:
    string multiply(string num1, string num2) {
       
        if( num1.size() == 0 || num2.size() == 0) {
            return "";
        }
        
        string result( num1.size() + num2.size() + 1, '0' );
        reverse(num2.begin(),num2.end());
        reverse(num1.begin(),num1.end());
        
        for( int i = 0 ; i < num2.size(); i++){
            int a = num2[i] - '0';
            int carry = 0 ;
            for( int j = 0 ; j < num1.size(); j++){
                int b = num1[j] - '0';
                int temp = result[i+j] - '0';
                int sum = a*b + temp + carry;
                result[i+j] = sum%10 + '0';
                carry = sum/10;
            }
            result[i + num1.size()] = carry + '0';            
        }
        reverse( result.begin(),result.end());
        
        cout<<result;
        result.erase(0, result.find_first_not_of('0'));
        if( result.size() == 0){
            result.push_back('0');
        }
        
        
        return result;
        
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

    displayInt(sol.multiply(input));

    return 0;
}