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
// maybe output:
// Done spawning threads.
// Done spawning threads.
// Done spawning threads.
// (the main thread will now pause for 5 seconds)
// pause of 0 seconds ended
// 26120pause of 0 seconds ended
// 24972

// pause of 0 seconds ended
// 7340
// pause of pause of 1 seconds ended
// 668
// 1 seconds ended
// 24116
// pause of 1 seconds ended
// 25080
// pause of 2 seconds ended
// 26448
// pause of 2 seconds ended
// 20236
// pause of 2 seconds ended
// 23556
// pause of 15 seconds ended
// 25836
