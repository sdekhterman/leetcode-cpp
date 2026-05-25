class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int,int> umap;
        // The last instance of a key is maintained
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]] = i;
        }

        vector<vector<int>> index_pairs;
        int target = 0;
        int k  = 0;
        int duplicate = 0;
        for (int i = 0; i < nums.size()-2; i++) {
            target = -nums[i];
            int j = i+1;
            // run time is poor due to the second for-loop. I need to look at soluations to figure out how other got around this.
            for (int j = (i+1); j < nums.size()-1; j++){
                k = umap[target-nums[j]];
                if((target == (nums[k] + nums[j])) && (j < k)){
                    if(index_pairs.empty()) {
                        index_pairs.insert(index_pairs.end(), {nums[i],nums[j],nums[k]});
                    }
                    else{
                        bool duplicate = false;
                        for(int l = 0; l < index_pairs.size(); l++){
                            duplicate = (((index_pairs[l][0] == nums[i]) && (index_pairs[l][1] == nums[j]) && (index_pairs[l][2] == nums[k])) ||
                                         ((index_pairs[l][0] == nums[i]) && (index_pairs[l][2] == nums[j]) && (index_pairs[l][1] == nums[k])) || 
                                         ((index_pairs[l][1] == nums[i]) && (index_pairs[l][0] == nums[j]) && (index_pairs[l][2] == nums[k])) ||
                                         ((index_pairs[l][1] == nums[i]) && (index_pairs[l][2] == nums[j]) && (index_pairs[l][0] == nums[k])) ||
                                         ((index_pairs[l][2] == nums[i]) && (index_pairs[l][0] == nums[j]) && (index_pairs[l][1] == nums[k])) ||
                                         ((index_pairs[l][2] == nums[i]) && (index_pairs[l][1] == nums[j]) && (index_pairs[l][0] == nums[k]))   );
                            if(duplicate){break;}
                        }
                        if(!duplicate) {index_pairs.insert(index_pairs.end(), {nums[i],nums[j],nums[k]});}
                    }
            
                }
            }
        }
        return index_pairs;
    }
};
