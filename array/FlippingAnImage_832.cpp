/*


Given a binary matrix A, we want to flip the image horizontally, then invert it, and 
return the resulting image.

To flip an image horizontally means that each row of the image is reversed.  For example, 
flipping [1, 1, 0] horizontally results in [0, 1, 1].

To invert an image means that each 0 is replaced by 1, and each 1 is replaced by 0. For example, 
inverting [0, 1, 1] results in [1, 0, 0].

Example 1:

Input: [[1,1,0],[1,0,1],[0,0,0]]
Output: [[1,0,0],[0,1,0],[1,1,1]]
Explanation: First reverse each row: [[0,1,1],[1,0,1],[0,0,0]].
Then, invert the image: [[1,0,0],[0,1,0],[1,1,1]]
Example 2:

Input: [[1,1,0,0],[1,0,0,1],[0,1,1,1],[1,0,1,0]]
Output: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Explanation: First reverse each row: [[0,0,1,1],[1,0,0,1],[1,1,1,0],[0,1,0,1]].
Then invert the image: [[1,1,0,0],[0,1,1,0],[0,0,0,1],[1,0,1,0]]
Notes:

1 <= A.length = A[0].length <= 20
0 <= A[i][j] <= 1


WrittenBy : Himanshu Srivastava
Problem : Flipping an Image
TimeComplexity : O(n)



*/



class Solution {
    
    void swap(int* a, int* b){
        int temp = *a;
        
        if( *b ){
            *a = 0;
        }else{
            *a = 1;
        }
        
        if( temp ){
            *b = 0;
            
        }else{
            *b = 1;
        }

    }
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
        
        for( int i = 0 ; i < A.size();i++){
            
            int left = 0;
            int right = A[i].size()-1;
            
            while( left <= right){                
                swap(&A[i][left],&A[i][right]);
                left++;
                right--;
            }
            
        }
        
        return A;
        
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

    cout<<(sol.flipAndInvertImage(input));

    return 0;
}