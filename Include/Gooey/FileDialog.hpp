#pragma once

#include "Dialog.hpp"

namespace Goo
{
class OpenFileDialog
{
public:
	OpenFileDialog(const std::string& text, const std::string& filter);

	DialogResult ShowDialog();
	std::string GetFileName();

	void SetText(const std::string& text);
	std::string GetText() { return text; }
	void SetFilter(const std::string& filter);
	std::string GetFilter() { return filter; }

private:
	std::string text;
	std::string filter;
	char filename[0x500];
};
}
