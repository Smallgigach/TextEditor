#pragma once
#include <unistd.h>
#define CTRL_KEY(k) ((k) & 0x1f)

class Editor {
public:
  Editor() {};

public:
  char editorReadKey();
  void editorProcessKeyPress();
  void editorRefreshScreen();
  void editorDrawRows();
};
