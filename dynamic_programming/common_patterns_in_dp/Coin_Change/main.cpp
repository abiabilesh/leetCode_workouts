class Solution {
    
    vector<int> mCoins;
    int mAmount;
    std::unordered_map<int, int> memo;

    int calculateMinCoins(int amount){
        
        int minCoins = INT_MAX;
        
        if(amount == 0){
            return 0;
        }
        
        if(amount < 0){
            return INT_MAX;
        }
        
        for(int i = mCoins.size()-1; i >= 0; i--){
            int remainingAmount = amount - mCoins[i];
        
            if((memo.find(remainingAmount) == memo.end())){     
                memo[remainingAmount] = calculateMinCoins(remainingAmount);    
            }
                
            if(memo[remainingAmount] != INT_MAX){
                minCoins = min(minCoins, 1 + memo[remainingAmount]);
            }
                
        }
    
        return minCoins;
        
    }
    
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0)
            return 0;
        
        mCoins  = coins;
        mAmount = amount;
        
        int minCoins = calculateMinCoins(mAmount);
        return ((minCoins != INT_MAX) && (minCoins != 0)) ? minCoins : -1;
    }
};
