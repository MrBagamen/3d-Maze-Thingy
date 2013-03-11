#include "Config.hpp"

#include <fstream>
#include <iostream>

Config::Config()
{
    map["anisotropic"] = "true";
}

bool Config::LoadFromFile(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file)
    {
        return false;
    }

    std::string key, discard, value;

    while (file >> key >> discard >> value)
    {
        map[key] = value;
    }

    return true;
}

bool Config::SaveToFile(const std::string& filename)
{
    std::ofstream file(filename);

    if (!file)
    {
        return false;
    }

    for (const auto & pair : map)
    {
        file << pair.first << " = " << pair.second << '\n';
    }

    return true;
}

bool Config::GetBool(const std::string& key)
{
    return map[key] == "true";
}

bool Config::GetFloat(const std::string & key)
{
    return map[key] == "true";
}
