#include <iostream>       // std::cout
#include <thread>         // std::thread, std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
using namespace std;

void pause_thread(int n)
{
	std::this_thread::sleep_for(std::chrono::seconds(n));
	std::cout << "pause of " << n << " seconds ended\n";
	std::cout << std::this_thread::get_id() << std::endl;
}

int main()
{
	std::cout << "Spawning and detaching 3 threads...\n";
	int i = 0;
	while (i < 3) {
		std::thread(pause_thread, 1).detach();
		std::thread(pause_thread, 2).detach();
		std::thread(pause_thread,0).detach();
		std::cout << "Done spawning threads.\n";
		i++;
	}


	std::cout << "(the main thread will now pause for 5 seconds)\n";
	// give the detached threads time to finish (but not guaranteed!):
	pause_thread(15);
	return 0;
}
