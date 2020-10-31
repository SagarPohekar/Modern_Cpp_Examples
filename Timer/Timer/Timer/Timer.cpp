#include "Timer.h"

using namespace std::chrono_literals;

template<typename ...Args>
class Timer
{
public:
  Timer(std::function<void(Args...)> func, std::chrono::milliseconds step, Args&&... args)
    : m_callback{ func },
    m_args{ std::forward<Args>(args)... },
    m_time{ step },
    m_stop{ false }
  {
    this->start();
  }

  ~Timer() { stop(); puts(__func__); }

  void stop() { m_stop = true; }

private:
  void start()
  {
    auto callback = [this]() {
      while (!this->m_stop)
      {
        std::apply(m_callback, this->m_args);
        std::this_thread::sleep_for(this->m_time);
      }
    };

    m_executer = std::thread{ callback };
    m_executer.detach();
  }

private:
  std::function<void(Args...)> m_callback;
  std::thread m_executer;
  std::tuple<Args...> m_args;
  std::chrono::milliseconds m_time;
  bool m_stop;
};

template<typename Func, typename ...Args>
Timer(Func, std::chrono::milliseconds, Args&&...) -> Timer<Args...>;

int main()
{
  // Create a timer
  auto timer = Timer([](int a, int b, float c) { std::cout << a + b + c << '\n'; }, 500ms, 15, 17, 12.0f);

  // Stop timer after 10s
  bool running{ true };
  std::thread{ [&]() { std::this_thread::sleep_for(10s); timer.stop(); running = false; } }.join();
  size_t n{ 0 };

  // Simulate long running process
  //while (running) n += 1;
  return 0;
}