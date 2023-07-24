#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

void dfs(vector<int>& list, vector<bool>& flag, vector<int>& res, int n, int num, int x, vector<vector<int>>& count){
    if(res.size() == n){
        if(num == x){
            count.push_back(res);
        }
        return;
    }
    else{
        for(int i = 0; i < list.size(); i++){
            if(flag[i]) continue;
            flag[i] = true;
            res.push_back(list[i]);
            num += list[i];
            dfs(list, flag, res, n, num, x, count);
            flag[i] = false;
            num -= res.back();
            res.pop_back();
        }
    }
}

int findMaxEssentialPosts(int n, int m, int k, vector<pair<int, int>>& intervals){
    vector<string> posts(n + 1, "putong");
    for(auto& interval : intervals){
        int li = interval.first;
        int ri = interval.second;
        for(int i = li; i <= ri; i++){
            posts[i] = "jinghua";
        }
    }
    int maxEssential = 0;
    int currentEssential = 0;
    for(int i = 1; i <= n; i++){
        if(posts[i] == "jinghua"){
            currentEssential++;
        }
        if(i > k && posts[i - k] == "jinghua"){
            currentEssential--;
        }
        maxEssential = max(maxEssential, currentEssential);
    }
    return maxEssential;
}

long long findMaxSubarraySum(int n, long long x, vector<long long>& arr) {
    long long maxSum = arr[0];
    long long currentSum = arr[0];
    long long maxSubarraySum = arr[0];
    
    for (int i = 1; i < n; i++) {
        currentSum = max(arr[i], currentSum + arr[i]);
        maxSubarraySum = max(maxSubarraySum, currentSum);
        maxSum += max(arr[i], 0LL);
    }

    return max(maxSum, maxSubarraySum + x);
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        long long x;
        cin >> n >> x;

        vector<long long> arr(n);
        for (int j = 0; j < n; j++) {
            cin >> arr[j];
        }

        long long result = findMaxSubarraySum(n, x, arr);
        cout << result << endl;
    }

    return 0;
}
