
/*

There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

You may assume nums1 and nums2 cannot be both empty.

Example 1:

nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:

nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5


 WrittenBy : Himanshu Srivastava
 Problem : Find Median of Two Sorted Arrays 
 TimeComplexity : O(log(min(n, m)))

 */

#include "header.hpp"


class Solution {
public:

  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        int N1 = nums1.size();
        int N2 = nums2.size();
        
        if ( N1 > N2 ){
            return findMedianSortedArrays(nums2,nums1);
        }

        int low = 0 ;
        int high = N1;

        while( low <= high ){
            int partitionX = ( low + high )/2;
            int partitionY = ( N1 + N2 + 1 )/2 - partitionX;

            int maxLeftX = ( partitionX == 0 ) ? INT_MIN : nums1[partitionX-1];
            int minRightX = (partitionX == N1 ) ? INT_MAX : nums1[partitionX];

            int maxLeftY = ( partitionY == 0 ) ? INT_MIN : nums2[partitionY-1];
            int minRightY = ( partitionY == N2 ) ? INT_MAX : nums2[partitionY];

            if ( maxLeftX <= minRightY && maxLeftY <= minRightX ){

                if( (N1 + N2 ) % 2 == 0){
                    return (max(maxLeftX,maxLeftY) + min( minRightX,minRightY) )/2.0;
                }else{
                    return ( max(maxLeftX,maxLeftY));
                }
            }else if ( maxLeftX > minRightY ){
                high = partitionX - 1; 
            }else {
                low = partitionX + 1;
            }

        }

        return -1.0;

    }

    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        
    int N1 = nums1.size();
    int N2 = nums2.size();
    if (N1 < N2) return findMedianSortedArrays1(nums2, nums1);	// Make sure A2 is the shorter one.
    
    int lo = 0, hi = N2 * 2;
    while (lo <= hi) {
        int mid2 = (lo + hi) / 2;   // Try Cut 2 
        int mid1 = N1 + N2 - mid2;  // Calculate Cut 1 accordingly
        
        double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];	// Get L1, R1, L2, R2 respectively
        double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
        double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
        double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];
        
        if (L1 > R2) lo = mid2 + 1;		// A1's lower half is too big; need to move C1 left (C2 right)
        else if (L2 > R1) hi = mid2 - 1;	// A2's lower half too big; need to move C2 left.
        else return (max(L1,L2) + min(R1, R2)) / 2;	// Otherwise, that's the right cut.
    }
    return -1;
    }
};



int main(){

    Solution sol;

    vector<int> input1{1, 3, 11, 15};
    vector<int> input2{2};

    cout<<sol.findMedianSortedArrays(input1,input2)<<endl;

    return 0;
}
