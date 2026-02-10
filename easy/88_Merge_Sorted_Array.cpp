class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if(n!= 0) {
            if (m == 0) {
                nums1 = nums2;
            } else {
                int i = 0, j = 0;
                while((i+j) < (n+m)) {
                    if((j < n) && ((nums2[j] < nums1[i+j]) || (i > (m-1)))) {
                        nums1.insert(nums1.begin()+i+j, nums2[j]);
                        j++;
                    } else {
                        i++;
                    }
                }
                nums1.resize(n+m);
            }
        }
    }
};
