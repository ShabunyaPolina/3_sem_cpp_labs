#ifndef LIST_VIEW_H
#define LIST_VIEW_H

#include <windows.h>
#include <sstream>
#include <string>

#include "bidirectional_list.h"

template <class T>
class ListView {
public:
	ListView(HWND hDlg, int listbox_id, const BidirectionalList<T>* list);
	void Update();
private:
	HWND _hDlg;
	int _listbox_id;
	const BidirectionalList<T>* _list;  // model
};

// constructor
template <class T>
ListView<T>::ListView(HWND hDlg, int listbox_id, 
	const BidirectionalList<T>* list)
	: _hDlg(hDlg), _listbox_id(listbox_id), _list(list) {}

// displays the list in the listbox
template <class T>
void ListView<T>::Update() {
	if (_listbox_id != 0 && _hDlg != NULL) {
		SendDlgItemMessage(_hDlg, _listbox_id, LB_RESETCONTENT, NULL, NULL);
		std::stringstream ss;
		std::string buf;
		ss << *_list;
		while (ss >> buf) {
			SendDlgItemMessage(_hDlg, _listbox_id, LB_ADDSTRING, NULL, (LPARAM)buf.c_str());
		}
	}
}

#endif  // LIST_VIEW_H
