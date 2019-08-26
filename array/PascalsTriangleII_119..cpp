/*

Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?

WrittenBy : Himanshu Srivastava
Problem : Pascal's Triangle II
TimeComplexity : O(n)

*/



class Solution {
public:
    vector<int> getRow(int rowIndex) {

        vector<vector<int>> res(rowIndex+1);

        for( int i = 0 ; i <= rowIndex; i++){
            res[i].resize(i+1);

            res[i][0] = res[i][i] = 1;

            for( int j = 1 ; j < i;j++){

                res[i][j] = res[i-1][j-1]+ res[i-1][j];
            }

        }

        return res[rowIndex];

    }
};




void displayInt(vector<int>input){
    cout<<"Displaying size "<<input.size()<<endl;
    for (std::vector<int>::size_type i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main(){

    Solution sol;

    int numRows = 5;

    displayInt(sol.getRow(numRows));

    return 0;
}
