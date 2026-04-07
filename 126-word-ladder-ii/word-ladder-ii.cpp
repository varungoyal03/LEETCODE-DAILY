class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        vector<vector<string>> result;

        if (!wordSet.count(endWord)) return result;

        unordered_map<string, vector<string>> parent;

        queue<string> q;
        q.push(beginWord);

        unordered_set<string> visited;
        bool found = false;

        while (!q.empty() && !found) {
            int size = q.size();
            unordered_set<string> levelVisited;

            for (int i = 0; i < size; i++) {
                string word = q.front(); 
                q.pop();

                for (int j = 0; j < word.size(); j++) {
                    string temp = word;

                    for (char c = 'a'; c <= 'z'; c++) {
                        temp[j] = c;

                        if (temp == word) continue;

                        if (wordSet.count(temp)) {

                            if (!visited.count(temp)) {

                                if (!levelVisited.count(temp)) {
                                    q.push(temp);
                                    levelVisited.insert(temp);
                                }

                                parent[temp].push_back(word);

                                if (temp == endWord) found = true;
                            }
                        }
                    }
                }
            }

            for (auto &w : levelVisited) {
                visited.insert(w);
                wordSet.erase(w);
            }
        }

        if (!found) return result;

        vector<string> path = {endWord};
        dfs(endWord, beginWord, parent, path, result);

        return result;
    }

private:
    void dfs(string word, string beginWord,
             unordered_map<string, vector<string>>& parent,
             vector<string>& path,
             vector<vector<string>>& result) {

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            return;
        }

        for (auto &p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, parent, path, result);
            path.pop_back();
        }
    }
};