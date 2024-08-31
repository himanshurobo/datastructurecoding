/*

In a row of seats, 1 represents a person sitting in that seat, and 0 represents that the seat is empty. 

There is at least one empty seat, and at least one person sitting.

Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 

Return that maximum distance to closest person.

Example 1:

Input: [1,0,0,0,1,0,1]
Output: 2
Explanation: 
If Alex sits in the second open seat (seats[2]), then the closest person has distance 2.
If Alex sits in any other open seat, the closest person has distance 1.
Thus, the maximum distance to the closest person is 2.
Example 2:

Input: [1,0,0,0]
Output: 3
Explanation: 
If Alex sits in the last seat, the closest person is 3 seats away.
This is the maximum distance possible, so the answer is 3.
Note:

1 <= seats.length <= 20000
seats contains only 0s or 1s, at least one 0, and at least one 1.


WrittenBy : Himanshu Srivastava
Problem : Maximize Distance to Closest Person
TimeComplexity : O(n)

*/

#include"../header.hpp"
#include<math.h>

class Solution {
public:
    int maxDistToClosest1(vector<int>& seats) {
        
        int res = 0, n = seats.size(), last = -1;
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                res = last < 0 ? i : max(res, (i - last) / 2);
                last = i;
                std::cout<<"i : "<<i<<" res : "<<res<<" last : "<<last<<endl;
            }
        }
        res = max(res, n - last - 1);
        cout<<"RESULT : "<<res<<endl;
        return res;
        
    }

    int maxDistToClosest2(vector<int>& seats) {
        int N = seats.size();
        int K = 0; //current longest group of empty seats
        int ans = 0;

        for (int i = 0; i < N; ++i) {
            if (seats[i] == 1) {
                K = 0;
            } else {
                K++;
                ans = max(ans, (K + 1) / 2);
            }
        }

        for (int i = 0; i < N; ++i)  if (seats[i] == 1) {
            ans = max(ans, i);
            break;
        }

        for (int i = N-1; i >= 0; --i)  if (seats[i] == 1) {
            ans = max(ans, N - 1 - i);
            break;
        }

        return ans;
    }

int maxDistToClosest(vector<int>& seats) {

        int maxDist = 0;
        int len = -1;
        int n = seats.size();

        for( int i =0 ;i < n; i++){

            if( seats[i]== 1){

                if ( len == -1){
                    maxDist = i;
                }else{
                    maxDist = std::max(maxDist, (i - len) /2);
                }

                len = i;
            }

        }

        if( seats[n-1] == 0){
            maxDist = std::max(maxDist,n- 1 - len);
        }
        
        return maxDist;
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

    vector<int>input{0,0,0,0,1};

    std::cout<<(sol.maxDistToClosest(input));

    return 0;
}
