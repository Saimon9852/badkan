#include <string>
#include <iostream>
using namespace std;

class TestCase {
private:
    string testName;
    int passedTests;
    int count;
    int failedTests;
    ostream err;
public:
     TestCase(string name,ostream& error);

    template<typename T>
     TestCase check_equal(T b,T a){
         count++;
         if(b!=a)  err << testName << ": Failure in test #" << count << ": " << b << "should equal " << a << endl;
         return *this;
    }

    template<typename T>
    TestCase check_different(T b,T a){
        count++;
        if(b==a) err<< err << testName << ": Failure in test #" << count << ": " << b << "should be different" << a << endl;
        return *this;
    }

    template<typename T>
    TestCase check_output(T a,string test){
        count++;
        ostream holder;
        holder << a;
        if(holder.str() != test)
            err << testName << ": Failure in test #" << count << ": string value should be " << test << "but  is returned " << holder.str() << endl;
        return *this;
    }

    template<typename T,typename G>
    TestCase check_function(T arg,G exep){
            count++;
            G tes = f(arg);
            if(tes != exep)
                err << testName << ": Failure in test #" << count << ": Function should return " << exep << "but returned " << tes << endl;
            return *this;
    }

    void print(){

    }
};