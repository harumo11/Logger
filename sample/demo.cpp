#include <Logger/Logger.hpp>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char const* argv[])
{
	Logger console("test");

	console.changeStyle(Logger::StyleSet::INFO);
	console << "this is colorful info" << endl;
	console.changeStyle(Logger::StyleSet::WARN);
	console << "this is colorful warn" << endl;
	console.changeStyle(Logger::StyleSet::ERROR);
	console << "this is colorful error" << endl;
	console.changeStyle(Logger::StyleSet::CRITICAL);
	console << "this is colorful critical" << endl;


	//Progress bar(20,"title", 2);
	//for (int i = 0; i < 10; i++) {
	//	sleep(1);
	//	bar.show();
	//}
	return 0;
}
