class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i = 0; i < n; i++){
            bool isSet = false;
            for(int j = 0; j < m; j++){
                if(nums2[i] < nums1[j]){
                    nums1.pop_back();
                    nums1.insert(nums1.begin()+j, nums2[i]);
                    m++;
                    isSet = true;
                    break;
                }
            }
            if(!isSet){
                nums1.insert(nums1.begin()+m, nums2[i]);
                m++;
                nums1.pop_back();
            }
        }
        
    }
};