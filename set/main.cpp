#include "set.hpp"
#include "../tree/pair.hpp"
#include "../vector/vector.hpp"
#include <set>

template <class T1>
void print_set(ft::set<T1> &v)
{
	typename ft::set<T1>::iterator begin = v.begin();
	typename ft::set<T1>::iterator end = v.end();
	std::cout << "size=\t\t" << v.size() << std::endl;
	for (; begin != end; begin++)
		std::cout << "\033[38;5;46m" << *begin << "\033[0m ";
	std::cout << std::endl;
}

template <class T1>
void print_set(const ft::set<T1> &v)
{
	typename ft::set<T1>::const_iterator begin = v.begin();
	typename ft::set<T1>::const_iterator end = v.end();
	std::cout << "size=\t\t" << v.size() << std::endl;
	for (; begin != end; begin++)
		std::cout << "\033[38;5;46m" << *begin << "\033[0m ";
	std::cout << std::endl;
}

void set_test_construct() {
	ft::set<char> one;
	one.insert('a');
	one.insert('b');
	one.insert('c');
	one.insert('d');

	print_set(one);
	ft::set<char> two(one.begin(), one.end());
	print_set(two);
	ft::set<char> three(two);
	print_set(three);

	std::cout << (one == two) << std::endl;
}

void set_test_insert() {
	ft::set<int> a;
	a.insert(100);
	a.insert(200);
	ft::pair<ft::set<int>::iterator, bool> ret;
	ret = a.insert(500);
	if (!ret.second) {
		std::cout << "element already exists" << std::endl;
	}
	a.insert(a.begin(), 300);
	a.insert(a.begin(), 400);
	for (int i = 500; i < 1000; ++i)
		a.insert(i);
	print_set(a);

	ft::set<int> b;
	ft::vector<int> vec(10, 10);
	b.insert(vec.begin(), vec.end());
	print_set(b);
}

void set_test_equal_range() {
	ft::set<char> a;
	ft::set<char>::iterator it;
	a.insert('a');
	a.insert('b');
	a.insert('c');
	ft::pair<ft::set<char>::iterator, ft::set<char>::iterator> ret;
	ret = a.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << *ret.first << std::endl;
	std::cout << "upper bound points to: ";
	std::cout << *ret.second << std::endl;
	ret = a.equal_range('d');
	std::cout << "lower bound points to: ";
	std::cout << *ret.first << std::endl;
	std::cout << "upper bound points to: ";
	std::cout << *ret.second << std::endl;
	ft::pair<ft::set<char,int>::const_iterator,ft::set<char,int>::const_iterator> cret;
	cret = a.equal_range('b');
	std::cout << "lower bound points to: ";
	std::cout << *cret.first << std::endl;
	std::cout << "upper bound points to: ";
	std::cout << *cret.second << std::endl;
	cret = a.equal_range('d');
	std::cout << "lower bound points to: ";
	std::cout << *cret.first << std::endl;
	std::cout << "upper bound points to: ";
	std::cout << *cret.second << std::endl;
}

void set_test_uplow() {
	ft::set<char> a;
	ft::set<char>::iterator itlow, itup;
	ft::set<char>::const_iterator citlow, citup;

	a.insert('a');
	a.insert('b');
	a.insert('c');
	a.insert('d');
	a.insert('e');
	itlow = a.lower_bound ('b');
	itup = a.upper_bound ('d');
	std::cout << *itlow << std::endl;
	std::cout << *itup << std::endl;
	citlow = a.lower_bound ('b');
	citup = a.upper_bound ('d');
	std::cout << *citlow << std::endl;
	std::cout << *citup << std::endl;
	print_set(a);
	a.erase(itlow,itup);
	print_set(a);
	itlow = a.lower_bound ('a');
	itup = a.lower_bound('e');
	std::cout << *itlow << std::endl;
	std::cout << *itup << std::endl;
	a.erase(itlow,itup);
	print_set(a);
}

void set_test_iterators()
{
	ft::set<int> a;
	for (int i = 0; i < 10; ++i) {
		a.insert(i);
	}
	ft::set<int, int>::iterator begin = a.begin();
	ft::set<int, int>::iterator end = a.end();
	ft::set<int, int>::const_iterator cbegin = a.begin();
	ft::set<int, int>::const_iterator cend = a.end();
	begin++;
	cbegin++;
	end--;
	cend--;
	++begin;
	++cbegin;
	std::cout << *begin << std::endl;
	std::cout << *cbegin << std::endl;
	std::cout << *end << std::endl;
	std::cout << *cend << std::endl;
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
	std::cout << *begin << std::endl;
	std::cout << *cbegin << std::endl;
	std::cout << *end << std::endl;
	std::cout << *cend << std::endl;
	std::cout << (begin != cbegin) << std::endl;
	std::cout << (begin != begin) << std::endl;
	std::cout << (begin == cbegin) << std::endl;
	std::cout << (begin == begin) << std::endl;
}

void set_test_reverse_iterators()
{
	ft::set<int> a;
	for (int i = 0; i < 10; ++i) {
		a.insert(i);
	}
	ft::set<int>::reverse_iterator begin = a.rbegin();
	ft::set<int>::reverse_iterator end = a.rend();
	ft::set<int>::const_reverse_iterator cbegin = a.rbegin();
	ft::set<int>::const_reverse_iterator cend = a.rend();
	begin++;
	cbegin++;
	end--;
	cend--;
	++begin;
	++cbegin;
	std::cout << *begin << std::endl;
	std::cout << *cbegin << std::endl;
	std::cout << *end << std::endl;
	std::cout << *cend << std::endl;
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

	std::cout << *begin << std::endl;
	std::cout << *cbegin << std::endl;
	std::cout << *end << std::endl;
	std::cout << *cend << std::endl;

	std::cout << (begin != cbegin) << std::endl;
	std::cout << (begin != begin) << std::endl;
	std::cout << (begin == cbegin) << std::endl;
	std::cout << (begin == begin) << std::endl;
}

