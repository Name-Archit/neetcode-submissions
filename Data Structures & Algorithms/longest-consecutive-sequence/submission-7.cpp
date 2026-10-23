class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return 1;


        unordered_set<int> numSet(nums.begin(), nums.end());
        int maxCount = 0;

        for(int num : numSet){
            if(!numSet.count(num - 1)){
                int currentNum = num;
                int count = 1;

                while(numSet.count(currentNum + 1)){
                    currentNum++;
                    count++;
                }
                maxCount = max(maxCount, count);
            }

        }


        return maxCount;
    }
};
