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
  virtual void draw() = 0;
  virtual double area() = 0;
  virtual ~Shape();
};

Shape::~Shape() {

}

class ColoredShape : public Shape {
public:
  int amountPaintNeeded();
  int amountPaintNeeded(int height, int width);
  int amountPaintNeeded(int radius);
  int amountPaintNeeded(int length, bool x);
  virtual void draw() = 0;
  virtual double area() = 0;
  virtual ~ColoredShape();
};

int ColoredShape::amountPaintNeeded() {
  return 1;
}

int ColoredShape::amountPaintNeeded(int height, int width) {
  return (2 * height) + (2 * width) - 4;
}

int ColoredShape::amountPaintNeeded(int radius) {
  int x_start = _position.x - radius/2;
  int x_stop  = _position.x + radius/2;
  int amountPaintNeeded = 0;
  for(int i=x_start; i<=x_stop; i++){
    amountPaintNeeded += 2;
  }
  return amountPaintNeeded;
}

int ColoredShape::amountPaintNeeded(int length, bool x) {
  return length;
}

ColoredShape::~ColoredShape() {

}

class Line : public ColoredShape {
protected:
  int _length;
public:
  Line(int x = 0, int y = 0, int length = 0, Colors color = Colors::RED);
  virtual void draw();
  virtual double area();
};

Line::Line(int x, int y, int length, Colors color) {
  _position = Position(x,y);
  _color = color;
  _length = length;
  std::cout << "Line amount paint needed: " << ColoredShape::amountPaintNeeded(_length, true) << std::endl;
}

double Line::area() {
  return 0;
}

void Line::draw() {
  for(int i = _position.x; i < (_position.x + _length); i++) {
    ansiConsole.printText(i, _position.x, "-", _color);
  }
}

class Point : public ColoredShape {
public:
  Point(int x=0, int y=0, Colors color = Colors::RED);
  virtual void draw();
  virtual double area();
};

Point::Point(int x, int y, Colors color){
  _position = Position(x,y);
  _color = color;
  std::cout << "Point amount paint needed: " << ColoredShape::amountPaintNeeded() << std::endl;
}

double Point::area() {
  return 0;
}

void Point::draw(){
  ansiConsole.printText(_position.x,_position.y,"*", _color);
}

class Circle : public ColoredShape {
protected:
  int       _radius;
public:
  Circle(int x=0, int y=0, int radius=0, Colors color = Colors::RED);
  virtual void draw();
  virtual double area();
};

Circle::Circle(int x, int y, int radius, Colors color){
  _position = Position(x,y);
  _color = color;
  _radius=radius;
  std::cout << "Circle amount paint needed: " << ColoredShape::amountPaintNeeded(_radius) << std::endl;
}

double Circle::area() {
  return M_PI * (_radius * _radius);
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

class Rectangle : public ColoredShape {
protected:
  int       _height;
  int       _width;
public:
  Rectangle(int x=0, int y=0, int height=0, int width=0, Colors color = Colors::RED);
  virtual double area();
  virtual void draw();
};

Rectangle::Rectangle(int x, int y, int height, int width, Colors color) {
  _position = Position(x,y);
  _height = height;
  _width = width;
  _color = color;
  std::cout << "Rectangle amount paint needed: " << ColoredShape::amountPaintNeeded(_height, _width) << std::endl;

}

double Rectangle::area() {
  return _height * _width;
}

void Rectangle::draw() {
  for(int i = _position.x; i < (_position.x + _width); i++) {
    ansiConsole.printText(i, _position.y, "#", _color);
    ansiConsole.printText(i, _position.y + _height - 1, "#", _color);
  }
  for(int i = _position.y; i < (_position.y + _height); i++) {
    ansiConsole.printText(_position.x , i, "#", _color);
    ansiConsole.printText(_position.x + _width - 1, i, "#", _color);
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

int main(int argc, char **argv)
{
  // x=0 and y=0 is the upper left corner
  // x and y are more like column and row
  /*ansiConsole.printText(5,5,"Hello, World!");

  Point* p = new Point(10,10);
  p->draw();

  Point* p2 = new Point(2,10);
  p2->draw();


  Circle* c = new Circle(30, 15, 10);
  c->draw();

  Point* p3= new Point(30,15);
  p3->draw();


  delete p;
  delete p2;
  delete p3;
  delete c;*/
  std::cout << std::endl;

  Shape* p = new Point(30 ,15,Colors::BLUE);
  Shape* c = new Circle(15,10,10, Colors::YELLOW);
  Shape* r = new Rectangle(25,8,4,4,Colors::GREEN);
  Shape* l = new Line(15, 45 ,5, Colors::RED);

  std::cout << "Circle: "<< c->area() << " Rectangle: " << r->area() << " Line: " << l->area() << " Point " << p->area() << std::endl;

  delete p;
  delete c;
  delete r;
  delete l;


  return 0;
}
