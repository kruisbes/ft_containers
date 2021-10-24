#include <iostream>
#include <vector>
#include "vector.hpp"

class B
{

public:
	std::string a;
	std::string b;
	int *hehe;

	B()
	{
		a = "Hello";
		b = ", World!";
		hehe = new int[7];
		for (int i = 0; i < 7; ++i) {
			hehe[i] = i;
		}
	}

	B(const B & src) {
		hehe = new int[7];
		for (int i = 0; i < 7; ++i) {
			if (!src.hehe[i])
				hehe[i] = 0;
			else
				hehe[i] = src.hehe[i];
		}
	}
	B & operator=(const B & src){
		if (this == &src)
			return *this;
		hehe = new int[7];
		if (!src.hehe)
			return *this;
		for (int i = 0; i < 7; ++i) {
			if (!src.hehe[i])
				hehe[i] = 0;
			else
				hehe[i] = src.hehe[i];
		}
		return *this;
	}
	~B() {
		delete[] hehe;
	}
};

std::ostream & operator<<(std::ostream & os, B const & bb) {
	std::cout << bb.a << " " << bb.b << bb.hehe[3] << std::endl;
	return os;
}

template <class T>
void print_vector(std::vector<T> &v)
{
	typename std::vector<T>::iterator begin = v.begin();
	typename std::vector<T>::iterator end = v.end();
	std::cout << "capacity=\t" << v.capacity() << std::endl;
	std::cout << "size=\t\t" << v.size() << std::endl;
	for (; begin != end; begin++)
		std::cout << "\033[38;5;46m" << *begin << "\033[0m ";
	std::cout << std::endl;
}

template <class T>
void print_vector(const std::vector<T> &v)
{
	typename std::vector<T>::const_iterator begin = v.begin();
	typename std::vector<T>::const_iterator end = v.end();
	std::cout << "capacity=\t" << v.capacity() << std::endl;
	std::cout << "size=\t\t" << v.size() << std::endl;
	for (; begin != end; begin++)
		std::cout << "\033[38;5;46m" << *begin << "\033[0m ";
	std::cout << std::endl;
}

void test_reverse_iterators()
{
	std::vector<int> a(5, 10);
	std::vector<int>::reverse_iterator begin = a.rbegin();
	std::vector<int>::reverse_iterator end = a.rend();
	std::vector<int>::const_reverse_iterator cbegin = a.rbegin();
	std::vector<int>::const_reverse_iterator cend = a.rend();
	std::cout << *(begin + 1) << std::endl;
	std::cout << *(1 + begin) << std::endl;
	std::cout << *(begin - 0) << std::endl;
	std::cout << begin - end << std::endl;
	std::cout << begin - cend << std::endl;
	std::cout << end - begin << std::endl;
	std::cout << end - cbegin << std::endl;
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
	std::cout << *(begin += 1) << std::endl;
	std::cout << *(cbegin += 1) << std::endl;
	std::cout << *(begin -= 1) << std::endl;
	std::cout << *(cbegin -= 1) << std::endl;

	std::cout << *begin << std::endl;
	std::cout << *cbegin << std::endl;
	std::cout << *end << std::endl;
	std::cout << *cend << std::endl;

	std::cout << (begin != cbegin) << std::endl;
	std::cout << (begin != begin) << std::endl;
	std::cout << (begin == cbegin) << std::endl;
	std::cout << (begin == begin) << std::endl;

	std::cout << (begin < cbegin) << std::endl;
	std::cout << (begin < begin) << std::endl;
	std::cout << (begin <= cbegin) << std::endl;
	std::cout << (begin <= begin) << std::endl;

	std::cout << (begin > cbegin) << std::endl;
	std::cout << (begin > begin) << std::endl;
	std::cout << (begin >= cbegin) << std::endl;
	std::cout << (begin >= begin) << std::endl;

	std::cout << begin[0] << std::endl;
	std::cout << cbegin[0] << std::endl;
	std::cout << end[0] << std::endl;
	std::cout << cend[0] << std::endl;

	std::vector<class B> b(5);
	std::vector<class B>::iterator bbegin = b.begin();
	std::vector<class B>::const_iterator cbbegin = b.begin();

	std::cout << bbegin->a << bbegin->b << std::endl;
	std::cout << (*bbegin).a << (*bbegin).b << std::endl;

	std::cout << cbbegin->a << cbbegin->b << std::endl;
	std::cout << (*cbbegin).a << (*cbbegin).b << std::endl;

	cbegin = begin;
	//*cbegin = *begin;
	//*cbegin = 10;
}

