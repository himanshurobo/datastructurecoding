/*

Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]


WrittenBy : Himanshu Srivastava
Problem : Subsets
TimeComplexity : O(n+m)

*/





class Solution {

    void subsets(vector<int>& nums, int index ,vector<int>& path, vector<vector<int>>& res){
        res.push_back(path);

        for( int i = index; i < nums.size(); i++){
            path.push_back(nums[i]);

            subsets(nums, i+1, path, res);

            path.pop_back();
        }

    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int>path;

        subsets(nums, 0, path, res);

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

    vector<int> input{2, 7, 11, 15};

    displayInt(sol.subsets(input));

    return 0;
}
