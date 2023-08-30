# Settings

C++ library to manage program settings.

## Installation

Run the following commands

```
git clone https://github.com/RichardGladman/settings.git
cd settings
mkdir build
cd build
cmake ..
make
sudo make install
```

## Usage

Using the setting library is very simple. Example code:

CMakeLists.txt

```
cmake_minimum_required(VERSION 3.27)

project(test-lib)

find_package(settings REQUIRED)

add_executable(test-lib main.cpp)
target_include_directories(test-lib PRIVATE /usr/local/include/settings)
target_link_libraries(test-lib PRIVATE settings::settings_lib)

```

main.cpp

```
#include <iostream>
#include <string>
#include <settings.h>
#include <memory>

void input_settings(std::shared_ptr<Settings> settings)
{
    std::string key {};
    std::string value {};

    std::cout << "Enter Settings\n\n";

    do {
        std::cout << "Enter setting name: ";
        getline(std::cin, key);
        if (key != "done") {
            std::cout << "Enter setting value: ";
            getline(std::cin, value);
            settings->add(key, value);
        }

    } while (key != "done");

}

int main()
{
    std::shared_ptr<Settings> settings = std::make_shared<Settings>("test-lib");
    if (!settings->load()) {
        std::cout << "Failed to load settings" << std::endl;
    } else {
        std::cout << *settings << std::endl;
        return 0;
    }

    input_settings(settings);

    if (!settings->save()) {
        std::cout << "Failed to save settings" << std::endl;
        return 1;
    }

    return 0;
}
```
