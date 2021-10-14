#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator_traits.hpp"
#include <iostream>
#include <cstddef>

namespace ft
{
	template <typename T> class ConstRanIt;
	template <typename T> class RanItIt
	{
	public:
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;

		pointer base() const {
			return ptr;
		}
		RanItIt() { this->ptr = NULL; }
		RanItIt(const RanItIt & rhs) {
			*this = rhs;
		}
		RanItIt(pointer rhs)
		{
			this->ptr = rhs;
		}
		~RanItIt() {}
		RanItIt & operator=(const RanItIt & rhs) {
			this->ptr = rhs.base();
			return *this;
		}
		bool operator==(const RanItIt & rhs) const {
			return this->ptr == rhs.base();
		}
		bool operator==(const ConstRanIt<T> & rhs) const {
			return this->ptr == rhs.base();
		}
		bool operator!=(const RanItIt & rhs) const {
			return this->ptr != rhs.base();
		}
		bool operator!=(const ConstRanIt<T> & rhs) const {
			return this->ptr != rhs.base();
		}
		bool operator<(const RanItIt & rhs) {
			return this->ptr < rhs.base();
		}
		bool operator<(const ConstRanIt<T> & rhs){
			return this->ptr < rhs.base();
		}
		bool operator<=(const RanItIt & rhs) {
			return this->ptr <= rhs.base();
		}
		bool operator<=(const ConstRanIt<T> & rhs){
			return this->ptr <= rhs.base();
		}
		bool operator>(const RanItIt & rhs) {
			return this->ptr > rhs.base();
		}
		bool operator>(const ConstRanIt<T> & rhs){
			return this->ptr > rhs.base();
		}
		bool operator>=(const RanItIt & rhs) {
			return this->ptr >= rhs.base();
		}
		bool operator>=(const ConstRanIt<T> & rhs){
			return this->ptr >= rhs.base();
		}
		RanItIt & operator++() {
			++this->ptr;
			return *this;
		}
		RanItIt operator++(int) {
			RanItIt tmp = *this;
			++this->ptr;
			return tmp;
		}
		RanItIt & operator--() {
			--this->ptr;
			return *this;
		}
		RanItIt operator--(int) {
			RanItIt tmp = *this;
			--this->ptr;
			return tmp;
		}
		RanItIt operator+(difference_type a) const {
			return this->ptr + a;
		}

		template<typename L>
		friend RanItIt<L> operator+(typename RanItIt<L>::difference_type a, const RanItIt<L> & iter);

		RanItIt operator-(difference_type a) const {
			return this->ptr - a;
		}
		difference_type operator-(const RanItIt b) const {
			return this->ptr - b.base();
		}
		difference_type operator-(const ConstRanIt<T> &b) const {
			return this->ptr - b.base();
		}
		RanItIt & operator+=(difference_type a) {
			this->ptr += a;
			return *this;
		}
		RanItIt & operator-=(difference_type a) {
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
	private:
		pointer ptr;
	};
	template <typename T> class ConstRanIt
	{
	public:
		typedef const T value_type;
		typedef ptrdiff_t difference_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;

		pointer base() const {
			return ptr;
		}
		ConstRanIt() { this->ptr = NULL; }
		ConstRanIt(const ConstRanIt & rhs) {
			*this = rhs;
		}
		ConstRanIt(const RanItIt<T> & rhs) {
			*this = rhs;
		}
		ConstRanIt(pointer rhs)
		{
			this->ptr = rhs;
		}
		~ConstRanIt() {}
		ConstRanIt & operator=(const ConstRanIt & rhs) {
			this->ptr = rhs.base();
			return *this;
		}
		ConstRanIt & operator=(const RanItIt<T> & rhs) {
			this->ptr = rhs.base();
			return *this;
		}
		bool operator==(const ConstRanIt & rhs) {
			return this->ptr == rhs.base();
		}
		bool operator!=(const ConstRanIt & rhs) {
			return this->ptr != rhs.base();
		}
		bool operator<(const ConstRanIt & rhs) {
			return this->ptr < rhs.base();
		}
		bool operator<=(const ConstRanIt & rhs) {
			return this->ptr <= rhs.base();
		}
		bool operator>(const ConstRanIt & rhs) {
			return this->ptr > rhs.base();
		}
		bool operator>=(const ConstRanIt & rhs) {
			return this->ptr >= rhs.base();
		}
		ConstRanIt & operator++() {
			++this->ptr;
			return *this;
		}
		ConstRanIt operator++(int) {
			ConstRanIt tmp = *this;
			++this->ptr;
			return tmp;
		}
		ConstRanIt & operator--() {
			--this->ptr;
			return *this;
		}
		ConstRanIt operator--(int) {
			ConstRanIt tmp = *this;
			--this->ptr;
			return tmp;
		}
		ConstRanIt operator+(difference_type a) const {
			return this->ptr + a;
		}
		ConstRanIt operator-(difference_type a) const {
			return this->ptr - a;
		}
		difference_type operator-(const RanItIt<T>& a) const {
			return this->ptr - a.base();
		}
		difference_type operator-(const ConstRanIt<T>& a) const {
			return this->ptr - a.base();
		}
		ConstRanIt & operator+=(difference_type a) {
			this->ptr += a;
			return *this;
		}
		ConstRanIt & operator-=(difference_type a) {
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
	private:
		pointer ptr;
	};
	template <typename L>
	RanItIt<L> operator+(typename RanItIt<L>::difference_type a, const RanItIt<L> & iter){
		return iter.base() + a;
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

