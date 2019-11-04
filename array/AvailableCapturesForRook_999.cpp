/*

On an 8 x 8 chessboard, there is one white rook.  There also may be empty squares, white bishops, 
and black pawns.  These are given as characters 'R', '.', 'B', and 'p' respectively.
 Uppercase characters represent white pieces, and lowercase characters represent black pieces.

The rook moves as in the rules of Chess: it chooses one of four cardinal directions 
(north, east, west, and south), then moves in that direction until it chooses to stop, 
reaches the edge of the board, or captures an opposite colored pawn by moving to the same square it occupies. 
 Also, rooks cannot move into the same square as other friendly bishops.

Return the number of pawns the rook can capture in one move.

 

Example 1:



Input: [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 3
Explanation: 
In this example the rook is able to capture all the pawns.
Example 2:



Input: [[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 0
Explanation: 
Bishops are blocking the rook to capture any pawn.
Example 3:



Input: [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
Output: 3
Explanation: 
The rook can capture the pawns at positions b5, d6 and f5.
 

Note:

board.length == board[i].length == 8
board[i][j] is either 'R', '.', 'B', or 'p'
There is exactly one cell with board[i][j] == 'R'

WrittenBy : Himanshu Srivastava
Problem : Available Captures for Rook
TimeComplexity : O(n)

*/


class Solution {
    
    private:
    int capture(vector<vector<char>>& board, int x, int y, int dx, int dy){
        
        while( x >= 0 && x < board.size() && y >= 0 && y < board[x].size() && board[x][y] != 'B'){
            
            if( board[x][y] == 'p') return 1;
            
            x += dx, y +=dy;
        }
        
        return 0;
    }
    
    
    
public:
    int numRookCaptures(vector<vector<char>>& board) {
        
        int m =  board.size();
        int n = board[0].size();
        
        
        for( auto i = 0 ; i < m ; i++){
            for( auto j  = 0 ; j < n ; j++){
                
                if( board[i][j] == 'R'){
                    return capture( board,i,j,0,1) + capture( board,i,j,1,0) + capture( board,i,j,0,-1) + capture( board,i,j,-1,0);
                }
            }
        }
        
        return 0;
        
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

    vector<int>input{7,1,5,3,6,4}

    cout<<(sol.numRookCaptures(input));

    return 0;
}