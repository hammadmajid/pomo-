#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>

void timer(unsigned int *p_remaining_seconds) {
  using namespace std::chrono_literals;

  while (*p_remaining_seconds != 0) {
    std::cout << *p_remaining_seconds << "\n";
    *p_remaining_seconds -= 1;
    std::this_thread::sleep_for(1s);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage:\n\ttimer <seconds>" << std::endl;
    return EXIT_FAILURE;
  }

  const unsigned int SECONDS = abs(std::stoi(argv[1]));

  unsigned int remaining_seconds = SECONDS;
  auto *p_remaining_seconds = &remaining_seconds;

  std::thread timer_thread(timer, &remaining_seconds);

  bool done = false;
  while (!done) {

    char choice;
    std::cin >> choice;

    switch (choice) {
    case 'r':
      *p_remaining_seconds = SECONDS;
      break;
    case 'e':
      *p_remaining_seconds = 0;
      done = true;
    }
  }

  timer_thread.join();

  return EXIT_SUCCESS;
}
