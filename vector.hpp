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

		vector() : _vec(0), _size(0), _capacity(0), _allocator(allocator_type()) {}

		explicit vector(const Allocator & al)  : _vec(0), _size(0), _capacity(0), _allocator(al) {}

		explicit vector(size_type n) : _size(n), _capacity(n) {
			_vec = _allocator.allocate(n, (void*)0);
			for (size_type i = 0; i < n; i++) {
				_allocator.construct(_vec + i, T());
			}
		}

		vector(size_type n, const T & val) : _size(n), _capacity(n), _allocator(allocator_type()) {
			_vec = _allocator.allocate(n, (void*)0);
			for (size_type i = 0; i < n; i++) {
				_allocator.construct(_vec + i, val);
			}
		}

		vector(size_type n, const T & val, const Allocator & al) : _size(n), _capacity(n), _allocator(al) {
			_vec = _allocator.allocate(n, (void*)0);
			pointer tmp = _vec;
			for (size_type i = 0; i < n; i++, tmp++) {
				_allocator.construct(tmp, val);
			}
		}

		template<class It>
		vector(It first, typename enable_if<!is_integral<It>::value, It>::type last, const Allocator & al = allocator_type()) : _allocator(al) {
			difference_type dist = std::distance(first, last);
			_vec = _allocator.allocate(dist);
			_size = dist;
			_capacity = dist;
			for (size_type i = 0; dist > 0; i++, dist--) {
				_allocator.construct(_vec + i, *(first + i));
			}
		}

		vector(const vector & other) : _allocator(other._allocator){
			_size = other.size();
			_capacity = other.capacity();
			_vec = _allocator.allocate(_capacity);
			for (size_type i = 0; i < _size; i++)
				_allocator.construct(_vec + i, *(other._vec + i));
		}

		~vector() {
			if (_vec != 0) {
				for (size_type i = 0; _vec + i != _vec + _size; i++)
					_allocator.destroy(_vec + i);
				_allocator.deallocate(_vec, _capacity);
			}
			_vec = 0, _size = 0, _capacity = 0;
		}

		// MEMBER FUNCTIONS

		template<typename InputIterator>
		void assign(InputIterator first, typename enable_if<!is_integral<InputIterator>::value>::type last) {

		}
		void assign(size_type n, const T & val) {
			if (n > _capacity) {
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(_vec + i);
				_allocator.deallocate(_vec, _capacity);
				_capacity = n;
				_size = n;
				_allocator.allocate(_capacity);
				for (size_type i = 0; i < n; ++i) {
					_allocator.construct(_vec + i, val);
				}
			}
			else {
				for (size_type i = 0; i < _size; i++)
					_allocator.destroy(_vec + i);
				_size = n;
				for (size_type i = 0; i < n; ++i) {
					_allocator.construct(_vec + i, val);
				}
			}
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
			return iterator(_vec);
		}
		const_iterator begin() const {
			return const_iterator(_vec);
		}
		size_type capacity() const {
			return _capacity;
		}
		void clear() {
			if (_vec != 0) {
				for (size_type i = 0; _vec + i != _vec + _size; i++)
					_allocator.destroy(_vec + i);
			}
			_vec = 0, _size = 0;
		}
		bool empty() const {
			return size() == 0;
		}
		iterator end() {
			return iterator(_vec + _size);
		}
		const_iterator end() const {
			return const_iterator(_vec + _size);
		}
		iterator erase(iterator position) {
			if (position == end() - 1) {
				_allocator.destroy(_vec + _size);
				_size--;
				return _vec;
			}
			pointer temp_arr = _allocator.allocate(_size);
			for (size_type i = 0; i < _size; i++) {
				_allocator.construct(temp_arr + i, *(_vec + i));
				_allocator.destroy(_vec + i);
			}
			size_type j = 0;
			difference_type pos = std::distance(begin(), position);
			for (size_type i = 0; i < _size; ++i) {
				if (i == pos)
					continue;
				_allocator.construct(_vec + j, *(temp_arr + i));
				j++;
			}
			_allocator.deallocate(temp_arr, _size);
			_size--;
			return _vec;
		}
		iterator erase(iterator first, iterator last) {
			pointer temp_arr = _allocator.allocate(_size);
			for (size_type i = 0; i < _size; i++) {
				_allocator.construct(temp_arr + i, *(_vec + i));
				_allocator.destroy(_vec + i);
			}
			size_type posf = std::distance(begin(), first);
			size_type posl = std::distance(begin(), last);
			size_type del = posl - posf;
			size_type j = 0;
			for (size_type i = 0; i < _size; ++i) {
				if (i >= posf && i <= posl)
					continue;
				_allocator.construct(_vec + j, *(temp_arr + i));
				j++;
			}
			_size -= del;
			_allocator.deallocate(temp_arr, _size);
			return _vec;
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
			_size++;
			pointer temp_arr = _allocator.allocate(_size);
			for (size_type i = 0; i < _size; i++) {
				_allocator.construct(temp_arr + i, *(_vec + i));
				_allocator.destroy(_vec + i);
			}
			size_type pos = std::distance(begin(), position);
			if (_size > _capacity) {
				_allocator.deallocate(_vec, _capacity);
				_capacity *= 2;
				_vec = _allocator.allocate(_capacity);
			}
			for (size_type i = 0; i < pos; ++i) {
				_allocator.construct(_vec + i, *(temp_arr + i));
			}
			_allocator.construct(_vec + pos, val);
			for (; pos + 1 < _size; ++pos) {
				_allocator.construct(_vec + pos + 1, *(temp_arr + pos));
			}
			_allocator.deallocate(temp_arr, _size);
			return _vec;
		}
		void insert(iterator position, size_type n, const T & val) {

		}
		template<class InputIterator>
		void insert(iterator position, InputIterator first, InputIterator last) {

		}
		size_type max_size() const {
			return _allocator.max_size();
		}
		vector & operator=(const vector & other) {
			if (_vec != 0) {
				this->clear();
			}
			if (this != other)
			{
				_size = other.size();
				_capacity = other.capacity();
				_vec = _allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; i++)
					_allocator.construct(_vec + i, *(other._vec + i));
			}
			return *this;
		}
		reference operator[](size_type n) {
			return _vec[n];
		}
		const_reference operator[](size_type n) const {
			return _vec[n];
		}
		void pop_back() {
			erase(end() - 1);
		}
		void push_back(const T & val) {
			_size++;
			if (_size > _capacity) {
				pointer temp_arr = _allocator.allocate(_size);
				for (size_type i = 0; i < _size; i++) {
					_allocator.construct(temp_arr + i, *(_vec + i));
					_allocator.destroy(_vec + i);
				}
				_allocator.construct(temp_arr + _size - 1, val);
				_allocator.deallocate(_vec, _capacity);
				_capacity *= 2;
				_vec = _allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; ++i)
					_allocator.construct(_vec + i, *(temp_arr + i));
				_allocator.deallocate(temp_arr, _size);
			}
			else {
				_allocator.construct(_vec + _size - 1, val);
			}
		}
		reverse_iterator rbegin() {
			return reverse_iterator(_vec + _size);
		}
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(_vec + _size);
		}
		reverse_iterator rend() {
			return reverse_iterator(_vec);
		}
		const_reverse_iterator rend() const {
			return const_reverse_iterator(_vec);
		}
		void reserve(size_type new_cap) {

		}
		void resize(size_type n, T val = value_type()) {

		}
		size_type size() const {
			return _size;
		}
		void swap(vector & x) {
		}
	private:
		pointer _vec;
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
