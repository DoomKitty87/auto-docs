#include <string>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

//Fdocument_file:1:Generates documentation for given file based on comments.
//:file_name:The file to generate docs for.
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

  vector<vector<string> > functions = vector<vector<string> >();
  vector<string> footnotes = vector<string>();

  for (int i = 0; i < commentlines.size() / commentlines[0].size(); i++) {
    if (commentlines[i][2] == 'F') {
      vector<string> functiondata = vector<string>();
      for (int j = 0; j < commentlines[i].length(); j++) {
        if (line[j] == ':') {
          functiondata.push_back(commentlines[i].substr(3, j));
          for (int k = j + 1; k < line.length(); k++) {
            if (commentlines[i][k] == ':') {
              functiondata.push_back(commentlines[i].substr(j + 1, k));
              functiondata.push_back(commentlines[i].substr(k + 1));
              break;
            }
          }
          break;
        }
      }
      
      for (int j = 0; j < stoi(functiondata[1]); j++) {
        string param;
        int colons = 0;
        for (int k = 2; k < commentlines[i + j].length(); k++) {
          if (commentlines[i + j][k] == ':') {
            colons++;
            if (colons > j * 2) {
              for (int l = k + 1; k < commentlines[i + j].length(); k++) {
                if (commentlines[i + j][l] == ':' || k == commentlines[i + j].length() - 1) {
                  param = commentlines[i + j].substr(k + 1, l);
                  break;
                }
              }
              break;
            }
          }
        }
        functiondata.push_back(param);
      }
    }
    else if (line[2] == 'N')  {
      footnotes.push_back(line.substr(3));
    }
  }

  ofstream file_write;
  string filestem;
  for (int i = 0; i < file_name.length(); i++) {
    if (file_name[i] == '.') {
      filestem = file_name.substr(0, i);
      break;
    }
  }
  file_write.open(filestem + "_doc.md");
}

//Fmain:0:Runs main program loop
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