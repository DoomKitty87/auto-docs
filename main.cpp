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
    for (int i = 0; i < line.length(); i++) {
      if (!(line[i] == ' ' || line[i] == '\t')) break;
      else { 
        line.erase(line.begin() + i);
        i--;
      }
    }
    if (line[0] == '/' && line[1] == '/') {
      commentlines.push_back(line);
    }
  }

  vector<vector<string> > functions = vector<vector<string> >();
  vector<string> footnotes = vector<string>();

  for (int i = 0; i < commentlines.size(); i++) {
    if (commentlines[i][2] == 'F') {
      vector<string> functiondata = vector<string>();
      for (int j = 3; j < commentlines[i].length() - 1; j++) {
        if (commentlines[i][j] == ':') {
          functiondata.push_back(commentlines[i].substr(3, j - 3));
          for (int k = j + 1; k < commentlines[i].length() - 1; k++) {
            if (commentlines[i][k] == ':') {
              functiondata.push_back(commentlines[i].substr(j + 1, k - (j + 1)));
              functiondata.push_back(commentlines[i].substr(k + 1));
              break;
            }
          }
          break;
        }
      }

      for (int j = 1; j <= stoi(functiondata[1]); j++) {
        string param;
        for (int k = 2; k < commentlines[i + j].length(); k++) {
          if (commentlines[i + j][k] == ':') {
            for (int l = k + 1; l < commentlines[i + j].length(); l++) {
              if (commentlines[i + j][l] == ':' || l == commentlines[i + j].length() - 1) {
                param = commentlines[i + j].substr(3, l - 3) + ": " + commentlines[i + j].substr(l + 1);
                break;
              } 
            }
            break;
          }
        }
        functiondata.push_back(param);
      }
      functions.push_back(functiondata);
    }
    else if (commentlines[i][2] == 'N')  {
      footnotes.push_back(commentlines[i].substr(3));
    }
  }
  file_read.close();
  ofstream file_write;
  string filestem;
  for (int i = 0; i < file_name.length(); i++) {
    if (file_name[i] == '.') {
      filestem = file_name.substr(0, i);
      break;
    }
  }
  file_write.open(filestem + "_doc.md");
  file_write << "#" + filestem + " Documentation" << endl;
  file_write << "Generated by auto-docs." << endl << endl;

  if (functions.size() > 0) {
    file_write << "#Functions" << endl;
    for (int i = 0; i < functions.size(); i++) {
      file_write << functions[i][0] << endl;
      file_write << functions[i][2] << endl;
      for (int j = 0; j < stoi(functions[i][1]); j++) {
        for (int k = 0; k < functions[i][3 + j].length(); k++) {
          if (functions[i][3 + j][k] == ':') {
            file_write << functions[i][3 + j].substr(0, k) << endl;
            file_write << functions[i][3 + j].substr(k + 1) << endl;
            break;
          }
        }
      }
      file_write << endl;
    }
  }

  if (footnotes.size() > 0) {
    file_write << "#Footnotes" << endl;
    for (int i = 0; i < footnotes.size(); i++) {
      file_write << footnotes[i] << endl << endl;
    }
  }
  file_write.close();
  //NAdds data to output file.
}

//Fmain:0:Runs main program loop.
int main() {
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