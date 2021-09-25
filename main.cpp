#include <iostream>
#include <vector>
#include "vector.hpp"
class B
{
public:
	std::string a;
	std::string b;
	B() {
	 a = "hello, ";
	 b = "world!";
	}
};

int main()
{
	//Test Iterators
	{
		std::vector<int> a(5, 10);
		std::vector<int>::iterator begin = a.begin();
		std::vector<int>::iterator end = a.end();
		std::vector<int>::const_iterator cbegin = a.begin();
		std::vector<int>::const_iterator cend = a.end();
		std::cout << *(begin + 1) << std::endl; // 1
		std::cout << *(1 + begin) << std::endl; // 2
		std::cout << *(begin - 0) << std::endl; // 3
		std::cout << begin - end << std::endl; // 4
		std::cout << begin - cend << std::endl; //5
		std::cout << end - begin << std::endl; //6
		std::cout << end - cbegin << std::endl; //7
		begin++;
		cbegin++;
		end--;
		cend--;
		++begin;
		++cbegin;
		std::cout << *begin << std::endl; // 8
		std::cout << *cbegin << std::endl; // 9
		std::cout << *end << std::endl; // 10
		std::cout << *cend << std::endl; // 11
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
		std::cout << *(begin += 1) << std::endl; //12
		std::cout << *(cbegin += 1) << std::endl; //13
		std::cout << *(begin -= 1) << std::endl; //14
		std::cout << *(cbegin -= 1) << std::endl; //15
		std::cout << *begin << std::endl; //16
		std::cout << *cbegin << std::endl; //17
		std::cout << *end << std::endl; //18
		std::cout << *cend << std::endl; //19
		std::cout << (begin != cbegin) << std::endl; //20
		std::cout << (begin != begin) << std::endl; //21
		std::cout << (begin == cbegin) << std::endl; //22
		std::cout << (begin == begin) << std::endl; //23
		std::cout << (begin < cbegin) << std::endl; //24
		std::cout << (begin < begin) << std::endl; //25
		std::cout << (begin <= cbegin) << std::endl; //26
		std::cout << (begin <= begin) << std::endl; //27
		std::cout << (begin > cbegin) << std::endl; //28
		std::cout << (begin > begin) << std::endl; //29
		std::cout << (begin >= cbegin) << std::endl; //30
		std::cout << (begin >= begin) << std::endl; //31
		std::cout << begin[0] << std::endl; //32
		std::cout << cbegin[0] << std::endl; //33
		std::cout << end[0] << std::endl; //34
		std::cout << cend[0] << std::endl; //35
		std::vector<class B> b(5);
		std::vector<class B>::iterator bbegin = b.begin();
		std::vector<class B>::const_iterator cbbegin = b.begin();
		std::cout << bbegin->a << bbegin->b << std::endl; //36
		std::cout << (*bbegin).a << (*bbegin).b << std::endl; //37
		std::cout << cbbegin->a << cbbegin->b << std::endl; //38
		std::cout << (*cbbegin).a << (*cbbegin).b << std::endl; //39
		cbegin = begin;
		//*cbegin = *begin;
		//*cbegin = 10;
	}
	// Test swap
	{
		ft::vector<int> foo (3,100);   // three ints with a value of 100
		ft::vector<int> bar (5,200);   // five ints with a value of 200

		std::cout << "foo size: " << foo.size() << " foo capacity: " << foo.capacity() << std::endl;
		std::cout << "bar size: " << bar.size() << " bar capacity: " << bar.capacity() << std::endl;
		std::cout << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			std::cout << ' ' << foo[i];
		std::cout << std::endl;

		std::cout << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			std::cout << ' ' << bar[i];
		std::cout << std::endl;
		foo.swap(bar);

		std::cout << "foo contains:";
		for (unsigned i=0; i<foo.size(); i++)
			std::cout << ' ' << foo[i];
		std::cout << std::endl;

		std::cout << "bar contains:";
		for (unsigned i=0; i<bar.size(); i++)
			std::cout << ' ' << bar[i];
		std::cout << std::endl;

		std::cout << "foo size: " << foo.size() << " foo capacity: " << foo.capacity() << std::endl;
		std::cout << "bar size: " << bar.size() << " bar capacity: " << bar.capacity() << std::endl;
	}

}
