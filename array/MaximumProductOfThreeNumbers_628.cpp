/*

Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:

Input: [1,2,3]
Output: 6
 

Example 2:

Input: [1,2,3,4]
Output: 24

WrittenBy : Himanshu Srivastava
Problem : Maximum Product of Three Numbers
TimeComplexity : O(n)

*/


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1 = INT_MIN, max2 = INT_MIN, max3 = INT_MIN;
        int min1 = INT_MAX, min2 = INT_MAX;
        
        
        for( int i = 0 ; i < nums.size(); i++ ){
            
            if( max3 < nums[i]){                 
                max1 = max2;
                max2 = max3 ;
                max3 = nums[i];
            }else if( max2 < nums[i]){
                    max1 = max2;
                    max2 = nums[i];
                    
            }else if( max1 < nums[i]){
                    max1 = nums[i];
            }

            
            if ( min2 > nums[i]) {
                
                min1 = min2;
                min2 = nums[i];
            }else if( min1 > nums[i] ){
                min1 = nums[i];
            }
            
        }
        
        // cout<<max1<<" "<<max2<<" "<<max3<<" "<<min1<<" "<<min2<<endl;
        return max(max1*max2*max3,min1*min2*max3);
        
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

    cout<<(sol.maximumProduct(input));

    return 0;
}