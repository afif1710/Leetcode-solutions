class TimeMap {
public:
    TimeMap() {
        
    }
    unordered_map<string, vector<pair<string, int>>> mp;
    void set(string key, string value, int timestamp) {
        mp[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        auto& values = mp[key];
        int l = 0, r = values.size()-1;
        string res = "";
        
        while(l<=r){
            int mid = (l+r)/2;
            if(values[mid].second <= timestamp){
                res = values[mid].first;
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return res;
        
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */