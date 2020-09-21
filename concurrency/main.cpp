#include "RequestProcessing.h"
#include <thread>

int main()
{
	RequestProcessing processing;
	std::thread process(&RequestProcessing::Processor, std::ref(processing));
	std::thread send(&RequestProcessing::Sender, std::ref(processing));
	process.join();
	send.join();
	return 0;
}