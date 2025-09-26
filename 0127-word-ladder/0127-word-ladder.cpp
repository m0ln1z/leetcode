class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0; 

        queue<pair<string, int>> q;
        q.push({beginWord, 1}); 

        while (!q.empty()) {
            auto [word, steps] = q.front();
            q.pop();

            if (word == endWord) return steps;

            for (int i = 0; i < word.size(); i++) {
                string next = word;
                for (char c = 'a'; c <= 'z'; c++) {
                    if (c == word[i]) continue;
                    next[i] = c;
                    if (dict.count(next)) {
                        q.push({next, steps + 1});
                        dict.erase(next); 
                    }
                }
            }
        }
        return 0; 
    }
};
