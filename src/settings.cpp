#include <settings.h>

Settings::Settings(const std::string application_name)
{
    std::string config_directory = getenv("HOME");
    if (config_directory == "") {
        config_directory = getpwuid(getuid())->pw_dir;
    }

    config_directory += "/.config/" + application_name + "/";

    try {
        std::filesystem::create_directory(config_directory);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    settings_file = config_directory + "settings.cfg";
}

std::string Settings::get(std::string key) {
    return items[key].get_value();
}

void Settings::add(std::string key, std::string value) {
    items[key] = Setting {key, value};
}

bool Settings::load() 
{
    std::ifstream in_stream;
    in_stream.open(settings_file);

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
    out_stream.open(settings_file);

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
