#include <string>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main() {
  system("Color 03");

  cout << "Auto-Docs: Easy documentation for your programs." << endl;
  cout << "------------------------------------------------" << endl;

  while (true) {
    cout << "Please enter a file to create documentation for." << endl;
    string file_name;
    cin >> file_name;
    cout << "Generating documentation for " + file_name + "." << endl;
  }
}