#include <Logger/Logger.hpp>
#include <iostream>
#include <unistd.h>

using namespace std;

int main(int argc, char const* argv[])
{
	Progress bar(20,"title", 2);
	for (int i = 0; i < 10; i++) {
		sleep(1);
		bar.show();
	}
	return 0;
}
