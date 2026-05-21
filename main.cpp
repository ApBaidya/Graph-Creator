/*Aparajita Baidya 5.20.2026
  graph creator - adjacency table - breadth first search
  - directed and weighted edges
  array of labels --> indexes are important
  array of array type of thing for the adjacency table which has the wieghts corresposing to the edges
*/

#include <iostream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

//funcs
void addV(vector<vector<int>> &, vector<string> &, string & l);
void addE();
void rmV();
void rmE();
void findPath();
void printTable();//print out that adjacency table

int main(){
  //variable time
  int running = 1;
  //labels
  string label1;
  string label2;
  //user input
  char input[3];
  //weight
  int weight;
  //vector of vectors of ints -> adjacency table
  vector<vector<int>> adjTable;
  //vector -> index related to label
  vector<string> labels;
  while(running){
     cout<<"[av]add vertex, [ae]add edge, [rv]remove vertex, [re]remove edge, [f]find shortest path, [p]print adjacency table, [q]quit"<<endl;
    cin >> input;
    cin.ignore(10, '\n');
    cin.clear();
    if(strcmp(input, "av")==0){//ADDV
      cout<<"label:"<<endl;
      cin>>label1;
      cin.ignore(10, '\n');
      cin.clear();
      addV(adjTable, labels, label1);
      cout<<"done"<<endl;
    }
    else if(strcmp(input, "ae")==0){//ADDE
      cout<<"done"<<endl;
    }
    else if(strcmp(input, "re")==0){//RME
      cout<<"done"<<endl;
    }
    else if(strcmp(input, "rv")==0){//RMV
      cout<<"done"<<endl;
    }
    else if(strcmp(input, "f")==0){//FP
      cout<<"done"<<endl;
    }
    else if(strcmp(input, "p")==0){//PT
      cout<<"done"<<endl;
    }
    else if(strcmp(input, "q")==0){//QUIT
      cout<<"done"<<endl;
    }
  }//end of main while
  cout<<"and thus the loop ends. Never to wake again. Or something. Idk."<<endl;
  return 0;
}

void addV(vector<vector<int>> & adjTable, vector<string> & labels, string & l){
  return;
}

