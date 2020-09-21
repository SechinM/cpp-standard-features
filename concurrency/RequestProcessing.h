#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <thread>

class RequestProcessing
{
	enum class Status
	{
		newRequest,
		processed,
		waiting
	};
	std::mutex req_;
	std::condition_variable reqCheck_;
	Status status_ = Status::waiting;

public:
	void Processor()
	{
		std::unique_lock<std::mutex> ul(req_);
		reqCheck_.wait(ul, [=]() {
			return status_ == Status::newRequest;
		});
		std::cout << std::this_thread::get_id() << " - Processed" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(3));
		status_ = Status::processed;
		reqCheck_.notify_one();
	}

	void Sender()
	{
		{
			std::lock_guard<std::mutex> lg(req_);
			status_ = Status::newRequest;
			std::cout << std::this_thread::get_id() << " - New request" << std::endl;
			reqCheck_.notify_one();
		}

		std::unique_lock<std::mutex> ul(req_);
		reqCheck_.wait(ul, [=]() {
			return status_ == Status::processed;
		});
		std::cout << std::this_thread::get_id() << " - Waiting" << std::endl;
		status_ = Status::waiting;
		ul.unlock();
	}
};