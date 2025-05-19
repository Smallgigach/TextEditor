#include "Terminal.h"
#include "../Input/PressKey.h"
#include <cstdio>
#include <ncurses.h>
#include <stdlib.h>
#include <termios.h>
void Terminal::start() {

  initscr();
  cbreak();
  noecho();
  intrflush(stdscr, FALSE);
  printNumberChar();
  cursor();
  int ch;
  while ((ch = getch()) != 27) {
    PressKey(ch);
  }
  endwin();
};
void Terminal::printNumberChar() {
  int col, rows;
  getmaxyx(stdscr, rows, col);
  for (int i = 0; i < rows; ++i) {
    mvaddch(i, 0, '~');
  }
}
void Terminal::cursor() { move(0, 0); }
