/*

Given an array A of integers, return true if and only if we can partition the array into three non-empty parts with equal sums.

Formally, we can partition the array if we can find indexes i+1 < j with (A[0] + A[1] + ... + A[i] == A[i+1] + A[i+2] + ... + A[j-1] == A[j] + A[j-1] + ... + A[A.length - 1])

 

Example 1:

Input: [0,2,1,-6,6,-7,9,1,2,0,1]
Output: true
Explanation: 0 + 2 + 1 = -6 + 6 - 7 + 9 + 1 = 2 + 0 + 1
Example 2:

Input: [0,2,1,-6,6,7,9,-1,2,0,1]
Output: false
Example 3:

Input: [3,3,6,5,-2,2,5,1,-9,4]
Output: true
Explanation: 3 + 3 = 6 = 5 - 2 + 2 + 5 + 1 - 9 + 4
 

Note:

3 <= A.length <= 50000
-10000 <= A[i] <= 10000

WrittenBy : Himanshu Srivastava
Problem : Partition Array Into Three Parts With Equal Sum
TimeComplexity : O(n)

*/

class Solution {
public:
    bool canThreePartsEqualSum1(vector<int>& A) {
        
        int left = 0;
        int right = A.size()-1;
        
        int leftSum = 0 ;
        int rightSum = 0;
        while( left <= right ){
            
            
           
            cout<<leftSum<<"<->"<<rightSum<<endl;
            if( leftSum < rightSum ){
                leftSum += A[left];
                 left++;
            }else{
                 rightSum += A[right];
                right--;
            }
                       
            if( leftSum == rightSum){
                break;
            }
            
        }
        

        
        cout<<leftSum<<" "<<rightSum<<" "<<left<<" "<<right<<endl;
        int midSum =0 ;
        while(left <= right ){
            midSum += A[left];
            
            left++;
        }
        cout<<midSum<<" "<<left<<" "<<right<<endl;
        if( leftSum == midSum ){
            return true;
        }
        
        
        return false;
        
    }
    
    bool canThreePartsEqualSum(vector<int>& a)
{
    int sum = accumulate(a.begin(), a.end(), 0);
    
    if(sum%3!=0) return false;
    
    int subSum = sum/3;
    cout<<subSum<<endl;
    bool firstFound=false, secondFound = false, thirdFound = false;
    
    int prefixSum=0;
    for(auto ele : a)
    {
        prefixSum += ele;
        if(!firstFound && prefixSum==subSum) firstFound = true;
        else if(firstFound && !secondFound && prefixSum==subSum*2) secondFound = true;
        else if(firstFound && secondFound && prefixSum==subSum*3) thirdFound = true;
    }
    
    return (firstFound && secondFound && thirdFound);
        
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

    cout<<(sol.canThreePartsEqualSum(input));

    return 0;
}