#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class TrieNode
{
public:
    unordered_map<char, TrieNode*> children;
    int frequency;
    TrieNode() : frequency(0) {}
};

class Trie
{
    private:
    TrieNode* root;

    void dfs(TrieNode* node, string prefix, vector<string>& suggestions)
    {
        if (node->frequency > 0)
            suggestions.push_back(prefix);

        for (const auto& child : node->children)
            dfs(child.second, prefix + child.first, suggestions);
    }

    public:
    Trie()
    {
        root = new TrieNode();
    }

    void insert(const string& word)
    {
        TrieNode* current = root;
        for (char ch : word)
        {
            if (current->children.find(ch) == current->children.end())
                current->children[ch] = new TrieNode();
            current = current->children[ch];
        }
        current->frequency++;
    }

    vector<string> autocomplete(const string& prefix)
    {
        TrieNode* current = root;
        for (char ch : prefix)
        {
            if (current->children.find(ch) == current->children.end())
                return {};
            current = current->children[ch];
        }

        vector<string> suggestions;
        dfs(current, prefix, suggestions);
        return suggestions;
    }
};

int main()
{
    Trie techTrie;

    techTrie.insert("Airbnb");
    techTrie.insert("Alibaba");
    techTrie.insert("Amazon");
    techTrie.insert("Apple");
    techTrie.insert("Adobe");
    techTrie.insert("Baidu");
    techTrie.insert("Cisco");
    techTrie.insert("Dell");
    techTrie.insert("Facebook");
    techTrie.insert("Google");
    techTrie.insert("HP");
    techTrie.insert("LinkedIn");
    techTrie.insert("Microsoft");
    techTrie.insert("Netflix");
    techTrie.insert("NVIDIA");
    techTrie.insert("Qualcomm");
    techTrie.insert("Salesforce");
    techTrie.insert("Snap");
    techTrie.insert("Slack");
    techTrie.insert("Sony");
    techTrie.insert("Square");
    techTrie.insert("Tencent");
    techTrie.insert("Twitter");
    techTrie.insert("Uber");
    techTrie.insert("VMware");

    string prefix;
    cout << "Enter a prefix to get suggestions : ";
    cin >> prefix;

    vector<string> suggestions = techTrie.autocomplete(prefix);

    if (suggestions.empty())
        cout << "No suggestions found for the input!" << endl;
    else
    {
        cout << "Autocomplete suggestions for prefix '" << prefix << "':" << endl;
        for (const auto& suggestion : suggestions)
            cout << suggestion << endl;
    }

    return 0;
}
