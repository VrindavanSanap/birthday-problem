#include <iostream>
#include <cstdio>   // For fputs, stderr
#include <ctime>    // For timespec, timespec_get, TIME_UTC
#include <iomanip>  // For std::fixed and std::setprecision
          //
double nanos(void)
{
  struct timespec ts;
  // timespec_get requires C++17 or later
  if (timespec_get(&ts, TIME_UTC) != TIME_UTC)
  {
    fputs("timespec_get failed!", stderr);
    return 0;
  }
  // Convert seconds to nanoseconds and add the nanoseconds part
  return 1000000000.0 * ts.tv_sec + ts.tv_nsec;
}


float prob_unique_birthday(int n){
  // gives probability that two people share the same
  // birthday given n people
  float res = 1;
  for(int i = 0;i<n;i++){
  float num = 365 - i;
  float den = 365;
  res *= (num / den);
  }
  return res;
}
int main(){
 double start = nanos(); 
  for (int i = 5; i<=90; i+=5){
  float res = 1 - prob_unique_birthday(i);
  std::cout << i << " " << std::fixed << std::setprecision(5) << res << std::endl;
  }
  double end = nanos();
  // time taken in seconds
  double time_taken = (end - start) / 1e9;
  std::cout << "Time taken by program is : " << std::fixed << std::setprecision(9) << time_taken << " sec" << std::endl;

  
  start = nanos();
  for (int i = 21; i<25; i+=1){
  float res = 1 - prob_unique_birthday(i);
  std::cout << i << " " << std::fixed << std::setprecision(5) << res << std::endl;
  }
  end = nanos();
  // time taken in seconds
  time_taken = (end - start) / 1e9;
  std::cout << "Time taken by program is : " << std::fixed << std::setprecision(9) << time_taken << " sec" << std::endl;

  return 0;
}
