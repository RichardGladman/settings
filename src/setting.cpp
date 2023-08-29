#include <setting.h>

std::ostream &operator<<(std::ostream &os, const Setting &setting)
{
    os << setting.key << ": " << setting.value << "\n";
    return os;
}

Setting::Setting(std::string key, std::string value): key {key}, value {value} {}

std::string Setting::get_key() const { return key; }
std::string Setting::get_value() const { return value; }
