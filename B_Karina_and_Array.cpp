#include<iostream>
#include<vector>
using namespace std;

class ClassA {
public:
	ClassA() {
		cout<<"ClassA Constructor\n";
	}
};

class ClassB {
private:
	ClassA aa;
	int x;
public:
	ClassB(int x) {
		this->aa = ClassA();
		this->x = x;
	}
};

class ClassC {
private:
	int &y;
	ClassB bb;

public:
	ClassC(int &y, const ClassB &bb) : y(y) , bb(bb){
	}
    int gety(){
        return y ; 
    }
};


int main() {
	int hello = 10;
	ClassB b(5);
	ClassC cc(hello, b);
    hello = 1 ;
    cout << cc.gety() << endl ; 
	return 0;
}
