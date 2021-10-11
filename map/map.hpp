#ifndef FT_CONTAINERS_MAP_HPP
#define FT_CONTAINERS_MAP_HPP

#include "pair.hpp"
// elements in a map are always sorted by its key
namespace ft {
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map {
	public:

		// DEF

		typedef Key									key_type;
		typedef T									mapped_type;
		typedef ft::pair<const Key, T>				value_type;
		typedef std::size_t							size_type;
		typedef std::ptrdiff_t						difference_type;
		typedef Compare								key_compare;
		typedef Allocator							allocator_type;
		typedef value_type&							reference;
		typedef const value_type&					const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;
		typedef std::iterator<std::bidirectional_iterator_tag, mapped_type, difference_type, pointer, reference> iterator;
		typedef std::iterator<std::bidirectional_iterator_tag, const mapped_type, difference_type, const_pointer, const_reference> const_iterator;
		typedef std::reverse_iterator<iterator> reverse_iterator;
		typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

//		typedef ft::map_iterator<value_type> iterator;
//		typedef ft::const_map_iterator<value_type> const_iterator;
//		typedef ft::map_reverse_iterator<value_type> reverse_iterator;
//		typedef ft::const_map_reverse_iterator<value_type> const_reverse_iterator;

		// VALUE COMPARE CLASS

		class value_compare {
			friend class map;
		public:
			value_compare() {}
			~value_compare() {}

			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type secont_argument_type;

			bool operator()(const value_type& lhs, const value_type& rhs) const {
				return comp(lhs.first, rhs.first);
			} // compares two values of type value_type

		protected:
			Compare comp; // the stored comparator
			value_compare(Compare c) : comp(c) {} // initializes the internal instance of the comparator to c
		};

		// CONSTRUCTORS + DESTRUCTOR

		explicit map(const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type());

		template<class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare& comp = key_compare(),
			const allocator_type& alloc = allocator_type());

		map(const map& x);

		~map();

		// OPERATORS

		map& operator=(const map& other);
		mapped_type& operator[] (const key_type& k);

		// MEMBER FUNCTIONS
		iterator begin();
		const_iterator begin() const;
		void clear();
		size_type count(const key_type& k) const;
		bool empty() const {
			return _size == 0;
		}
		iterator end();
		const_iterator end() const;
		ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const;
		ft::pair<iterator, iterator> equal_range(const key_type& k);
		void erase(iterator position);
		size_type erase(const key_type& k);
		void erase(iterator first, iterator last);
		iterator find(const key_type& k);
		const_iterator find(const key_type& k) const;
		allocator_type get_allocator() const;
		ft::pair<iterator, bool> insert(const value_type& val);
		iterator insert(iterator position, const value_type& val);
		template<class InputIterator>
		void insert(InputIterator first, InputIterator last);
		key_compare key_comp() const;
		iterator lower_bound(const key_type& k);
		const_iterator lower_bound(const key_type& k) const;
		size_type max_size() const {
			return _allocator.max_size();
		}
		reverse_iterator rbegin();
		const_reverse_iterator rbegin() const;
		reverse_iterator rend();
		const_reverse_iterator rend() const;
		size_type size() const {
			return _size;
		}
		void swap(map& x);
		iterator upper_bound(const key_type& k);
		const_iterator upper_bound(const key_type& k) const;
		value_compare value_comp() const;

	private:
		size_type _size;
		allocator_type _allocator;
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs);
	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs);
	template <class Key, class T, class Compare, class Alloc>
	bool operator<(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs);
	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs);
	template <class Key, class T, class Compare, class Alloc>
	bool operator>(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs);
	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key, T, Compare, Alloc>& lhs, const map<Key, T, Compare, Alloc>& rhs);
}

#endif
