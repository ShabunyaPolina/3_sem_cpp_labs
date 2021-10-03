#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <Windows.h>

#include "resource.h"
#include "list_view.h"

class Controller {
public:
	static INT_PTR CALLBACK DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam);
};

#endif // CONTROLLER_H
