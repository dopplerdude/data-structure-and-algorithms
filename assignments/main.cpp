#include <iostream>

using namespace std;
int main(void)
{
	cout << "------------------------------------" << endl;
	int j = 10, k = 20;
	int& a = j;
	const int& b = 5;
	const int& c = j+k;
	cout << "a = " << a << " " << "b = " << b << " " << "c = " << c << endl;	

	cout << "Enter number " << endl;
	while (cin >> j)
	{
		try
		{
			if(j < 20)
			{
				throw runtime_error ("Number less than 20");
			}
			else
			{
				throw runtime_error ("Number greater than 20");
			}
			// throw breaks the execution flow and jumps to first matching exception handler
			cout << "Can someone print me??" << endl;
		}

		catch(runtime_error err)
		{
			cout << err.what() << endl;
			cout << "Try Again? Enter y or n" << endl;
			char c;
			cin >> c;
			if(!cin || c == 'n')
				break;
		}
		cout << "Enter number " << endl;
	}

	cout << "********* END ************" << endl;
	return(0);
}
