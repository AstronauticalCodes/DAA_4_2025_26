#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Node {
public:
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

void generateCodes(Node* root, string str, unordered_map<char, string>& codes) {
    if (!root) return;

    if (!root->left && !root->right) {
        codes[root->ch] = (str == "") ? "0" : str;
    }

    generateCodes(root->left, str + "0", codes);
    generateCodes(root->right, str + "1", codes);
}

Node* buildTree(string text) {
    unordered_map<char, int> freq;
    for (char c : text) freq[c]++;

    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();

        Node* sum = new Node('\0', left->freq + right->freq);
        sum->left = left;
        sum->right = right;
        pq.push(sum);
    }
    return pq.top();
}

string encode(string text, unordered_map<char, string>& codes) {
    string res = "";
    for (char c : text) res += codes[c];
    return res;
}

string decode(Node* root, string encodedStr) {
    string res = "";
    Node* curr = root;
    for (char bit : encodedStr) {
        if (bit == '0') curr = curr->left;
        else curr = curr->right;

        if (!curr->left && !curr->right) {
            res += curr->ch;
            curr = root;
        }
    }
    return res;
}

int main() {
    string text = "I am Aryan";
    
    cout << "Original text: " << text << endl;
    
    Node* root = buildTree(text);
    unordered_map<char, string> codes;
    generateCodes(root, "", codes);
    
    cout << "\nHuffman Codes:" << endl;
    for (auto pair : codes) {
        cout << pair.first << ": " << pair.second << endl;
    }
    
    string encoded = encode(text, codes);
    cout << "\nEncoded: " << encoded << endl;
    
    string decoded = decode(root, encoded);
    cout << "Decoded: " << decoded << endl;
    
    return 0;
}