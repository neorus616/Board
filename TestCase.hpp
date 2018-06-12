#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class TestCase {
    private:
        string test_name;
        ostream &out;
        uint fail, pass, total;
    public:
        TestCase(string nme, ostream& os): test_name(nme), out(os), fail(0), pass(0), total(0) {}

        void print() {
            cout << fail << " failed " << pass << " passed " << total  << " total " << endl;
        }

        template<typename T> TestCase& check_equal(T x, T y){
            total++;
            if (x == y){
                pass++;
                // out << test_name << " Passed" << endl;
            }
            else {
                fail++;
                out << test_name << ": Failure in test #" << total << " " << x << " should equal" << " " << y << " !" << endl;
            }
            // print();
            return *this;
        }

        template<typename T> TestCase& check_different(T x, T y) {
            total++;
            if (x != y){
                pass++;
                // out << test_name << " Passed" << endl;
            }
            else {
                fail++;
                out << test_name << ": Failure in test #" << total << " " << x << " should not equal" << " " << y << " !" << endl;
            }
            // print();
            return *this;
        }

        template<typename T> TestCase& check_output(T x, string str) {
            total++;
            stringstream st; 
            st << x;
            if (st.str() == str){
                pass++;
                // out << test_name << " Passed" << endl;
            }
            else {
                fail++;
                out << test_name << ": Failure in test #" << total << " string value should be " << str << " but is " << st.str() << endl;
            }
            // print();
            return *this;
        }

        template<typename func, typename T, typename U> TestCase& check_function(func f,T t, U u) {
            total++;
            U res = f(t);
            if (res == u){
                pass++;
                // out << test_name << " Passed" << endl;
            }
            else {
                fail++;
                out << test_name << ": Failure in test #" << total << " Function should return " << u << " but returned " << res << endl;
            }
            // print();
            return *this;
        }

};