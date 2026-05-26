/*Aparajita Baidya 5.24.2026
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
void addE(vector<vector<int>> &, vector<string>, string start, string end, int weight);
void rmV(vector<vector<int>> &, vector<string> &, string & l);
void rmVLabel(vector<string> & labels, int index);
void rmE(vector<vector<int>>&, vector<string>, string start, string end);
void printTable(vector<vector<int>>);//print out that adjacency table
void findPath(vector<vector<int>> adjTable, vector<string> labels, string start, string end);
void Dijkstra(vector<vector<int>> adjT, vector<string> labels, vector<string> & visited, vector<string> & unvisited, int* shortestDist, string* previous, string start);

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
      cout<<"start:"<<endl;
      cin>>label1;
      cin.ignore(10, '\n');
      cin.clear();
      cout<<"end:"<<endl;
      cin>>label2;
      cin.ignore(10, '\n');
      cin.clear();
      cout<<"weight:"<<endl;
      cin>>weight;
      cin.ignore(10, '\n');
      cin.clear();
      addE(adjTable, labels, label1, label2, weight);
      cout<<"done"<<endl;
    }
    else if(strcmp(input, "re")==0){//RME
      cout<<"start:"<<endl;
      cin>>label1;
      cin.ignore(10, '\n');
      cin.clear();
      cout<<"end:"<<endl;
      cin>>label2;
      cin.ignore(10, '\n');
      cin.clear();
      rmE(adjTable, labels, label1, label2);
      cout<<"done"<<endl;
    }
    else if(strcmp(input, "rv")==0){//RMV
      cout<<"label:"<<endl;
      cin>>label1;
      cin.ignore(10, '\n');
      cin.clear();
      rmV(adjTable, labels, label1);

      cout<<"done"<<endl;
    }
    //LOOK HERE
    else if(strcmp(input, "f")==0){//FP
      cout<<"start:"<<endl;
      cin>>label1;
      cin.ignore(10, '\n');
      cin.clear();
      cout<<"end:"<<endl;
      cin>>label2;
      cin.ignore(10, '\n');
      cin.clear();
      findPath(adjTable, labels, label1, label2);
      cout<<"done"<<endl;
    }
    else if(strcmp(input, "p")==0){//PT
      printTable(adjTable);
      cout<<"done"<<endl;
    }
    else if(strcmp(input, "q")==0){//QUIT
      running = 0;
      for(vector<vector<int>>::iterator it = adjTable.begin(); it != adjTable.end(); ++it){
	(*it).clear();
      }
      adjTable.clear();
      labels.clear();
      cout<<"done"<<endl;
    }
  }//end of main while
  cout<<"and thus the loop ends. Never to wake again. Or something. Idk."<<endl;
  return 0;
}

void findPath(vector<vector<int>> adjT, vector<string> labels, string start, string end){
  //dijkstra to make that table if labels exist  
  int indexS;
  int Sfound = 0;
  int indexE;
  int Efound = 0;
  int count = 0;
  for(vector<string>::iterator it = labels.begin(); it != labels.end(); ++it){
    if((*it) == start){
      indexS = count;
      Sfound = 1;
    }
    else if((*it) == end){
      indexE = count;
      Efound = 1;
    }
    ++ count;
  }
  if(Sfound == 1 && Efound == 1){
    //vectors for visited and unvisited
    vector<int> visited;//int bc index and I don't have to keep check labels for index
    vector<int> unvisited;
    //the table, besides labels 
    int shortestDist[count];
    string previous[count];
    
    for(int i = 0; i < count; i++){//just setting up the array
      shortestDist[i] = 99999;
      previous[i] = "NONE";
      unvisited.push_back(i);
    }//done setting up arrays

    shortestDist[indexS] = 0;//set own distance to 0
    
    //ALGORITHM TIME
    while(!(unvisited.empty())){
      int current = (*(unvisited.begin()));//current index
      int sum;//path length
      for(vector<int>::iterator it = unvisited.begin(); it != unvisited.end(); ++ it){//find which index to visit
	if(shortestDist[current] > shortestDist[(*it)]){
	  current = (*it);//get new current index
	}
      }
      //cout<<"current "<<current<<endl;

      //for each unvisited neighbhor of current
      for(vector<int>::iterator it = unvisited.begin(); it != unvisited.end(); ++it){
	//cout<<"path length "<<(*((*(adjT.begin()+current)).begin()+(*it)))<<endl;
	//cout<<"prev length"<<shortestDist[(*it)]<<endl;
	if((*((*(adjT.begin()+current)).begin()+(*it))) > 0){//if there is a connection on the adj table
	  int sum1 = 0;
	  if(shortestDist[current] != 99999){//if this isn't our first time adding
	    sum1 = shortestDist[current];
	  }
	  sum = sum1 + (*((*(adjT.begin()+current)).begin()+(*it)));//add shortest distance to current with the distance for the connection
	  //cout<<"sum "<<sum<<endl;
	  if(sum<shortestDist[(*it)]){//if we need to update the path
	    shortestDist[(*it)] = sum;//update path length
	    previous[(*it)] = labels[current];//update previous
	  }
	}
      }
      
      //remove from unvisited
      int remIndex = 0;
      int count2 = 0;
      for(vector<int>::iterator it = unvisited.begin(); it != unvisited.end(); ++it){
	if((*it) == current){
	  remIndex = count2;
	}
	++count2;
      }
      unvisited.erase(unvisited.begin()+remIndex);
      //add to visited
      visited.push_back(current);
    }//done making table
    /*
    for(int i = 0; i < count; i++){
      cout<<shortestDist[i];
    }
    cout<<endl;
    for(int i = 0; i < count; i++){
      cout<<previous[i];
      }*/
    cout<<endl;
    //find the shortest path now.
    //string path;
    int currentIndex = indexE;
    string currentL = end;
    int temp = 0;
    int plen = 0;
    //cout<<end;
    vector<string> path;
    path.push_back(end);
    while(currentL != start){
      path.push_back(previous[currentIndex]);
      ++ plen;
      // cout<<"cout"<<previous[currentIndex]<<endl;
      currentL = previous[currentIndex];
      for(int i = 0; i < count; i++){
	if((*(labels.begin()+i)) == currentL){
	  currentIndex = temp;
	}
	++temp;
      }
    }
    //cout path
    for(int i =plen; i >-1; i--){
      cout<<(*(path.begin()+i));
    }
    path.clear();//clear that guy
    cout<<endl;
    cout<<shortestDist[indexE]<<endl;
  }
}
void addV(vector<vector<int>> & adjTable, vector<string> & labels, string & l){
  //push into labels
  labels.push_back(l);
  //add int vector, 0 for self and -1 for everything else
  vector<int> newV;//new vector to add into this bad boy
  adjTable.push_back(newV);
  int length = 0;
  for(vector<vector<int>>::iterator it = adjTable.begin(); it != adjTable.end(); ++it){
    if((*it) == newV){//found new vector
      for(int i = 0; i < length; ++i){//fill -1 up till reaching own index, then add 0
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

void addE(vector<vector<int>> & adjT, vector<string> labels, string start, string end, int weight){
  //important ints
  int indexS;
  int Sfound = 0;
  int indexE;
  int Efound = 0;
  int count = 0;
  for(vector<string>::iterator it = labels.begin(); it != labels.end(); ++it){//get index of start and end...if they even exist
    if((*it) == start){
      indexS = count;
      Sfound = 1;
    }
    else if((*it) == end){
      indexE = count;
      Efound = 1;
    }
    ++ count;
  }
  if(Sfound == 1 && Efound == 1){//can add edge
    adjT[indexS][indexE] = weight;//change value in the table
  }
  return;
}

void printTable(vector<vector<int>> adjTable){//iterate through the 2D vector. oh yeahhhhh.
  for(vector<vector<int>>::iterator it = adjTable.begin(); it != adjTable.end(); ++it){
    for(auto it1 = (*it).begin(); it1 != (*it).end(); ++it1){//https://www.geeksforgeeks.org/cpp/how-to-iterate-2d-vector-in-cpp/
      cout << (*it1) << " ";
    }
    cout<<endl;
  }
  return;
}

void rmVLabel(vector<string> & labels, int index){
  int count = 0;
  for(vector<string>::iterator it = labels.begin(); it != labels.end(); ++it){
    if(count == index){
      labels.erase(it);
      return;
    }
    ++ count;
  }
}

void rmV(vector<vector<int>> & adjT, vector<string> & labels, string & l){
  int exists = 0; //1 if there
  int rmIndex;
  int count = 0;
  for(vector<string>::iterator it = labels.begin(); it != labels.end(); ++it){
    if((*it) == l){
      rmIndex = count;
      exists = 1;
    }
    ++ count;
  }
  if(exists == 1){
    rmVLabel(labels, rmIndex);//rm from label list
    //remove from all vectors
    for(vector<vector<int>>::iterator it = adjT.begin(); it != adjT.end(); ++it){
      (*it).erase((*it).begin() + rmIndex);//remove the value at the rmindex for all vectors
    }
    //clear specific vertex vector
    (*(adjT.begin()+rmIndex)).clear();
    //erase the empty vertec object
    adjT.erase(adjT.begin()+rmIndex);
  }
  return;
}

void rmE(vector<vector<int>>& adjT, vector<string> labels, string start, string end){
  //similar process to addE
    //important ints
  int indexS;
  int Sfound = 0;
  int indexE;
  int Efound = 0;
  int count = 0;
  for(vector<string>::iterator it = labels.begin(); it != labels.end(); ++it){
    if((*it) == start){
      indexS = count;
      Sfound = 1;
    }
    else if((*it) == end){
      indexE = count;
      Efound = 1;
    }
    ++ count;
  }
  if(Sfound == 1 && Efound == 1){//can remove edge
    adjT[indexS][indexE] = -1;//change value in the table
  }
  return;

}
