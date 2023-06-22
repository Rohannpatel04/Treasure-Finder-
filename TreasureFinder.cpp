// The implementation of the TresureFinder.h file
#include "TreasureFinder.h"

// Implementation of constructors
TreasureFinder::TreasureFinder() : x_(0), y_(0), tX_(0), tY_(0) {}
TreasureFinder::TreasureFinder(int x, int y, int tX, int tY) {
  x_ = x;
  y_ = y;
  tX_ = tX;
  tY_ = tY;
}

// Implementations of getters
int TreasureFinder::getX() const { return x_; }
int TreasureFinder::getY() const { return y_; }
int TreasureFinder::getTargetX() const { return tX_; }
int TreasureFinder::getTargetY() const { return tY_; }
string TreasureFinder::getPath() const { return path_; }
int TreasureFinder::getPathCount() const { return pathCount_; }

// Implementations of setters
void TreasureFinder::setX(int x) {}
void TreasureFinder::setY(int y) {}
void TreasureFinder::setTargetX(int tx) {}
void TreasureFinder::setTargetY(int ty) {}
void TreasureFinder::setPath(string path) {}
void TreasureFinder::setPathCount() { pathCount_++; }

// Implementations of recursive method
void TreasureFinder::mapper(int x, int y, string path) {
  // Base case (We have found the treasure) and also a checker for making sure
  // the robot does not move more than twice in the same direction.
  if (x == tX_ && y == tY_) {
    for (int i = 0; i < path.length() - 1; i++) {
      if (path.at(i) == path.at(i + 1)) {
        checkerCounter_++;
        if (checkerCounter_ == 2) {
          return;
        }

      } else {
        checkerCounter_ = 0;
      }
    }

    if (checkerCounter_ < 2) {
      paths_.push_back(path);
      setPathCount();
    }
  } else {
    // Robot moves North
    if (y < tY_) {
      mapper(x, y + 1, path + "N");
    }

    // Robot moves South
    if (y > tY_) {
      mapper(x, y - 1, path + 'S');
    }

    // Robot moves east
    if (x < tX_) {
      mapper(x + 1, y, path + 'E');
    }

    // Robot moves west
    if (x > tX_) {
      mapper(x - 1, y, path + 'W');
    }
  }
}

// Output all the possible paths and print out the number of paths
ostream &operator<<(ostream &output, const TreasureFinder &t) {
  cout << "All Possible Shortest Paths:" << endl;
  for (int i = 0; i < t.paths_.size(); i++) {
    output << t.paths_[i] << endl;
  }

  output << "Total Number Shortest Paths: " << t.getPathCount() << endl;

  return output;
}
// Inputs the starting and treasure points
istream &operator>>(istream &input, TreasureFinder &t) {
  input >> t.x_ >> t.y_ >> t.tX_ >> t.tY_;

  return input;
}
