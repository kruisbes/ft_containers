#include "map.hpp"
#include "../vector/vector.hpp"
#include <map>

template <class T1, class T2>
void print_map(ft::map<T1, T2> &v)
{
	typename ft::map<T1, T2>::iterator begin = v.begin();
	typename ft::map<T1, T2>::iterator end = v.end();
	std::cout << "size=\t\t" << v.size() << std::endl;
	for (; begin != end; begin++)
		std::cout << "\033[38;5;46m" << begin->first << "->" << begin->second << "\033[0m ";
	std::cout << std::endl;
}

template <class T1, class T2>
void print_map(const ft::map<T1, T2> &v)
{
	typename ft::map<T1, T2>::const_iterator begin = v.begin();
	typename ft::map<T1, T2>::const_iterator end = v.end();
	std::cout << "size=\t\t" << v.size() << std::endl;
	for (; begin != end; begin++)
		std::cout << "\033[38;5;46m" << begin->first << "->" << begin->second << "\033[0m ";
	std::cout << std::endl;
}

void map_test_construct() {
	ft::map<char, int> one;
	one['a'] = 10;
	one['b'] = 30;
	one['c'] = 50;
	one['d'] = 70;
	print_map(one);
	ft::map<char, int> two(one.begin(), one.end());
	print_map(two);
	ft::map<char, int> three(two);
	print_map(three);

	std::cout << (one == two) << std::endl;
}

void map_test_insert() {
	ft::map<int, int> a;
	a.insert(ft::pair<int, int>(0, 100));
	a.insert(ft::pair<int, int>(10, 200));
	ft::pair<ft::map<int, int>::iterator, bool> ret;
	ret = a.insert(ft::pair<int, int>(1, 500));
	if (!ret.second) {
		std::cout << "element already exists" << std::endl;
	}
	a.insert(a.begin(), ft::pair<int, int>(2, 300));
	a.insert(a.begin(), ft::pair<int, int>(3, 400));
	for (int i = 11; i < 1000; ++i)
		a.insert(ft::pair<int, int>(i, i));
	print_map(a);

	ft::map<int, int> b;
	ft::vector<ft::pair<int, int> > vec(100, ft::pair<int, int>(10, 10));
	b.insert(vec.begin(), vec.end());
	print_map(b);
}

void map_test_equal_range() {
	ft::map<char, int> a;
	ft::map<char, int>::iterator it;
	a['a'] = 10;
	a['b'] = 20;
	a['c'] = 30;
	ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
	ret = a.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << "->" << ret.first->second << std::endl;
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << "->" << ret.second->second << std::endl;
	ret = a.equal_range('d');
	std::cout << "lower bound points to: ";
	std::cout << ret.first->first << "->" << ret.first->second << std::endl;
	std::cout << "upper bound points to: ";
	std::cout << ret.second->first << "->" << ret.second->second << std::endl;
	ft::pair<ft::map<char,int>::const_iterator,ft::map<char,int>::const_iterator> cret;
	cret = a.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << cret.first->first << "->" << cret.first->second << std::endl;
	std::cout << "upper bound points to: ";
	std::cout << cret.second->first << "->" << cret.second->second << std::endl;
	cret = a.equal_range('d');
	std::cout << "lower bound points to: ";
	std::cout << cret.first->first << "->" << cret.first->second << std::endl;
	std::cout << "upper bound points to: ";
	std::cout << cret.second->first << "->" << cret.second->second << std::endl;
}

