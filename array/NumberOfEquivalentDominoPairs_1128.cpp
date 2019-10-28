/*

Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a==c and b==d), or (a==d and b==c) - that is, one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

 

Example 1:

Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
Output: 1
 

Constraints:

1 <= dominoes.length <= 40000
1 <= dominoes[i][j] <= 9

WrittenBy : Himanshu Srivastava
Problem : Number of Equivalent Domino Pairs
TimeComplexity : O(n)


*/


class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        // 1 <= dominoes[i][j] <= 9
        vector<int> res(100);
        int count = 0;
        for( auto domino : dominoes){
            
            int up = domino[0] > domino[1] ? domino[0]:domino[1];
            int down = domino[0] > domino[1] ? domino[1] : domino[0];            
            count += res[up*10+down]++;            
        }
        
        return count;
        
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

    cout<<(sol.numEquivDominoPairs(input));

    return 0;
}