#include <iostream>
using namespace std;


int main(void)
{
    cout << "***************" << endl;
    string str1;
    cout << "***************" << endl;
    string str2 = "Apple";
    cout << "***************" << endl;
    string str3("Mango");
    cout << "***************" << endl;
    string str4(str2);
    cout << "***************" << endl;
    string str5 = str3;
    cout << "***************" << endl;
    str1 = str2;
    cout << "***************" << endl;
    str2 = "Banana";
    
    cout << "str1 = " << str1 << endl; 
    cout << "str2 = " << str2 << endl; 
    cout << "str3 = " << str3 << endl; 
    cout << "str4 = " << str4 << endl; 
    cout << "str5 = " << str5 << endl; 
    
    return(0);
}