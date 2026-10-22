class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        int n = heights.size();
        int maxi = heights[n-1];

        vector<int> arr(n), vec;
        set<int> st;
        arr[n-1] = n-1;

        for(int i=n-2; i>=0; i--){
            if(maxi < heights[i]){
                maxi = heights[i];
                arr[i] = i;
            }
            else arr[i] = arr[i + 1];
        }

        for(int i = 0; i<n; i++) st.insert(arr[i]);

        for(auto a: st){            

            vec.push_back(a);
        }

        return vec;
    }
};