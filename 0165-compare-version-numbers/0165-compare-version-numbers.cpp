class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        string token;
        stringstream ss1(version1), ss2(version2);

        while(getline(ss1, token, '.')) {
            v1.push_back(stoi(token));
        }
        while(getline(ss2, token, '.')) {
            v2.push_back(stoi(token));
        }

        for(int i = 0; i < max(v1.size(), v2.size()); i++) {
            int v1_part = (i < v1.size()) ? v1[i] : 0;
            int v2_part = (i < v2.size()) ? v2[i] : 0;

            if(v1_part < v2_part) {
                return -1;
            } else if(v2_part < v1_part) {
                return 1;
            }
        }
        return 0;
    }
};