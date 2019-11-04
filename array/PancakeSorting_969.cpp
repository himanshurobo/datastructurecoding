/*

Given an array A, we can perform a pancake flip: We choose some positive integer k <= A.length, 
then reverse the order of the first k elements of A.  We want to perform zero or more pancake flips 
(doing them one after another in succession) to sort the array A.

Return the k-values corresponding to a sequence of pancake flips that sort A.  Any valid answer
 that sorts the array within 10 * A.length flips will be judged as correct.

 

Example 1:

Input: [3,2,4,1]
Output: [4,2,4,3]
Explanation: 
We perform 4 pancake flips, with k values 4, 2, 4, and 3.
Starting state: A = [3, 2, 4, 1]
After 1st flip (k=4): A = [1, 4, 2, 3]
After 2nd flip (k=2): A = [4, 1, 2, 3]
After 3rd flip (k=4): A = [3, 2, 1, 4]
After 4th flip (k=3): A = [1, 2, 3, 4], which is sorted. 
Example 2:

Input: [1,2,3]
Output: []
Explanation: The input is already sorted, so there is no need to flip anything.
Note that other answers, such as [3, 3], would also be accepted.




WrittenBy : Himanshu Srivastava
Problem : Pancake Sorting
TimeComplexity : O(n)

*/


class Solution {
    
private:
    int findMax(vector<int>& A, int n){
        int maxElementIndex = std::max_element(A.begin(), A.begin() + n) - A.begin();
        return maxElementIndex + 1;
    }
public:
    vector<int> pancakeSort(vector<int>& A) {
        
        int size = A.size();
        vector<int> B;
        for( int i=0; i<size-1; i++){
            int k = findMax(A, size-i); 
            
            reverse(A.begin(), A.begin() + k);
            B.push_back(k);
            
            reverse(A.begin(), A.begin() + size-i);
            B.push_back(size - i);

        }
        
        return B;
        
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

    cout<<(sol.pancakeSort(input));

    return 0;
}