#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <iostream>

namespace ft
{
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
		bool operator==(const iterator & rhs) {
			return this->ptr == rhs.ptr;
		}
		bool operator!=(const iterator & rhs) {
			return this->ptr != rhs.ptr;
		}
		bool operator<(const iterator & rhs) {
			return this->ptr < rhs.ptr;
		}
		bool operator<=(const iterator & rhs) {
			return this->ptr <= rhs.ptr;
		}
		bool operator>(const iterator & rhs) {
			return this->ptr > rhs.ptr;
		}
		bool operator>=(const iterator & rhs) {
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
		iterator operator+(const difference_type & a) {
			return this->ptr + a;
		}
		iterator operator-(const difference_type & a) {
			return this->ptr - a;
		}
		difference_type operator-(const iterator &b) {
			return this->ptr - b.ptr;
		}
		iterator & operator+=(const difference_type & a) {
			return this->ptr += a;
		}
		iterator & operator-=(const difference_type & a) {
			return this->ptr -= a;
		}
		pointer operator->()
		{
			return this->ptr;
		}
		value_type & operator*() {
			return *ptr;
		}
		iterator & operator[](difference_type n) const {
			return (*(*this + n));
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
		const_iterator operator+(const difference_type & a) {
			return this->ptr + a;
		}
		const_iterator operator-(const difference_type & a) {
			return this->ptr - a;
		}
		const_iterator & operator+=(const difference_type & a) {
			return this->ptr += a;
		}
		const_iterator & operator-=(const difference_type & a) {
			return this->ptr -= a;
		}
		pointer operator->()
		{
			return this->ptr;
		}
		value_type & operator*() {
			return *ptr;
		}
		const_iterator & operator[](difference_type n) const {
			return (*(*this + n));
		}
	};
	template <typename T> class reverse_iterator {
	public:
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;
		pointer ptr;

		reverse_iterator() { this->ptr = NULL;}
		reverse_iterator(const reverse_iterator & rhs) {
			*this = rhs;
		}
		reverse_iterator(pointer rhs) {
			this->ptr = rhs;
		}
		~reverse_iterator() {}
		reverse_iterator & operator=(const reverse_iterator & rhs) {
			this->ptr = rhs.ptr;
			return *this;
		}
		bool operator==(const reverse_iterator &rhs) {
			return this->ptr == rhs.ptr;
		}
		bool operator!=(const reverse_iterator & rhs) {
			return this->ptr != rhs.ptr;
		}
		bool operator<(const reverse_iterator & rhs) {
			return this->ptr < rhs.ptr;
		}
		bool operator<=(const reverse_iterator & rhs) {
			return this->ptr <= rhs.ptr;
		}
		bool operator>(const reverse_iterator & rhs) {
			return this->ptr > rhs.ptr;
		}
		bool operator>=(const reverse_iterator & rhs) {
			return this->ptr >= rhs.ptr;
		}
		reverse_iterator & operator++() {
			--this->ptr;
			return *this;
		}
		reverse_iterator & operator++(int) {
			reverse_iterator tmp = *this;
			--this->ptr;
			return tmp;
		}
		reverse_iterator & operator--() {
			++this->ptr;
			return *this;
		}
		reverse_iterator & operator--(int) {
			reverse_iterator tmp = *this;
			++this->ptr;
			return tmp;
		}
		reverse_iterator operator+(const difference_type & a) {
			return this->ptr - a;
		}
		reverse_iterator operator-(const difference_type & a) {
			return this->ptr + a;
		}
		reverse_iterator & operator+=(const difference_type & a) {
			return this->ptr -= a;
		}
		reverse_iterator & operator-=(const difference_type & a) {
			return this->ptr += a;
		}
		pointer operator->() {
			return this->ptr;
		}
		value_type & operator*() {
			return *ptr;
		}
		reverse_iterator & operator[](difference_type n) const {
			return (*(this + n));
		}
	};
	template <typename T> class const_reverse_iterator {
	public:
		typedef const T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;
		pointer ptr;

		const_reverse_iterator() { this->ptr = NULL;}
		const_reverse_iterator(const const_reverse_iterator & rhs) {
			*this = rhs;
		}
		const_reverse_iterator(const reverse_iterator<T> & rhs) {
			*this = rhs;
		}
		const_reverse_iterator(pointer rhs) {
			this->ptr = rhs;
		}
		~const_reverse_iterator() {}
		const_reverse_iterator & operator=(const const_reverse_iterator & rhs) {
			this->ptr = rhs.ptr;
			return *this;
		}
		const_reverse_iterator & operator=(const reverse_iterator<T> & rhs) {
			if (this != rhs)
				this->ptr = rhs.ptr;
			return *this;
		}
		bool operator==(const const_reverse_iterator &rhs) {
			return this->ptr == rhs.ptr;
		}
		bool operator!=(const const_reverse_iterator & rhs) {
			return this->ptr != rhs.ptr;
		}
		bool operator<(const const_reverse_iterator & rhs) {
			return this->ptr < rhs.ptr;
		}
		bool operator<=(const const_reverse_iterator & rhs) {
			return this->ptr <= rhs.ptr;
		}
		bool operator>(const const_reverse_iterator & rhs) {
			return this->ptr > rhs.ptr;
		}
		bool operator>=(const const_reverse_iterator & rhs) {
			return this->ptr >= rhs.ptr;
		}
		const_reverse_iterator & operator++() {
			--this->ptr;
			return *this;
		}
		const_reverse_iterator & operator++(int) {
			const_reverse_iterator tmp = *this;
			--this->ptr;
			return tmp;
		}
		const_reverse_iterator & operator--() {
			++this->ptr;
			return *this;
		}
		const_reverse_iterator & operator--(int) {
			const_reverse_iterator tmp = *this;
			++this->ptr;
			return tmp;
		}
		const_reverse_iterator operator+(const difference_type & a) {
			return this->ptr - a;
		}
		const_reverse_iterator operator-(const difference_type & a) {
			return this->ptr + a;
		}
		const_reverse_iterator & operator+=(const difference_type & a) {
			return this->ptr -= a;
		}
		const_reverse_iterator & operator-=(const difference_type & a) {
			return this->ptr += a;
		}
		pointer operator->() {
			return this->ptr;
		}
		value_type & operator*() {
			return *ptr;
		}
		const_reverse_iterator & operator[](difference_type n) const {
			return (*(this + n));
		}
	};
}

#endif