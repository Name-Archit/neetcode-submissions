class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;

        sort(nums.begin(), nums.end());
        int count = 1;
        int maxi = -1e9;

        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] + 1 == nums[i+1]) count++;
            
            else if(nums[i] == nums[i+1]) continue;
            else{
                maxi = max(maxi, count);
                count = 1;
            }
        }

        maxi = max(maxi, count);

        return maxi;
    }
};
