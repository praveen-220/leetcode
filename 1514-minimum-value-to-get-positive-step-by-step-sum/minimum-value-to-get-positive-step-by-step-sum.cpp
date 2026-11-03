class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int st = 1;

        while(true) {
            int sum = st;
            bool valid = true;

            for(int i = 0; i < nums.size(); i++) {
                sum += nums[i];

                if(sum < 1) {
                    valid = false;
                    break;
                }
            }

            if(valid)
                return st;

            st++;
        }
    }
};