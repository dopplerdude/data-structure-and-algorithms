#include <iostream>

using namespace std;

class student{
	private:.
		char* name;
		int age;
	
	public:
	student()
	{
		name = new char (10);
		name = "abcdefhij";
		age = 25;
	}
	
/*	student(student& s)
	{
		age = s.age;
		name = new char (10);
		strncpy(name, s.name, 10);
	}
*/
	char* getName()
	{
		return(name);
	}		

	int getAge()
	{
		return (age);
	}
}

int main()
{
	class student s1;

	class student s2(s1); // deep copy of s1

	cout << s2.age << " " << s2.name << endl;

	return(0);
}


