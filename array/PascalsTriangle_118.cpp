/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]



WrittenBy : Himanshu Srivastava
Problem : Pascal's Triangle I
TimeComplexity : O(n)

*/



class Solution {
public:
    vector<vector<int>> generate(int numRows) {

       vector<vector<int>> vec(numRows);

        for( int i = 0 ; i < numRows ; i++){
            vec[i].resize(i + 1);
            vec[i][0] = vec[i][i] = 1;

            for( int j = 1 ; j<i;j++){

                vec[i][j] = vec[i-1][j-1] + vec[i-1][j];

            }

        }

        return vec;

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

    vector<vector<int>> res = sol.generate(numRows);

    return 0;
}
