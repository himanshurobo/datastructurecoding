/*

Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.

Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2.  
Elements that don't appear in arr2 should be placed at the end of arr1 in ascending order.

 

Example 1:

Input: arr1 = [2,3,1,3,2,4,6,7,9,2,19], arr2 = [2,1,4,3,9,6]
Output: [2,2,2,1,4,3,3,9,6,7,19]
 

Constraints:

arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
Each arr2[i] is distinct.
Each arr2[i] is in arr1.


WrittenBy : Himanshu Srivastava
Problem : Relative Sort Array
TimeComplexity : O(n)

*/



class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        
        
        map<int,int> hash;
        
        for( int i = 0 ; i < arr1.size();i++){            
            hash[arr1[i]]++;
        }
        
        
        vector<int> res;
        
        for( int i = 0 ; i < arr2.size();i++){
            
            while(hash[arr2[i]] > 0 ){
                res.push_back(arr2[i]);
               hash[arr2[i]]--;
            }           
            hash.erase(arr2[i]);
        }
        
         map<int, int>::iterator it ;
        for (it = hash.begin(); it!=hash.end(); ++it){
            while(it->second>0){
                res.push_back(it->first);
                it->second--;
            }
            
            hash.erase(it->first);
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

    cout<<(sol.relativeSortArray(input));

    return 0;
}