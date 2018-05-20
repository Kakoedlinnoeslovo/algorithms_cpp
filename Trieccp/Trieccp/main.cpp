//
//  main.cpp
//  Trieccp
//
//  Created by Roman Degtyarev on 20.05.2018.
//  Copyright © 2018 Roman Degtyarev. All rights reserved.
//

#include <iostream>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    
    bool isEndOfWord;
};

struct TrieNode *getNode(void){
    struct TrieNode *pNode = new TrieNode;
    pNode->isEndOfWord = false;
    
    for (int i = 0;i < ALPHABET_SIZE; i++){
        pNode -> children[i] = NULL;
    };
    return pNode;
};

void insert(struct TrieNode *root, string key){
    struct TrieNode *pCrawl = root;
    
    for (int i=0; i<key.length(); i++){
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    };
    pCrawl->isEndOfWord = true;
};

bool search(struct TrieNode *root, string key){
    struct TrieNode *pCrowl = root;
    for (int i = 0; i< key.length(); i++){
        int index = key[i] - 'a';
        if (!pCrowl->children[index])
            return false;
        pCrowl = pCrowl->children[index];
    }
    return (pCrowl !=NULL && pCrowl -> isEndOfWord);
};




// Driver
int main()
{
    // Input keys (use only 'a' through 'z'
    // and lower case)
    string keys[] = {"the", "a", "there",
        "answer", "any", "by",
        "bye", "their" };
    int n = sizeof(keys)/sizeof(keys[0]);
    
    struct TrieNode *root = getNode();
    
    // Construct trie
    for (int i = 0; i < n; i++)
        insert(root, keys[i]);
    
    // Search for different keys
    search(root, "the")? cout << "Yes\n" :
    cout << "No\n";
    search(root, "these")? cout << "Yes\n" :
    cout << "No\n";
    return 0;
}
