#include <settings.h>

std::string Settings::get(std::string key) {
    return items[key].get_value();
}

void Settings::add(std::string key, std::string value) {
    items[key] = Setting {key, value};
}

bool Settings::load() 
{
    std::ifstream in_stream;
    in_stream.open(SETTINGS_FILE);

    if (!in_stream) {
        return false;
    }

    std::string line {};
    std::string key {};
    std::string value {};

    while (std::getline(in_stream, line)) {
        std::stringstream str_stream(line);
        str_stream >> key >> value;
        add(key, value);
    }

    in_stream.close();

    return true;

}

bool Settings::save() 
{
    std::ofstream out_stream;
    out_stream.open(SETTINGS_FILE);

    if (!out_stream) {
        return false;
    }

    for (auto const& [key, val]: items) {
        out_stream << key << " " << val.get_value() << std::endl;
    }

    out_stream.close();

    return true;
}


std::ostream &operator<<(std::ostream &os, const Settings &settings) 
{
    std::map<std::string, Setting>::iterator it;

    for (auto const& [key, val]: settings.items) {
        os << key << ": " << val.get_value() << std::endl;
    }

    return os;
}
