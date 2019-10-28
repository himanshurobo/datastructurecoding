

 /*
 Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:

Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75

WrittenBy : Himanshu Srivastava
Problem : . Maximum Average Subarray I
TimeComplexity : O(n)

 */



 class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        
        if( nums.size() < k){
            return -1;
        }
        
        double res = 0.0;
        double avg = 0.0 ;
        for( int i = 0 ; i <k; i++ ){
            avg += nums[i];            
        }
        
        avg /=k;
        res = avg;

        for( int i = k ; i < nums.size(); i++){
            
            avg = avg*k - nums[i-k];
            avg = (avg + nums[i])/k;
            
            res = max(res,avg);
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

    cout<<(sol.findMaxAverage(input));

    return 0;
}