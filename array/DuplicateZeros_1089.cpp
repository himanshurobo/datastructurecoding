/*
Given a fixed length array arr of integers, duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place, do not return anything from your function.

 

Example 1:

Input: [1,0,2,3,0,4,5,0]
Output: null
Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
Example 2:

Input: [1,2,3]
Output: null
Explanation: After calling your function, the input array is modified to: [1,2,3]
 

Note:

1 <= arr.length <= 10000
0 <= arr[i] <= 9


WrittenBy : Himanshu Srivastava
Problem : Duplicate Zeros
TimeComplexity : O(n)

*/


class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        
        int n = arr.size(), j = n + count(arr.begin(), arr.end(), 0);
        // cout<<j<<endl;
        for (int i = n - 1; i >= 0; --i) {
            if (--j < n){
                // cout<<j<<i<<"**"<<endl;
                arr[j] = arr[i];
            }
            if (arr[i] == 0 && --j < n){
                // cout<<j<<i<<"++"<<endl;
                arr[j] = 0;
            }
                
        }
        
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

    cout<<(sol.duplicateZeros(input));

    return 0;
}