class Solution {
private:
    int n;
    long long sum1, sum2;
    vector<pair<int, int>> arr;

    // finds max sum which can be made in t time with i as last index taken
    // using simple knapsack dp - take, not take

    long long dp[1001][1001];

    long long f(vector<int>& nums1 ,int t , int i) {
        // base case
        if(t == 0 or i < 0)  return 0;
        // memoization case
        if(dp[t][i] != -1)  return dp[t][i];
        // calling recursion
        long long notTake = f(nums1, t, i - 1);
        long long take = nums1[arr[i].second] + arr[i].first * 1ll * t
            + f(nums1, t - 1, i - 1);
        return dp[t][i] = max(take, notTake);
    }

public:
    int minimumTime(vector<int>& nums1 , vector<int>& nums2 , int x) {

        n = nums1.size();
        sum1 = 0;
        sum2 = 0;
        arr = vector<pair<int, int>>();

        for(int i = 0 ; i < n ; i++) {
            arr.push_back({nums2[i] , i});
            sum1 += nums1[i];
            sum2 += nums2[i];
        }

        sort(arr.begin() , arr.end());
        memset(dp, -1, sizeof(dp));

        for(int t = 0; t <= n; t++) {
            long long sum = sum1 + t * sum2;
            if(sum - f(nums1, t, n - 1) <= x)    return t;
        }
        return -1;
    }
};
