#include <windows.h>

#include "resource.h"
#include "controller.h"

int APIENTRY WinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPSTR lpCmdLine,
	_In_ int nCmdShow) {
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_MAIN_DIALOG), NULL, Controller::DlgProc);
	return 0;
}
