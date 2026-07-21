class Solution {
private: 
    int square(int n){
        int ans = 0;
        while(n>0){
            int digit = n%10;
            ans += digit*digit;
            n /= 10;
        }
        return ans;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        while(true){
            int temp = square(n);
            if(temp == 1){
                return true;
            }
            if(st.count(temp)){
                return false;
            }
            st.insert(temp);
            n = temp;
        }
    }
};
