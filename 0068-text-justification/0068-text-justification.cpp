class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int n = words.size();
        int i = 0;

        while (i < n) {
            int lineLen = words[i].size();
            int j = i + 1;

            while (j < n && lineLen + 1 + words[j].size() <= maxWidth) {
                lineLen += 1 + words[j].size();
                j++;
            }

            int numWords = j - i;
            int spaces = maxWidth - (lineLen - (numWords - 1)); 
            string line;

            if (j == n || numWords == 1) {
                line = words[i];
                for (int k = i + 1; k < j; k++) {
                    line += " " + words[k];
                }
                line += string(maxWidth - line.size(), ' ');
            } else {
                int spacePerSlot = spaces / (numWords - 1);
                int extra = spaces % (numWords - 1);

                line = words[i];
                for (int k = i + 1; k < j; k++) {
                    line += string(spacePerSlot + (extra-- > 0 ? 1 : 0), ' ');
                    line += words[k];
                }
            }

            result.push_back(line);
            i = j;
        }

        return result;
    }
};
