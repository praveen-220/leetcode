class Solution {
public:
    double myPow(double base, long long pow) {
        double ans=1.0;
        if(pow<0){
            return ans/myPow(base,-pow);
           
        }
        if(pow==0)
        return 1.0;
        double half=myPow(base,pow/2);
        if(pow%2==0)
        return half*half;
        return base*half*half;

    }
};