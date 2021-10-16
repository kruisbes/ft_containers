#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include <iostream>

namespace ft {
	template <typename T>
	class BidIt {
	public:

		// DEF

		typedef T								value_type;
		typedef T&								reference;
		typedef T*								pointer;
		typedef std::bidirectional_iterator_tag	iterator_category;
		typedef std::ptrdiff_t					difference_type;

		// CONSTRUCTORS + DESTRUCTOR

		BidIt();
		BidIt(const BidIt& other);
		BidIt& operator=(const BidIt& other);
		~BidIt();

		// COMPARISON

		bool operator==(const BidIt& rhs);
		bool operator!=(const BidIt& rhs);

		// DEREFERENCE

		reference operator*();
		pointer operator->();

		// INCREMENT/DECREMENT

		BidIt & operator++();
		BidIt operator++(int);
		BidIt & operator--();
		BidIt operator--(int);
	};
}

#endif
