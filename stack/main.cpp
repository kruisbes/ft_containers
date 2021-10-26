#include "stack.hpp"
#include "../vector/vector.hpp"
#include <stack>
#include <vector>
#include <deque>

void stack_test_construct() {
	ft::vector<int> a(100, 100);
	std::deque<int> d(100, 100);
	ft::stack<int> b;
	ft::stack<int, ft::vector<int> > c(a);
	ft::stack<int, std::deque<int> > e(d);
	std::cout << b.size() << std::endl;
	std::cout << c.size() << std::endl;
	std::cout << e.size() << std::endl;
	std::cout << b.empty() << std::endl;
	std::cout << c.empty() << std::endl;
	std::cout << e.empty() << std::endl;
}

void stack_test_push_pop() {
	ft::stack<int> a;
	for (int i = 0; i < 1000; ++i) {
		a.push(i);
	}
	while (!a.empty()) {
		std::cout << a.top() << std::endl;
		a.pop();
	}
}

void stack_test_compare() {
	ft::stack<int> a;
	ft::stack<int> b;
	ft::stack<int> c;

	a.push(1);
	a.push(2);
	a.push(3);

	b.push(7);
	b.push(8);
	b.push(9);
	b.push(10);

	c.push(1);
	c.push(2);
	c.push(3);

	// Compare non equal containers
	std::cout << "a == b returns " << (a == b) << std::endl;
	std::cout << "a != b returns " << (a != b) << std::endl;
	std::cout << "a < b returns " << (a < b) << std::endl;
	std::cout << "a <= b returns " << (a <= b) << std::endl;
	std::cout << "a > b returns " << (a > b) << std::endl;
	std::cout << "a >= b returns " << (a >= b) << std::endl;

	std::cout << std::endl;

	// Compare equal containers
	std::cout << "a == c returns " << (a == c) << std::endl;
	std::cout << "a != c returns " << (a != c) << std::endl;
	std::cout << "a < c returns " << (a < c) << std::endl;
	std::cout << "a <= c returns " << (a <= c) << std::endl;
	std::cout << "a > c returns " << (a > c) << std::endl;
	std::cout << "a >= c returns " << (a >= c) << std::endl;


}

int main() {
	stack_test_construct();
	stack_test_push_pop();
	stack_test_compare();
}
