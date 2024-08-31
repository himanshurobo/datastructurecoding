/*

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and
 return its area.

Example:

Input:
[
  ["1","0","1","0","0"],
  ["1","0","1","1","1"],
  ["1","1","1","1","1"],
  ["1","0","0","1","0"]
]
Output: 6



WrittenBy : Himanshu Srivastava
Problem : Maximal Rectangle
TimeComplexity : O(n)

*/




class Solution {

    private :

    int largestRectangleArea(vector<int>& heights) {

        stack<int> s;
        int maxArea = 0, area=-1;
        int n = heights.size();
        // s.push(0);
        int i;
        for( i =  0; i < n;){

            if( s.empty() || ( heights[i] > heights[s.top()])){

                s.push(i++);

            }else{
                int top = s.top();

                s.pop();

                if(s.empty()){

                    area = heights[top] * i;

                }else{

                    area = heights[top] * (i - s.top() - 1);

                }

                if( area > maxArea)
                    maxArea = area;
            }

        }

        while(!s.empty()){

                int top = s.top();
                s.pop();

                if(s.empty()){
                    area = heights[top] * i;

                }else{
                    area = heights[top] * (i - s.top() - 1);

                }

                if( area > maxArea)
                    maxArea = area;
        }
        return maxArea;

    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {

         if( matrix.size() == 0 ){
            return 0;
        }

        int row = matrix.size();
        int col = matrix[0].size();



        vector<int> res(col,0);
        int maxArea = 0;

        for( int r = 0 ; r < row;r++){
            for( int c = 0 ; c < col;c++){
                if( matrix[r][c] == '1'){
                    res[c] += 1;
                }else{
                    res[c] = 0;
                }
            }
            maxArea = max( maxArea,largestRectangleArea(res));
        }


        return maxArea;
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

    vector<char> input{
      ["1","0","1","0","0"],
      ["1","0","1","1","1"],
      ["1","1","1","1","1"],
      ["1","0","0","1","0"]
    };
    cout<<sol.maximalRectangle(input);

    return 0;
}
