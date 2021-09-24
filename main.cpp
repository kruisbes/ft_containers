#include "vector.hpp"
#include <vector>
#include <iostream>

int main() {
    std::vector<int> a(5,10);
    std::vector<int> c(2, 7);
    ft::vector<int> b(5, 10);
    ft::vector<int> d(2, 7);

    a.assign(c.begin(), c.end());
    b.assign(d.begin(), d.end());

    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    a.push_back(7);
    a.push_back(8);
    a.push_back(9);
    a.push_back(10);
    a.push_back(11);
    a.push_back(12);

    b.push_back(5);
    b.push_back(6);
    b.push_back(7);
    b.push_back(7);
    b.push_back(8);
    b.push_back(9);
    b.push_back(10);
    b.push_back(11);
    b.push_back(12);

    a.insert(a.begin() + 5, 6, 90);
    b.insert(b.begin() + 5, 6, 90);

    a.insert(a.begin() + 10, 789);
    b.insert(b.begin() + 10, 789);
    a.insert(a.begin() + 10, 789);
    b.insert(b.begin() + 10, 789);
    a.insert(a.begin() + 10, 789);
    b.insert(b.begin() + 10, 789);
    a.insert(a.begin() + 10, 789);
    b.insert(b.begin() + 10, 789);


    std::vector<int> e(5, 10);
    ft::vector<int> f(5, 10);

    a.insert(a.begin() + 2, e.begin(), e.end());
    b.insert(b.begin() + 2, f.begin(), f.end());

    a.insert(a.end(), 5);
    b.insert(b.end(), 5);

    a.insert(a.end(), 5, 10);
    b.insert(b.end(), 5, 10);

    a.reserve(70);
    b.reserve(70);
    a.reserve(50);
    b.reserve(50);

    a.resize(10, 5);
    b.resize(10, 5);

    a.resize(60, 60);
    b.resize(60, 60);

    a.resize(80, 60);
    b.resize(80, 60);


    std::vector<int>::iterator ita = a.begin();
    std::vector<int>::iterator itae = a.end();
    std::cout << "| std | -> size: " << a.size() << " capacity: " << a.capacity() << std::endl;
    while (ita != itae) {
        std::cout << *ita << " ";
        ita++;
    }
    std::cout << std::endl;
    ft::vector<int>::iterator itb = b.begin();
    ft::vector<int>::iterator itbe = b.end();
    std::cout << "| ft | -> size:  " << b.size() << " capacity: " << b.capacity() << std::endl;
    while (itb != itbe) {
        std::cout << *itb << " ";
        itb++;
    }
    std::cout << std::endl;
}
