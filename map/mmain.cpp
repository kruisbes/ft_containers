#include "pair.hpp"
#include "map.hpp"
#include <iostream>
#include "rbtree.hpp"
#include <iterator>
#include <map>

int main() {
	ft::pair<int, int> pair(13,15);
	ft::pair<int, int> pair2(11,15);
	ft::rbNode<ft::pair<int, int> >* a = new (ft::rbNode<ft::pair<int, int> >);
	a->val = pair;
	ft::rbNode<ft::pair<int, int> >* b = new (ft::rbNode<ft::pair<int, int> >);
	b->val = pair2;
	b->right = 0;
	a->right = b;
	ft::rbNode<ft::pair<int, int> > f;
//	ft::rb_iterator<ft::pair<int, int> > b;
	ft::rb_const_iterator<ft::pair<int, int> > c;

	std::cout << ft::rbNode<ft::pair<int, int> >::maximum(a)->val.first << std::endl;
//	std::map<int,int> first;
//
//	first['a']=10;
//	first['b']=30;
//	first['c']=50;
//	first['d']=70;
//
//	std::cout << first[97] << std::endl;
//	std::cout << first[98] << std::endl;
//	std::map<int, std::map<int, int> > second;
//	second[0] = first;
//	std::cout << second[0][100] << std::endl;
//
//	std::map<int, int>::iterator it = first.begin();
//	return 0;
//	ft::pair <std::string,double> product1;                     // default constructor
//	ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
//	ft::pair <std::string,double> product3 (product2);          // copy constructor
//
//	product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)
//
//	product2.first = "shoes";                  // the type of first is string
//	product2.second = 39.90;                   // the type of second is double
//
//	std::cout << "The price of " << product1.first << " is $" << product1.second << std::endl;
//	std::cout << "The price of " << product2.first << " is $" << product2.second << std::endl;
//	std::cout << "The price of " << product3.first << " is $" << product3.second << std::endl;
//
//	std::cout << std::endl;
//
//	ft::pair<int,char> foo (10,'z');
//	ft::pair<int,char> bar (90,'a');
//
//	if (foo==bar) std::cout << "foo and bar are equal\n";
//	if (foo!=bar) std::cout << "foo and bar are not equal\n";
//	if (foo< bar) std::cout << "foo is less than bar\n";
//	if (foo> bar) std::cout << "foo is greater than bar\n";
//	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
//	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
//
//	std::cout << std::endl;
//
//	ft::pair <std::string,int> planet, homeplanet;
//
//	planet = ft::make_pair("Earth",6371);
//
//	homeplanet = planet;
//
//	std::cout << "Home planet: " << homeplanet.first << '\n';
//	std::cout << "Planet size: " << homeplanet.second << '\n';
//	return 0;
}