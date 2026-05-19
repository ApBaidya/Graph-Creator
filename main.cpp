//Aparajita Baidya 5.15.2026 - Graph Creator
/*
  graph creator - breadth first search
To do:
- Add vertex to graph
- Add Edge: enter 2 nodes and weight --> add edge from 1st to 2nd Node
- Remove Vertex: enter label --> rem from graph --> remove all edges to it
- Remove Edge: enter 2 vertex labels --> remove edge between them
- Find shortest Path --> Dijkstra's algoritm to find shortest path from first to last --> return path and total
Remember, comment. Comment to bring honor.
*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

//struct for vertex
struct vertex{
  string label;
  int visited = 0;
};
//strcut for LLL
struct Node{
  Node* next = NULL;//for the vertices ll
  Node* edges = NULL;//for the edges LL
  vertex* vert = NULL;
};

//function defs: V - vertex, E - edge
Node* addV(Node* head, string l);
Node* addEdgeProc(Node* edge, vertex* newv);
Node* addE(Node* head, string l1, string l2);
Node* rmE(Node* head);
Node* rmV(Node* head);
Node* findPath(Node* head);//shortest path
Node* search(Node* head, string l);
//aid debug
void printV(Node* head);
void printE(Node* head);
void printA();//print adjacency table

//main
int main(){
  cout<<"welcome"<<endl;
  //variables that I n e e d
  char input[3];
  int running = 0;
  string label;
  //start of the vertices list --> didn't want an array
  Node* head = NULL; 
  //start of main loop
  while(running){
    cout<<"[av]add vertex, [ae]add edge, [rv]remove vertex, [re]remove edge, [f]find shortest path, [q]quit"<<endl;
    cin >> input;
    cin.ignore(10, '\n');
    cin.clear();
    if(strcmp(input, "av")==0){
      cout<<"input label"<<endl;
      cin>>label;
      head = addV(head, label);
    }
  }//end of main loop
  cout<<"farewell"<<endl;
  return 0;
}

Node* addV(Node* head, string l){
  if(!head){//head case
    head = new Node;//create head
    vertex* v = new vertex;//create a vertex
    v->label = l;
    head->vert = v;//set head's vertex to v
    return head;
  }
  else{
    head->next = addV(head->next, l);//recurse
    return head;
  }
}

Node* search(Node* head, string l){//return a vertex
  if(!head){
    return NULL;//can't find it
  }
  if(head->vert->label == l){
    return head;
  }
  else{
    head->next = search(head->next, l);
    return head;
  }
}

Node* addEdgeProc(Node* edge, vertex* newv){
  if(!edge){
    edge = new Node;
    edge->vert = newv;//assign new vertex to the edge list
    return edge;
  }
  else{//recurse
    edge->edges = addEdgeProc(edge->edges, newv);
    return edge;
  }
}

Node* addE(Node* head, string l1, string l2){
  if(!head){//nothing, head, end 
    return head;
  }
  if(head->vert->label == l1){//found start
    Node* end = NULL;
    end = search(head, l2);//find second node, if it exists
    vertex* newv = end->vert;
    if(end){//if end != NULL
      //add to end of edge list
      head->edges = addEdgeProc(head->edges, newv);
    }
  }
  //if not found yet
  else{
    head->next = addE(head->next, l1, l2);//recurse
  }
  return head;//return head at the end
}

Node* rmE(Node* head){
  return head;
}

Node* rmV(Node* head){
  return head;
}
