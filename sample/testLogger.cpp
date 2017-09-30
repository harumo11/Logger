#include <Logger/Logger.hpp>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char const* argv[])
{
	std::cout << Logger::info() << "this is info " << std::endl;
	std::cout << Logger::warn() << "this is warn " << std::endl;
	std::cout << Logger::error() << "this is error " << std::endl;
	std::cout << Logger::critical() << "this is critical " << std::endl;

	Logger console("test");

	console.changeStyle(0);
	console << "this is cool ostream info" << endl;
	console.changeStyle(1);
	console << "this is cool ostream warn" << endl;

	cout << "ここから下は出力されない" << endl;
	console.enabled = false;
	console.changeStyle(2);
	console << "this is cool ostream error" << endl;
	console.changeStyle(3);
	console << "this is cool ostream critical" << endl;
	cout << "ここから再び出力" << endl;

	console.changeStyle(Logger::StyleSet::ERROR);
	console.enabled = true;
	console << "this is cool ostream error" << endl;
	console.changeStyle(Logger::StyleSet::CRITICAL);
	console << "this is cool ostream critical" << endl;

	cout << Logger::bold() << "this is bold" << endl;
	cout << Logger::charColor(Logger::ColorSet::perple) << "this is perple and bold" << endl;
	cout << Logger::remove();

	Progress bar(20,"title", 2);
	for (int i = 0; i < 10; i++) {
		sleep(1);
		bar.show();
	}
	return 0;
}
