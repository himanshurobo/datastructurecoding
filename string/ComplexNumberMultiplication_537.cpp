/*

Given two strings representing two complex numbers.

You need to return a string representing their multiplication. Note i2 = -1 according to the definition.

Example 1:
Input: "1+1i", "1+1i"
Output: "0+2i"
Explanation: (1 + i) * (1 + i) = 1 + i2 + 2 * i = 2i, and you need convert it to the form of 0+2i.
Example 2:
Input: "1+-1i", "1+-1i"
Output: "0+-2i"
Explanation: (1 - i) * (1 - i) = 1 + i2 - 2 * i = -2i, and you need convert it to the form of 0+-2i.
Note:

The input strings will not have extra blank.
The input strings will be given in the form of a+bi, where the integer a and b will both belong to the
 range of [-100, 100]. And the output should be also in this form.

WrittenBy : Himanshu Srivastava
Problem : Complex Number Multiplication
TimeComplexity : O(n)

*/



class Solution {
    
    pair<int, int> parse(const string& a) {
        int plus = find(a.begin(), a.end(), '+') - a.begin();
        int i = find(a.begin(), a.end(), 'i') - a.begin();
        int ra = stoi(a.substr(0, plus));
        int rb = stoi(a.substr(plus + 1, i - plus));
        return {ra, rb};
    }
public:
    string complexNumberMultiply(string a, string b) {
        pair<int, int> av = parse(a);
        pair<int, int> bv = parse(b);
        int ra = av.first * bv.first - av.second * bv.second;
        int rb = av.first * bv.second + av.second * bv.first;
        return to_string(ra) + "+" + to_string(rb) + "i";
        
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

    displayInt(sol.complexNumberMultiply(input));

    return 0;
}