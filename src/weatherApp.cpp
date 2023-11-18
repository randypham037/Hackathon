#include <string>
#include <vector>

class WeatherData {
public:
    WeatherData(const std::string& filename);
    void readData();

private:
    std::string filename;
    std::vector<std::string> data; 
};