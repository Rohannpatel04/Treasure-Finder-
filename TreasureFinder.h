// The header file for the tresure finder program
#include <iostream>
#include <vector>
using namespace std;
#include <utility>

class TreasureFinder {
  friend ostream &operator<<(ostream &output, const TreasureFinder &t);
  friend istream &operator>>(istream &input, TreasureFinder &t);

 public:
  // Constructors
  TreasureFinder();
  TreasureFinder(int x, int y, int tX, int tY);

  // Getters
  int getX() const;
  int getY() const;
  int getTargetX() const;
  int getTargetY() const;
  string getPath() const;
  int getPathCount() const;

  // Setters
  void setX(int x);
  void setY(int y);
  void setTargetX(int tX);
  void setTargetY(int y);
  void setPath(string path);
  void setPathCount();

  // Mapper method definition
  void mapper(int x, int y, string path);

 private:
  int x_;
  int y_;
  int tX_;
  int tY_;
  string path_;
  int pathCount_ = 0;
  vector<string> paths_;
  int checkerCounter_ = 0;
};
