#pragma once

#include "Dialog.hpp"

namespace Goo
{
enum class MessageBoxButtons
{
	AbortRetryIgnore, OK, OKCancel, RetryCancel, YesNo, YesNoCancel
};

enum class MessageBoxIcon
{
	Asterisk, Error, Exclamation, Hand, Information, None, Question, Stop, Warning
};

namespace MessageBox
{
	DialogResult Show(const std::string& text, const std::string& title,
		MessageBoxIcon icon = MessageBoxIcon::None, MessageBoxButtons buttons = MessageBoxButtons::OK);
};
}
