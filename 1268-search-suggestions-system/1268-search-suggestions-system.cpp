class Node {
    public:
    Node*links[26];
    bool flag = false;
};
class Trie {
public:
    Node*root;
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node*curr = root;
        for(int i = 0 ; i < word.length() ; i++) {
            if(curr->links[word[i]-'a'] == NULL){
                curr->links[word[i]-'a'] = new Node();
            }
            curr = curr->links[word[i]-'a'];
        }
        curr->flag = true;
    }

    void dfs(Node* node, vector<string>& temp, string pre) {
        if(temp.size() == 3) return;
        if(node->flag) {
            temp.push_back(pre);
        }
        if(temp.size() == 3) return;
        for(char ch = 'a' ; ch <= 'z' ; ch++) {
            if(node->links[ch - 'a']) {
                dfs(node->links[ch - 'a'], temp, pre + ch);
            }
        }
        return;
    }
    
    void search(string prefix, vector<string>& temp) {
        Node*curr = root;
        for(int i = 0 ; i < prefix.length() ; i++) {
            if(curr->links[prefix[i]-'a'] == NULL){
                return;
            }
            curr = curr->links[prefix[i]-'a'];
        }
        // we have reached the node, which has links for the last char in prefix

        dfs(curr, temp, prefix); 
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string sw) {
        Trie* trie = new Trie();
        for(string p : products) {
            trie->insert(p);
        }

        vector<vector<string>> ans;
        string prefix = "";

        for(int i = 0 ; i < sw.size() ; i++) {
            vector<string> temp;
            prefix += sw[i];
            trie->search(prefix, temp);
            ans.push_back(temp);
        }   

        return ans;
    }
};