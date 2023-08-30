#ifndef SETTINGS_H
#define SETTINGS_H

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <pwd.h>
#include <unistd.h>
#include <filesystem>

#include <setting.h>

class Settings
{
    friend std::ostream &operator<<(std::ostream &os, const Settings &settings);

public:
    Settings() = default;
    Settings(const std::string application_name);
    ~Settings() = default;

    std::string get(std::string key);
    void add(std::string key, std::string value);

    bool load();
    bool save();

private:
    std::pair<std::string, std::string> split_first(const std::string to_split, const char split_on);
    std::map<std::string, Setting> items;

    std::string settings_file;

};

#endif
