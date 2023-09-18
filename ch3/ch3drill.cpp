#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
  string temp;
  double sum = 0;
  int cnt = 0;
  bool have_unit, have_number, validity;
  vector<double> arr;
  while (cin >> temp) {
    if (temp == "terminate") {
      break;
    }
    have_unit = false;
    have_number = false;
    validity = true;
    double v = 0;
    string unit;
    for (char i : temp) {
      if ((int(i) <= int('9')) && (int(i) >= int('0')) ||
          (int(i) == int('.'))) { // check if input contains number
        have_number = true;
        if (have_unit == true) {
          if (validity) {
            cout << "Error: Number after unit.\n";
          }
          validity = false;
        }
      } else {             // check if input contains unit
        unit.push_back(i); // adding nonnumber to unit
        have_unit = true;
      }
    }
    if (have_number && validity) {
      v = stod(temp); // extract value from temp
    } else if (have_number == false) {
      cout << "Error: input does not contain any numbers.\n";
      validity = false;
    } // preventing stod nonnumber
    if (have_unit == false) {
      cin >> unit;
    } // handling format of [number+' '+unit]

    if (unit == "cm") {
      v *= 0.01;
    } else if (unit == "m") {
    } else if (unit == "in") {
      v *= 2.54 * 0.01;
    } else if (unit == "ft") {
      v *= 12 * 2.54 * 0.01;
    } else {
      cout << "Error: Invalid unit.\n";
      validity = false;
    } // unit conversion and validation

    if (validity) {
      sum += v;
      cnt += 1;
      arr.push_back(v);
    }
  }
  sort(arr.begin(), arr.end());
  cout << "Sum is: " << sum << "\n";
  if (cnt > 0) {
    cout << "Smallest value is: " << arr[0] << "\n";
    cout << "Largest value is: " << arr[cnt - 1] << "\n";
  }
  cout << "Number of entries: " << cnt << "\n";

  for (auto x : arr) {
    cout << x << ' ';
  }
  cout << "\n"; // output handling
}