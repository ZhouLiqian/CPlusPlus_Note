//
//  main.cpp
//  Test++
//
//  Created by Qian on 7/20/23.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace::std;

int findMinNumber(const string& str, int length){
    vector<int> nums;
    string currentNum;
    
    for(char ch : str){
        if(isdigit(ch)){
            currentNum += ch;
        }
        else if(!currentNum.empty()){
            nums.push_back(stoi(currentNum));
            currentNum.clear();
        }
    }
    
    if(!currentNum.empty()){
        nums.push_back(stoi(currentNum));
    }
    
    sort(nums.begin(), nums.end());
    
    int minNumber = nums[0];
    for(int i = 1; i < length; i++){
        if(nums[i] != minNumber + i){
            minNumber = minNumber + 1;
            break;
        }
    }
    return minNumber;
}

int countQuacks(const string& str){
    int count = 0;
    int qCount = 0;
    int uCount = 0;
    int aCount = 0;
    int cCount = 0;
    int kCount = 0;
    
    for(char ch : str){
        if(ch == 'q'){
            qCount++;
        }
        else if(ch == 'u' && qCount > 0){
            uCount++;
            qCount--;
        }
        else if (ch == 'a' && uCount > 0){
            aCount++;
            uCount--;
        }
        else if(ch == 'c' && aCount > 0){
            cCount++;
            aCount--;
        }
        else if(ch == 'k' && cCount > 0){
            kCount++;
            cCount--;
        }
    }
    if(qCount == 0 && uCount == 0 && aCount == 0 && cCount == 0 && kCount == 0){
        count = kCount;
    }
    else{
        count = -1;
    }
    return count;
}

void removeDependentServices(unordered_map<string, unordered_set<string>>& childServices, const string& service){
    if(childServices.count(service)){
        unordered_set<string> dependentServices = childServices[service];
        childServices.erase(service);
        for(const string& dependentService : dependentServices){
            removeDependentServices(childServices, dependentService);
        }
    }
}

int main() {
    // insert code here...
    string relationsStr, breakdownStr;
    getline(cin, relationsStr);
    getline(cin, breakdownStr);
    
    stringstream ss(relationsStr);
    string s;
    vector<vector<string>> relations;
    while (getline(ss, s, ',')) {
        stringstream ss2(s);
        string child, father;
        getline(ss2, child, '-');
        getline(ss2, father, '-');
        relations.push_back({child, father});
    }
    
    stringstream ss3(breakdownStr);
    vector<string> breakdowns;
    while (getline(ss3, s, ',')) {
        breakdowns.push_back(s);
    }
    unordered_map<string, unordered_set<string>> childServices;
    unordered_map<string, int> firstAppear;
    int i = 0;
    for(const auto& relation : relations){
        const string& child = relation[0];
        const string& father = relation[1];
        childServices[child];
        childServices[father].insert(child);
        firstAppear[child] = i++;
        firstAppear[father] = i++;
    }
    for(const string& breakdown : breakdowns){
        removeDependentServices(childServices, breakdown);
    }
    vector<string> ans;
    ans.reserve(childServices.size());
    for(const auto& p: childServices){
        ans.push_back(p.first);
    }
    if(ans.empty()){
        cout << "," << endl;
        return 0;
    }
    sort(ans.begin(), ans.end(), [&](const string& a, const string& b){
        return firstAppear[a] < firstAppear[b];
    });
    stringstream res;
    for(int i = 0; i < ans.size(); i++){
        res << ans[i];
        if(1 != ans.size() - 1){
            res << ",";
        }
    }
    cout << res.str() << endl;
    return 0;
}
