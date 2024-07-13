class Solution {
public:
    string reverseWords(string s) {
        stringstream st(s);
        string word;
        vector<string> result;

        while(st >> word) {
            result.emplace_back(word);
        }

        int n = result.size();

        for(int i = 0; i < n / 2; ++i) {
            swap(result[i], result[n - 1 - i]);
        }

        string results = "";

        for(int i = 0; i < result.size(); ++i) {
            results += result[i] + " ";
        }

        results.pop_back();
        return results;
    }
};