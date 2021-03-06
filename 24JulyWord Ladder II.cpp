class Solution {
public:
    vector<vector<string>> findLadders(string bw, string ew, vector<string>& wl) {
        vector<vector<string>> ans;
        wl.emplace_back(bw);
        vector<int> v(wl.size(), INT_MAX);
        v.back() = true;
        int n = wl.size();
        queue<vector<int>> q;
        q.push({n - 1});

        int ew_idx = 0;
        for (; ew_idx < n && wl[ew_idx] != ew; ew_idx++);
        
        for (; !q.empty() && ans.empty();) {
            for (int i = 0, e = q.size(); i < e; i++) {
                auto t = q.front();
                q.pop();
                auto &s = wl[t.back()];
                    
                for (int j = 0; j < n; j++) {
                    if (v[j] < t.size()) continue;
                    int c = 0;
                    for (int k = 0; c < 2 && k < bw.size(); k++) c += wl[j][k] != s[k];
                    if (c == 1) {
                        v[j] = t.size();
                        if (j == ew_idx) {
                            ans.emplace_back(t.size() + 1);
                            transform(t.begin(), t.end(), ans.back().begin(), [&] (int j) {return wl[j];});
                            ans.back().back() = ew;
                        } else {
                            q.emplace(t);
                            q.back().emplace_back(j);
                        }
                    }
                }
            }
        }
        return ans;
    }
};