void test_iterators()
{
	std::vector<int> a(5, 10);
	std::vector<int>::iterator begin = a.begin();
	std::vector<int>::iterator end = a.end();
	std::vector<int>::const_iterator cbegin = a.begin();
	std::vector<int>::const_iterator cend = a.end();
	std::cout << *(begin + 1) << std::endl;
	std::cout << *(1 + begin) << std::endl;
	std::cout << *(begin - 0) << std::endl;
	std::cout << begin - end << std::endl;
	std::cout << begin - cend << std::endl;
	std::cout << end - begin << std::endl;
	std::cout << end - cbegin << std::endl;
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
	std::cout << *(begin += 1) << std::endl;
	std::cout << *(cbegin += 1) << std::endl;
	std::cout << *(begin -= 1) << std::endl;
	std::cout << *(cbegin -= 1) << std::endl;

	std::cout << *begin << std::endl;
	std::cout << *cbegin << std::endl;
	std::cout << *end << std::endl;
	std::cout << *cend << std::endl;

	std::cout << (begin != cbegin) << std::endl;
	std::cout << (begin != begin) << std::endl;
	std::cout << (begin == cbegin) << std::endl;
	std::cout << (begin == begin) << std::endl;

	std::cout << (begin < cbegin) << std::endl;
	std::cout << (begin < begin) << std::endl;
	std::cout << (begin <= cbegin) << std::endl;
	std::cout << (begin <= begin) << std::endl;

	std::cout << (begin > cbegin) << std::endl;
	std::cout << (begin > begin) << std::endl;
	std::cout << (begin >= cbegin) << std::endl;
	std::cout << (begin >= begin) << std::endl;

	std::cout << begin[0] << std::endl;
	std::cout << cbegin[0] << std::endl;
	std::cout << end[0] << std::endl;
	std::cout << cend[0] << std::endl;

	std::vector<class B> b(5);
	std::vector<class B>::iterator bbegin = b.begin();
	std::vector<class B>::const_iterator cbbegin = b.begin();

	std::cout << bbegin->a << bbegin->b << std::endl;
	std::cout << (*bbegin).a << (*bbegin).b << std::endl;

	std::cout << cbbegin->a << cbbegin->b << std::endl;
	std::cout << (*cbbegin).a << (*cbbegin).b << std::endl;

	cbegin = begin;
	//*cbegin = *begin;
	//*cbegin = 10;
}

void test_clear()
{
	{
		std::vector<int> a(4, 10);
		std::cout << a.size() << std::endl;
		std::cout << a.capacity() << std::endl;
		std::cout << a[0] << " " << a[1] << " "  << a[2] << " " << a[3] << std::endl;
		a.clear();
		std::cout << a.size() << std::endl;
		std::cout << a.capacity() << std::endl;
		std::cout << a[0] << " " << a[1] << " "  << a[2] << " " << a[3] << std::endl;
	}
	{
		std::vector<int> a(10, 100);
		std::vector<int>::iterator begin = a.begin();
		std::vector<int>::iterator end = a.end();
		std::cout << end - begin << std::endl;
		print_vector(a);
		a.clear();
		begin = a.begin();
		end = a.end();
		std::cout << a.capacity() << std::endl;
		std::cout << a.size() << std::endl;
		std::cout << "\033[31m" << end - begin << "\033[0m" << std::endl;
		print_vector(a);
	}
	std::vector<int> c;
	c.clear();
	std::cout << c.max_size() << std::endl;
}

void test_million_push_back()
{
	std::vector<int> a(10);
	for (int i = 0; i < 1000000; i++)
		a.push_back(1000);
}

void test_push_back()
{
	std::vector<int> a;
	a.push_back(1);
	print_vector(a);
}

void test_assign()
{
	//with_iterators
	std::vector<int> a(15, 1);
	std::vector<int> b(10, 9);
	print_vector(b);
	std::vector<int>::iterator begin = a.begin();
	std::vector<int>::iterator end = a.end();
	std::vector<int>::iterator cbegin = a.begin();
	std::vector<int>::iterator cend = a.end();
	b.assign(begin, end);
	b.assign(cbegin, cend);
	print_vector(b);
	std::vector<int> c;
	std::vector<int>::iterator begin1 = c.begin();
	std::vector<int>::iterator end1 = c.end();
	b.assign(begin1, end1);
	print_vector(b);
	a.assign(a.begin(), a.end());
	print_vector(a);
	std::vector<int> aa;
	std::vector<int>::iterator begin2 = aa.begin();
	std::vector<int>::iterator end2 = aa.end();
	aa.assign(begin2, end2);
	//with value
	std::vector<int> u(15, 1);
	print_vector(u);
	u.assign(20, 4);
	print_vector(u);
	u.assign(50, 10);
	print_vector(u);
	u.assign(0, 1);
	print_vector(u);
}

