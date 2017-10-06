#include <iostream>
#include <cmath>
#include <variant>

struct Rect {
  float x, y, w, h;
};

void shift(Rect & rect, float dx, float dy) {
  rect.x += dx;
  rect.y += dy;
}

float area(Rect const & rect) {
  return rect.w * rect.h;
}

struct Circ {
  float x, y, r;
};

void shift(Circ & circ, float dx, float dy) {
  circ.x += dx;
  circ.y += dy;
}

float area(Circ const & circ) {
  return M_PI*circ.r*circ.r;
}

template<typename Shape0, typename Shape1, typename Cont>
auto on_smaller(Shape0 & s0, Shape1 & s1, Cont cont) {
  return area(s0) < area(s1) ? cont(s0) : cont(s1);
}

float test() {
 Circ c{0.f, 0.f, 1.f};
 Rect r{0.f, 0.f, 2.f, 2.f};
 return on_smaller(c,r, [](auto s){return area(s);});
}

using Shape = std::variant<Rect, Circ>;

float area(Shape const & s) {
  return std::visit([](auto const & s){ return area(s); }, s);
}

Shape const & smaller(Shape const & s0, Shape const & s1) {
  return area(s0) < area(s1) ? s0 : s1;
}

float test_new() {
 Circ c{0.f, 0.f, 1.f};
 Rect r{0.f, 0.f, 2.f, 2.f};
 return area(smaller(c,r));
}

int main() {
  std::cout << test() << std::endl;
  std::cout << test_new() << std::endl;
}
