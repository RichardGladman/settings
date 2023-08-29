#ifndef SETTING_H
#define SETTING_H

#pragma once

#include <iostream>

class Setting
{
    friend std::ostream &operator<<(std::ostream &os, const Setting &setting);

public:
    Setting() = default;
    Setting(std::string key, std::string value);
    ~Setting() = default;

    std::string get_key() const; 
    std::string get_value() const;

private:
    std::string key;
    std::string value;
};

#endif
