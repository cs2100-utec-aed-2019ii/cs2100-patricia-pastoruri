#include <iostream>
#include "Tries.h"

int main() {
    Trie t;
    t.insert("hola");
    t.insert("ae");
    t.insert("hole");
    t.insert("xi");

    auto  aux = t.lastfinal;
    auto track = t.lastfinal;
    while(aux != nullptr){
       while(aux != nullptr) {
           auto padre = aux->parent;
           if(padre!=nullptr){
               for (auto it = padre->characters.begin(); it != padre->characters.end(); ++it) {
                   if (it->second == aux) {
                       cout << it->first << endl;
                   }
               }
           }
           aux = aux->parent;
       }
       aux = track->next;
       track = track->next;
       cout << endl;
    }



    auto last = t.lastfinal;

    while(last != nullptr){
        if(last->parent->is_word == false && last->parent->characters.size()==1){
            for(auto it = last->parent->parent->characters.begin(); it !=last->parent->parent->characters.end(); ++it){
                if( it->second == last->parent){
                    auto it2 = last->parent->characters.begin();
                    it->first =
                            it->first + it2->first;
                }
            }
        }


    }






    return 0;
}