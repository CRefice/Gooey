#include <algorithm>

#include "Platform.hpp"
#include "Filedialog.hpp"

namespace Goo
{
OpenFileDialog::OpenFileDialog(const std::string& text, const std::string& filter) : text(text), filter(filter) {}

DialogResult OpenFileDialog::ShowDialog()
{
	std::string filterCopy(filter);
	std::replace(filterCopy.begin(), filterCopy.end(), '|', '\0');
	filterCopy += '\0';
	filterCopy += '\0';

	OPENFILENAME ofn;
	::ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = NULL;
	ofn.lpstrFile = filename;
	ofn.lpstrFile[0] = '\0';
	ofn.nMaxFile = sizeof(filename);
	ofn.lpstrFilter = filterCopy.c_str();
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.lpstrTitle = text.c_str();
	ofn.nMaxFileTitle = 0;
	ofn.lpstrInitialDir = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	return (::GetOpenFileName(&ofn) == TRUE) ? DialogResult::OK : DialogResult::Cancel;
}

std::string OpenFileDialog::GetFileName() const
{
	return std::string(filename);
}

void OpenFileDialog::SetText(const std::string & text_)
{
	text = text_;
}

void OpenFileDialog::SetFilter(const std::string & filter_)
{
	filter = filter_;
}
}
