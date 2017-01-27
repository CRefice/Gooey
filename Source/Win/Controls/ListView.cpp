#include <algorithm>

#include "Platform.hpp"

#include "ListView.hpp"

namespace goo
{
void ListView::createControl() {
	createHandle(WC_LISTVIEW, NULL, LVS_EDITLABELS | LVS_REPORT, WS_EX_CLIENTEDGE);
	for (auto& column : _columns) {
		doAddColumn(column);
	}
	for (auto& item : _items) {
		doAddItem(item);
	}
}

void ListView::addColumn(ColumnHeader column) {
	doAddColumn(column);
	_columns.push_back(std::move(column));
}
void ListView::addItem(ListViewItem item) {
	doAddItem(item);
	_items.push_back(std::move(item));
}

void ListView::doAddColumn(const ColumnHeader& column) {
	int fmt;
	switch (column.textAlignment()) {
	case TextAlignment::Center:
		fmt = LVCFMT_CENTER;
		break;

	case TextAlignment::Left:
		fmt = LVCFMT_LEFT;
		break;

	case TextAlignment::Right:
		fmt = LVCFMT_RIGHT;
		break;
	}

	const std::string& text = column.text();
	char* temp = new char[text.size() + 1];
	std::copy(text.cbegin(), text.cend(), temp);
	temp[text.size()] = '\0';

	LVCOLUMN lvc;
	lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	lvc.iSubItem = (int)(_columns.size());
	lvc.pszText = temp;
	lvc.cx = column.width();
	lvc.fmt = fmt;
	ListView_InsertColumn(handle(), _columns.size(), &lvc);

	delete[] temp;
}

void ListView::doAddItem(const ListViewItem& item) {
	const std::string& text = item.text();
	char* temp = new char[text.size() + 1];
	std::copy(text.cbegin(), text.cend(), temp);
	temp[text.size()] = '\0';

	LVITEM lvi;
	lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM | LVIF_STATE;
	lvi.iSubItem = 0;
	lvi.pszText = LPSTR_TEXTCALLBACK;
	lvi.state = 0;
	lvi.stateMask = 0;
	ListView_InsertItem(handle(), &lvi);

	delete[] temp;
}

void ColumnHeader::setTextAlignment(TextAlignment alignment) {
	_alignment = alignment;
	// TODO: actual handling
}
}
