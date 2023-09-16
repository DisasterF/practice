#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
  string temp;
  double sum = 0;
  double min = 1000000;
  double max = 0;
  int cnt = 0;
  vector<double> arr;
  while (cin >> temp) {
    bool have_unit, have_number = false;
    double v = 0;
    string unit;
    for (char i : temp) {
      if (int(i) <= int('9')) { // check if input contains number
        have_number = true;
      } else {             // check if input contains unit
        unit.push_back(i); // adding nonnumber to unit
        have_unit = true;
      }
    }
    if (have_number) {
      v = stod(temp); // extract value from temp
    } else {
      cout << "Input does not contain number.\n";
      break;
    } // preventing stod nonnumber
    if (have_unit == false) {
      cin >> unit;
    } // handling format of [number+' '+unit]

    cout << unit << "\n";
    if (unit == "cm") {
      v *= 0.01;
    } else if (unit == "m") {
    } else if (unit == "in") {
      v *= 2.54 * 0.01;
    } else if (unit == "ft") {
      v *= 12 * 2.54 * 0.01;
    } else {
      cout << "Invalid expression.\n";
      break;
    } // unit conversion and validation

    sum += v;
    cnt += 1;
    arr.push_back(v);
    if (v < min) {
      min = v;
    }
    if (v > max) {
      max = v;
    }
  }
  cout << "Sum is: " << sum << "\n";
  cout << "Smallest value is: " << min << "\n";
  cout << "Largest value is: " << max << "\n";
  cout << "Number of entries: " << cnt << "\n";
  sort(arr.begin(), arr.end());
  for (auto x : arr) {
    cout << x << ' ';
  }
  cout << "\n"; // output handling
}