#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
using namespace std;


class Object{
	public:
		virtual string getClassName() const = 0 ;
		virtual ~Object(){

		}
}; 

class Printable : virtual public Object{
	public:
		virtual void print() const = 0 ; 
		virtual ~Printable(){} ; 
}; 

class Cloneable : virtual public Object{
	public:
		virtual Object* clone() const = 0 ; 
		virtual ~Cloneable(){

		}
};

class Comparabile : virtual public Object{
	public:
		virtual bool compare(Object* obj) const = 0 ;
		virtual ~Comparabile(){

		} 
};

class Sortable : virtual public Object{
	public : 
		virtual void sort() = 0 ; 
		virtual ~Sortable(){

		}
};

class Payble : public Printable , public Cloneable , public Comparabile{
	public:
		virtual double pay() const = 0 ; 
		~Payble(){

		}
};

class Employee : public Payble{
	private:
		string name ; 
		double salary ; 
	public:
		Employee(double salary , string name) : salary(salary) , name(name){

		}
		virtual void print() const override{
			cout << "Employyee : " << name << " " << salary << endl ; 
			return ; 
		}
		virtual double pay() const override{
			return salary ; 
		}
		virtual bool compare(Object* another_emloyee) const override{
			Employee* ptr = dynamic_cast<Employee*>(another_emloyee) ; 
			if (ptr)
				return tie(salary,name)<tie(ptr->salary,ptr->name) ; 
			return false ; 
		}
		virtual string getClassName() const override{
			return "Employee" ; 
		}
		virtual Object* clone() const override{
			return new Employee(*this) ; 
		}
};

class Invoice : public Payble{
	private:
		double salary ; 
	public:
		Invoice(double salary) : salary(salary){

		}
		virtual void print() const override{
			cout << "Invoice : " << salary << endl ; 
			return ; 
		}
		virtual double pay() const override{
			return salary ; 
		}
		virtual bool compare(Object* another_Invoice) const override{
			Invoice* ptr = dynamic_cast<Invoice*>(another_Invoice) ; 
			if (ptr)
				return salary<ptr->salary ; 
			return false ; 
		}
		virtual string getClassName() const override{
			return "Invoice" ; 
		}
		virtual Object* clone() const override{
			return new Invoice(*this) ; 
		}
};

bool compare(Payble* p1 , Payble* p2){
	if (p1->getClassName() !=p2->getClassName()){
		return p1->getClassName()<p2->getClassName() ; 
	}
	return p1->compare(p2); 
}

class CompanyPayroll : public Sortable , public Printable{
	private : 
		vector<Payble*> paybles ; 
	public : 
		CompanyPayroll(){}
		CompanyPayroll (const CompanyPayroll&) = delete;
		CompanyPayroll& operator= (const CompanyPayroll&) = delete;
		void AddPayable(const Payble& payble){
			paybles.push_back(dynamic_cast<Payble*>(payble.clone())) ; 
		}
		virtual string getClassName() const override{
			return "CompanyPayroll" ; 
		}
		virtual void sort() override{
			std :: sort(paybles.begin(),paybles.end(),compare); 
		}
		virtual void print() const override{
			double total = 0 ; 
			for (const Payble* p: paybles){
				p->print() ; 
				total+=p->pay() ; 
			}
			cout << "Total to pay : " << total << endl ; 
			return ; 
		}
		virtual ~CompanyPayroll(){
			for (auto payable : paybles)
				delete payable;
			paybles.clear();
		}
};

int main() {
	CompanyPayroll payroll;
	payroll.AddPayable(Employee(50, "mostafa"));
	payroll.AddPayable(Invoice(200));
	payroll.AddPayable(Employee(10, "ziad"));
	payroll.AddPayable(Invoice(100));
	payroll.AddPayable(Employee(30, "belal"));
	payroll.AddPayable(Invoice(300));

	payroll.sort();
	payroll.print();	
	return 0;
}
