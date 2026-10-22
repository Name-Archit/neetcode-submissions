class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> suffix, prefix;
        vector<int> arr;

        int n = nums.size();

        int mul = 1;

        for(int i=0; i<nums.size(); i++){
            mul *= nums[i];
            suffix.push_back(mul);
        }

        mul = 1;

        for(int i=n-1; i>=0; i--){
            mul *= nums[i];
            prefix.push_back(mul);
        }

        reverse(prefix.begin(), prefix.end());
        
        arr.push_back(prefix[1]);

        for(int i=2; i<n; i++){
            int a = prefix[i] * suffix[i-2];
            arr.push_back(a);
        }

        arr.push_back(suffix[n-2]);

        return arr;
    }
};
