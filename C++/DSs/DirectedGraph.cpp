#include <bits/stdc++.h>

using namespace std;

class DirectedGraph{
private:
    struct Adjacents {
        int src;
        int dst;
        int weight;
    };

    int n;
    vector<vector<Adjacents*>> v;

public:
    DirectedGraph(int n){
        v.reserve(n);
        for(int i = 0; i < n; i++) v.push_back({});
    }

    void insertNode(char src, char dst, int weight);
    void printGraph();
};

void DirectedGraph::insertNode(char src, char dst, int weight){
    Adjacents* a = new Adjacents();
    a->src = src - 'a';
    a->dst = dst - 'a';
    a->weight = weight;
    v[src - 'a'].push_back(a);
}

void DirectedGraph::printGraph(){
    for(vector<Adjacents*> adv : v){
        for(Adjacents* ad : adv){
            cout << (char)(ad->src + 'a') << " -----> " << (char)(ad->dst + 'a') << ", weight = " << ad->weight << endl;
        }
    }
}

int main(){

    DirectedGraph dg(8);
    dg.insertNode('a', 'b', 3);
    dg.insertNode('a', 'c', 6);
    dg.insertNode('b', 'c', 4);
    dg.insertNode('b', 'd', 4);
    dg.insertNode('b', 'e', 11);
    dg.insertNode('c', 'd', 8);
    dg.insertNode('c', 'g', 11);
    dg.insertNode('d', 'e', -4);
    dg.insertNode('d', 'f', 5);
    dg.insertNode('d', 'g', 2);
    dg.insertNode('e', 'h', 9);
    dg.insertNode('f', 'h', 1);
    dg.insertNode('g', 'h', 2);

    dg.printGraph();

	return 0;
}
