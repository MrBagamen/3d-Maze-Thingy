#ifndef CONFIG_HPP
#define CONFIG_HPP

#include <string>
#include <map>

class Config
{
public:
    Config();
    bool LoadFromFile(const std::string& filename);
    bool SaveToFile(const std::string& filename);
    bool GetBool(const std::string& key);
    bool GetFloat(const std::string & key);
private:
    std::map<std::string, std::string> map;
};

#endif // CONFIG_HPP
