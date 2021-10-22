#include "pair.hpp"
#include "rbtree.hpp"
#include "get_first.hpp"
#include "map.hpp"

int main() {
	ft::rbTree<int, ft::pair<char, int>, ft::get_first<ft::pair<char, int> > > tree;
	tree.insert(ft::pair<char, int>('a', 100));
	tree.insert(ft::pair<char, int>('z', 200));
	ft::rbTree<int, ft::pair<char, int>, ft::get_first<ft::pair<int, int> > >::iterator it = tree.begin();
	tree.insert(it, ft::pair<char, int>('b', 300));
	tree.insert(it, ft::pair<char, int>('c', 400));
    it = tree.begin();
    it++;
    tree.erase(it);
	tree.balance();
	tree.printRBT();
	std::cout << "tree contains: " << std::endl;
	for (it=tree.begin(); it!=tree.end(); ++it)
		std::cout << it->first << " => " << it->second << std::endl;
	std::cout << tree.find('a')->second << std::endl;

//	ft::map<char, int> my;
//	my.insert(ft::pair<char, int>('a', 100));
//	my.insert(ft::pair<char, int>('z', 200));
//	ft::pair<ft::map<char, int>::iterator, bool> ret;
//	ret = my.insert(ft::pair<char, int>('z', 500));
//	// second insert function version (with hint position):
//	ft::map<char,int>::iterator it = my.begin();
//	my.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
//	my.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting
//
//	// third insert function version (range insertion):
//	ft::map<char,int> anothermap;
////	anothermap._insert(my.begin(),my.find('c'));
//
//
//	// showing contents:
//	std::cout << "mymap contains:\n";
//	for (it=my.begin(); it!=my.end(); ++it)
//		std::cout << it->first << " => " << it->second << '\n';
//
//	std::cout << "anothermap contains:\n";
//	for (it=anothermap.begin(); it!=anothermap.end(); ++it)
//		std::cout << it->first << " => " << it->second << '\n';
//
//	return 0;
//	ft::pair<int, int> b(10, 15);
//	ft::rbTree<int, ft::pair<int, int>, ft::get_first<ft::pair<int, int> > > a;
//	a.insert_unique(b);
//	std::cout << a.begin().node->val.second << std::endl;
//	ft::rbTree<int, ft::pair<int, int>, ft::get_first<ft::pair<int, int> > >::iterator aa = a.begin();
//	std::cout << aa->first << std::endl;
//	ft::rbTree<int, ft::pair<int, int>, ft::get_first<ft::pair<int, int> > >::const_iterator aaaa = a.begin();
//	std::cout << aaaa->first << std::endl;
//	ft::pair<int, int> c(11, 16);
//	a.insert_unique(a.begin(), c);
//	std::cout << a.begin().node->val.second << std::endl;
//	ft::rbTree<int, ft::pair<int, int>, ft::get_first<ft::pair<int, int> > >::iterator p = a.begin();
//	++p++;
//	ft::rbTree<int, ft::pair<int, int>, ft::get_first<ft::pair<int, int> > > test;
//	test.insert_unique(a.begin(), a.end());
//	ft::map<int, int> mapp;
//	mapp.insert(b);
//	std::cout << ((a.begin())+2).node->val.second << std::endl;
//	ft::pair<int, int> pair(13,15);
//	ft::pair<int, int> pair2(11,15);
//	ft::rbNode<ft::pair<int, int> >* a = new (ft::rbNode<ft::pair<int, int> >);
//	a->val = pair;
//	ft::rbNode<ft::pair<int, int> >* b = new (ft::rbNode<ft::pair<int, int> >);
//	b->val = pair2;
//	b->right = 0;
//	a->right = b;
//	ft::rbNode<ft::pair<int, int> > f;
////	ft::rb_iterator<ft::pair<int, int> > b;
//	ft::rb_const_iterator<ft::pair<int, int> > c;
//
//	ft::rbTree<char, ft::pair<int, char>, int> dnk;
//	dnk.begin();
//	dnk.end();
//	std::cout << dnk.max_size() << std::endl;
//	std::cout << dnk.size() << std::endl;
//	ft::rbTree<char, ft::pair<int, char>, int > one(dnk);
//	ft::rbTree<char, ft::pair<int, char>, int > lol;
//	lol.equal_range('l');


//	ft::rbTree<char, ft::pair<int, int>, int> A;
//	ft::rbTree<char, ft::pair<int, int>, int> B(A);
//
//	std::cout << A.size() << " " << B.size() << std::endl;
 //	std::cout << ft::rbNode<ft::pair<int, int> >::maximum(a)->val.first << std::endl;
//	std::allocator<int> alloc;
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
