    #include<bits/stdc++.h>
    typedef long long  ll;
     
    #define all(x) (x).begin() , (x).end()
    #define pb push_back
    #define yes cout << "YES\n"
    #define no cout << "NO\n"
    #define nope cout << "-1\n" ;
    #define pii pair<int,int>
    #define pll pair<ll,ll>
    #define SaveTime ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    #define endl "\n"
     
    using namespace std;
     
    const int INF = 1000*1000*1000; // 1 e 9
    const ll inf = (ll)1e18;
     
    const int N = 2e5+100 ;
     
    const int mod = 1e9+7 ;
     


class Point{
	private :
		int x , y ; 
	public : 
	Point(int x , int y) : x(x),y(y){

	}
	int getX(){
		return x ; 
	}
	int getY(){
		return y ; 
	}
	void setX(int x){
		this->x = x ;
	}
	void setY(int y){
		this->y = y ; 
	}
	string toString() const{
		ostringstream os ; 
		os << "( " << this->x << "," << this->y << " )" ;
		return os.str() ;   	
	}
};
     
class Shape{
	private : 
		int color ; 
	public : 
		Shape(int color) : color(color){

		}
		int getColor(){
			return color ; 
		}
		void setColor(int color){
			this->color = color ; 
		}
		virtual double computeArea() const{
			throw logic_error("you do not override it") ; 
			return -1.0 ; 
		}
		virtual void Draw() const{
			cout << "You are Drawing a Shape of area " << computeArea() << endl ; 
			return  ;
		}
		virtual Shape* clone(){
			throw logic_error("you do not override it") ; 
			return NULL ; 
		}
		virtual ~Shape(){
			cout << "~Shape" << endl ; 
		}
};

class Rectangle : public Shape{
	private : 
		Point top_left ; 
		Point bottom_right ; 
	public : 
		Rectangle(int color , const Point &top_left , const Point &bottom_right):Shape(color),top_left(top_left),bottom_right(bottom_right){

		}
		virtual double computeArea() const override{
			return 1110.0 ; 
		}
		virtual void Draw() const override{
			Shape::Draw() ; 
			cout << "Drawing Rectangle " << top_left.toString() << " " << bottom_right.toString() << endl ; 
			return ; 
		}
		virtual Shape* clone(){ // virtual copy constuctor ; 
			return new Rectangle(*this) ; 
		}
		virtual ~Rectangle(){
			cout << "~Rectangle" << endl ; 
		}
};

class Circle : public Shape{
	private : 
		Point center ;  
		double radiues ; 
	public : 
		Circle(int color , const Point &center , double radiues):Shape(color),center(center),radiues(radiues){

		}
		virtual double computeArea() const override{
			return 550.0 ; 
		}
		virtual void Draw() const override{
			Shape::Draw() ; 
			cout << "Drawing Rectangle " << center.toString() << endl ;  
			return ; 
		}
		virtual Shape* clone(){ // virtual copy constuctor ; 
			return new Circle(*this) ; 
		}
		virtual ~Circle(){
			cout << "~Circle" << endl ; 
		}
};

class ImageEditor{
	protected:
		vector<Shape*> shapes ;
	public:
		ImageEditor(){} ; 
		void AddShape(Shape &shape){
			shapes.push_back(shape.clone()) ; 
		} 
		void Draw() const{
			cout << "ImageEditor :: Drawing" << endl ; 
			for (auto shapePtr : shapes){
				shapePtr->Draw() ; 
			}
			return ; 
		}
		~ImageEditor(){
			cout << "AAAAAAAAAAAAAAAAAAAAAAAA" << endl ; 
			for (auto ptr : shapes){
				delete ptr ; 
			}
			shapes.clear() ; 
		}
};

class AdobeImageEditor: public ImageEditor {
public:
	void EnlargeShpaes(double percent) {
		for (auto shapePtr : shapes) {
			// Enlarge
		}
	}
};

void initalize(AdobeImageEditor* editor) {
	Circle c1(20, Point(8, 9), 3.5);
	Rectangle r1(10, Point(3, 4), Point(5, 6));
	editor->AddShape(r1);
	editor->AddShape(c1);
	return ; 
}

 
int main() {
	AdobeImageEditor* editor = new AdobeImageEditor();

	initalize(editor) ; 
	editor->Draw();
	delete editor;
	editor = nullptr;
	cout << "Bye" << endl ;
	return 0;
}