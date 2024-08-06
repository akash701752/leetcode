class Solution {
public:
    int minimumPushes(string word) {
       
        const unsigned int letter_count = 26;
        
        int letter_counter[letter_count]{};

        for(char c : word) letter_counter[(int)c - (int)'a']++;
        sort(letter_counter, letter_counter + letter_count, std::greater<>());
        int pushes = 0;
        for(int i = 0; i < letter_count; i++)
        {
            pushes += letter_counter[i] * ((int)(i / 8) + 1);
        }

        return pushes;
    }
};
