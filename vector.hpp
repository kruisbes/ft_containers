#ifndef FT_CONTAINERS_VECTOR_HPP
#define FT_CONTAINERS_VECTOR_HPP

#include <iostream>
#include "iterator.hpp"
#include "utils.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
	public:

		// DEF

		typedef T value_type;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef ft::iterator<T> iterator;
		typedef ft::const_iterator<T> const_iterator;
		typedef ft::reverse_iterator<T> reverse_iterator;
		typedef ft::const_reverse_iterator<T> const_reverse_iterator;

		// CONSTRUCTORS + DESTRUCTOR

		vector() : _first(0), _last(0), _end(0), _size(0), _capacity(0) {
			_first = _allocator.allocate(0);
		}

		explicit vector(const Allocator & al)  : _first(0), _last(0), _end(0), _size(0), _capacity(0), _allocator(al) {
			_first = _allocator.allocate(0);
		}

		explicit vector(size_type n) : _size(n), _capacity(n) {
			_first = _allocator.allocate(n, (void*)0);
			_last = _first;
			_end = _first + n;
			pointer tmp = _first;
			for (size_type i = 0; i < n; i++, tmp++) {
				_allocator.construct(tmp, T());
			}
		}

		vector(size_type n, const T & val) : _size(n), _capacity(n) {
			_first = _allocator.allocate(n, (void*)0);
			_last = _first;
			_end = _first + n;
			pointer tmp = _first;
			for (size_type i = 0; i < n; i++, tmp++) {
				_allocator.construct(tmp, val);
			}
		}

		vector(size_type n, const T & val, const Allocator & al) : _size(n), _capacity(n), _allocator(al) {
			_first = _allocator.allocate(n, (void*)0);
			_last = _first;
			_end = _first + n;
			pointer tmp = _first;
			for (size_type i = 0; i < n; i++, tmp++) {
				_allocator.construct(tmp, val);
			}
		}

		template<class It>
		vector(It first, typename enable_if<!is_integral<It>::value>::type last, const Allocator & al = allocator_type()) {

		}

		~vector() {
			if (_first != 0) {
				for (; _first != _last; ++_first)
					_allocator.destroy(_first); // std::allocator<T>::destroy calls the destructor of the object pointed by p
				_allocator.deallocate(_first, _capacity);
			}
			_first = 0, _last = 0, _end = 0, _size = 0, _capacity = 0;
		}

		// MEMBER FUNCTIONS

		template<typename InputIterator>
		void assign(InputIterator first, typename enable_if<!is_integral<InputIterator>::value>::type last) {

		}
		void assign(size_type n, const T & val) {

		}
		reference at(size_type n) {
			if (size() <= n)
				throw std::out_of_range("vector<T>");
			return (*begin() + n);
		}
		const_reference at(size_type n) const {
			if (size() <= n)
				throw std::out_of_range("vector<T>");
			return (*begin() + n);
		}
		reference back() {
			return *(end() - 1);
		}
		const_reference back() const {
			return *(end() - 1);
		}
		iterator begin() {
			return iterator(_first);
		}
		const_iterator begin() const {
			return const_iterator(_first);
		}
		size_type capacity() const {
			return (_first == 0 ? 0 : _end - _first);
		}
		void clear() {
			if (_first != 0)
			{
				for (; _first != _last; ++_first)
					_allocator.destroy(_first);
				_allocator.deallocate(_first, _end - _first);
			}
			_first = 0, _last = 0, _end = 0, _size = 0;
		}
		bool empty() const {
			return size() == 0;
		}
		iterator end() {
			return iterator(_last);
		}
		const_iterator end() const {
			return const_iterator(_last);
		}
		iterator erase(iterator position) {

		}
		iterator erase(iterator first, iterator last) {

		}
		reference front() {
			return (*begin());
		}
		const_reference front() const {
			return (*begin());
		}
		allocator_type get_allocator() const {
			return _allocator;
		}
		iterator insert(iterator position, const T & val) {

		}
		void insert(iterator position, size_type n, const T & val) {

		}
		template<class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last) {

		}
		size_type max_size() const {
			return _allocator.max_size();
		}
		vector & operator=(const vector & x) {

		}
		reference operator[](size_type n) {
			return _first[n];
		}
		const_reference operator[](size_type n) const {
			return _first[n];
		}
		void pop_back() {
			erase(end() - 1);
		}
		void push_back(const T & val) {
			_size++;
			// huh ?
		}
		reverse_iterator rbegin() {
			return reverse_iterator(_end);
		}
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(_end);
		}
		reverse_iterator rend() {
			return reverse_iterator(_first);
		}
		const_reverse_iterator rend() const {
			return const_reverse_iterator(_first);
		}
		void reserve(size_type new_cap) {

		}
		void resize(size_type n, T val = value_type()) {

		}
		size_type size() const {
			return _first == 0 ? 0 : _last - _first;
		}
		void swap(vector & x) {
			if (_allocator == x._allocator) {
				std::swap(_first, x._first);
				std::swap(_last, x._last);
				std::swap(_end, x._end);
			}
			else {
				vector temp = *this;
				*this = x;
				x = temp;
			}
		}
	private:
		pointer _first, _last, _end;
		size_type _size, _capacity;
		allocator_type _allocator;
	};

	template <typename T, typename Alloc>
	inline bool operator==(const vector<T, Alloc> & x, const vector<T, Alloc> & y) {
		if (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()))
			return true;
		else
			return false;
	}
	template<typename T, typename Alloc>
	inline bool operator!=(const vector<T, Alloc> & x, const vector<T, Alloc> & y) {
		if (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()))
			return false;
		else
			return true;
	}
	template <typename T, typename Alloc>
	inline bool operator<(const vector<T, Alloc> & x, const vector<T, Alloc> & y) {
		return ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end());
	}
	template <typename T, typename Alloc>
	inline bool operator<=(const vector<T, Alloc> & x, const vector<T, Alloc> & y) {
		return !(y < x);
	}
	template <typename T, typename Alloc>
	inline bool operator>(const vector<T, Alloc> & x, const vector<T, Alloc> & y) {
		return y < x;
	}
	template <typename T, typename Alloc>
	inline bool operator>=(const vector<T, Alloc> & x, const vector<T, Alloc> & y) {
		return !(x < y);
	}
	template <typename T, typename Alloc>
	inline void swap(vector<T, Alloc> & x, vector<T, Alloc> & y) {
		x.swap(y);
	}
}

#endif
