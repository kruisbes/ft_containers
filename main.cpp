#include "vector.hpp"
#include <vector>
#include <iostream>
#include <map>


int main() {
//	ft::vector<char> a;
//	ft::vector<char> b(5);
//	ft::vector<char> c(5, 10);
//	ft::vector<char> d(5, 10, std::allocator<char>());
//	ft::vector<char> e(c.begin(), c.end());
//	int i = 0;
//	ft::vector<char>::iterator start = e.begin();
//	ft::vector<char>::iterator end = e.end();
//	while (start != end)
//	{
//		i++;
//		std::cout << i << std::endl;
//		start++;
//	}
//	std::cout << "===================" << std::endl;
//	bool hi = e.begin() == e.end();
//	std::cout << hi << std::endl;
//	ft::vector<char>::const_iterator cbeginn = e.begin();
//	hi = cbeginn == e.begin();
//	std::cout << hi << std::endl;
//
//
//	ft::vector<int> r(5, 10);
//	ft::vector<int> rr(5, 10);
//	std::cout << r.size() << " " << r.capacity() << std::endl;
//	std::cout << rr.size() << " " << rr.capacity() << std::endl;
//	r.clear();
//	rr.clear();
//	std::cout << r.size() << " " << r.capacity() << std::endl;
//	std::cout << rr.size() << " " << rr.capacity() << std::endl;
//

	ft::vector<int> a(5, 10);
	std::vector<int> b(5, 10);
	b.erase(b.begin() + 1, b.begin() + 3);
	a.erase(a.begin() + 1, a.begin() + 3);
	std::cout << b.size() << " " << b.capacity() << std::endl;
	std::cout << a.size() << " " << a.capacity() << std::endl;
	std::vector<int>::iterator std_begin = b.begin();
	std::vector<int>::iterator std_end = b.end();
	while (std_begin != std_end){
		std::cout << *std_begin << " ";
		std_begin++;
	}
	std::cout << std::endl;
	ft::vector<int>::iterator ft_begin = a.begin();
	ft::vector<int>::iterator ft_end = a.end();
	while (ft_begin != ft_end){
		std::cout << *ft_begin << " ";
		ft_begin++;
	}
	std::cout << std::endl;
	std::cout << b[0] << " " << b[1] << " " << b[2] << " " << b[3] << " " << b[4] << std::endl;
	std::cout << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << std::endl;

	b.push_back(5);
	a.push_back(5);
	b.push_back(3);
	a.push_back(3);
//	b.push_back(4);
//	a.push_back(4);
	b.insert(b.begin() + 2, 11);
	a.insert(a.begin() + 2, 11);
	b.assign(12, 10);
	a.assign(12, 10);
	b.insert(b.begin() + 2, 4, 17);
	a.insert(a.begin() + 2, 4, 17);
	std::cout << "std: " << b.size() << " " << b.capacity() << std::endl;
	std::cout << "ft: " << a.size() << " " << a.capacity() << std::endl;
	std::cout << "std: " << b[0] << " " << b[1] << " " << b[2] << " " << b[3] << " " << b[4] << " " << b[5] << std::endl;
	std::cout << "ft: " << a[0] << " " << a[1] << " " << a[2] << " " << a[3] << " " << a[4] << " " << a[5] <<std::endl;

}
