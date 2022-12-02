#include <windows.h>
#include <string>

// Display a message
void message_box(string message)
{
	MessageBox(NULL, L"MySecurity", L"KLMBOX", MB_OK);
}
