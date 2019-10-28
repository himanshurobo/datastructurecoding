/*


Validate if a given string can be interpreted as a decimal number.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
" -90e3   " => true
" 1e" => false
"e3" => false
" 6e-1" => true
" 99e2.5 " => false
"53.5e93" => true
" --6 " => false
"-+3" => false
"95a54e53" => false

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one. However, here is a list of characters that can be in a valid decimal number:

Numbers 0-9
Exponent - "e"
Positive/negative sign - "+"/"-"
Decimal point - "."
Of course, the context of these characters also matters in the input.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button to reset your code definition.


WrittenBy : Himanshu Srivastava
Problem : Valid Number
TimeComplexity : O(n)

*/


class Solution {
public:
    bool isNumber(string s) {
                
        int i = 0 ;
        //Skip White space from starting
        while( s[i] == ' ')
            i++;
        // Skip sign exist
        if(s[i] == '-' || s[i] == '+')
            i++;
        
        int k = s.size()-1;
        // Skip trailing space
        while(s[k] == ' ')
            k--;
        
        bool eSeen = false;
        bool dotSeen = false;
        bool digitSeen = false;
        for( int j = i ;  j <= k ; j++ ){

            char ch = s[j];

            if( isdigit(ch) ){
                digitSeen = true;
            }else if( ch == 'e'){
                if( eSeen || !digitSeen ) return false;
                else{
                    eSeen = true;
                    digitSeen = false;
                }
            }else if( ch == '.'){                
                if( eSeen || dotSeen ) return false;
                else{
                    dotSeen = true;
                }
            }else if (ch == '-' || ch == '+'){
                if( j !=0 && (s[j-1]) != 'e') return false;                
            }else{
                return false;
            }
                        
        }
        
        return digitSeen;
        
        
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

    displayInt(sol.isNumber(input));

    return 0;
}