class Solution {
public:
    
    vector<vector<int>> res;
    int n;
    unordered_map<int, int> mp;
    
    
    void solve(unordered_map<int, int> &mp, vector<int>& temp){
        
        if(temp.size() == n){
            res.push_back(temp);
            return;
        }
        
        for(auto& [number, count] : mp){
            if(count == 0){
                continue;
            }
            temp.push_back(number);
            mp[number]--;
            solve(mp, temp);
            temp.pop_back();
            mp[number]++;
            
            
        }        
    }
    
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n = nums.size();
        vector <int> temp;

        for(int num: nums){
            mp[num]++;
        }
        solve(mp, temp);
        
        return res;
        
    }
};