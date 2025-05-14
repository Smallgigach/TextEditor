#include "Terminal/RawMode.h"
#include <cctype>
#include <iostream>
#include <termios.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  RawMode rawmode;
  rawmode.enableRawMode();
  while (1) {
    char c = '\0';
    if (read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN) {
      rawmode.die("read");
    }
    if (iscntrl(c)) {
      std::cout << c << "";
    } else {
      std::cout << "()" << c << "";
    }
    if (c == 'q') {
      break;
    }
  };

  return 0;
}
