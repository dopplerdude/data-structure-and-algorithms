#include <iostream>
#include <cstring>

using namespace std;

class mystring{
    char* str;
    size_t size;
public:
    mystring():str(nullptr), size(0)
    {
        cout << "Default constructor" << endl;
        str = new char[1];
        str[0] = '\0';
    }
 
    mystring(const char* new_string)
    {
        cout << "Parameterized constructor : string parameter" << endl;
        size = strlen(new_string);
        str = new char[size + 1]; 
        if(str == nullptr)
        {
            throw runtime_error("Error: Not enough memory!");
        }
        strncpy(str, new_string, size);
        str[size] = '\0';
    }

    mystring(const mystring& obj)
    {
        cout << "Copy constructor" << endl;
        size = obj.size;
        str = new char[size+1];
        
        if(str == nullptr)
        {
            throw runtime_error("Error: Not enough memory!");
        }
        strncpy(str, obj.str, size);
        str[size] = '\0';
    }

    mystring& operator()(const mystring& obj)
    {
        cout << "Parantheses operator" << endl;        

        // Check for self copy
        if(this == &obj)
        {
            cout << "Self-copy!!" << endl;
            return(*this);
        }

        delete [] str;
        size = obj.size;
        str = new char [size+1];
        if(str == nullptr)
        {
            throw runtime_error("Error: Not enough memory!");
        }
        strncpy(str, obj.str, size);
        str[size] = '\0';

        return(*this);        
    }

    mystring& operator=(const mystring& obj)
    {
        cout << "Assignment operator" << endl;        

        // check for self-copy
        if(this == &obj)
        {
            cout << "Self-copy!!" << endl;
            return(*this);
        }

        delete []str;
        size = obj.size;
        str = new char[size+1];
        if(str == nullptr)
        {
            throw runtime_error("Error: Not enough memory!");
        }
        strncpy(str, obj.str, size);
        str[size] = '\0';

        return(*this);
    }

    mystring& operator=(const char* new_string)
    {
        cout << "Assignment operator : string" << endl;        
        
        delete []str;

        size = strlen(new_string);
        str = new char[size+1];
        if(str == nullptr)
        {
            throw runtime_error("Error: Not enough memory!");
        }
        strncpy(str, new_string, size);
        str[size] = '\0';

        return(*this);
    }

 friend ostream& operator<< (ostream& os, const mystring& obj); 
};

ostream& operator<< (ostream& os, const mystring& obj)
{
    os << obj.str;
    return(os);
}

int main(void)
{
     cout << "***************" << endl;
    mystring str1;
    cout << "***************" << endl;
    mystring str2 = "Apple";
     cout << "***************" << endl;
    mystring str3("Mango");
    cout << "***************" << endl;
    mystring str4(str2);
    cout << "***************" << endl;
    mystring str5 = str3;
    cout << "***************" << endl;
    str1 = str2;
    cout << "***************" << endl;
    str2 = "Banana";
    cout << "***************" << endl;
    str3(str2);
    str5(str5);
    str5 = str5;
    cout << "str1 = " << str1 << endl; 
    cout << "str2 = " << str2 << endl; 
    cout << "str3 = " << str3 << endl; 
    cout << "str4 = " << str4 << endl; 
    cout << "str5 = " << str5 << endl; 

       
    return(0);
}