void test_at()
{
	int a_ref;
	int a_ref2;
	std::vector<int> a(10, 4);
	try
	{
		a_ref = a.at(9);
		a_ref2 = a.at(10);
	}
	catch (std::out_of_range &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << a_ref << std::endl;
	std::vector<int> myvector (10);

	for (unsigned i=0; i<myvector.size(); i++)
		myvector.at(i)=i;

	std::cout << "myvector contains:";
	for (unsigned i=0; i<myvector.size(); i++)
		std::cout << ' ' << myvector.at(i);
	std::cout << '\n';
}

void test_back()
{
	std::vector<int> a(10, 10);
	print_vector(a);
	std::cout << "back = \033[38;5;57m" << a.back() << "\033[0m" <<std::endl;
	a.push_back(99);
	print_vector(a);
	std::cout << "back = \033[38;5;57m" << a.back() << "\033[0m" <<std::endl;
	const std::vector<int> a_c(10, 99);
	print_vector(a_c);
	std::cout << "back = \033[38;5;57m" << a_c.back() << "\033[0m" <<std::endl;
}

void test_erase()
{
	std::vector<int> a;
	for (int i = 0; i < 10; i++)
		a.push_back(i);
//	std::cout << &a[0] << std::endl;
	print_vector(a);
	a.erase(a.begin() + 1);
//	std::cout << &a[0] << std::endl;
	print_vector(a);
	a.erase(a.end() - 1);
//	std::cout << &a[0] << std::endl;
	print_vector(a);
	a.erase(a.begin() + 3);
//	std::cout << &a[0] << std::endl;
	print_vector(a);
	a.erase(a.begin());
	print_vector(a);
	a.erase(a.begin());
	print_vector(a);
	a.erase(a.begin());
	print_vector(a);
	a.erase(a.begin());
	print_vector(a);
	a.erase(a.begin());
	print_vector(a);
	a.erase(a.begin());
	print_vector(a);
	a.erase(a.begin());
	print_vector(a);
	for (int i = 0; i < 100; i++)
		a.push_back(i);
	print_vector(a);
	a.erase(a.begin(), a.begin() + 20);
	print_vector(a);
	a.erase(a.end() - 40, a.end() - 1);
	print_vector(a);

/*	std::vector<class B> b;
	B j;
	b.reserve(20);
	b.push_back(j);
	B i;
	b.push_back(i);
	print_vector(b);
	b.erase(b.begin() + 2);
	print_vector(b); */

	std::vector<int> test(100, 100);
	std::vector<int>::iterator i;
	i = test.erase(test.begin() + 10);
	std::cout << "iteraror points to: ";
	std::cout << *i << std::endl;
	i = test.erase(test.begin() + 10, test.begin() + 20);
	std::cout << "iterator points to: ";
	std::cout << *i << std::endl;
}

void test_front()
{
	std::vector<int> a;
	a.push_back(1);
	std::cout << a.front() << std::endl;
	a.front() += 10;
	std::cout << a.front() << std::endl;
	a.front() -= 100;
	std::cout << a.front() << std::endl;
	a.push_back(1);
	std::cout << a.front() << std::endl;
}

void test_get_allocator()
{
	std::vector<int> myvector;
	int * p;
	unsigned int i;

	p = myvector.get_allocator().allocate(5);

	for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);
	print_vector(myvector);

	std::cout << "The allocated array contains:";
	for (i=0; i<5; i++) std::cout << ' ' << p[i];
	std::cout << '\n';
	print_vector(myvector);

	for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
	myvector.get_allocator().deallocate(p,5);
}

void test_pop_back()
{
	std::vector<int> myvector;
	int sum (0);
	myvector.push_back (100);
	myvector.push_back (200);
	myvector.push_back (300);

	while (!myvector.empty())
	{
		sum += myvector.back();
		myvector.pop_back();
	}

	std::cout << "The elements of myvector add up to " << sum << '\n';
}

