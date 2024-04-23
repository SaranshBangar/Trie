// #include <iostream>
// #include <unordered_map>

// using namespace std;

// class TrieNode
// {
//     public:
//     unordered_map<char, TrieNode*>children;
//     bool isEnd;
//     TrieNode() : isEnd(false) {}
// };

// class Trie
// {
//     private:
//     TrieNode* root;

//     public:
//     Trie()
//     {
//         root = new TrieNode();
//     }

//     void insert(const string& word)
//     {
//         TrieNode* current = root;
//         for (char ch : word)
//         {
//             if (current->children.find(ch) == current->children.end())
//                 current->children[ch] = new TrieNode();
//             current = current->children[ch];
//         }
//         current->isEnd = true;
//     }

//     bool search(const string& word, int& iterations)
//     {
//         TrieNode* current = root;
//         for (char ch : word)
//         {
//             iterations++;
//             if (current->children.find(ch) == current->children.end())
//                 return false; 
//             current = current->children[ch];
//         }
//         return current->isEnd; 
//     }

// };

// int main()
// {
//     Trie techTrie;

//     techTrie.insert("Microsoft");
//     techTrie.insert("Apple");
//     techTrie.insert("Google");
//     techTrie.insert("Amazon");
//     techTrie.insert("Facebook");
//     techTrie.insert("NVIDIA");
//     techTrie.insert("Cisco");
//     techTrie.insert("Qualcomm");
//     techTrie.insert("Adobe");
//     techTrie.insert("Netflix");
//     techTrie.insert("Sony");
//     techTrie.insert("HP");
//     techTrie.insert("Dell");
//     techTrie.insert("VMware");
//     techTrie.insert("Alibaba");
//     techTrie.insert("Tencent");
//     techTrie.insert("Baidu");
//     techTrie.insert("Twitter");
//     techTrie.insert("Uber");
//     techTrie.insert("Airbnb");
//     techTrie.insert("LinkedIn");
//     techTrie.insert("Snap");
//     techTrie.insert("Square");
//     techTrie.insert("Slack");
//     techTrie.insert("Salesforce");

//     string userInput;
//     cout << "Enter a tech company name : ";
//     cin >> userInput;

//     int iterations = 0;
//     bool found = techTrie.search(userInput, iterations);

//     if (found)
//         cout << "Company found in the trie in " << iterations << " iterations";
//     else
//     {
//         cout << "Company not found in the trie" << endl;
//         cout << "Iterations done : " << userInput.length();
//     }

//     return 0;
// }


#include <iostream>
#include <unordered_map>

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

    void dfs(TrieNode* node, string prefix, vector<pair<string, int>>& suggestions)
    {
        if (node->frequency > 0)
            suggestions.push_back({prefix, node->frequency});

        for (const auto& child : node->children)
        {
            dfs(child.second, prefix + child.first, suggestions);
        }
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

    vector<pair<string, int>> autocomplete(const string& prefix)
    {
        TrieNode* current = root;
        for (char ch : prefix)
        {
            if (current->children.find(ch) == current->children.end())
                return {}; // Prefix not found
            current = current->children[ch];
        }

        vector<pair<string, int>> suggestions;
        dfs(current, prefix, suggestions);
        return suggestions;
    }
};

int main()
{
    Trie techTrie;

    techTrie.insert("Microsoft");
    techTrie.insert("Apple");
    techTrie.insert("Google");
    techTrie.insert("Amazon");
    techTrie.insert("Facebook");
    techTrie.insert("NVIDIA");
    techTrie.insert("Cisco");
    techTrie.insert("Qualcomm");
    techTrie.insert("Adobe");
    techTrie.insert("Netflix");
    techTrie.insert("Sony");
    techTrie.insert("HP");
    techTrie.insert("Dell");
    techTrie.insert("VMware");
    techTrie.insert("Alibaba");
    techTrie.insert("Tencent");
    techTrie.insert("Baidu");
    techTrie.insert("Twitter");
    techTrie.insert("Uber");
    techTrie.insert("Airbnb");
    techTrie.insert("LinkedIn");
    techTrie.insert("Snap");
    techTrie.insert("Square");
    techTrie.insert("Slack");
    techTrie.insert("Salesforce");

    string prefix;
    cout << "Enter a prefix to get autocomplete suggestions: ";
    cin >> prefix;

    vector<pair<string, int>> suggestions = techTrie.autocomplete(prefix);

    if (suggestions.empty())
        cout << "No suggestions found for the given prefix." << endl;
    else
    {
        cout << "Autocomplete suggestions for prefix '" << prefix << "':" << endl;
        for (const auto& suggestion : suggestions)
            cout << suggestion.first << " (frequency: " << suggestion.second << ")" << endl;
    }

    return 0;
}
