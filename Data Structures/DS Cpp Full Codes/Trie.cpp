#include <map>
#include <string>
#include <iostream>

using namespace std;

class TrieNode{
    public:
        map<char, TrieNode*> children;
        bool IsEndOfWord;

        TrieNode() : IsEndOfWord(false) {}
        ~TrieNode(){
            for(auto& pair : children){
                delete pair.second;
            }
        }
};

class Trie{
    private:
        TrieNode* root;
    
    public:
        Trie();
        ~Trie();

        void insert(const string& word);
        bool search(const string& word) const;
        bool startsWith(const string& prefix) const;
        void remove(const std::string &word);
        bool removeHelper(TrieNode *node, const std::string &word, int depth);

    private:
        void clear(TrieNode* node);
};

Trie::Trie(){
    root = new TrieNode();
}

Trie::~Trie(){
    clear(root);
}

void Trie::clear(TrieNode* node){
    if(!node) return;
    for(auto& pair : node->children){
        clear(pair.second);
    }
    delete node;
}

void Trie::insert(const string& word){
    TrieNode* current = root;
    for(char ch : word){
        if(!current->children.count(ch)){
            current->children[ch] = new TrieNode();
        }
        current = current->children[ch];
    }
    current->IsEndOfWord = true;
}

bool Trie::search(const string &word) const{
    TrieNode* current = root;

    for(char ch : word){
        if(!current->children.count(ch)){
            return false;
        }
        current = current->children[ch];
    }
    return current->IsEndOfWord;
}

bool Trie::startsWith(const string &prefix) const{
    TrieNode* current = root;

    for(char ch : prefix){
        if(!current->children.count(ch)){
            return false;
        }
        current = current->children[ch];
    }
    return true;
}

void Trie::remove(const std::string& word){
    removeHelper(root, word, 0);
}

bool Trie::removeHelper(TrieNode* node, const std::string& word, int depth) {
    if(!node) return false;

    if(depth == word.length()){
        if(!node->IsEndOfWord)
            return false;

        node->IsEndOfWord = false;

        return node->children.empty();
    }

    char ch = word[depth];
    TrieNode* child = node->children[ch];

    if(!child) return false;

    bool shouldDeleteChild = removeHelper(child, word, depth + 1);

    if(shouldDeleteChild) {
        delete child;
        node->children.erase(ch);
        return !node->IsEndOfWord && node->children.empty();
    }

    return false;
}

int main() {
    Trie trie;

    trie.insert("car");
    trie.insert("cartoon");

    cout<<boolalpha;
    cout<<"Search card "<<trie.search("card")<<"\n";
    cout<<"Search car "<<trie.search("car")<<"\n";
    cout<<"Search ca "<<trie.search("ap")<<"\n";


    cout<<"Starts with carto "<<trie.startsWith("carto")<<"\n";
    cout<<"Starts with arto "<<trie.startsWith("arto")<<"\n";

    trie.remove("car");

    cout<<"Search car "<<trie.search("car")<<"\n";
    cout<<"Search cartoon "<<trie.search("cartoon")<<"\n";
}