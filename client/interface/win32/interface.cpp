#include <string>
#include <windows.h>

// Display a message
void message_box(string message) {
  MessageBox(NULL, L"MySecurity", L"KLMBOX", MB_OK);
}
