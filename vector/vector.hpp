#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <iostream>
#include "../iterator/iterator.hpp"
#include "../utility/type_traits.hpp"
#include "../utility/algorithm.hpp"

namespace ft {
	template <class T, class Allocator = std::allocator<T> >
	class vector {
	public:

		// DEF

		typedef T										value_type;
		typedef Allocator								allocator_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		typedef ft::iterator<T>							iterator;
		typedef ft::const_iterator<T>					const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		// CONSTRUCTORS + DESTRUCTOR

		vector() : _vec(0), _size(0), _capacity(0), _allocator(allocator_type()) {}

		explicit vector(const Allocator & al)  : _vec(0), _size(0), _capacity(0), _allocator(al) {}

		explicit vector(size_type n) : _size(n), _capacity(n) {
			_vec = _allocator.allocate(n);
			for (size_type i = 0; i < n; i++) {
				_allocator.construct(_vec + i, T());
			}
		}

		vector(size_type n, const T & val) : _size(n), _capacity(n), _allocator(allocator_type()) {
			_vec = _allocator.allocate(n);
			for (size_type i = 0; i < n; i++) {
				_allocator.construct(_vec + i, val);
			}
		}

		vector(size_type n, const T & val, const Allocator & al) : _size(n), _capacity(n), _allocator(al) {
			_vec = _allocator.allocate(n);
			for (size_type i = 0; i < n; i++) {
				_allocator.construct(_vec + i, val);
			}
		}

		template<class It>
		vector(It first, typename ft::enable_if<!ft::is_integral<It>::value, It>::type last, const Allocator & al = allocator_type()) : _allocator(al) {
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
//				for (size_type i = 0; i < _size; i++)
//					_allocator.destroy(_vec + i);
				_allocator.deallocate(_vec, _capacity);
			}
			_vec = 0, _size = 0, _capacity = 0;
		}

		// MEMBER FUNCTIONS

