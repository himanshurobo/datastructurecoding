/*

Students are asked to stand in non-decreasing order of heights for an annual photo.

Return the minimum number of students not standing in the right positions.  
(This is the number of students that must move in order for all students to be standing in
 non-decreasing order of height.)

 

Example 1:

Input: [1,1,4,2,1,3]
Output: 3
Explanation: 
Students with heights 4, 3 and the last 1 are not standing in the right positions.
 

Note:

1 <= heights.length <= 100
1 <= heights[i] <= 100

WrittenBy : Himanshu Srivastava
Problem : Height Checker
TimeComplexity : O(n)


*/


class Solution {
public:
    int heightChecker(vector<int>& heights) {
        
        vector<int> cpy = heights;
        int res= 0;
        sort(cpy.begin(),cpy.end());
        
        for( int i = 0 ; i < heights.size();i++){
            
            if( heights[i] != cpy[i]){
                res++;
            }
        }
        
        return res;
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

    cout<<(sol.heightChecker(input));

    return 0;
}