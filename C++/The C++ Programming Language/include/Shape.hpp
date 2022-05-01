#include <iostream>
#include <vector>

using namespace std;

class Point {
  int x, y;
};

class Shape {
 public:
  Shape(const Shape&) = delete;
  Shape& operator=(const Shape&) = delete;  // no copy operations
  Shape(Shape&&) = delete;
  Shape& operator=(Shape&&) = delete;  // no move operations

  virtual Point center() const = 0;  // pure virtual
  virtual void move(Point to) = 0;
  virtual void draw() const = 0;  // draw on current "Canvas"
  virtual void rotate(int angle) = 0;
  virtual ~Shape() {}  // destructor
};

class Circle : public Shape {
 public:
  Circle(Point p, int rr);  // constructor
  Point center() const { return x; }
  void move(Point to) { x = to; }
  void draw() const;
  void rotate(int) {}  // nice simple algorithm

 private:
  Point x;  // center
  int r;    // radius
};

class Smiley : public Circle {  // use the circle as the base for a face public:
 public:
  Smiley(Point p, int r) : Circle{p, r}, mouth{nullptr} {}
  ~Smiley() {
    delete mouth;
    for (auto p : eyes) delete p;
  }
  void move(Point to);
  void draw() const;
  void rotate(int);
  void add_eye(Shape* s) { eyes.push_back(s); }
  void set_mouth(Shape* s);
  virtual void wink(int i);  // wink eye number i
 private:
  vector<Shape*> eyes;  // usually two eyes
  Shape* mouth;
};

void Smiley::draw() const {
  Circle::draw();
  for (auto p : eyes) p->draw();
  mouth->draw();
}

void rotate_all(vector<unique_ptr<Shape>>& v,
                int angle) {  // rotate v’s elements by angle degrees
  for (auto p : v) p->rotate(angle);
}

enum class Kind { circle, triangle, smiley };

class Triangle : public Shape {
 public:
  Triangle(Point p, Point q, Point r) {}
  Point center() const {}
  void move(Point to) {}
  void draw() const;
  void rotate(int) {}  // nice simple algorithm
};

unique_ptr<Shape> read_shape(
    istream& is) {  // read shape descriptions from input stream is
  // ... read shape header from is and ﬁnd its Kind k ...
  Kind k;
  switch (k) {
    case Kind::circle:
      // read circle data {Point,int} into p and r
      Point p;
      int r;
      return new Circle{p, r};
    case Kind::triangle:
      // read triangle data {Point,Point,Point} into p1, p2, and p3
      Point p1, p2, p3;
      return new Triangle{p1, p2, p3};
    case Kind::smiley:
      // read smiley data {Point,int,Shape,Shape,Shape} into p, r, e1 ,e2, and m
      Point p;
      int r;
      Circle *e1, *e2, *m;
      Smiley* ps = new Smiley{p, r};
      ps->add_eye(e1);
      ps->add_eye(e2);
      ps->set_mouth(m);
      return ps;
  }
}

void draw_all(vector<unique_ptr<Shape>> v) {}

void user() {
  vector<unique_ptr<Shape>> v;
  while (cin) v.push_back(read_shape(cin));
  draw_all(v);        // call draw() for each element
  rotate_all(v, 45);  // call rotate(45) for each element
}  // all Shapes implicitly destroyed