void test_insert() {
	std::vector<int> myvector(5, 10);
	print_vector(myvector);
	myvector.insert(myvector.begin() + 2, 5);
	for (int i = 0; i < 5; ++i) {
		myvector.insert(myvector.begin() + 2, 5);
	}
	print_vector(myvector);
	myvector.insert(myvector.begin() + 2, 5, 70);
	print_vector(myvector);
	myvector.insert(myvector.begin() + 2, 5, 80);
	print_vector(myvector);
	myvector.insert(myvector.begin() + 2, 100, 5);
	print_vector(myvector);
	print_vector(myvector);
	for (int i = 0; i < 100; ++i) {
		myvector.insert(myvector.begin() + 2, 5, 90);
	}
	print_vector(myvector);
	std::vector<int> from(5, 60);
	for (int i = 0; i < 10000; ++i) {
		myvector.insert(myvector.end(), from.begin(), from.end() - 1);
	}
	print_vector(myvector);
	std::vector<int> a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	print_vector(a);
	a.insert(a.end(), a.begin(), a.end());
	print_vector(a);

	std::vector<int> empty;
	print_vector(empty);
	empty.insert(empty.begin(), 5);
	print_vector(empty);
	std::vector<int> empty2;
	print_vector(empty2);
	empty2.insert(empty2.begin(), 5, 10);
	print_vector(empty2);
	std::vector<int> empty3;
	print_vector(empty3);
	empty3.insert(empty3.begin(), from.begin(), from.end() - 1);
	print_vector(empty3);

	std::vector<int> test_it(100,100);
	std::vector<int>::iterator retit;
	retit = test_it.insert(test_it.begin() + 10, 77);
	std::cout << "iterator points to: ";
	std::cout << *retit << std::endl;
}

void test_resize() {
	std::vector<int> myvector(100,100);
	print_vector(myvector);
	myvector.resize(1000, 5);
	print_vector(myvector);
	for (int i = 1; i < 1000000; ++i) {
		myvector.resize(i, 5);
	}
	print_vector(myvector);
	for (int i = 1000000; i > 0; i--) {
		myvector.resize(i, 5);
	}
	try {
		myvector.resize(-19);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	try {
		myvector.resize(myvector.max_size() + 1, 5);
	}
	catch (std::exception & e) {
		std::cout << e.what() << std::endl;
	}
	print_vector(myvector);
}

void test_reserve() {
	std::vector<int> myvector(100, 100);
	print_vector(myvector);
	for (int i = 0; i < 10000; ++i) {
		myvector.reserve(i);
		print_vector(myvector);
	}
	for (int i = 10000; i > 0; i--) {
		myvector.reserve(i);
		print_vector(myvector);
	}
}

void test_insert3()
{
	std::vector<int> a(100, 1);
	std::vector<int> b(100);
	b.push_back(1);
	b.push_back(2);
	b.push_back(3);
	print_vector(a);
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	print_vector(a);
	a.insert(a.end(), b.end() - 50, b.end());
	print_vector(a);
	a.reserve(100);
	print_vector(a);
	std::vector<int> million(1000000, 10);
	a.insert(a.end(), million.begin(), million.end() - 1000);
	print_vector(a);
	a.erase(a.begin(), a.end());
	print_vector(a);
	a.insert(a.begin(), million.end() - 1000, million.end());
	print_vector(a);
	std::vector<int> one_thousand;
	for (int i = 0; i < 1000; i++)
		one_thousand.push_back(i);
	for (int i = 0; i < 1000; i++)
		a.insert(a.end(), one_thousand.begin(), one_thousand.end());
	print_vector(a);
	a.insert(a.end(), a.begin(), a.end());
	std::cout << *(a.begin()) << " " << *(a.end()); ////////////////////////////////
	print_vector(a);
	std::vector<int> test;
	for (int i = 0; i < 500; i++)
	test.push_back(i);
	print_vector(a);
	test.insert(test.begin() + 10, test.begin(), test.end());
	print_vector(a);
	std::vector<int> myvector(100, 100);
	std::vector<int> from(5, 60);
	for (int i = 0; i < 100; ++i) {
	myvector.insert(myvector.end(), from.begin(), from.end() - 1);
	}
	print_vector(myvector);
}

void test_compare()
{
	std::vector<int> a;
	std::vector<int> b;
	std::vector<int> c;

	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	print_vector(a);

	b.push_back(7);
	b.push_back(8);
	b.push_back(9);
	b.push_back(10);
	print_vector(b);

	c.push_back(1);
	c.push_back(2);
	c.push_back(3);
	print_vector(c);

	std::cout << std::boolalpha;

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

void test_swap() {
	std::vector<int> foo (3,100);
	std::vector<int> bar (5,200);

	foo.swap(bar);

	std::cout << "foo contains:";
	for (size_t i = 0; i < foo.size(); i++)
		std::cout << ' ' << foo[i];
	std::cout << std::endl;

	std::cout << "bar contains:";
	for (size_t i = 0; i < bar.size(); i++)
		std::cout << ' ' << bar[i];
	std::cout << std::endl;

	std::vector<class B> b(5);
	std::vector<class B> c(6);
	b.swap(c);
}

int main()
{
	test_reverse_iterators();
	test_compare();
	test_insert3();
	test_reserve();
	test_resize();
	test_iterators();
	test_clear();
	test_million_push_back();
	test_push_back();
	test_assign();
	test_at();
	test_back();
	test_erase();
	test_front();
	test_get_allocator();
	test_pop_back();
	test_insert();
	test_swap();
}
