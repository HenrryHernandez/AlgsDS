#include <bits/stdc++.h>

using namespace std;

class UndirectedGraph{
private:
    struct Adjacents {
        int src;
        int dst;
        int weight;
    };

    int n;
    vector<vector<Adjacents*>> v;

public:
    UndirectedGraph(int n){
        v.reserve(n);
        for(int i = 0; i < n; i++) v.push_back({});
    }

    void insertNode(char src, char dst, int weight);
    void printGraph();
};

void UndirectedGraph::insertNode(char src, char dst, int weight){
    Adjacents* a = new Adjacents();
    a->src = src - 'a';
    a->dst = dst - 'a';
    a->weight = weight;
    Adjacents* b = new Adjacents();
    b->src = dst - 'a';
    b->dst = src - 'a';
    b->weight = weight;
    v[src - 'a'].push_back(a);
    v[dst - 'a'].push_back(b);
}

void UndirectedGraph::printGraph(){
    for(vector<Adjacents*> adv : v){
        for(Adjacents* ad : adv){
            cout << (char)(ad->src + 'a') << " -----> " << (char)(ad->dst + 'a') << ", weight = " << ad->weight << endl;
        }
    }
}

int main(){

    UndirectedGraph dg(8);
    dg.insertNode('a', 'b', 3);
    dg.insertNode('a', 'd', 6);
    dg.insertNode('b', 'c', 4);
    dg.insertNode('d', 'c', 4);
    dg.insertNode('d', 'b', 11);

    dg.printGraph();

	return 0;
}
