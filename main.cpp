#include "TreasureFinder.h"

int main() {
  // Store input values
  TreasureFinder t;
  int x;
  int y;

  // Ask the user for the starting and treasure point
  cout << "With spaces inbetween please enter the x and y value of the "
          "starting point and then the x and y for "
          "the treasure location:"
       << endl;
  cin >> t;

  // Ask the user for the starting point x value
  cout << "Enter the x value for your starting point: " << endl;
  cin >> x;

  // Ask the user for the starting point y value
  cout << "Enter the y value for your starting point: " << endl;
  cin >> y;

  // Call the recusive method
  t.mapper(x, y, "");

  // print out the results
  cout << t << endl;

  return 0;
}
