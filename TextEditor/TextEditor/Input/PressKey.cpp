#include <cctype>
#include <ncurses.h>
void PressKey(int ch) {
  switch (ch) {
  case '\n':
  case '\r':
  case KEY_ENTER:
    printw("\n");
    break;
  case ' ':
    printw(" ");
    break;
  default:
    printw("%c", ch);
  }
  refresh();
}
