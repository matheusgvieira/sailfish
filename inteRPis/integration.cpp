#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define PATHGPIO "/sys/class/gpio/gpio"
#define VALUE "/value"

int main () {
int pins[4] = {6, 22, 17, 26};
  // Create a text file
  ofstream MyWriteFile(PATHGPIO  + to_string(pins[0]) + VALUE);

  // Write to the file
  MyWriteFile << "Files can be tricky, but it is fun enough!";
 
  // Close the file
  MyWriteFile.close();

  // Create a text string, which is used to output the text file
  string myText;

  // Read from the text file
  ifstream MyReadFile(PATHGPIO  + to_string(pins[0]) + VALUE);

  // Use a while loop together with the getline() function to read the file line by line
  while (getline (MyReadFile, myText)) {
    // Output the text from the file
    cout << myText;
  }

  cout << "\n";

  // Close the file
  MyReadFile.close();
}