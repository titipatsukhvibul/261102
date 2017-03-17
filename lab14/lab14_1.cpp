#include <iostream>

using namespace std;

struct rect {
  double x, y, w, h;
};

double overlap(rect rectA, rect rectB) {
  double yMax = min(rectB.y, rectA.y);
  double xMin = max(rectA.x, rectB.x);
  double xMax = min((rectA.x + rectA.w), (rectB.x + rectB.w));
  double yMin = max((rectA.y - rectA.h), (rectB.y - rectB.h));

  return (xMin < xMax && yMin < yMax) ? (yMax - yMin) * (xMax - xMin) : 0;
}

int main() {
  rect rectA;
  rect rectB;

  cin >> rectA.x >> rectA.y >> rectA.w >> rectA.h;
  cin >> rectB.x >> rectB.y >> rectB.w >> rectB.h;

  double overlapArea = overlap(rectA, rectB);

  cout << overlapArea << endl;
}