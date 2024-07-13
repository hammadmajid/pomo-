#include <cstdlib>
#include <iostream>
#include <string>
#include <thread>

unsigned int remaining_seconds;

void timer() {
  using namespace std::chrono_literals;

  while (remaining_seconds != 0) {
    std::cout << remaining_seconds << "\n";
    remaining_seconds--;
    std::this_thread::sleep_for(1s);
  }
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Usage:\n\ttimer <seconds>" << std::endl;
    return EXIT_FAILURE;
  }

  remaining_seconds = abs(std::stoi(argv[1]));

  std::thread worker(timer);

  worker.join();

  return EXIT_SUCCESS;
}
