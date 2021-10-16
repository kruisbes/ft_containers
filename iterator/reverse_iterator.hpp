#ifndef REVERSE_ITERATOR_HPP
#define REVERSE_ITERATOR_HPP

#include "iterator_traits.hpp"

namespace ft {
	template <class Iter>
	class reverse_iterator {
	public:
		typedef Iter iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer pointer;
		typedef typename ft::iterator_traits<Iter>::reference reference;

		reverse_iterator() : _it() {}
		explicit reverse_iterator(iterator_type x) : _it(x) {}
		template<class U>
		reverse_iterator(const reverse_iterator<U>& other) : _it(other.base()) {}

		template<class U>
		reverse_iterator& operator=(const reverse_iterator<U>& other) {
			_it= other.base();
			return *this;
		}
		iterator_type base() const {
			return _it;
		}
		reference operator*() const {
			Iter tmp = _it;
			return *--tmp;
		}
		pointer operator->() const {
			return --_it;
		}
		reference operator[](difference_type n) const {
			return *(*this + n);
		}
		reverse_iterator& operator++() {
			--_it;
			return *this;
		}
		reverse_iterator& operator--() {
			++_it;
			return *this;
		}
		reverse_iterator operator++(int) {
			reverse_iterator tmp(*this);
			--_it;
			return tmp;
		}
		reverse_iterator operator--(int) {
			reverse_iterator tmp(*this);
			++_it;
			return tmp;
		}
		reverse_iterator operator+(difference_type n) const {
			return reverse_iterator(_it - n);
		}
		reverse_iterator operator-(difference_type n) const {
			return reverse_iterator(_it + n);
		}
		reverse_iterator& operator+=(difference_type n) {
			_it -= n;
			return *this;
		}
		reverse_iterator& operator-=(const difference_type n) {
			_it += n;
			return *this;
		}
	protected:
		Iter _it;
	};
	template <class Iter1, class Iter2>
	inline bool operator==(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y) {
		return x.base() == y.base();
	}
	template <class Iter1, class Iter2>
	inline bool operator!=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y) {
		return x.base() != y.base();
	}
	template <class Iter1, class Iter2>
	inline bool operator<(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y) {
		return x.base() < y.base();
	}
	template <class Iter1, class Iter2>
	inline bool operator<=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y) {
		return x.base() <= y.base();
	}
	template <class Iter1, class Iter2>
	inline bool operator>(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y) {
		return x.base() > y.base();
	}
	template <class Iter1, class Iter2>
	inline bool operator>=(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y) {
		return x.base() >= y.base();
	}
	template <class Iter1, class Iter2>
	typename reverse_iterator<Iter1>::difference_type
	operator-(const reverse_iterator<Iter1>& x, const reverse_iterator<Iter2>& y) {
		return y.base() - x.base();
	}
	template <class Iter>
	reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type n,
									 const reverse_iterator<Iter>& x) {
		return reverse_iterator<Iter>(x.base() - n);
	}
}

#endif
