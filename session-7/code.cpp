#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

struct HuffmanNode {
    int frequency;
    HuffmanNode *left;
    HuffmanNode *right;

    HuffmanNode(int freq) : frequency(freq), left(nullptr), right(nullptr) {}
};

struct MinHeapComparator {
    bool operator()(HuffmanNode* a, HuffmanNode* b) {
        return a->frequency > b->frequency;
    }
};

class Solution {
private:
    void generateCodes(HuffmanNode* root, string currentCode, vector<string>& resultCodes) {
        if (!root) return;

        if (!root->left && !root->right) {
            resultCodes.push_back(currentCode);
            return;
        }

        generateCodes(root->left, currentCode + "0", resultCodes);
        generateCodes(root->right, currentCode + "1", resultCodes);
    }

public:
    vector<string> huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<HuffmanNode*, vector<HuffmanNode*>, MinHeapComparator> minHeap;
        for (int i = 0; i < N; i++) {
            minHeap.push(new HuffmanNode(f[i]));
        }

        while (minHeap.size() > 1) {
            HuffmanNode* leftNode = minHeap.top();
            minHeap.pop();

            HuffmanNode* rightNode = minHeap.top();
            minHeap.pop();
            HuffmanNode* internalNode = new HuffmanNode(leftNode->frequency + rightNode->frequency);
            
            internalNode->left = leftNode;
            internalNode->right = rightNode;

            minHeap.push(internalNode);
        }

        HuffmanNode* root = minHeap.top();
        vector<string> resultCodes;
        
        generateCodes(root, "", resultCodes);
        
        return resultCodes;
    }
};

int main() {
    string S = "abcdef";
    vector<int> f = {5, 9, 12, 13, 16, 45};
    int N = S.length();

    Solution obj;
    vector<string> result = obj.huffmanCodes(S, f, N);

    cout << "Generated Huffman Codes:" << endl;
    for (const string& code : result) {
        cout << code << " ";
    }
    cout << endl;

    return 0;
}