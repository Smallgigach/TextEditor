#pragma once
#include <termios.h>
#include <unistd.h>
class Terminal {
public:
  void start();

private:
  void printNumberChar();
  void cursor();
};
