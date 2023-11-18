#ifndef WEATHERDATA_H
#define WEATHERDATA_H


#include <string>
#include <vector>



class WeatherData {
public:
    WeatherData(const std::string& filename);
    void readData();


private:
    std::string filename;




};

#endif 