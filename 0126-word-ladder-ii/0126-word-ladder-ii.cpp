class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return {}; 
        
        unordered_map<string, vector<string>> parents; 
        unordered_set<string> currentLevel, nextLevel;
        currentLevel.insert(beginWord);
        bool found = false;

        while (!currentLevel.empty() && !found) {
            for (auto& w : currentLevel) dict.erase(w); 
            nextLevel.clear();

            for (auto& word : currentLevel) {
                string w = word;
                for (int i = 0; i < w.size(); i++) {
                    char orig = w[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        w[i] = c;
                        if (dict.count(w)) {
                            nextLevel.insert(w);
                            parents[w].push_back(word);
                            if (w == endWord) found = true;
                        }
                    }
                    w[i] = orig;
                }
            }
            currentLevel.swap(nextLevel);
        }

        vector<vector<string>> result;
        if (found) {
            vector<string> path{endWord};
            backtrack(endWord, beginWord, parents, path, result);
        }
        return result;
    }

private:
    void backtrack(const string& word, const string& beginWord,
                   unordered_map<string, vector<string>>& parents,
                   vector<string>& path, vector<vector<string>>& result) {
        if (word == beginWord) {
            vector<string> tmp = path;
            reverse(tmp.begin(), tmp.end());
            result.push_back(tmp);
            return;
        }
        for (auto& p : parents[word]) {
            path.push_back(p);
            backtrack(p, beginWord, parents, path, result);
            path.pop_back();
        }
    }
};
