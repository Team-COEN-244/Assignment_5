#include <iostream> 
#include <string>
#include <vector>
#include <fstream>

using namespace std;
template <class T>

class array 
{
    private:
    int size;
    vector <T> vec;
    
    public: 

    array(int size=0)
    {
        this->size=size;
    }

    T operator[](int index)
    {
        return vec.at(index);
    }

    int getsize()
    {
        return size;
    }
    
    void push_back(T t)
    {
        vec.push_back(t);
        size++;
    }
};

int main()
{
    ofstream f("Template.txt");

    array<int> intarray(5);
    array<double> doublearray(5);
    array<string> stringarray(3);
    
    cout << "Enter data for integer array\n";
    for(int i=0; i<5; ++i)
    {
        cout << "Data: ";
        int n;
        cin >> n;
        intarray.push_back(n);
    }
    cout << "Please enter data for double array\n";
    for (int i=0; i<5; ++i)
    {
        cout << "Data: ";
        double n;
        cin >> doublearray.push_back(n);
    }
    cout << "Please enter data for string array\n:";
    for (int i=0; i<3; ++i)
    {
        cout << "Data: ";
        string n;
        cin >> n;
        stringarra.push_back(n);
    }

    cout << "Data integer array\n";
    for (int i=0; i<5; ++i)
    {
        cout << intsarray[i] << endl;
        f<<intarray[i]<< endl;
    }

    cout << "Double data array\n ";
    for (int i=0; i<5; ++i)
    {
        cout << doublearray[i] << endl;
        f<<doublearray[i]<<endl;
    }
    cout <<"Data string array\n";
    for (int i=0; i<3; ++i)
    {
        cout << stringarray[i]<< endl;
        f << stringarray[i] << endl;
        
    }

}
