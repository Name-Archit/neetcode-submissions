class Solution {
public:
    long long check(vector<int>& piles, int term){
        long long count = 0;

        for(auto it: piles){            
            if(it % term != 0){
                count += it/term;
                count++;
            }
            else count += it/term;
        }

        return count;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long n = piles.size();                

        long long left = 1;
        long long right = *max_element(piles.begin(), piles.end());

        long long mini = 1e9+7;

        while(left <= right){
            long long mid = left + (right - left)/2;

            if(check(piles, mid) <= h){
                mini = min(mini, mid);
                right = mid - 1;                
            }
            else left = mid + 1;
        }

        return mini;
    }
};
