#include "controller.h"

INT_PTR CALLBACK Controller::DlgProc(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	static BidirectionalList<int> list{ 1,2,3 };
	static ListView<int> lv(hDlg, IDC_LIST, &list);

	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		lv.Update();
		return (INT_PTR)TRUE;
	case WM_COMMAND:
		switch (wParam)
		{
		case IDCANCEL:
		case IDOK:
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		case IDC_BUTTON_PUSH_BACK:
		{
			int tmp = GetDlgItemInt(hDlg, IDC_EDIT, 0, 1);
			list.PushBack(tmp);
			lv.Update();
			break;
		}
		case IDC_BUTTON_PUSH_FRONT:
		{
			int tmp = GetDlgItemInt(hDlg, IDC_EDIT, 0, 1);
			list.PushFront(tmp);
			lv.Update();
			break;
		}
		case IDC_BUTTON_POP_BACK:
			list.PopBack();
			lv.Update();
			break;
		case IDC_BUTTON_POP_FRONT:
			list.PopFront();
			lv.Update();
			break;
		case IDC_BUTTON_CLEAR:
			list.Clear();
			lv.Update();
			break;
		}
	}
	return (INT_PTR)FALSE;
}
