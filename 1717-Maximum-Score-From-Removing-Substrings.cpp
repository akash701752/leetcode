class Solution {
public:
    int maximumGain(string s, int x, int y) {
        ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        int cnt = 0;
        string s1 = x > y ? "ab" : "ba";
        string s2 = x > y ? "ba" : "ab";
        int high = max(x, y);
        int low = min(x, y);
        
        // Helper function to process a pattern
        auto processPattern = [&](const string& pattern, int points) {
            stack<char> st;
            int gain = 0;
            for (char c : s) {
                if (!st.empty() && st.top() == pattern[0] && c == pattern[1]) {
                    st.pop();
                    gain += points;
                } else {
                    st.push(c);
                }
            }
            // Rebuild the string without the processed pattern
            string remaining;
            while (!st.empty()) {
                remaining += st.top();
                st.pop();
            }
            reverse(remaining.begin(), remaining.end());
            s = remaining;  // Update the original string
            return gain;
        };

        // Process the higher point pattern first
        cnt += processPattern(s1, high);
        // Process the lower point pattern on the updated string
        cnt += processPattern(s2, low);

        return cnt;
    }
};
