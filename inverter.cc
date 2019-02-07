#include <string> 
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>    // Needed to perform IO operations
#include <vector>
using namespace std;

//input >> noskipws >> c; /*parsing the input*/

vector<string> readFiletoVector(string filename){
  ifstream inFile(filename);
  vector<string> lines;
  string line;
  while(getline(inFile, line)){
    lines.push_back(line);
  }

  return lines;
}

void displayVector(const vector<string> v){

  for(int i(0); i != v.size(); ++i){
    cout << "\n" << v[i];
  }
    
}

int main(int argc, char *argv[]) {

  /*if (argc != 1){
    cout << "Usage: ./inverter <x>; where <x> is a file that contains names of files" << endl;

    char* words = openFile(argv[1]);*/

  string listFilename(argv[1]);

  vector<string> texts = readFiletoVector(listFilename);
  displayVector(texts);
  
  // map<string, set<int> > invertedIndex;
  
  // cout << "hello, world" << endl;  // Say Hello
  return 0;          
}                                 
