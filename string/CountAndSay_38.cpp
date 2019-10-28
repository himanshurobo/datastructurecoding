/*
The count-and-say sequence is the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence.

WrittenBy : Himanshu Srivastava
Problem : Count and Say
TimeComplexity : O(n)


*/

class Solution {
public:
    string countAndSay(int n) {
        string curr_str;

	// The initial case, when n = 1
	curr_str += '1';
    cout<<curr_str<<endl;
	// The iterative case, when n > 1
	for (int i = 0; i < n - 1; i++)
	{
		string buffer;

		// Handle the current string
		int index = 0;
		for (index = 0; index < curr_str.size(); ++index)
		{
			// Count the occurance of each digit
			int cnt = 1; // At least one occurance
			
			while (index + 1 < curr_str.size() and curr_str[index + 1] == curr_str[index]) 
			{
				index++;
				cnt++;
			}

			buffer.push_back(cnt + '0');
			buffer.push_back(curr_str[index]);
		}

		// Update the current string
		curr_str = buffer;
	}

	return curr_str;
        
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

    displayInt(sol.countAndSay(input));

    return 0;
}