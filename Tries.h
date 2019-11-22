#ifndef TRIES_TRIES_H
#define TRIES_TRIES_H
#include <map>
#include <string>
#include <queue>
using namespace std;

struct Node{
    bool is_word = false;
    map<string,Node*> characters;
    Node() = default;
    ~Node() = default;
    Node* next = nullptr;
    Node* parent = nullptr;
    Node* previous = nullptr;
};


struct Trie{
    Node* root = new Node;
    Node* lastfinal = nullptr;

    Node* lasttail = nullptr;

    Trie() = default;

    void print() {
        queue<Node*> q;

        if (root)
            q.push(root);
        else
            return;

        while (!q.empty()) {
            unsigned nodos = q.size();

            while (nodos > 0) {
                Node* n = q.front();

                for (auto& [letter, child] : n->characters) {
                    cout << letter << " ";
                    if (child) {
                        q.push(child);
                    }
                }
                cout << endl;

                q.pop();

                --nodos;
            }
            cout << endl;
        }
    }


    void insert(string word){
        auto aux = root;

        for(int i=0; i<word.size(); i++) {
            string s(1,word[i]);
            if(!search_in_node(s,aux->characters)){
                pair aux_pair(s, new Node);
                auto aux_parent = aux;
                aux->characters.insert(aux_pair);
                aux = aux->characters[s];
                aux->parent = aux_parent;
            }
            else{
                aux = aux->characters[s];
            }
        }
        aux->is_word = true;
        auto auxf = lastfinal;
        aux->next = auxf;
        lastfinal = aux;
    }

    bool search_complete_word(string word){
        auto aux = root;
        bool fail_case = false;
        for(int i = 0; i<word.size(); ++i){
            for (auto it = aux->characters.begin(); it!= aux->characters.end(); ++it){
                string s(1,word[i]);
                if (s == it->first){
                    aux = aux->characters[it->first];
                    goto Here;
                }
            }
            fail_case = true;
            Here:
            cout << "";
        }
        if(aux->characters.size()==0 && !fail_case){
            return true;
        }
        else{
            return false;
        }
    };

    Trie patriciafy(Node* node){
        auto aux = node;
            for(auto it = aux->characters.begin(); it!=  aux->characters.end(); ++it){

            }
    }

    bool search_by_prefix(string word){
        auto aux = root;
        bool fail_case = false;
        for(int i = 0; i<word.size(); ++i){

            for (auto it = aux->characters.begin(); it!= aux->characters.end(); ++it){
                string s(1,word[i]);
                if (s == it->first){
                    aux = aux->characters[it->first];
                    goto Here;
                }

            }
            fail_case = true;
            Here:
            cout << "";
        }
        if(aux->characters.size()!=0 && !fail_case){
            return true;
        }
        else{
            return false;
        }


    }

    bool search_in_node(string c, map<string,Node*> characters){
        if(characters.size() > 0){
            for(auto it = characters.begin(); it!=characters.end(); ++it){
                if(c == it->first){
                    return true;
                }
            }
            return false;
        }
        else{
            return false;
        }

    }

};





#endif //TRIES_TRIES_H