void map_test_uplow() {
	ft::map<char,int> a;
	ft::map<char,int>::iterator itlow, itup;
	ft::map<char,int>::const_iterator citlow, citup;

	a['a'] = 20;
	a['b'] = 40;
	a['c'] = 60;
	a['d'] = 80;
	a['e'] = 100;

	itlow = a.lower_bound ('b');
	itup = a.upper_bound ('d');
	std::cout << itlow->first << " " << itlow->second << std::endl;
	std::cout << itup->first << " " << itup->second << std::endl;
	citlow = a.lower_bound ('b');
	citup = a.upper_bound ('d');
	std::cout << citlow->first << " " << citlow->second << std::endl;
	std::cout << citup->first << " " << citup->second << std::endl;
	print_map(a);
	a.erase(itlow,itup);
	print_map(a);
	itlow = a.lower_bound ('a');
	itup = a.lower_bound('e');
	std::cout << itlow->first << " " << itlow->second << std::endl;
	std::cout << itup->first << " " << itup->second << std::endl;
	a.erase(itlow,itup);
	print_map(a);
}

void map_test_iterators()
{
	ft::map<int, int> a;
	a['a'] = 20;
	a['b'] = 40;
	a['c'] = 60;
	a['d'] = 80;
	a['e'] = 100;
	ft::map<int, int>::iterator begin = a.begin();
	ft::map<int, int>::iterator end = a.end();
	ft::map<int, int>::const_iterator cbegin = a.begin();
	ft::map<int, int>::const_iterator cend = a.end();
	begin++;
	cbegin++;
	end--;
	cend--;
	++begin;
	++cbegin;
	std::cout << begin->first << "->" << begin->second << std::endl;
	std::cout << cbegin->first << "->" << begin->second << std::endl;
	std::cout << end->first << "->" << end->second << std::endl;
	std::cout << cend->first << "->" << cend->second << std::endl;
	++end;
	++cend;
	--begin;
	--cbegin;
	--end;
	--cend;
	begin--;
	cbegin--;
	end--;
	cend--;
	std::cout << begin->first << "->" << begin->second << std::endl;
	std::cout << cbegin->first << "->" << begin->second << std::endl;
	std::cout << end->first << "->" << end->second << std::endl;
	std::cout << cend->first << "->" << cend->second << std::endl;
	std::cout << (begin != cbegin) << std::endl;
	std::cout << (begin != begin) << std::endl;
	std::cout << (begin == cbegin) << std::endl;
	std::cout << (begin == begin) << std::endl;
}

void map_test_reverse_iterators()
{
	ft::map<int, int> a;
	a[1] = 20;
	a[2] = 40;
	a[3] = 60;
	a[4] = 80;
	a[5] = 100;
	ft::map<int, int>::reverse_iterator begin = a.rbegin();
	ft::map<int, int>::reverse_iterator end = a.rend();
	ft::map<int, int>::const_reverse_iterator cbegin = a.rbegin();
	ft::map<int, int>::const_reverse_iterator cend = a.rend();
	begin++;
	cbegin++;
	end--;
	cend--;
	++begin;
	++cbegin;
	std::cout << begin->first << "->" << begin->second << std::endl;
	std::cout << cbegin->first << "->" << cbegin->second << std::endl;
	std::cout << end->first << "->" << end->second << std::endl;
	std::cout << cend->first << "->" << cend->second << std::endl;
	++end;
	++cend;
	--begin;
	--cbegin;
	--end;
	--cend;
	begin--;
	cbegin--;
	end--;
	cend--;

	std::cout << begin->first << "->" << begin->second << std::endl;
	std::cout << cbegin->first << "->" << cbegin->second << std::endl;
	std::cout << end->first << "->" << end->second << std::endl;
	std::cout << cend->first << "->" << cend->second << std::endl;

	std::cout << (begin != cbegin) << std::endl;
	std::cout << (begin != begin) << std::endl;
	std::cout << (begin == cbegin) << std::endl;
	std::cout << (begin == begin) << std::endl;
}

void map_test_clear() {
	ft::map<char,int> a;
	std::cout << a.empty() << std::endl;
	a['x']=100;
	a['y']=200;
	a['z']=300;
	std::cout << a.empty() << std::endl;
	print_map(a);
	a.clear();
	std::cout << a.empty() << std::endl;
	print_map(a);
	a['a']=1101;
	a['b']=2202;
	print_map(a);
}

