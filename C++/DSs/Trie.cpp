#include <bits/stdc++.h>

/*
    Complexity:
        Basically everything depend on the length of the word. Not much to say.
        The complexity of creating a trie is O(W*L), where W is the number of words, and L is an average
        length of the word: you need to perform L lookups on the average for each of the W words in the set.
        Same goes for looking up words later: you perform L steps for each of the W words.
*/

class Trie {
    private:
        struct UniqueChar{
            UniqueChar* tries[26] = {NULL};
            int counter = 0;
            UniqueChar(){
                for(int i = 0; i < 26; i++){
                    tries[i] = NULL;
                }
            }
        };

        UniqueChar* uc;

    public:
        Trie(){
            uc = new UniqueChar();
        }

        bool isEmpty(UniqueChar* uc);
        void insertWord(std::string s);
        void deleteWord(std::string s);
        UniqueChar* deleteWord(UniqueChar* root, std::string s, int sSize);
        int searchWord(std::string s);
        bool startsWith(std::string s);
};

bool Trie::isEmpty(UniqueChar* uc){
    for(int i = 0; i < 26; i++)
        if(uc->tries[i] != NULL) return false;
    return true;
}

void Trie::insertWord(std::string s){
    UniqueChar* temp = uc;
    for(char c : s){
        if(temp->tries[c - 'a'] == NULL) temp->tries[c - 'a'] = new UniqueChar();
        temp = temp->tries[c - 'a'];
    }
    temp->counter++;
}

void Trie::deleteWord(std::string s){
    uc->tries[s[0] - 'a'] = deleteWord(uc->tries[s[0] - 'a'], s, 1);
}

Trie::UniqueChar* Trie::deleteWord(UniqueChar* root, std::string s, int sSize){
    if(root == NULL) return NULL;

    if (sSize == s.size()) {
        //std::cout << "if 1 empty = " << s[sSize] << ", sSize = " << sSize << ", counter = " << root->counter << std::endl;
        if (root->counter > 0) root->counter--;
        if (root->counter == 0 && isEmpty(root)) {
            delete (root);
            root = NULL;
        }
        return root;
    }

    root->tries[s[sSize] - 'a'] = deleteWord(root->tries[s[sSize] - 'a'], s, sSize + 1);

    if(root->counter == 0 && isEmpty(root)){
        //std::cout << "empty = " << s[sSize] << ", sSize = " << sSize << std::endl;
        delete(root);
        root = NULL;
    }
    return root;
}

int Trie::searchWord(std::string s){
    UniqueChar* temp = uc;
    for(char c : s){
        if(temp->tries[c - 'a'] == NULL) return 0;
        temp = temp->tries[c - 'a'];
    }

    return temp->counter;

}

bool Trie::startsWith(std::string s){
    if(s.size() == 0) return false;
    UniqueChar* temp = uc;
    for(char c : s){
        if(temp->tries[c - 'a'] == NULL) return false;
        temp = temp->tries[c - 'a'];
    }
    return true;
}


int main(){

    Trie tr;
    tr.insertWord("hola");
    tr.insertWord("hola");
    tr.insertWord("hola");
    tr.insertWord("hoas");
    tr.deleteWord("hoa");
    if(tr.searchWord("hoas")) std::cout << "exists " << tr.searchWord("hoas") << " times" << std::endl;
    if(tr.startsWith("hoas")) std::cout << "it starts with" << std::endl;


    return 0;
}
