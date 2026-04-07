
class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
       set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord))
            return 0;

        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        wordSet.erase(beginWord);

        while (!q.empty()) {
            auto [word, level] = q.front();
            q.pop();

            for (int i = 0; i < word.size(); ++i) {
                string temp = word;
                for (char c = 'a'; c <= 'z'; ++c) {
                    temp[i] = c;
                    if (temp == endWord)
                        return level + 1;
                    if (wordSet.count(temp)) {
                        q.push({temp, level + 1});
                        wordSet.erase(temp); // avoid revisiting
                    }
                }
            }
        }

        return 0; // no path found
    }
};
