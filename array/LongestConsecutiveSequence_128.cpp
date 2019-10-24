
/*

Given an unsorted array of integers, find the length of the longest consecutive elements sequence.

Your algorithm should run in O(n) complexity.

Example:

Input: [100, 4, 200, 1, 3, 2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

WrittenBy : Himanshu Srivastava
Problem : Longest Consecutive Sequence
TimeComplexity : O(n)

*/












class Solution {
public:
    int longestConsecutive1(vector<int>& nums) {
        unordered_map<int, int> m;
        int r = 0;
        for (int i : nums) {
            if (m[i]) continue;
          r = max(r, m[i] = m[i + m[i + 1]] = m[i - m[i - 1]] = m[i + 1] + m[i - 1] + 1);
        }
         return r;
    }
    
     int longestConsecutive2(vector<int>& nums) {
        
         int result = 0;
         
         map<int,int> hash;
         
         for( int i : nums){
             
            if(hash.find(i) == hash.end()){
                
                int left = hash.find(i-1) != hash.end() ?hash[i-1]:0;
                int right = hash.find(i+1) != hash.end() ?hash[i+1]:0;
                
                int sum = left+right+1;
                
                hash[i] = sum;
                
                result = std::max(result,sum);

                cout<<i<<" "<<left<<" "<<right<<" "<<"-->>"<<i-left<<" *** "<<i+right<<" "<<sum<<endl;    
                // extend the length to the boundary(s)
                // of the sequence
                // will do nothing if n has no neighbors
                hash[i-left] = sum;
                hash[i+right] = sum;
    
                
            }else{
                continue;
            }  
             
         }
         
         for (auto const& pair: hash) {
             std::cout << "{" << pair.first << ": " << pair.second << "}\n";
        }
         
          return result;
         
         
     }
    
    int longestConsecutive(vector<int>& nums) {
        
        if( nums.size() == 0 )
            return 0;
        
        sort(nums.begin(), nums.end());
        int global = 1;
        int local = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1] + 1) {
                local++;
            } else if (nums[i] != nums[i - 1]) {
                local = 1;
            }
            global = max(global, local);
        }
        return global;
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

    cout<<(sol.longestConsecutive(input));

    return 0;
}