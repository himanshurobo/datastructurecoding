/*
Given a 2D board and a word, find if the word exists in the grid.

The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring. The same letter cell may not be used more than once.

Example:

board =
[
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
]

Given word = "ABCCED", return true.
Given word = "SEE", return true.
Given word = "ABCB", return false.


WrittenBy : Himanshu Srivastava
Problem : Word Search
TimeComplexity : O(n+m)

*/




class Solution {

    bool search( vector<vector<char>>& board, string word, int index, int i, int j ){
        if( index == word.size()){
            return true;
        }

        int row = board.size();
        int col = board[0].size();

        if( i < 0 || i >= row || j < 0 || j >= col || board[i][j] != word[index]){
            return false;
        }

        char ch = board[i][j];
        board[i][j] = '*';

        bool isPresent = search(board, word, index+1,i-1,j)||
                         search(board, word, index+1,i,j-1)||
                         search(board, word, index+1,i+1,j)||
                         search(board, word, index+1,i,j+1);

        board[i][j] = ch;

        return isPresent;


    }


public:
    bool exist(vector<vector<char>>& board, string word) {

        if( board.size() == 0 || board[0].size() == 0 || word.size() == 0){
            return false;
        }

        int row = board.size();
        int col = board[0].size();

        for( int i = 0; i < row; i++){
            for( int j = 0; j < col; j++){
                if( search(board,word,0,i,j) ){
                    return true;
                }

            }
        }

        return false;

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

    vector<vector<char>> input{[
      ['A','B','C','E'],
      ['S','F','C','S'],
      ['A','D','E','E']
    ]};

    cout<<sol.exist(input);

    return 0;
}
