class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> mp;
        
        for (auto& s : strs) {
            string key = s;
            sort(key.begin(), key.end()); // сортируем буквы
            mp[key].push_back(s);
        }
        
        vector<vector<string>> result;
        for (auto& [key, group] : mp) {
            result.push_back(move(group));
        }
        return result;
    }
};
