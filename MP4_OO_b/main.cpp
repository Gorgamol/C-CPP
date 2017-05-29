//  file main_mp4_OO_b.cpp
#include <iostream>
#include <cassert>

//=======================================

struct FooVal {
    FooVal(int initialValue=0);
    ~FooVal();
private:
    int _someValue;
};

//=======================================

class FooBase {
    FooVal _value;
public:
    FooBase();
    FooBase(int initialValue);
    virtual ~FooBase();
};

//=======================================

class FooDerived : public FooBase {
  int _ival;
public:
    FooDerived(int initialValue);
    ~FooDerived();
};

//=======================================

class Bar {
    FooBase *_helperObject;
public:
    Bar();
    ~Bar();
};

//=======================================

FooVal::FooVal(int initialValue)
: _someValue(initialValue)
{
    std::cout << "FooVal::FooVal()" << std::endl;
}

FooVal::~FooVal(){
    std::cout << "FooVal::~FooVal()" << std::endl;
}

FooBase::FooBase(){
    std::cout << "FooBase::FooBase()" << std::endl;
}

FooBase::FooBase(int initialValue)
: _value(initialValue)
{
    std::cout << "FooBase::FooBase(int)" << std::endl;
}

FooBase::~FooBase(){
    std::cout << "FooBase::~FooBase(" << std::endl;
}

FooDerived::FooDerived(int initialValue)
: FooBase(initialValue), _ival(0)
{
    std::cout << "FooDerived::FooDerived()" << std::endl;
}

FooDerived::~FooDerived(){
    std::cout << "FooDerived::~FooDerived()" << std::endl;
}

Bar::Bar(){
    _helperObject =  new FooDerived(0);
}

Bar::~Bar(){
    delete _helperObject;
}


struct StackObject {
private:
    void* operator new(size_t size) noexcept {
        bool noStackObjectOnHeap = false;
        assert(noStackObjectOnHeap);
        return nullptr;
    }
};


struct A : public StackObject {
    A(){std::cout << "+A ";}
    A(const A&){std::cout << "+A";}
    ~A(){std::cout << "-A ";}
};

struct B : public StackObject {
    B(){std::cout << "+B ";}
    //B(const B&){std::cout << "+B";}
    ~B(){std::cout << "-B ";}
};


struct C : public StackObject {
    C(){std::cout << "+C ";}
    //C(const C&){std::cout << "+C";}
    ~C(){std::cout << "-C ";}
};

class HeapObject{
public:
    void*   operator new (size_t size);
    HeapObject();
    virtual ~HeapObject();
    static bool assertionsHold();
protected:
private:
    static int ctorCount;
    static int dtorCount;
    static int newCount;
    //    static void remove(HeapObject *);
    HeapObject(const HeapObject&) = delete;
    HeapObject& operator=(const HeapObject&) = delete;
};

int HeapObject::ctorCount = 0;
int HeapObject::dtorCount = 0;
int HeapObject::newCount  = 0;

void*   HeapObject::operator new (size_t size){
    newCount++;
    return new char[size];
}

HeapObject::HeapObject(){
    ctorCount++;
}

HeapObject::~HeapObject(){
    dtorCount++;
}

bool HeapObject::assertionsHold(){
    assert(ctorCount == newCount);   // all objects have been allocated on heap
    assert(ctorCount == dtorCount);  // all objects have been deleted
    return true;
}


class K : public HeapObject
{
public:
  K(){std::cout << "+K ";}
    ~K(){std::cout << "-K ";}
};

class M : public K {
public:
  B b;
    M(){std::cout << "+M ";}
    ~M(){std::cout << "-M ";}
};

class L : public M {
public:
  L(){std::cout << "+L ";}
  ~L(){std::cout << "-L ";}
};

B AtoB(A a) {
  B b;
  return b;
}

void pattern1() {
  std::cout << "\npattern1()" << std::endl;
 B b;
 {
   C c;
 }
 A a;
}

void pattern2() {
  std::cout << "\npattern2()" << std::endl;
  B b;
  C c;
  A a;
}

void pattern3() {
  std::cout << "\npattern3()" << std::endl;
  A a1;
  AtoB(a1);
  C c;
}

int main(int argc, const char * argv[]) {
  /*Bar * bar = new Bar();
  // ...
  delete bar; // implies "delete _helperObject";

  FooBase *obj = new FooDerived(7);
  delete obj;

  {
    C c;
    K* k = new K();
    delete k;
  }*/

  /*pattern1();
  std::cout << std::endl;
  pattern2();
  std::cout << std::endl;
  pattern3();
  std::cout << std::endl;
  std::cout << std::endl;
  L* p1 = new L();
  delete p1;
  std::cout << std::endl;
  L* p2 = new L();
  delete p2;*/

  K* p1;
 {
   A a;
    {
      B b;
      p1 = new K();
    }
    delete p1;
 }

 std::cout << std::endl;

 {
   A a;
   L* p2 = new L();
      delete p2;
   std::cout << " \nHello World \n";

 }


  HeapObject::assertionsHold();
  std::cout << "ENDE" << std::endl;
  return 0;
}