void set_test_clear() {
	ft::set<char> a;
	std::cout << a.empty() << std::endl;
	a.insert('a');
	std::cout << a.empty() << std::endl;
	print_set(a);
	a.clear();
	std::cout << a.empty() << std::endl;
	print_set(a);
	a.insert('b');
	a.insert('c');
	print_set(a);
}

void set_test_count() {
	ft::set<int> a;
	std::cout << a.empty() << std::endl;
	for (int i = 0; i < 100; ++i)
		a.insert(i);
	std::cout << a.empty() << std::endl;
	print_set(a);
	for (int i = 0; i < 110; i+=2) {
		if (a.count(i) > 0)
			std::cout << *a.find(i) << std::endl;
		else
			std::cout << "no such element" << std::endl;
	}
}

void set_test_erase() {
	ft::set<int> a;
	for (int i = 0; i < 1000; ++i) {
		a.insert(i);
	}
	for (int i = 10; i < 50; ++i) {
		a.erase(i);
	}
	print_set(a);
	a.clear();
	print_set(a);
	for (int i = 0; i < 1000; ++i) {
		a.insert(i);
	}
	for (int i = 0; i < 50; ++i) {
		a.erase(i);
	}
	print_set(a);
	a.clear();
	print_set(a);
	for (int i = 0; i < 1000; ++i) {
		a.insert(i);
	}
	for (int i = 100; i > 50; i--) {
		a.erase(i);
	}
	print_set(a);
	a.clear();
	print_set(a);
	for (int i = 0; i < 10000; ++i) {
		a.insert(i);
	}
	print_set(a);
	ft::set<int, int>::iterator it;
	it = a.begin();
	for (int i = 0; i < 10; ++i, it++) ;
	std::cout << *it << std::endl;
	a.erase(it);
	print_set(a);
	it = a.begin();
	for (int i = 0; i < 20; ++i, it++) ;
	std::cout << *it << std::endl;
	a.erase(it);
	print_set(a);
	it = a.begin();
	for (int i = 0; i < 256; ++i, it++) ;
	a.erase(it);
	print_set(a);
	it = a.begin();
	ft::set<int, int>::iterator itt = a.begin();
	for (int i = 0; i < 50; ++i, it++, itt++) ;
	for (int i = 0; i < 50; ++i, itt++) ;
	std::cout << *it << std::endl;
	std::cout << *itt << std::endl;
	std::cout << a.size() << std::endl;
	a.erase(it, itt);
	std::cout << a.size() << std::endl;
	print_set(a);
}

void set_simple_test() {
	ft::set<int> a;
	std::cout << a.empty() << std::endl;
	for (int i = 0; i < 1000; ++i) {
		a.insert(i);
	}
	std::cout << a.empty() << std::endl;
	std::cout << a.size() << std::endl;
}

void set_test_compare() {
	ft::set<int> a;
	for (int i = 0; i < 100; ++i)
		a.insert(i);
	ft::set<int> c(a);
	ft::set<int> b;
	for (int i = 0; i < 5; ++i) {
		b.insert(i);
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

void set_test_swap() {
	ft::set<char> foo,bar;

	foo.insert('x');
	foo.insert('y');
	bar.insert('a');
	bar.insert('b');
	bar.insert('c');
	foo.swap(bar);

	std::cout << "foo contains:\n";
	for (ft::set<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
		std::cout << *it << std::endl;

	std::cout << "bar contains:\n";
	for (ft::set<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
		std::cout << *it << std::endl;
}

void set_test_find() {
	ft::set<int> a;
	for (int i = 0; i < 100; ++i) {
		a.insert(i);
	}
	ft::set<int, int>::iterator it;
	it = a.find(23);
	std::cout << *it << std::endl;
	it = a.find(120);
	std::cout << *it << std::endl;
}

void set_test_comp() {
	{
		ft::set<char> myset;
		ft::set<char>::key_compare mycomp = myset.key_comp();
		myset.insert('a');
		myset.insert('b');
		myset.insert('c');
		std::cout << "myset contains:\n";
		char highest = *myset.rbegin();
		ft::set<char,int>::iterator it = myset.begin();
		do {
			std::cout << *it << std::endl;
		} while ( mycomp((*it++), highest) );
		std::cout << std::endl;
	}
	{
		ft::set<char> myset;
		myset.insert('x');
		myset.insert('y');
		myset.insert('z');
		std::cout << "myset contains:" << std::endl;
		char highest = *myset.rbegin();
		ft::set<char>::iterator it = myset.begin();
		do {
			std::cout << *it << std::endl;
		} while ( myset.value_comp()(*it++, highest) );
	}
}

int main() {
	set_simple_test();
	set_test_reverse_iterators();
	set_test_construct();
	set_test_iterators();
	set_test_insert();
	set_test_equal_range();
	set_test_uplow();
	set_test_clear();
	set_test_count();
	set_test_erase();
	set_test_compare();
	set_test_swap();
	set_test_find();
	set_test_comp();
}
