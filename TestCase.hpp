#pragma once
#include <iostream>
#include <string>
using namespace std;

class TestCase {
    private:
        string test_name;
        ostream &out;
        uint fail, pass, total;
    public:
        TestCase(string nme, ostream& os): test_name(nme), out(os), fail(0), pass(0), total(0) {} 
        void print() {
            out << " Total: " << total << endl << "Passed: " << pass << endl << "Failed: " << fail << endl;
        }

        template<typename T> TestCase check_equal(T x, T y){
            total++;
            if (x == y){
                pass++;
                out << test_name << " Passed" << endl;
            }
            else {
                fail++;
                out << test_name << " Failed" << endl; 
            }
            return this;
        }

        template<typename T> TestCase check_different(T x, T y) {
            total++;
            if (x != y){
                pass++;
                out << test_name << " Passed" << endl;
            }
            else {
                fail++;
                out << test_name << " Failed" << endl;
            }
            return this;
        }

        template<typename T> TestCase check_output(T x, string str) {
            total++;
            string st; 
            st << x;
            if (st.compare(str) == 0){
                pass++;
                out << test_name << " Passed" << endl;
            }
            else {
                fail++;
                out << test_name << " Failed" << endl;
            }
            return this;
        }

        template<typename func, typename T, typename U> TestCase check_function(func f,T t, U u) {
            total++;
            if (f(t) == u){
                pass++;
                out << test_name << " Passed" << endl;
            }
            else {
                fail++;
                out << test_name << " Failed" << endl;
            }
            return this;
        }

};