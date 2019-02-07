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
    if(){

    }else{//create a new key,value pair

    }
  }

}

int main(int argc, char *argv[]) {

  /*if (argc != 1){
    cout << "Usage: ./inverter <x>; where <x> is a file that contains names of files" << endl;

    char* words = openFile(argv[1]);*/

  string listFilename(argv[1]);

  vector<string> texts = readFiletoVector(listFilename);
  displayVector(texts);

  for (int i = 0; i != texts.size(); i++){
    vector<string> words = readFiletoVectorbyWord(texts[i]);
    displayVector(words);
  }

  //vector<string> words = readFiletoVectorbyWord(listFilename);
  //displayVector(words);
  
  
  // cout << "hello, world" << endl;  // Say Hello
  return 0;          
}                                 
