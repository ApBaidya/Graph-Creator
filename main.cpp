/*Aparajita Baidya 5.19.2026
  graph creator - adjacency table - breadth first search
  - directed and weighted edges
*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

//funcs
void addV();
void addE();
void rmV();
void rmE();
void findPath();

int main(){
  cout<<"welcome"<<endl;
  //variables that I n e e d
  char input[3];
  int running = 0;
  string label1;
  string label2;
  int weight;
  //start of main loop
  while(running){
    cout<<"[av]add vertex, [ae]add edge, [rv]remove vertex, [re]remove edge, [f\
]find shortest path, [q]quit"<<endl;
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
