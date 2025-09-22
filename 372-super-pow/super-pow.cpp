class Solution {
public:
    
    int solve(long int a, int pow){ //int a won't work here bcoz a*a. Even though we r using % 1337, the  multiplication a*a happens earlier than % which evaluates to a number bigger than int can hold
        long int ans = 1;
        while(pow > 0){
            if(pow%2 == 1){
                ans = (ans * a) % 1337;    //Mod na korle signed integer overflow hobe as 'a' is a huge value
                pow = pow - 1;
            }else{
                a = (a*a) % 1337;          //Same as above   
                pow = pow/2;
            }
        }
        return ans % 1337; //Mod Na korleo hobe but kore fela better
    }

    int superPow(int a, vector<int>& b) { //int a works here bcoz we ain't doing a*a here and int can store inputs up to 2³¹−1
        int Mod = 1337;
        //double ETFofMod = 1337 * (6/7) * (190/191) == 1140;    //EtfOfX = X * (1 - 1/a) * (1 - 1/b) .... where a,b...are        
                                                    //Unique prime factors of x.
        
        int res = 0; //long na nileo hobe as etar value always 1140 er cheye kom hobe

        for(int i = 0; i<b.size(); i++){
            res = (res * 10 + b[i]) % 1140;  //Mod na korle signed integer overflow hobe as a is 'b' huge value
        }
        if(res == 0){
            res = 1140;     //only case when b = [1,1,4,0], res will become 0, hence change its value to 1140;
        }
 
        return solve(a, res);
    }
};