# Logger documentation
Logger can display your log colorfully.

## Install

	cd Logger
	mkdir build
	cd build
	cmake ../
	make
	sudo make install


## Usage

### Include

```cpp
#include <Logger/Logger.hpp>
```

### CMakeLists.txt

```cmake
cmake_minimum_required(VERSION 3.5)
add_definitions("-std=c++11)
add_executable(your_program your_program.cpp)
target_link_libraries(your_program Logger)
```

### sample

see sample/sample.cpp


