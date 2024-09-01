/*

Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


WrittenBy : Himanshu Srivastava
Problem : Add Binary
TimeComplexity : O(n)

*/


class Solution {
public:
    string addBinary1(string a, string b) {
        
     reverse( a.begin(), a.end());
     reverse( b.begin(), b.end()); 
        
     int len = 0 ;      
        
     if( a.size() > b.size()){
         len = a.size() + 1;
     }else{
         len = b.size() + 1;
     }
      
      string result(len,'0');
        if( a.size() == 1 && b.size() == 1 && a[0] == '0' && b[0] == '0'){
            return "0";
        }
        
        int carry = 0 ;
        
        for( int i = 0 ; i<len ; i++){
            
            int p = i < a.size() ? a[i] - '0' : 0 ;
            int q = i < b.size() ? b[i] - '0' : 0 ;
            
            int sum = p + q + carry;
            
            if(sum == 0){
                carry = 0 ;
                result[i] = '0';
            }
            
            if( sum == 1){
                carry = 0;
                result[i] = '1';
            }
            
            if( sum == 2){
                carry = 1;
                result[i] = '0';
            }
            
            if( sum == 3){
                carry = 1;
                result[i] = '1';
            }
            
        }
        
        reverse( result.begin(),result.end());
        
        if(carry != 1 ){
            result.erase(0, result.find_first_not_of('0'));
        }
        return result ;
        
        
        
        
    }
    
    
string addBinary(string a, string b) {
    string result;
    int carry = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    // Process both strings from end to start
    while (i >= 0 || j >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += a[i--] - '0'; // Convert char to int and add to sum
        if (j >= 0) sum += b[j--] - '0'; // Convert char to int and add to sum
        
        carry = sum / 2; // Calculate carry
        result += (sum % 2) + '0'; // Add the current bit to the result
    }

    reverse(result.begin(), result.end()); // Reverse the result to get the final answer
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

    displayInt(sol.addBinary(input));

    return 0;
}
