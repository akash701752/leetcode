// class Trie{
//     Trie* next[26]  ;
//     bool isword ;
//     Trie() {
//         Trie* temp = this ;
//         for(int i=0;i<26;i++){
//            temp->next[i] = NULL ; 
//         }
//         temp->isword = false ;
//     }
//     Trie* head = this ;
//     void insert(string word) 
//     {
//         Trie* temp = head ;
//         int n = word.length() ;
//         for(int i=0;i<n;i++){
//             if(temp->next[word[i]-'a']==NULL){
//                 temp->next[word[i]-'a'] = new Trie() ;
//             }
//             temp = temp->next[word[i]-'a'] ;
//         }
//         temp->isword = true ;
//     }
    
//     bool search(string word) {
//         int n = word.length() ; 
//         Trie* temp = head ;
//         for(int i=0;i<n;i++){
//             if(temp->next[word[i]-'a']==NULL){
//                 return false ;
//             }
//             temp = temp->next[word[i]-'a'] ;
//         }
//         return temp->isword ; 
//     }
    
//     bool startsWith(string prefix) {
//         int n = prefix.length() ; 
//         Trie* temp = head ;
//         for(int i=0;i<n;i++){
//             if(!temp->next[prefix[i]-'a']){
//                 return false ;
//             }
//             temp = temp->next[prefix[i]-'a'] ;
//         }
//         return true ;
//     }
// }
// class WordDictionary {
// public:
//     WordDictionary() {
        
//     }
    
//     void addWord(string word) {
        
//     }
    
//     bool search(string word) {
        
//     }
// };

// /**
//  * Your WordDictionary object will be instantiated and called as such:
//  * WordDictionary* obj = new WordDictionary();
//  * obj->addWord(word);
//  * bool param_2 = obj->search(word);
//  */
class TrieNode {
public:
    bool word;
    TrieNode* children[26];
    TrieNode() {
        word = false;
        memset(children, NULL, sizeof(children));
    }
};

class WordDictionary {
public:
    WordDictionary() {    
    }
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node -> children[c - 'a']) {
                node -> children[c - 'a'] = new TrieNode();
            }
            node = node -> children[c - 'a'];
        }
        node -> word = true;
    }
    bool search(string word) {
        return search(word.c_str(), root);
    }
private:
    TrieNode* root = new TrieNode();
    bool search(const char* word, TrieNode* node) {
        for (int i = 0; word[i] && node; i++) {
            if (word[i] != '.') {
                node = node -> children[word[i] - 'a'];
            } else {
                TrieNode* tmp = node;
                for (int j = 0; j < 26; j++) {
                    node = tmp -> children[j];
                    if (search(word + i + 1, node)) {
                        return true;
                    }
                }
            }
        }
        return node && node -> word;
    }
};
