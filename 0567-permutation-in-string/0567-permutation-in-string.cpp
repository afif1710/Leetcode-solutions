class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size();
        int size2 = s2.size();
        
        vector<int>v1(26, 0);                
        vector<int>v2(26, 0);
        int left = 0, right = 0;
        if(size1>size2)return false;
        
        while(right<size1){
            v1[s1[right]-'a']++;
            v2[s2[right]-'a']++;
            right++;
        }
        right--;
        
        while(right<size2){
            if(v1 == v2)return true;
            right++;
            
            if(right!=size2){
                v2[s2[right] - 'a']++;   
                v2[s2[left] - 'a']--;
                left++;
            }
            
            
        }
        return false;
        
    }
};