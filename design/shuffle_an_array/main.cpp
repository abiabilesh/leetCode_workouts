class Solution {
    vector<int> m_nums;
    
public:
    Solution(vector<int>& nums): m_nums(nums){}
    
    vector<int> reset() {
        return m_nums;
    }
    
    vector<int> shuffle() {
        int random; 
        unordered_map<int, int> hash_maps;
        vector<int> shuffled_vector;
        
        for(int i = 0; i < m_nums.size(); ){
            random = rand() % (m_nums.size());
            auto itr = hash_maps.find(random);
            if(itr == hash_maps.end()){
                hash_maps[random] = -1;
                shuffled_vector.push_back(m_nums[random]);
                i++;
            }
        }
        
        return shuffled_vector;
    }
};





/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();