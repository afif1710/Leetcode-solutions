class Solution {
public:
    int s;
    priority_queue<int>pq;
    int leastInterval(vector<char>& tasks, int n) {
        s = tasks.size();
        vector<int>vc(26, 0);
        for(auto &ch: tasks){        //Mapping using vector
            vc[ch - 'A']++;
        }
        for(auto &v: vc){
            if(v>0){        //Pushing to PQ only the values which are > 0
                pq.push(v);
            }
        }
        int time  = 0;
        while(!pq.empty()){

            vector<int> tmp;    //restarts at each iteration
            for(int i = 1; i <= n+1; i++){  //n+1 bcoz, at once we'll take n+1 chars together before repeating
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    tmp.push_back(freq);    
                }
            }
            for(auto &f: tmp){
                if(f>0){       //Frequency still greater than 0
                    pq.push(f);
                }
            }

            if(pq.empty()){
                time += tmp.size();
            }else{
                time += n+1;
            }
        }
        return time;
    }
};