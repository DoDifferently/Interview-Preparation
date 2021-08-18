#include <bits/stdc++.h>
using namespace std;

#define M 3
#define N 4

int dx[] = {0, 1 , 1 ,1, 0, -1, -1,-1};
int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1};

struct trie_node
{
    bool isEndOfWord;
    string word; // store the word at leaf node
    map<char, trie_node*> children;
    trie_node(): isEndOfWord(false), word("") {}
};

class Trie
{
    trie_node *root;
    public:
        Trie(): root(new trie_node) {}
        ~Trie()
        {
            delete root;
            root = nullptr;
        }
        void insert(string word)
        {
            trie_node* tmp = root;
            for(auto ch: word)
            {
                if(tmp->children.count(ch) == 0)
                    tmp->children[ch] = new trie_node();
                tmp = tmp->children[ch];
            }
            tmp->isEndOfWord = true;
            tmp->word = word;
        }
        trie_node* getRootNode()
        {
            return root;
        }
};

bool isInBounds(int x, int y)
{
    return x >= 0 and x < M and y >= 0 and y < N;
}

void dfs(char board[M][N], trie_node* node, int x, int y, bool visited[M][N], unordered_set<string>& output)
{
    char ch = board[x][y];
    if(node->children.count(ch) == 0)
        return;
    visited[x][y] = true;
    node = node->children[ch];

    // this word can be prefix of another word so don't return(keep searching)
    if(node->isEndOfWord)
        output.insert(node->word);
    
    for(int dir = 0; dir < 8; dir++)
    {
        int newX = x + dx[dir];
        int newY = y + dy[dir];
        if(isInBounds(newX, newY) and !visited[newX][newY])
            dfs(board, node, newX, newY, visited, output);
    }
    // backtrack to consider this character for some other word
    visited[x][y] = false;
}

void searchAll(trie_node* root, char board[M][N], unordered_set<string>& output)
{
    // 8-way DFS search from every cell
    bool visited[M][N] {false};
    for(int i = 0; i < M; ++i)
        for(int j = 0; j < N; ++j)
            dfs(board, root, i, j, visited, output);
}

void insertAllWordsIntoTrie(Trie& trie, vector<string> dictionary)
{
    for(auto word: dictionary)
        trie.insert(word);
}

void solve(vector<string> words, char board[M][N])
{
    Trie trie;
    insertAllWordsIntoTrie(trie, words);
    /**
     * Take a container to store words that are found in DFS search
     * There are muliple ways to create a same word but we need only
     * one instance
     */
    unordered_set<string> output;
    searchAll(trie.getRootNode(), board, output);
    for(auto word: output)
        cout << word << "\t";
}

int main()
{
    vector<string> words = {"SNAKE", "FOR", "QUEZ", "SNACK", "SNACKS", "GO", "TUNES", "CAT"};    
    char board[M][N] = { {'S', 'E', 'R' ,'T'}, {'U', 'N', 'K' ,'S'}, {'T', 'C', 'A' ,'T'} };
    solve(words, board);
    // vector<string> words {"GEEKS", "FOR", "QUIZ", "GO"};
    // char board[M][N] = {{'G', 'I', 'Z'}, {'U', 'E', 'K'}, {'Q', 'S', 'E'}};
    // solve(words, board);
    return 0;
}