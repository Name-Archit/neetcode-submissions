class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxi = -1e9;
        int mini = 1e9;

        vector<int> suffix, prefix(n);

        for(int i=0; i<n; i++){
            mini = min(mini, prices[i]);
            suffix.push_back(mini);
        }

        for(int i=n-1; i>=0; i--){
            maxi = max(maxi, prices[i]);
            prefix[i] = maxi;
        }

        maxi = -1e9;

        for(int i=0; i<n; i++){
            int sum = abs(suffix[i] - prefix[i]);

            maxi = max(maxi, sum);
        }

        return maxi;
    }
};
