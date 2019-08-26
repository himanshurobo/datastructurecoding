
/*

Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.
Example:

Input:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

Output: [1,2,2,3,5,6]


WrittenBy : Himanshu Srivastava
Problem : Merge Sorted Array
TimeComplexity : O(n+m)


*/



class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

        int i = m-1 ;
        int j = n-1 ;
        int l = m+n-1;

        while( j>=0 ){
            nums1[l--] = i >= 0 && nums1[i] > nums2[j] ? nums1[i--]:nums2[j--];
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

    vector<int> input1{1,2,3,0,0,0};
    std::vector<int> input2{2,5,6};
    displayInt(sol.merge(input1,input1.size(), input2, input2.size()));

    return 0;
}
