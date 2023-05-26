#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

void document_file(string file_name) {
  ifstream file_read;
  file_read.open(file_name);
  vector<string> commentlines = vector<string>();
  string line;
  while (getline(file_read, line)) {
    if (line[0] == '/' && line[1] == '/') {
      commentlines.push_back(line);
    }
  }

  for (int i = 0; i < commentlines.size() / commentlines[0].size(); i++) {
    
  }
}

int main() {
  system("Color 03");

  cout << "Auto-Docs: Easy documentation for your programs." << endl;
  cout << "------------------------------------------------" << endl;

  while (true) {
    cout << "Please enter a file to create documentation for." << endl;
    string file_name;
    cin >> file_name;
    cout << "Generating documentation for " + file_name + "." << endl;
    document_file(file_name);
  }
}