#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;
double nanos(void) {
  struct timespec ts;
  // timespec_get requires C++17 or later
  if (timespec_get(&ts, TIME_UTC) != TIME_UTC) {
    fputs("timespec_get failed!", stderr);
    return 0;
  }
  // Convert seconds to nanoseconds and add the nanoseconds part
  return 1000000000.0 * ts.tv_sec + ts.tv_nsec;
}

float prob_unique_birthday(int n_people, int n_simulations){
	int count_unique = 0;
	int birthdays[365];
  for (int i = 0; i < n_simulations;i++) {
		// simluate a group of n_people
		bool duplicate_found = false;
		memset(birthdays, 0, sizeof(birthdays)); // reset birthdays array
		for(int i = 0;i<n_people;i++){
			// check if birthday is unique
			int bday = rand() % 365;
			if(birthdays[bday] == 1){
				duplicate_found = true;
				break;

			}else{
				birthdays[bday] = 1;
			}
			if(duplicate_found) break;

		}

			if(!duplicate_found) count_unique++;
	}
	float res = (float)count_unique / (float)n_simulations;
	return res;
}
int main(){
  srand(time(NULL));
  float res = 0;
	double start = nanos();
  res = 1 - prob_unique_birthday(5, 100000000);
	double end = nanos();
	// cout time taken in seconds
	double time_taken = (end - start) / 1e9;

	cout << fixed << setprecision(9);
        cout << "Time taken by program is : " << time_taken << " sec" << endl;

        float exp_ans = 0.02714;
	cout << fixed << setprecision(5);
	cout << "Estimated probability: " << res << endl;

  cout << "Expected probability: " << exp_ans << endl;

  return 0;
}