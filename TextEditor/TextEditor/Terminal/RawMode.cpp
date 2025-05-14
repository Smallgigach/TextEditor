#include "RawMode.h"
#include <cstdio>
#include <cstdlib>
#include <termios.h>
#include <unistd.h>
struct termios RawMode::term;
void RawMode::enableRawMode() {
  if (tcgetattr(STDIN_FILENO, &term) == -1) {
    die("tcgetattr");
  }
  struct termios raw = term;
  raw.c_iflag &= ~(BRKINT | INPCK | ISTRIP | ICRNL | IXON);
  raw.c_oflag &= ~(OPOST);
  raw.c_cflag |= (CS8);
  raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG); // ICANON считывает по байтно
  raw.c_cc[VTIME] = 1;
  raw.c_cc[VMIN] = 0;

  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
};
void RawMode::die(const char *s) {
  perror(s);
  exit(1);
}
