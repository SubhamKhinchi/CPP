vector<int> twoSum(vector<int>& nums, int target) {
       unordered_map<int,int> umap;
      vector<int> ans;
        for(int j=0; j<nums.size(); j++){
            if(umap.find(target-nums[j])!=umap.end()){
                ans.push_back(umap[target-nums[j]]);
                ans.push_back(j);
                
                return ans;
            }
            umap.insert({nums[j],j});
        }
        return ans;
    }
