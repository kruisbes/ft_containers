#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator_traits.hpp"
#include <iostream>
#include <cstddef>

namespace ft
{
	template <typename T> class const_iterator;
	template <typename T> class iterator
	{
	public:
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
		pointer ptr;

		iterator() { this->ptr = NULL; }
		iterator(const iterator & rhs) {
			*this = rhs;
		}
		iterator(pointer rhs)
		{
			this->ptr = rhs;
		}
		~iterator() {}
		iterator & operator=(const iterator & rhs) {
			this->ptr = rhs.ptr;
			return *this;
		}

		bool operator==(const iterator & rhs) const {
			return this->ptr == rhs.ptr;
		}
		bool operator==(const const_iterator<T> & rhs) const {
			return this->ptr == rhs.ptr;
		}
		bool operator!=(const iterator & rhs) const {
			return this->ptr != rhs.ptr;
		}
		bool operator!=(const const_iterator<T> & rhs) const {
			return this->ptr != rhs.ptr;
		}
		bool operator<(const iterator & rhs) {
			return this->ptr < rhs.ptr;
		}
		bool operator<(const const_iterator<T> & rhs){
			return this->ptr < rhs.ptr;
		}
		bool operator<=(const iterator & rhs) {
			return this->ptr <= rhs.ptr;
		}
		bool operator<=(const const_iterator<T> & rhs){
			return this->ptr <= rhs.ptr;
		}
		bool operator>(const iterator & rhs) {
			return this->ptr > rhs.ptr;
		}
		bool operator>(const const_iterator<T> & rhs){
			return this->ptr > rhs.ptr;
		}
		bool operator>=(const iterator & rhs) {
			return this->ptr >= rhs.ptr;
		}
		bool operator>=(const const_iterator<T> & rhs){
			return this->ptr >= rhs.ptr;
		}
		iterator & operator++() {
			++this->ptr;
			return *this;
		}
		iterator operator++(int) {
			iterator tmp = *this;
			++this->ptr;
			return tmp;
		}
		iterator & operator--() {
			--this->ptr;
			return *this;
		}
		iterator operator--(int) {
			iterator tmp = *this;
			--this->ptr;
			return tmp;
		}
		iterator operator+(difference_type a) const {
			return this->ptr + a;
		}

		template<typename L>
		friend iterator<L> operator+(typename iterator<L>::difference_type a, const iterator<L> & iter);

		iterator operator-(difference_type a) const {
			return this->ptr - a;
		}
		difference_type operator-(const iterator b) const {
			return this->ptr - b.ptr;
		}
		difference_type operator-(const const_iterator<T> &b) const {
			return this->ptr - b.ptr;
		}
		iterator & operator+=(difference_type a) {
			this->ptr += a;
			return *this;
		}
		iterator & operator-=(difference_type a) {
			this->ptr -= a;
			return *this;
		}

		pointer operator->()
		{
			return this->ptr;
		}
		value_type & operator*() {
			return *ptr;
		}
		reference operator[](difference_type n) const {
			return (*(this->ptr + n));
		}
	};
	template <typename T> class const_iterator
	{
	public:
		typedef const T value_type;
		typedef ptrdiff_t difference_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;
		pointer ptr;

		const_iterator() { this->ptr = NULL; }
		const_iterator(const const_iterator & rhs) {
			*this = rhs;
		}
		const_iterator(const iterator<T> & rhs) {
			*this = rhs;
		}
		const_iterator(pointer rhs)
		{
			this->ptr = rhs;
		}
		~const_iterator() {}
		const_iterator & operator=(const const_iterator & rhs) {
			this->ptr = rhs.ptr;
			return *this;
		}
		const_iterator & operator=(const iterator<T> & rhs) {
			this->ptr = rhs.ptr;
			return *this;
		}
		bool operator==(const const_iterator & rhs) {
			return this->ptr == rhs.ptr;
		}
		bool operator!=(const const_iterator & rhs) {
			return this->ptr != rhs.ptr;
		}
		bool operator<(const const_iterator & rhs) {
			return this->ptr < rhs.ptr;
		}
		bool operator<=(const const_iterator & rhs) {
			return this->ptr <= rhs.ptr;
		}
		bool operator>(const const_iterator & rhs) {
			return this->ptr > rhs.ptr;
		}
		bool operator>=(const const_iterator & rhs) {
			return this->ptr >= rhs.ptr;
		}
		const_iterator & operator++() {
			++this->ptr;
			return *this;
		}
		const_iterator operator++(int) {
			const_iterator tmp = *this;
			++this->ptr;
			return tmp;
		}
		const_iterator & operator--() {
			--this->ptr;
			return *this;
		}
		const_iterator operator--(int) {
			const_iterator tmp = *this;
			--this->ptr;
			return tmp;
		}
		const_iterator operator+(difference_type a) const {
			return this->ptr + a;
		}
		const_iterator operator-(difference_type a) const {
			return this->ptr - a;
		}
		difference_type operator-(const iterator<T>& a) const {
			return this->ptr - a.ptr;
		}
		difference_type operator-(const const_iterator<T>& a) const {
			return this->ptr - a.ptr;
		}
		const_iterator & operator+=(difference_type a) {
			this->ptr += a;
			return *this;
		}
		const_iterator & operator-=(difference_type a) {
			this->ptr -= a;
			return *this;
		}
		pointer operator->()
		{
			return this->ptr;
		}
		value_type & operator*() {
			return *ptr;
		}
		reference operator[](difference_type n) const {
			return (*(this->ptr + n));
		}
	};
	template <typename L>
	iterator<L> operator+(typename iterator<L>::difference_type a, const iterator<L> & iter){
		return iter.ptr + a;
	}

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

