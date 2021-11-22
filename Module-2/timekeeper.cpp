#include <iostream>
#include <string>

using namespace std;

// Structure represeting time
struct timeCont {
  int hour;
  int minute;
  int second;
  string period;
};

// Increment the referenced time by one second
void tick(timeCont &toTick)
{
  if (toTick.second == 59) {
    toTick.second = 0;
    if (toTick.minute == 59) {
      toTick.minute = 0;
      if (toTick.hour == 12) {
        toTick.hour = 1;
      }
      else if (toTick.hour == 11){
        if (toTick.period == "AM") {
          toTick.period = "PM";
        } 
        else {
          toTick.period = "AM";
        }
        toTick.hour++;
      } 
      else {
        toTick.hour++;
      }
    } 
    else {
      toTick.minute++;
    }
  } 
  else {
    toTick.second++;
  }
}

// takes two times, returns the number of seconds between them
int diff(timeCont startTime, timeCont endTime){
  int diffSeconds = endTime.second - startTime.second;
  int diffMinutes = endTime.minute - startTime.minute;
  int diffHours = endTime.hour - startTime.hour; 
  int totalSeconds = diffSeconds + (diffMinutes * 60) + (diffHours * 3600);
  if (startTime.period == endTime.period){
    if(totalSeconds >= 0){
      return totalSeconds;
    }
    else{
      return (86400 + totalSeconds);
    }
  }
  else{
    return (43200 + totalSeconds);
  }
}

int main(){
   timeCont localTime = { 11, 58, 58, "AM"};
   int ticks;
   cout <<  "How many ticks? ";
   cin >> ticks;
   cout << localTime.hour << ":" << localTime.minute << ":" << localTime.second << " " << localTime.period << '\n';
   for(int j = 0; j < ticks; j++){
   tick(localTime);
   cout << localTime.hour << ":" << localTime.minute << ":" << localTime.second << " " << localTime.period << '\n';
   }
   cout << '\n';
  
   timeCont timeOne = { 5, 29, 03, "AM"};
   timeCont timeTwo = { 9, 12, 24, "AM"};
   timeCont timeThree = { 3, 46, 02, "PM"};
   timeCont timeFour = { 8, 37, 16, "PM"};
   timeCont timeFive = { 1, 16, 52, "AM"};
  
   cout << "The difference between the times is " << diff(timeOne, timeTwo) << " Seconds\n";
   cout << "The difference between the times is " << diff(timeOne, timeThree) << " Seconds\n";
   cout << "The difference between the times is " << diff(timeOne, timeFour) << " Seconds\n";
   cout << "The difference between the times is " << diff(timeOne, timeFive) << " Seconds\n";
   return(0);
}
