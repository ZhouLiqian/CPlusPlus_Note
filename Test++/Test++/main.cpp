#include <iostream>
#include <sstream>
#include <unordered_map>
using namespace std;

vector<int> findMaximumCongruentPair(vector<int>& nums, int n) {
    unordered_map<int, int> m;
    sort(nums.begin(), nums.end());
    for (int i = int(nums.size()) - 1; i >= 0; i--) {
        int value = nums[i] - (nums[i] / n) * n;
        if(m.count(value)) return {nums[i], m[value]};
        m[value] = nums[i];
    }
    return {};
}

int main() {
    
    string input;

    // 读取整数列
    getline(cin, input);
    vector<int> nums;
    istringstream iss(input);
    int num;
    while (iss >> num) {
        nums.push_back(num);
    }

    // 读取整数n
    cin.clear();
    int n;
    cin >> n;

    vector<int> v = findMaximumCongruentPair(nums, n);
    cout << v[0] << " " << v[1] << endl;
    return 0;
}
