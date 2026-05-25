class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> umap; // hash map <key type,value type>
        std::vector<int> index_pair = {};
        int value = 0; //safe to pick since start search at 0 and we have an anti-duplicate index check

        // The last instance of a key is maintained
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]] = i;
        }

        cout << umap[20];

        for(int i = 0; i < nums.size(); i++){
            value = umap[target-nums[i]];
            if((target == (nums[value] + nums[i])) && (i != value)){
                index_pair = {i,value};
            }
        }
        return index_pair;

        // for (int i = 0; i < nums.size(); i++) {
        //     value = umap[target-nums[i]];
        //     if((target == (nums[value] + nums[i])) && (i != value)){
        //         index_pair = {i,value};
        //     }
        //     // placed at bottom so not stuck with repeat value index of duplicate
        //     umap[nums[i]] = i;
        // }
        // return index_pair;
    }
};
