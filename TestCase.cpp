#include "TestCase.hpp"

// void print() {
//     cout << out << " Total: " << TestCase::total <<
// }
// template<typename T> TestCase check_equal(T x, T y){
//     total++;
//     if (x == y){
//         pass++;
//         out << test_name << " Passed" << endl;
//     }
//     else {
//         fail++;
//         out << test_name << " Failed" << endl; 
//     }
//     return this;
// }

// template<typename T> TestCase check_different(T x, T y) {
//     total++;
//     if (x != y){
//         pass++;
//         out << test_name << " Passed" << endl;
//     }
//     else {
//         fail++;
//         out << test_name << " Failed" << endl;
//     }
//     return this;
// }

// template<typename T> TestCase check_output(T x, string str) {
//     total++;
//     string st << x;
//     if (st.compare(str) == 0){
//         pass++;
//         out << test_name << " Passed" << endl;
//     }
//     else {
//         fail++;
//         out << test_name << " Failed" << endl;
//     }
//     return this;
// }

// template<typename func, typename T, typename U> TestCase check_function(func f,T t, U u) {
//     total++;
//     if (f(t) == u){
//         pass++;
//         out << test_name << " Passed" << endl;
//     }
//     else {
//         fail++;
//         out << test_name << " Failed" << endl;
//     }
//     return this;
// }