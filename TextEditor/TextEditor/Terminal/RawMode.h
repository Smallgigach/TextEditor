#pragma once
#include <termios.h>
#include <unistd.h>
class RawMode {
private:
  static struct termios term;

public:
  RawMode() { enableRawMode(); }
  ~RawMode() {
    if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &term) == -1) {
      die("tcsetattr");
    }
  }
  void enableRawMode();
  void die(const char *s);
};
