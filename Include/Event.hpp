#pragma once

#include <functional>

namespace Goo
{
template<typename ...Args>
class Event
{
public:
  using FuncType = std::function<void(Args...)>;

  Event() : handler([](Args...) {}) {}
  Event(FuncType handler) : handler(handler) {}

  void SetHandler(FuncType handler_)
  {
  	handler = handler_;
  }

  void operator()(Args... args) { handler(args...); }

private:
  FuncType handler;
};

//The following are some utility event arguments
struct CancelToken
{
  bool cancel = false;
};
}
