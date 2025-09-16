#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
using namespace std;

float prob_unique_birthday(int n_people, int num_simulations){
	int count_unique = 0;
  for (int i = 0; i < num_simulations;i++) {
		// simluate a group of n_people
		int birthdays[n_people];
		bool unique = true;
		for(int i = 0;i<n_people;i++){
			birthdays[i] = rand() % 365;
			// check if birthday is unique
			for(int j =0;j<i;j++){
				if(birthdays[i] == birthdays[j]){
					unique = false;
					break;
				}
			}
			if(!unique) break;

		}
		if(unique) count_unique++;
  }
	float res = (float)count_unique / (float)num_simulations;
	return res;
}
int main(){
  srand(time(NULL));
  float res = 0;
  res = 1 - prob_unique_birthday(5, 100000000);

  float exp_ans = 0.02714;
	cout << fixed << setprecision(5);
	cout << "Estimated probability: " << res << endl;

  cout << "Expected probability: " << exp_ans << endl;

  return 0;
}
