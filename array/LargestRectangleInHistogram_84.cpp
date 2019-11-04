/*

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1,
 find the area of largest rectangle in the histogram.




Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].




The largest rectangle is shown in the shaded area, which has area = 10 unit.



Example:

Input: [2,1,5,6,2,3]
Output: 10

WrittenBy : Himanshu Srivastava
Problem : Largest Rectangle in Histogram
TimeComplexity : O(n)


*/




class Solution {
public:
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
};




void displayInt(vector<int>input){
    cout<<"Displaying size "<<input.size()<<endl;
    for (std::vector<int>::size_type i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

int main(){

    Solution sol;

    vector<int> search{2,5,6,0,0,1,2};
    cout<<sol.largestRectangleArea(input);

    return 0;
}
