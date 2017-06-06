#include <iostream>
#include <cmath>
#include <vector>
#include "AnsiConsole.h"

struct Position{
  int x;
  int y;
  Position(int x_=0, int y_=0){ x=x_;y=y_;}
};

class Shape{
protected:
  Position _position;
  Colors _color;
public:
  Shape(int x, int y, Colors color) : _position(Position(x,y)), _color(color) {}
  virtual void draw() = 0;
  void nonVirtualMod_2(void);
  virtual void virtualMod_2(void) = 0;
  void nonVirtual(void);
  virtual ~Shape();
};

void Shape::nonVirtualMod_2(void) {
  std::cout << " Shape::nonVirtualMod_2 -> ";
  virtualMod_2();
}

void Shape::nonVirtual() {
  std::cout << "Shape::nonVirtual()" << std::endl;
}

Shape::~Shape() {

}

class Circle : public Shape {
protected:
  int       _radius;
public:
  Circle(int x=0, int y=0, int radius=0, Colors color = Colors::RED) : Shape(x, y, color), _radius(radius) {}
  void nonVirtual(void);
  virtual void virtualMod_2(void);
  virtual void draw();
};

void Circle::virtualMod_2() {
  std::cout << " Circle::virtualMod_2" << std::endl;
}

void Circle::nonVirtual() {
  std::cout << "Circle::nonVirtual" << std::endl;
}

void Circle::draw(){
  /* see https://de.wikibooks.org/wiki/Formelsammlung_Mathematik:_Geometrie
   * Höhensatz des Euklid
   * */
  int x_start = _position.x - _radius/2;
  int x_stop  = _position.x + _radius/2;

  for(int i=x_start; i<=x_stop; i++){
    double x_relative = double(i) - double(x_start);
    double h = sqrt(x_relative*(x_stop-x_start-x_relative));
    ansiConsole.printText(_position.x + int(x_relative)- _radius/2,
                          _position.y +h,"#",
                          _color);
    ansiConsole.printText(_position.x + int(x_relative)- _radius/2,
                          _position.y -h,"#",
                          _color);

  }
}

class Rectangle : public Shape{
protected:
  int       _height;
  int       _width;
public:
  Rectangle(int x=0, int y=0, int height=0, int width=0, Colors color = Colors::RED) : Shape(x, y, color), _height(height), _width(width) {}
  void nonVirtual(void);
  virtual void virtualMod_2(void);
  virtual void draw();
};

void Rectangle::virtualMod_2() {
  std::cout << " Rectangle::virtualMod_2" << std::endl;
}

void Rectangle::nonVirtual() {
  std::cout << "Rectangle::nonVirtual()" << std::endl;
}

void Rectangle::draw() {
  for(int i = _position.x; i <= (_position.x + _width); i++) {
    ansiConsole.printText(i, _position.y, "#", _color);
    ansiConsole.printText(i, _position.y + _height, "#", _color);
  }
  for(int i = _position.y; i <= (_position.y + _height); i++) {
    ansiConsole.printText(_position.x , i, "#", _color);
    ansiConsole.printText(_position.x + _width, i, "#", _color);
  }
}

class Scene {
private:
  std::vector<Shape*> _vecShape;
public:
  Scene();
  void addShape(Shape* s);
  void draw();
  ~Scene();
};

Scene::Scene() {

}

void Scene::addShape(Shape* s) {
  _vecShape.push_back(s);
}

void Scene::draw() {
  for(auto s : _vecShape) {
    s->draw();
  }
}

Scene::~Scene() {
  for(auto s : _vecShape) {
      delete s;
  }
  _vecShape.clear();
}

void invokeVirtually(Shape* theShape) {
  if(dynamic_cast<Rectangle*>(theShape) != NULL) {
    dynamic_cast<Rectangle*>(theShape)->nonVirtual();
  } else if(dynamic_cast<Circle*>(theShape) != NULL) {
    dynamic_cast<Circle*>(theShape)->nonVirtual();
  }
}

int main(int argc, char **argv)
{
  std::cout << std::endl;
  Shape* rectangle = new Rectangle(0,0,0,0,Colors::RED);
  Shape* circle = new Circle(0,0,0,Colors::RED);

  invokeVirtually(rectangle);
  invokeVirtually(circle);
  rectangle->nonVirtualMod_2();
  circle->nonVirtualMod_2();

  delete rectangle;
  delete circle;

  return 0;
}
