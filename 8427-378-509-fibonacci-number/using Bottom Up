class Solution {
public:
    int fib(int n) { //0 1 1 2 3 5 8
        if(n == 0){
            return 0;
        }
        int a = 0;
        int b = 1;
        int c = a+b;
        for(int i = 1; i<n; i++){
            c = a+b;
            a = b;
            b = c;
        }
        return c;
    }
};
