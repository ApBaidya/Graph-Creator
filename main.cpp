/*Aparajita Baidya 5.23.2026
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
void printTable(vector<vector<int>> adjTable);//print out that adjacency table

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
      printTable(adjTable);
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
  //push into labels
  labels.push_back(l);
  //add int vector, 0 for self and -1 for everything else
  vector<int> newV;
  adjTable.push_back(newV);
  int length = 0;
  for(vector<vector<int>>::iterator it = adjTable.begin(); it != adjTable.end(); ++it){
    if((*it) == newV){
      for(int i = 0; i < length; ++i){
	(*it).push_back(-1);
      }
      (*it).push_back(0);
    }
    else{
      (*it).push_back(-1);
    }
    ++length;
  }
  return;
}

void printTable(vector<vector<int>> adjTable){
  for(vector<vector<int>>::iterator it = adjTable.begin(); it != adjTable.end(); ++it){
    for(auto it1 = (*it).begin(); it1 != (*it).end(); ++it1){//https://www.geeksforgeeks.org/cpp/how-to-iterate-2d-vector-in-cpp/
      cout << (*it1) << " ";
    }
    cout<<endl;
  }
  return;
}
