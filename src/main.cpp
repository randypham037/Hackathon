#include <iostream>
#include <fstream>

using namespace std;

int GetWet(string weatherFile)  {   //read percipitation value from file  
   ifstream inWeather;  
   string date; //temp val to hold date
   string hot; //temp val to hold temperature
   string humid; // temp val to hold humidity
   double wet; //val to hold percipitation
   bool fileFail = false;
   int getWet = 0;
   
   //Open file and test if open
   cout << "Opening file " << weatherFile << endl;
   
   inWeather.open(weatherFile);
   if (!inWeather.is_open())  {
      cout << "Could not open " << weatherFile << endl;
      fileFail = true;
   }
   
   //ending program due to failure
   if (fileFail) {
      return -69420;
   }
   
   //reading values from files
   while(!inWeather.eof()) {
      inWeather >> date;
      inWeather >> hot;
      inWeather >> humid;
      inWeather >> wet;

        if (wet > 0.5)  {
        ++getWet; //days of enough rainfall
        }

   }
   
   //Done with file
   cout << "Closing file " << weatherFile << endl;
   inWeather.close();
   return getWet;
}
   

int main() {
   string weatherFile;
   int dayCnt = 0; //days of enough rain
   int waterDay = 0; //days to water lawn
   double wet = 0; //percipitation value
   
   cout << "Enter name of weather file: ";
   cin >> weatherFile;

  
    dayCnt = GetWet(weatherFile);
    if(dayCnt == -69420){
        cout << "Terminating Program" << endl;
        return EXIT_FAILURE;

    }


   //Find how many days to water
   if (dayCnt <= 0)  {
      waterDay = 3; //cout suggested: sprinkler will water on monday wednesday and friday
   }
   else if (dayCnt <= 3)  {
      waterDay = 2; //cout suggested: sprinkler will water on tuesday and friday
   }
   else  {
      waterDay = 0; //cout suggested: sprinkler will not run this week
   }
   
   // cout << dayCnt << endl; //FIXME
   cout << "Water your lawn for " << waterDay << " days." << endl;
   
   //output instructions
   if (waterDay == 0)  {
      cout << "Suggested to not water lawn this week." << endl;
   }
   else if (waterDay == 2)  {
      cout << "Suggested to water lawn on Tuesday and Friday." << endl;
   }
   else if (waterDay == 3)  {
      cout << "Suggested to water lawn on Monday, Wednesday, and Friday." << endl;
   }
   
   return 0;
}
