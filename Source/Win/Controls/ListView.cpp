#include <algorithm>

#include "Platform.hpp"

#include "ListView.hpp"

namespace Goo
{
void ColumnHeader::SetTextAlignment(TextAlignment alignment_)
{
	alignment = alignment_;
	// TODO: actual handling
}
void ListView::CreateControl()
{
	CreateHandle(WC_LISTVIEW, LVS_EDITLABELS | LVS_REPORT, WS_EX_CLIENTEDGE);

	for (auto& column : columns)
	{
		DoAddColumn(column);
	}
	for (auto& item : items)
	{
		DoAddItem(item);
	}
}

void ListView::AddColumn(const ColumnHeader& column)
{
	if (IsCreated())
	{
		DoAddColumn(column);
	}

	columns.push_back(column);
}

void ListView::AddItem(const ListViewItem& item)
{
	if (IsCreated())
	{
		DoAddItem(item);
	}

	items.push_back(item);
}

void ListView::DoAddColumn(const ColumnHeader& column)
{
	int fmt;
	switch (column.GetTextAlignment())
	{
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

	const std::string& text = column.GetText();
	char* temp = new char[text.size() + 1];
	std::copy(text.cbegin(), text.cend(), temp);
	temp[text.size()] = '\0';

	LVCOLUMN lvc;
	lvc.mask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM;
	lvc.iSubItem = (int)columns.size();
	lvc.pszText = temp;
	lvc.cx = column.GetWidth();
	lvc.fmt = fmt;
	ListView_InsertColumn(GetHandle(), columns.size(), &lvc);

	delete[] temp;
}

void ListView::DoAddItem(const ListViewItem& item)
{
	const std::string& text = item.GetText();
	char* temp = new char[text.size() + 1];
	std::copy(text.cbegin(), text.cend(), temp);
	temp[text.size()] = '\0';

	LVITEM lvi;
	lvi.mask = LVIF_TEXT | LVIF_IMAGE | LVIF_PARAM | LVIF_STATE;
	lvi.iSubItem = 0;
	lvi.pszText = LPSTR_TEXTCALLBACK;
	lvi.state = 0;
	lvi.stateMask = 0;

	ListView_InsertItem(GetHandle(), &lvi);

	delete[] temp;
}
}