		template<typename InputIterator>
		void assign(InputIterator first,  typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last) {
			clear();
			size_type new_cap = std::distance(first, last);
			if (new_cap > _capacity) {
				if (_capacity > 0)
                    _allocator.deallocate(_vec, _capacity);
				_capacity = new_cap;
				_vec = _allocator.allocate(_capacity);
			}
			_size = new_cap;
			for (size_type i = 0; i < _size; ++i)
				_allocator.construct(_vec + i, *(first++));
		}
		void assign(size_type n, const T & val) {
			clear();
            if (n > _capacity) {
                if (_capacity > 0)
                    _allocator.deallocate(_vec, _capacity);
                _capacity = n;
                _vec = _allocator.allocate(_capacity);
            }
            _size = n;
            for (size_type i = 0; i < n; ++i) {
                _allocator.construct(_vec + i, val);
            }
		}
		reference at(size_type n) {
			if (size() <= n)
				throw std::out_of_range("vector");
			return (*(begin() + n));
		}
		const_reference at(size_type n) const {
			if (size() <= n)
				throw std::out_of_range("vector");
			return (*(begin() + n));
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
			_size = 0;
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
				return position;
			}
			size_type pos = std::distance(begin(), position);
			_allocator.destroy(_vec + pos);
			for (size_type i = pos; i < _size; ++i) {
				_allocator.construct(_vec + i, *(_vec + i + 1));
			}
			_size--;
			return position;
		}
		iterator erase(iterator first, iterator last) {
			size_type posf = std::distance(begin(), first);
			size_type posl = std::distance(begin(), last);
			size_type len = std::distance(begin(), end());
			_size -= (posl - posf);
			for (size_type i = posf; i < posl; ++i) {
				_allocator.destroy(_vec + i);
			}
			for (size_type i = posl; i < len; ++i) {
				_allocator.construct(_vec + posf++, *(_vec + i));
			}
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
        iterator insert (iterator position, const value_type & val) {
            size_type pos = std::distance(begin(), position);
            if (_size == _capacity) {
                _capacity = (_capacity == 0) ? 1 : _capacity * 2;
                pointer temp_arr = _allocator.allocate(_capacity);
                for (size_type i = 0; i < pos; ++i)
                    _allocator.construct(temp_arr + i, *(_vec + i));
                _allocator.construct(temp_arr + pos, val);
                _size++;
                for (size_type i = pos; i < _size - 1; ++i)
					_allocator.construct(temp_arr + i + 1, *(_vec + i));
                _allocator.deallocate(_vec, _size - 1);
                _vec = temp_arr;
            }
            else {
                for (size_type i = _size; i > pos; i--) {
					_allocator.construct(_vec + i, *(_vec + i - 1));
					_allocator.destroy(_vec + i - 1);
				}
                _allocator.construct(_vec + pos, val);
                _size++;
            }
            return position;
        }
        void insert(iterator position, size_type n, const value_type & val) {
            size_type pos = std::distance(begin(), position);
            if (_size + n > _capacity) {
                size_type temp_cap = _capacity;
                _capacity = (_capacity == 0) ? 1 : _capacity * 2;
                if (_capacity < _size + n)
                    _capacity = _size + n;
                pointer temp_arr = _allocator.allocate(_capacity);
                size_type i, j;
                for (i = 0; i < pos; ++i)
					_allocator.construct(temp_arr + i, *(_vec + i));
                for (j = pos; j < pos + n; ++j)
                    _allocator.construct(temp_arr + j, val);
                for (; i < _size; ++i, ++j)
					_allocator.construct(temp_arr + j, *(_vec + i));
                _allocator.deallocate(_vec, temp_cap);
                _vec = temp_arr;
                _size += n;
            }
            else {
                size_type cnt;
                if (pos + n > _size) {
                    cnt = _size - pos;
                    _size += n;
                    for (size_type i = _size - 1; cnt > 0; --i, --cnt) {
						_allocator.construct(_vec + i, *(_vec + i - n));
						_allocator.destroy(_vec + i - n);
					}
                    for (size_type i = pos; i < pos + n; ++i)
                        _allocator.construct(_vec + i, val);
                }
                else
                {
                    _size += n;
                    for (size_type i = _size - 1; i > pos + n - 1; i--) {
						_allocator.construct(_vec + i, *(_vec + i - n));
						_allocator.destroy(_vec + i - n);
					}
                    for (size_type i = pos; i < pos + n; ++i)
                        _allocator.construct(_vec + i, val);
                }
            }
        }
        template<class InputIterator>
        void insert(InputIterator position,
                    typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type first,
                    typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type last) {
            if (std::distance(first, last) < 0)
                throw (std::length_error("vector: range insert"));
            size_type pos = std::distance(begin(), position);
            size_type num = std::distance(first, last);
            if (_size + num > _capacity) {
                _size += num;
                size_type temp_cap = _capacity;
                _capacity = (_capacity == 0) ? 1 : _capacity * 2;
                if (_capacity < _size)
                    _capacity = _size;
                pointer temp_arr = _allocator.allocate(_capacity);
                size_type i, j = 0;
                for (i = 0; i < pos; ++i, ++j)
					_allocator.construct(temp_arr + i, *(_vec + i));
				for (; first != last; first++, i++)
                    _allocator.construct(temp_arr + i, *first);
                for (; i < _size; ++i, ++j)
					_allocator.construct(temp_arr + i, *(_vec + j));
                _allocator.deallocate(_vec, temp_cap);
                _vec = temp_arr;
            }
            else {
                size_type cnt;
                if (pos + num > _size) {
                    cnt = _size - pos;
                    _size += num;
                    for (size_type i = _size - 1; cnt > 0; --i, --cnt) {
						_allocator.construct(_vec + i, *(_vec + i - num));
						_allocator.destroy(_vec + i - num);
					}
                    for (size_type i = pos; first != last; first++, i++)
                        _allocator.construct(_vec + i, *first);
                }
                else
                {
                    _size += num;
                    for (size_type i = _size - 1; i > pos + num - 1; i--) {
						_allocator.construct(_vec + i, *(_vec + i - num));
						_allocator.destroy(_vec + i - num);
					}
                    for (size_type i = pos; first != last; first++, i++)
                        _allocator.construct(_vec + i, *first);
                }
            }
        }
		size_type max_size() const {
			return _allocator.max_size();
		}
		vector & operator=(const vector & other) {
			if (_vec != 0)
				clear();
			if (this != other) {
				_allocator = other._allocator;
				_allocator.deallocate(_capacity);
				_capacity = other._capacity;
				_size = other._size;
				_vec = _allocator.allocate(_capacity);
				for (size_type i = 0; i < _size; ++i)
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
			if (_capacity == 0) {
			    _capacity = 1;
			    _vec = _allocator.allocate(_capacity);
			}
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
		    if (max_size() < new_cap)
                throw std::length_error("vector");
		    else if (capacity() < new_cap) {
		        pointer temp_arr = _allocator.allocate(new_cap);
                for (size_type i = 0; i < _size; i++) {
                    _allocator.construct(temp_arr + i, *(_vec + i));
                    _allocator.destroy(_vec + i);
                }
                _allocator.deallocate(_vec, _capacity);
                _capacity = new_cap;
                _vec = _allocator.allocate(_capacity);
                for (size_type i = 0; i < _size; ++i)
                    _allocator.construct(_vec + i, *(temp_arr + i));
                _allocator.deallocate(temp_arr, new_cap);
		    }
		}
		void resize(size_type n, T val = value_type()) {
			if (n > max_size()) {
				throw (std::length_error("vector"));
			}
		    if (_size > n) {
                for (size_type i = n; i < _size; ++i)
                    _allocator.destroy(_vec + i);
                _size = n;
		    }
		    else if (_size < n) {
		        if (_capacity < n) {
		            pointer temp_arr = _allocator.allocate(_size);
		            for (size_type i = 0; i < _size; ++i) {
		                _allocator.construct(temp_arr + i, *(_vec + i));
		                _allocator.destroy(_vec + i);
		            }
		            _allocator.deallocate(_vec, _capacity);
		            _capacity *= 2;
		            if (capacity() < n)
		                _capacity = n;
		            _vec = _allocator.allocate(_capacity);
		            size_type i;
                    for (i = 0; i < _size; ++i)
                        _allocator.construct(_vec + i, *(temp_arr + i));
                    for (; i < n; ++i)
                        _allocator.construct(_vec + i, val);
                    _size = n;
                    _allocator.deallocate(temp_arr, _size);
		        }
		        else {
                    for (size_type i = _size; i < n; ++i)
                        _allocator.construct(_vec + i, val);
                    _size = n;
		        }
		    }
		}
		size_type size() const {
			return _size;
		}
		void swap(vector & x) {
			std::swap(_vec, x._vec);
			std::swap(_size, x._size);
			std::swap(_capacity, x._capacity);
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