/*
You have an array of logs.  Each log is a space delimited string of words.

For each log, the first word in each log is an alphanumeric identifier.  Then, either:

Each word after the identifier will consist only of lowercase letters, or;
Each word after the identifier will consist only of digits.
We will call these two varieties of logs letter-logs and digit-logs.  It is guaranteed that each log has 
at least one word after its identifier.

Reorder the logs so that all of the letter-logs come before any digit-log.  The letter-logs are ordered 
lexicographically ignoring identifier, with the identifier used in case of ties.  The digit-logs should
 be put in their original order.

Return the final order of the logs.

 

Example 1:

Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]



WrittenBy : Himanshu Srivastava
Problem : Reorder Data in Log Files
TimeComplexity : O(n)

*/


class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> digitLogs, letterLogs;
        for (string &s : logs) {
            int i = 0;
            while (s[i] != ' ') ++i;
            if (isalpha(s[i + 1])) letterLogs.push_back(s.substr(i + 1) + " " + s.substr(0, i));
            else digitLogs.push_back(s);
        }
        sort(letterLogs.begin(), letterLogs.end());
        for (string &s : letterLogs) {
            int i = s.size() - 1;
            while (s[i] != ' ') --i;
            s = s.substr(i + 1) + " " + s.substr(0, i);
        }
        for (string &s : digitLogs) letterLogs.push_back(s);
        return letterLogs;
    
        
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

    displayInt(sol.reorderLogFiles(input));

    return 0;
}