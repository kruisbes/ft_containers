#ifndef SET_HPP
#define SET_HPP

#include <iostream>
#include "../map/rbtree.hpp"

namespace ft {
	template <typename T>
	struct ret_value {
		T& operator()(T& value) {
			return value;
		}
		const T& operator(const T& value) const {
			return value;
		}
	};

	template <class T, class Compare = std::less<Key>, class Allocator = std::allocator<T> >
	class set {
	public:

		// DEF
		typedef T									key_type;
		typedef T									value_type;
		typedef std::size_t							size_type;
		typedef std::ptrdiff_t						difference_type;
		typedef Compare								key_compare;
		typedef Compare								value_compare;
		typedef Allocator							allocator_type;
		typedef rbTree<key_type, value_type, ft::ret_value<value_type>, key_compare, allocator_type> tree;
		typedef typename Allocator::reference						reference;
		typedef typename Allocator::const_reference					const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef typename tree::iterator iterator;
		typedef typename tree::const_iterator const_iterator;
		typedef typename tree::reverse_iterator reverse_iterator;
		typedef typename tree::const_reverse_iterator const_reverse_iterator;

		// CONSTRUCTORS + DESTRUCTOR

		explicit set(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : _tree(comp, alloc) {}

		template<class InputIterator>
		set(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type()) : _tree(comp, alloc) {
			_tree.insert(first, last);
		}

		set(const set& x) : _tree(x._tree) {}

		// OPERATORS

		set& operator=(const set& other) {
			_tree = other._tree;
		}
		// MEMBER FUNCTIONS
		iterator begin() {
			return _tree.begin();
		}
		const_iterator begin() const {
			return _tree.begin();
		}
		void clear() {
			return _tree.clear();
		}
		size_type count(const key_type& k) const {
			return _tree.count(k);
		}
		bool empty() const {
			return _tree.empty();
		}
		iterator end() {
			return _tree.end();
		}
		const_iterator end() const {
			return _tree.end();
		}
		ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
			return _tree.equal_range(k);
		}
		ft::pair<iterator, iterator> equal_range(const key_type& k) {
			return _tree.equal_range(k);
		}
		void erase(iterator position) {
			_tree.erase(position);
		}
		size_type erase(const key_type& k) {
			return _tree.erase(k);
		}
		void erase(iterator first, iterator last) {
			_tree.erase(first, last);
		}
		iterator find(const key_type& k) {
			return _tree.find(k);
		}
		const_iterator find(const key_type& k) const {
			return _tree.find(k);
		}
		allocator_type get_allocator() const {
			return _tree.get_allocator();
		}
		ft::pair<iterator, bool> insert(const value_type& val) {
			return _tree.insert(val);
		}
		iterator insert(iterator position, const value_type& val) {
			return _tree.insert(position, val);
		}
		template<class InputIterator>
		void insert(InputIterator first, InputIterator last) {
			_tree.insert(first, last);
		}
		key_compare key_comp() const {
			return _tree.key_comp();
		}
		iterator lower_bound(const key_type& k) {
			return _tree.lower_bound(k);
		}
		const_iterator lower_bound(const key_type& k) const {
			return _tree.lower_bound(k);
		}
		size_type max_size() const {
			return _allocator.max_size();
		}
		reverse_iterator rbegin() {
			return _tree.rbegin();
		}
		const_reverse_iterator rbegin() const {
			return _tree.rbegin();
		}
		reverse_iterator rend() {
			return _tree.rend();
		}
		const_reverse_iterator rend() const {
			return _tree.rend();
		}
		size_type size() const {
			return _tree.size();
		}
		void swap(set& x) {
			_tree.swap(x._tree);
		}
		iterator upper_bound(const key_type& k) {
			return _tree.upper_bound(k);
		}
		const_iterator upper_bound(const key_type& k) const {
			return _tree.upper_bound(k);
		}
		value_compare value_comp() const {
			return value_compare(_tree.key_comp());
		}
		template<typename T1, typename Comp, typename Alloc>
		friend bool operator==(const set<T1, Comp, Alloc>& x, const set<T1, Comp, Alloc>& y);
		template<typename T1, typename Comp, typename Alloc>
		friend bool operator<(const set<T1, Comp, Alloc>& x, const set<T1, Comp, Alloc>& y);

	private:
		tree _tree;
		allocator_type _allocator;
	};

	template<typename T1, typename Comp, typename Alloc>
	inline bool operator==(const set<T1, Comp, Alloc> &x, const set<T1, Comp, Alloc> &y) {
		return x._tree == y._tree;
	}
	template<typename T1, typename Comp, typename Alloc>
	inline bool operator!=(const set<T1, Comp, Alloc> &x, const set<T1, Comp, Alloc> &y) {
		return !(x == y);
	}
	template<typename T1, typename Comp, typename Alloc>
	inline bool operator<(const set<T1, Comp, Alloc> &x, const set<T1, Comp, Alloc> &y) {
		return x._tree < y._tree;
	}
	template<typename T1, typename Comp, typename Alloc>
	inline bool operator>(const set<T1, Comp, Alloc> &x, const set<T1, Comp, Alloc> &y) {
		return y < x;
	}
	template<typename T1, typename Comp, typename Alloc>
	inline bool operator<=(const set<T1, Comp, Alloc> &x, const set<T1, Comp, Alloc> &y) {
		return !(y < x);
	}
	template<typename T1, typename Comp, typename Alloc>
	inline bool operator>=(const set<T1, Comp, Alloc> &x, const set<T1, Comp, Alloc> &y) {
		return !(x < y);
	}
	template<typename T1, typename Comp, typename Alloc>
	inline void swap(const set<T1, Comp, Alloc> &x, const set<T1, Comp, Alloc> &y) {
		x.swap(y);
	}
}

#endif
