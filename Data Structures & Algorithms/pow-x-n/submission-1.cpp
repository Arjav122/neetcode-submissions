class Solution {
public:
    double myPow(double x, int n) {
        double res = 1;

        if(n>=0){
            while(n--){
                res *= x;
            }
            return res;
        }

        if(n<0){
            int N = -(n);
            double X = 1/x;
            while(N--){
                res *= X;
            }
            return res;
        }
    }
};