void map_test_count() {
	ft::map<int,int> a;
	std::cout << a.empty() << std::endl;
	for (int i = 0; i < 100; ++i)
		a.insert(ft::pair<int, int>(i, i));
	std::cout << a.empty() << std::endl;
	print_map(a);
	for (int i = 0; i < 110; i+=2) {
		if (a.count(i) > 0)
			std::cout << a[i] << std::endl;
		else
			std::cout << "no such element" << std::endl;
	}
}

void map_test_erase() {
	ft::map<int, int> a;
	for (int i = 0; i < 1000; ++i) {
		a.insert(ft::pair<int, int>(i, i));
	}
	for (int i = 10; i < 50; ++i) {
		a.erase(i);
	}
	print_map(a);
	a.clear();
	print_map(a);
	for (int i = 0; i < 1000; ++i) {
		a.insert(ft::pair<int, int>(i, i));
	}
	for (int i = 0; i < 50; ++i) {
		a.erase(i);
	}
	print_map(a);
	a.clear();
	print_map(a);
	for (int i = 0; i < 1000; ++i) {
		a.insert(ft::pair<int, int>(i, i));
	}
	for (int i = 100; i > 50; i--) {
		a.erase(i);
	}
	print_map(a);
	a.clear();
	print_map(a);
	for (int i = 0; i < 10000; ++i) {
		a.insert(ft::pair<int, int>(i, i));
	}
	print_map(a);
	ft::map<int, int>::iterator it;
	it = a.begin();
	for (int i = 0; i < 10; ++i, it++) ;
	std::cout << it->first << " " << it->second << std::endl;
	a.erase(it);
	print_map(a);
	it = a.begin();
	for (int i = 0; i < 20; ++i, it++) ;
	std::cout << it->first << " " << it->second << std::endl;
	a.erase(it);
	print_map(a);
	it = a.begin();
	for (int i = 0; i < 256; ++i, it++) ;
	a.erase(it);
	print_map(a);
	it = a.begin();
	ft::map<int, int>::iterator itt = a.begin();
	for (int i = 0; i < 50; ++i, it++, itt++) ;
	for (int i = 0; i < 50; ++i, itt++) ;
	std::cout << it->first << " " << it->second << std::endl;
	std::cout << itt->first << " " << itt->second << std::endl;
	std::cout << a.size() << std::endl;
	a.erase(it, itt);
	std::cout << a.size() << std::endl;
	print_map(a);
}

void map_simple_test() {
	ft::map<int, int> a;
	std::cout << a.empty() << std::endl;
	for (int i = 0; i < 1000; ++i) {
		a.insert(ft::pair<int, int>(i, i));
	}
	std::cout << a.empty() << std::endl;
	std::cout << a.size() << std::endl;
}

void map_test_compare() {
	ft::map<int, int> a;
	for (int i = 0; i < 100; ++i)
		a.insert(ft::pair<int, int>(i, i));
	ft::map<int, int> c(a);
	ft::map<int, int> b;
	for (int i = 0; i < 5; ++i) {
		b.insert(ft::pair<int, int>(i, i));
	}

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

void map_test_swap() {
	ft::map<char,int> foo,bar;

	foo['x']=100;
	foo['y']=200;

	bar['a']=11;
	bar['b']=22;
	bar['c']=33;

	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;

	std::cout << "bar contains:\n";
	for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
}

void map_test_find() {
	ft::map<int, int> a;
	for (int i = 0; i < 100; ++i) {
		a.insert(ft::pair<int, int>(i, i));
	}
	ft::map<int, int>::iterator it;
	it = a.find(23);
	std::cout << it->first << " " << it->second << std::endl;
	it = a.find(120);
	std::cout << it->first << " " << it->second << std::endl;
}

int main() {
//	map_simple_test();
//	map_test_reverse_iterators();
//	map_test_construct();
//	map_test_iterators();
//	map_test_insert();
//	map_test_equal_range();
//	map_test_uplow();
//	map_test_clear();
//	map_test_count();
//	map_test_erase();
//	map_test_compare();
//	map_test_swap();
	map_test_find();
}
