class Solution {
private:
    vector<int> mNums;
    vector<vector<int>> mOutput;
    
    void calcRecur(vector<int> recurVect, int index){
        
        if(recurVect.size() == mNums.size()){
            return;
        }
        
        for(int i = index; i < mNums.size(); i++){
            if(!std::count(recurVect.begin(), recurVect.end(), mNums[i])){
                recurVect.push_back(mNums[i]);
                if(!std::count(mOutput.begin(), mOutput.end(), recurVect))
                    mOutput.push_back(recurVect);
                calcRecur(recurVect, i+1);
            }
            recurVect.pop_back();
        }
        
        return;
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        std::vector<int> mtemp;
        mOutput.push_back(std::vector<int>());
        mNums = nums;
        calcRecur(mtemp, 0);
        return mOutput;
    }
};
