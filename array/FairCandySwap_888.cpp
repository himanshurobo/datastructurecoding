/*


Alice and Bob have candy bars of different sizes: A[i] is the size of the i-th bar of candy that Alice has, 
and B[j] is the size of the j-th bar of candy that Bob has.

Since they are friends, they would like to exchange one candy bar each so that after the exchange, 
they both have the same total amount of candy.  (The total amount of candy a person has is the sum of 
the sizes of candy bars they have.)

Return an integer array ans where ans[0] is the size of the candy bar that Alice must exchange, 
and ans[1] is the size of the candy bar that Bob must exchange.

If there are multiple answers, you may return any one of them.  It is guaranteed an answer exists.

 

Example 1:

Input: A = [1,1], B = [2,2]
Output: [1,2]
Example 2:

Input: A = [1,2], B = [2,3]
Output: [1,2]
Example 3:

Input: A = [2], B = [1,3]
Output: [2,3]
Example 4:

Input: A = [1,2,5], B = [2,4]
Output: [5,4]

WrittenBy : Himanshu Srivastava
Problem : Fair Candy Swap
TimeComplexity : O(n)

*/




class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        //
    // Note that the problem statement says that Alice and Bob need to exchange one candy each, no more or no less.
    //
    // Assume x needs to be removed and y needs to be added to A to equalize, so:
    //  Sum(A) - x + y = Sum(B) - y + x
    //  therefore, Sum(A) - Sum(B) = -2y + 2x
    //  therefore, x = ((Sum(A) - Sum(B)) / 2) + y
    //  lets call ((Sum(A) - Sum(B)) / 2), delta
    //
    
    int sumA = 0;
    int sumB = 0;
    
    for (auto e : A)
        sumA += e;
    
    for (auto e : B)
        sumB += e;
    
    int delta = (sumA - sumB) / 2;
    
    set<int> searchA;
    for (auto x : A)
    {
        //cout << x << endl;
        searchA.insert(x);
    }
    
    
    //cout << endl;
    for (auto y : B)    
    {
        //cout << y << setw(5) << delta + y << endl;
        if (searchA.count(delta + y) > 0)
        {
            return vector<int>{delta + y, y};
        }
    }
    
    return vector<int>();
        
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

    cout<<(sol.fairCandySwap(input));

    return 0;
}