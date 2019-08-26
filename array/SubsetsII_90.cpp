/*

Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: [1,2,2]
Output:
[
  [2],
  [1],
  [1,2,2],
  [2,2],
  [1,2],
  []
]


WrittenBy : Himanshu Srivastava
Problem : Subsets II
TimeComplexity : O(n+m)

*/


class Solution {

    void subsetsWithDup(vector<int>& nums, int index, vector<int>& path, vector<vector<int>>& res){

        res.push_back(path);

        for( int i = index ; i < nums.size();i++){

            if( i > index && nums[i] == nums[i-1])
                continue;

            path.push_back(nums[i]);
            subsetsWithDup( nums, i+1, path, res);
            path.pop_back();
        }
    }


public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        vector<vector<int>> res;
        vector<int> path;
        sort(nums.begin(), nums.end());
        subsetsWithDup(nums, 0, path,res);

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

    vector<int> input{2, 2,7, 11, 15};

    displayInt(sol.subsetsWithDup(input));

    return 0;
}
