class Solution {
    
    // For every Index finding the maximum value
    unordered_map<int, int> maxForIndexMemo;
    // Storing jobDiffculty as an array
    vector<int> mjobDifficulty;
    // Storing the number of days
    int mdays;
    // Double dimensional haspmap
    vector<vector<int>> efficiencyMemo;
    
public:
    
    void findMaxForIndex(vector<int> jobDifficulty){
        
        for(int i = jobDifficulty.size() - 1, j = 0; i >= 0; i--, j++){
            int max = 0;
            for(auto k = 0; k <= j; k++){
                max = std::max(max, jobDifficulty[i+k]);
            }
            maxForIndexMemo[i] = max;
        }
     /*   
        for(auto i : maxForIndexMemo){
            cout<< i.first << "\t" << i.second << "\n";
        }
    */
    }
    
    int findMinimumDifficulty(int numRemainingDays, int currentIndex){
        int maxIndexToIterate = mjobDifficulty.size() - currentIndex - numRemainingDays;
        int maxJobInADay = 0;
        int minJobEfficiency = INT_MAX;
        
        //For convenience
        int n = numRemainingDays;
        int m = currentIndex;
        
        if(numRemainingDays <= 0){
            return maxForIndexMemo[currentIndex];
        }
        
        if(efficiencyMemo[n][m] == -1){
            for(int i = currentIndex; i < maxIndexToIterate + currentIndex; i++){
                maxJobInADay = std::max(maxJobInADay, mjobDifficulty[i]);
                minJobEfficiency = std::min(minJobEfficiency, (maxJobInADay + findMinimumDifficulty(numRemainingDays-1, i+1)));
            }
            //cout<<"day: " << n << " index: " << m << " efficiencMemo = " << minJobEfficiency << "\n";
            efficiencyMemo[n][m] = minJobEfficiency;
        }
        
        return efficiencyMemo[n][m];
    }
    
    
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        mjobDifficulty = jobDifficulty;
        mdays = d;
        
        if(jobDifficulty.size() < d)
            return -1;
        
        //efficiencyMemo = new int[jobDifficulty.size()][mdays];
        for(int i = 0; i < d; i++){
            vector<int> vec;
            for(int j = 0; j <= jobDifficulty.size(); j++)
                vec.push_back(-1);
            efficiencyMemo.push_back(vec);
        }
        
        findMaxForIndex(jobDifficulty);
        return findMinimumDifficulty(mdays-1, 0);
    }
};
