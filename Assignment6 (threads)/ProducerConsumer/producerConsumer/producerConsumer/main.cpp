#include <queue>
#include <thread>
#include <iostream>
#include <mutex>
#include <condition_variable>

int c = 0;
std::queue<int> goods;

std::mutex myMutex;
std::condition_variable flag;
bool producedItem = false;

void producer() {
	std::cout << "Start producting items... \n" << std::endl;

	for (int i = 0; i < 500; ++i) {
		std::lock_guard<std::mutex> guard(myMutex);//lock operations on the goods queue
		goods.push(i);
		c++;

		producedItem = true;
	}

	std::this_thread::sleep_for(std::chrono::seconds(2));//producing items takes time you know :P
	flag.notify_one();//release
}

void consumer() {
	if (!producedItem) {
		std::cout << "Waiting for items to consume \n";
		std::unique_lock<std::mutex> lock(myMutex);
		flag.wait(lock);//wait until producer is not performing operations on the goods queue
	}

	while (!goods.empty()) {
		goods.pop();
		c--;
	}
}

int main() {
	std::thread producerThread(producer);
	std::thread consumerThread(consumer);

	producerThread.join();
	consumerThread.join();
	std::cout << "Net: " << c << std::endl;

	std::cin.get();
	return 0;
}