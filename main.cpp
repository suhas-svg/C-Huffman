#include<bits/stdc++.h>
using namespace std;

//using Heap 
struct MinHeapNode
{
    unsigned frequency;
    char data;
    MinHeapNode *leftNode, *rightNode;

    MinHeapNode(char data, unsigned frequency)
        : data(data), frequency(frequency), leftNode(NULL), rightNode(NULL)
    {}
};

//to compare the left and right sub-trees 
struct compare
{
    bool operator()(MinHeapNode* l, MinHeapNode* r)
    {
        return (l->frequency > r->frequency);
    }
};

// method to print the Huffman code
void printCodes(struct MinHeapNode* root, unordered_map<char, string> &huffmanCode)
{
    //to check whether root node or not
    if (!root)     
        return;

    stack<pair<MinHeapNode*, string>> s;
    s.push({ root, "" });

    //loop to check whether data exists or not
    do {     
        auto node = s.top().first;
        auto code = s.top().second;
        s.pop();

        //to check whether data is not blank
        if (node->data != '$') {     
            huffmanCode[node->data] = code;
        }

        //to print the right sub-trees with '1'
        if (node->rightNode) {    
            s.push({ node->rightNode, code + "1" });
        }
        
        //to print the left sub-trees with '0'
        if (node->leftNode) {     
            s.push({ node->leftNode, code + "0" });
        }

    } while (!s.empty());
}

// method to calculate the Huffman code
void HuffmanCodes(string text)
{
    unordered_map<char, unsigned> frequency;
    for (int i = 0; i < text.size(); i++) {
        frequency[text[i]]++;
    }
 
    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
    for (auto it = frequency.begin(); it != frequency.end(); ++it) {
        minHeap.push(new MinHeapNode(it->first, it->second));
    }

    //loop to iterate through the text when the heap is not empty
    do {
        MinHeapNode* leftNode = minHeap.top();
        minHeap.pop();
        MinHeapNode* rightNode = minHeap.top();
        minHeap.pop();

        MinHeapNode* parent = new MinHeapNode('$', leftNode->frequency + rightNode->frequency);
        parent->rightNode = rightNode;
        parent->leftNode = leftNode;
        minHeap.push(parent);

    } while (minHeap.size() > 1);

    unordered_map<char, string> huffmanCode;
    printCodes(minHeap.top(), huffmanCode);

    ofstream outfile;
    outfile.open("encoded.txt");
    for (int i = 0; i < text.size(); i++) {
        outfile << huffmanCode[text[i]];
    }

    outfile.close();

    //creating a 'encoded.txt' text file
    ifstream infile;
    infile.open("encoded.txt");
    string encodedText;
    getline(infile, encodedText);
    infile.close();
    
    //procedure to get the decoded text from the encoded text
    string decodedText = "";
    MinHeapNode* currentNode = minHeap.top();
    string::iterator it = encodedText.begin();
    //loop to iterate through the encoded text
    while (it != encodedText.end()) {
        //condition for left node
        if (*it == '0') {
            currentNode = currentNode->leftNode;
        } 
        //condition for right node
        else {
            currentNode = currentNode->rightNode;
        }
        it++;
        //condition for the root node
        if (currentNode->leftNode == nullptr && currentNode->rightNode == nullptr) {
            decodedText += currentNode->data;
            currentNode = minHeap.top();
        }
    }
    //creating a 'decoded.txt' text file
    ofstream outfile2;
    outfile2.open("decoded.txt");
    string temp = "";
    //loop to iterate through the encoded text
    for (char ch : encodedText) {
        temp += ch;
        for (auto it = huffmanCode.begin(); it != huffmanCode.end(); ++it) {
            if (it->second == temp) {
                outfile2 << it->first;
                temp = "";
            }
        }
    }
// write any remaining characters in temp to decoded.txt
outfile2 << temp;
outfile2.close();

    //output to be printed on the console
    cout << "Original text: " << text << endl;
    cout << "Encoded text: " << encodedText << endl;
    cout << "Decoded text: " << decodedText << endl;
}

int main()
{
    string text = "Computer and Information Science Cleveland State University";
    HuffmanCodes(text);
    return 0;
}
