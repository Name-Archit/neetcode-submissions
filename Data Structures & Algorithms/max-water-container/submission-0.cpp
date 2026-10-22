class Solution {
public:
    int maxArea(vector<int>& height) {
       int left = 0;
       int right = height.size() - 1;

       int maxi = -1e9;

       while(left <= right){
        int gap = right - left;

        int lft = height[left];
        int rgt = height[right];
        
        int ans = min(lft, rgt) * gap;

        maxi = max(maxi, ans);

        if(lft <= rgt) left++;
        else right--;
       }

       return maxi;
    }
};