#pragma once

#include <functional>

namespace Goo
{
template<typename ...Args>
class Event
{
public:
	Event() : handler([](Args...) {}) {}
	Event(const std::function<void(Args...)>& handler) : handler(handler) {}

	void SetHandler(const std::function<void(Args...)>& handler_)
	{
		handler = handler_;
	}

	void operator()(Args... args) { handler(args...); }

private:
	std::function<void(Args...)> handler;
};

//The following are some utility event arguments
struct CancelToken
{
	bool cancel = false;
};
}
