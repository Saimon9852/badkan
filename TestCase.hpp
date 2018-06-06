#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class TestCase {
private:
    string testName;
    int passedTests;
    int count;
    int failedTests;
    ostream* err;
public:
     TestCase(string name,ostream& error);
     void print();

    template<typename T>
     TestCase check_equal(const T& b,const T& a){
         count++;
         if((T)b==(T)a)
             passedTests++;
        else {
             failedTests++;
             *err << testName << ": Failure in test #" << count << ": " << b << " should equal " << a << endl;
         }
         return *this;
    }

    template<typename T>
    TestCase check_different(const T& b,const T& a){
        count++;
        if((T)b==(T)a){failedTests++;  *err << testName << ": Failure in test #" << count << ": " << b << " should be different" << a << endl;}
        else passedTests++;
        return *this;
    }

    template<typename T>
    TestCase check_output(const T& a,const string& test){
        count++;
        ostringstream holder;
        holder << a;
        if(holder.str() != test) {
            *err << testName << ": Failure in test #" << count << ": string value should be " << test << " but  is "
                 << holder.str() << endl;
            failedTests++;
        } else
            passedTests++;
        return *this;
    }

    template<typename T,typename G,typename O>
    TestCase check_function(G f,const T& arg,const O& exep){
            count++;
            O tes = f(arg);
            if((O)tes != (O)exep) {
                *err << testName << ": Failure in test #" << count << ": Function should return " << exep
                     << " but returned " << tes << endl;
                failedTests++;
            }
            else
                passedTests++;
            return *this;
    }


};