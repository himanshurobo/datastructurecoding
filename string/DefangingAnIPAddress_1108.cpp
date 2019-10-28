/*

Given a valid (IPv4) IP address, return a defanged version of that IP address.

A defanged IP address replaces every period "." with "[.]".

 

Example 1:

Input: address = "1.1.1.1"
Output: "1[.]1[.]1[.]1"
Example 2:

Input: address = "255.100.50.0"
Output: "255[.]100[.]50[.]0"

WrittenBy : Himanshu Srivastava
Problem : Defanging an IP Address
TimeComplexity : O(n)


*/


class Solution {
public:
    string defangIPaddr(string address) {
        int o = 0, r = 0, i = 0;
        while (i < 3) {
            r = (address.substr(o)).find(".") + o;
            address.replace(r, 1, "[.]");
            o = r + 4;
            i++;
        }
        return address;
        
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

    displayInt(sol.defangIPaddr(input));

    return 0;
}