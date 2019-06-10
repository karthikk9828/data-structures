#include <iostream>

using namespace std;

class employee {

	int eid;
	char name[20], dept[20];
	float basic_sal;

public:
	void get() {
		cout << "Enter EID, Name, Department, Basic Salary: ";
		cin >> eid >> name >> dept >> basic_sal;
	}

	void calculate() {
		basic_sal = basic_sal - (0.12 * basic_sal);
	}

	void display() {
		cout << "\nEID: " << eid << "\nName: " << name << "\nDepartment: " << dept << "\nSalary: " << basic_sal << "\n";
	}
};

int main()
{
	employee e;
	e.get();
	e.calculate();
	e.display();
	return 0;
}	