#ifndef SETTINGS_H
#define SETTINGS_H

#pragma once

#include <map>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include <setting.h>

const std::string SETTINGS_FILE {"Settings.cfg"};

class Settings
{
    friend std::ostream &operator<<(std::ostream &os, const Settings &settings);

public:
    Settings() = default;
    ~Settings() = default;

    std::string get(std::string key);
    void add(std::string key, std::string value);

    bool load();
    bool save();

private:
    std::map<std::string, Setting> items;

};

#endif
