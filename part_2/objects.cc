#include <iostream>
#include <cmath>

class Shape {
public:
  virtual void shift(float dx, float dy) = 0;
  virtual float area() const = 0;
};

class Rect : public Shape {
  float x, y, w, h;
public:
  Rect(float const x, float const y, float const w, float const h)
    : x(x), y(y), w(w), h(h) {}

  void shift(float dx, float dy) override {
    x += dx;
    y += dy;
  }

  float area() const override {
    return w*h;
  }
};

class Circ : public Shape {
  float x, y, r;
public:
  Circ(float const x, float const y, float const r)
    : x(x), y(y), r(r) {}

  void shift(float dx, float dy) override {
    x += dx;
    y += dy;
  }

  float area() const override {
    return M_PI*r*r;
  }
};

Shape const & smaller(Shape const & s0, Shape const & s1) {
  return s0.area() < s1.area() ? s0 : s1;
}

float test() {
  Circ c{0.f, 0.f, 1.f};
  Rect r{0.f, 0.f, 2.f, 2.f};
  return smaller(c,r).area();
}

int main() {
  std::cout << test() << std::endl;
}
