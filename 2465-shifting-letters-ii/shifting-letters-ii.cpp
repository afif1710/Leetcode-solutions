class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n, 0);

        //Filling out diff array first
        for(auto &shift: shifts){
            int l = shift[0];
            int r = shift[1];
            int d = shift[2];
            int x;
            if(d == 1){
                x = 1;      //If d == 1, we add +1 means right shift
            }else{
                x = -1;     //else , we add -1 mean left shift
            }
            diff[l] += x;      //Add x to the starting index element
            if(r + 1 <n)
                diff[r + 1] -= x;   //Subtract x to the immediate later element of the last ranged index
   
        }

        for(int i = 1; i <n; i++){
            diff[i] += diff[i-1];
        }

        for(int i = 0 ; i<n ; i++){
            int st = s[i] - 'a';       //value of the first char

            diff[i] = diff[i] % 26;
            if(diff[i] < 0){
                diff[i] += 26;
            }

            int value = (st + diff[i]) % 26;

            s[i] = value + 'a';


        }

        return s;


    }
};