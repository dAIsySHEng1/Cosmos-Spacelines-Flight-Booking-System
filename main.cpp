#include "Console.h"
#include <iostream>

int main() {
  string cont;
  Console *program = new Console();
  program->welcome();
  
  do {
    program->selection();
    cout << "--- Enter QUIT to end program. Otherwise, press any key to continue.---";
    cin >> cont;
  }
  while (cont != "QUIT");
  delete program;
}
