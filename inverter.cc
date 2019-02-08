#include <string> 
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <iostream>    // Needed to perform IO operations
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <regex>

using namespace std;


map<string, set<int> > invertedIndex;
//input >> noskipws >> c; /*parsing the input*/



void printInvertedIndex(){
  //print the map in order
  for(map<string, set<int> >::const_iterator it = invertedIndex.begin(); it!= invertedIndex.end(); ++it){
    
    cout << it -> first << ":";

    for(set<int>::const_iterator set_it = (it->second).begin(); set_it != (it->second).end(); ++set_it){

      cout << " " << *set_it;

    }

    cout << "\n";
  }
}

string cleanWord(string word){
  //removes the nonalphabet stuff from words

  regex reg("[^a-zA-Z]");
  word = regex_replace(word, reg, "");

  return word;
}

vector<string> readFiletoVector(string filename){
  ifstream inFile(filename);
  
  if(!inFile.is_open()){
    cerr << "File not open.\n";
    exit(1);
  } 
  
  vector<string> lines;
  string line;
  while(getline(inFile, line)){
    lines.push_back(line);
  }

  return lines;
}

vector<string> readFiletoVectorbyWord(string filename){
  //reads in the words and sets as vector
  ifstream inFile(filename);


  if(!inFile.is_open()){
    cerr << "File not open.\n";
    exit(1);
  }  
  
  vector<string> words;
  string word;

  while (inFile >> word){
    word = cleanWord(word);
    words.push_back(word);
  }

  return words;
  
}

void displayVector(const vector<string> v){

  for(int i(0); i != v.size(); ++i){
    cout << "\n" << v[i];
  }

  cout << "\n";
}

void addWordsfromVectorList(const vector<string> v, const int number){
  
  for(int i(0); i != v.size(); i++){
    //if its in the dictionary, add i to set
    if(invertedIndex.find(v[i]) == invertedIndex.end()){
      set<int> s;
      s.insert(number);
      invertedIndex[v[i]] = s;
    }else{//create a new key,value pair
      set<int> s = invertedIndex[v[i]];
      s.insert(number);
      invertedIndex[v[i]] = s;
    }
  }

}

int main(int argc, char *argv[]) {

  /*if (argc != 1){
    cout << "Usage: ./inverter <x>; where <x> is a file that contains names of files" << endl;

    char* words = openFile(argv[1]);*/

  string listFilename(argv[1]);

  vector<string> texts = readFiletoVector(listFilename);
  //displayVector(texts);

  for (int i = 0; i != texts.size(); i++){
    vector<string> words = readFiletoVectorbyWord(texts[i]);
    addWordsfromVectorList(words, i);
    //displayVector(words);
  }

  printInvertedIndex();
  
  //invertedIndex.print();
  //vector<string> words = readFiletoVectorbyWord(listFilename);
  //displayVector(words);
  
  
  // cout << "hello, world" << endl;  // Say Hello
  return 0;          
}                                 
