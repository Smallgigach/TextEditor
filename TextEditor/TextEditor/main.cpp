#include "Terminal/Terminal.h"
#include <cctype>
#include <cstdlib>
#include <ncurses.h>
#include <termios.h>
#include <unistd.h>
int main(int argc, char *argv[]) {
  Terminal terminal;
  terminal.start();
  return 0;
}
