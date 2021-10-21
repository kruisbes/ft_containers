#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <iostream>
#include <iomanip>
#include "pair.hpp"
#include "../iterator/reverse_iterator.hpp"

namespace ft {
	enum rbColor {red = false, black = true};

	template <typename Val>
	struct rbNode {
		typedef rbNode<Val>* pointer;
		typedef const rbNode<Val>* const_pointer;
		rbColor		clr;
		rbNode*		parent;
		rbNode*		left;
		rbNode*		right;
		Val			val;

		static pointer minimum(pointer x) {
			while (x->left != NULL)
				x = x->left;
			return x;
		}
		static const_pointer minimum(const_pointer x) {
			while (x->left != NULL)
				x = x->left;
			return x;
		}
		static pointer maximum(pointer x) {
			while (x->right != NULL)
				x = x->right;
			return x;
		}
		static const_pointer maximum(const_pointer x) {
			while (x->right != NULL)
				x = x->right;
			return x;
		}
	};

	template <class T>
	rbNode<T>* rb_tree_increment_local(rbNode<T>* node) {
		if (node->right != NULL) {
			node = node->right;
			while (node->left != NULL)
				node = node->left;
		}
		else {
			rbNode<T>* other = node->parent;
			while (node == other->right) {
				node = other;
				other = other->parent;
			}
			if (node->right != other)
				node = other;
		}
		return node;
	}
	template <class T>
	rbNode<T>* rb_tree_increment(rbNode<T>* node) {
		return rb_tree_increment_local(node);
	}
	template <class T>
	const rbNode<T>* rb_tree_increment(const rbNode<T>* node) {
		return rb_tree_increment_local(const_cast<rbNode<T>*>(node));
	}
	template <class T>
	rbNode<T>* rb_tree_decrement_local(rbNode<T>* node) {
		if (node->clr == red && node->parent->parent == node)
			node = node->right;
		else if (node->left != NULL) {
			rbNode<T>* other = node->left;
			while (other->right != NULL)
				other = other->right;
			node = other;
		}
		else {
			rbNode<T>* other = node->parent;
			while (node == other->left) {
				node = other;
				other = other->parent;
			}
			node = other;
		}
		return node;
	}
	template <class T>
	rbNode<T>* rb_tree_decrement(rbNode<T>* node) {
		return rb_tree_decrement_local(node);
	}
	template <class T>
	const rbNode<T>* rb_tree_decrement(const rbNode<T>* node) {
		return rb_tree_decrement_local(const_cast<rbNode<T>*>(node));
	}
	template <typename T>
	class rb_iterator {
	public:
			typedef T								value_type;
			typedef T&								reference;
			typedef T*								pointer;
			typedef std::bidirectional_iterator_tag	iterator_category;
			typedef std::ptrdiff_t					difference_type;
			typedef rb_iterator<T>					iterator;

			rb_iterator() : node() {}
			explicit rb_iterator(rbNode<T>* x) : node(x) {}

			reference operator*() const {
				return node->val;
			}
			pointer operator->() const {
				return &node->val;
			}
			iterator& operator++() {
				node = rb_tree_increment(node);
				return *this;
			}
			iterator operator++(int) {
				iterator tmp = *this;
				node = rb_tree_increment(node);
				return tmp;
			}
			iterator& operator--() {
				node = rb_tree_decrement(node);
				return *this;
			}
			iterator operator--(int) {
				iterator tmp = *this;
				node = rb_tree_decrement(node);
				return tmp;
			}
			bool operator==(const iterator& x) const {
				return node == x.node;
			}
			bool operator!=(const iterator& x) const {
				return node != x.node;
			}
			rbNode<T>*	 node;
		};
	template <typename T>
	class rb_const_iterator {
	public:
		typedef T										value_type;
		typedef const T&								reference;
		typedef const T*								pointer;
		typedef std::bidirectional_iterator_tag			iterator_category;
		typedef std::ptrdiff_t							difference_type;
		typedef rb_const_iterator<T>					iterator;
		typedef rb_iterator<T>							iterr;

		rb_const_iterator() : node() {}
		explicit rb_const_iterator(const rbNode<T>* x) : node(x) {}
		rb_const_iterator(const iterr& iter) : node(iter.node) {}
		reference operator*() const {
			return node->val;
		}
		pointer operator->() const {
			return &node->val;
		}
		iterator& operator++() {
			node = rb_tree_increment(node);
			return *this;
		}
		iterator operator++(int) {
			iterator tmp = *this;
			node = rb_tree_increment(node);
			return tmp;
		}
		iterator& operator--() {
			node = rb_tree_decrement(node);
			return *this;
		}
		iterator operator--(int) {
			iterator tmp = *this;
			node = rb_tree_decrement(node);
			return tmp;
		}
		bool operator==(const iterator& x) const {
			return node == x.node;
		}
		bool operator!=(const iterator& x) const {
			return node != x.node;
		}

		const rbNode<T>*	 node;
	};

	template <typename Val>
	inline bool operator==(const rb_iterator<Val>& x, const rb_const_iterator<Val>& y) {
		return x.node == y.node;
	}
	template <typename Val>
	inline bool operator!=(const rb_iterator<Val>& x, const rb_const_iterator<Val>& y) {
		return x.node == y.node;
	}
	template<typename Key, typename Val, typename KeyOfValue, typename Compare = std::less<Key>, typename Alloc = std::allocator<Val> >
	class rbTree {
//		typedef typename Alloc::template rebind<rbNode<Val> >::other node_allocator;
		typedef std::allocator<rbNode<Val> > node_allocator;
	public:

		typedef Val										value_type;
		typedef Compare									value_compare;
		typedef Alloc									allocator_type;
		typedef Key										key_type;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef rbNode<Val>*							rb_node;
		typedef const rbNode<Val>*						const_rb_node;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef rb_iterator<value_type>					iterator;
		typedef rb_const_iterator<value_type>			const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		rbTree() : _root(), _size(0), _allocator(), _nodeAlloc(), _comp() {
			_root.clr = red;
			_root.parent = 0;
			_root.right = &_root;
			_root.left = &_root;
			_size = 0;
		}
		rbTree(const Compare& comp, const allocator_type& a = allocator_type()) :
				_root(), _size(), _allocator(), _nodeAlloc(a), _comp(comp) {
			_root.clr = red;
			_root.parent = 0;
			_root.right = &_root;
			_root.left = &_root;
			_size = 0;
		}
		rbTree(const rbTree& other) {
			if (other._root.parent) {
				_root.parent = _copy(other._root.parent, &_root);
				_root.left = rbNode<Val>::minimum(_root.parent);
				_root.right = rbNode<Val>::maximum(_root.parent);
				_size = other._size;
			}
			else {
				_root.clr = red;
				_size = other._size;
				_root.parent = 0;
				_root.left = &_root;
				_root.right = &_root;
			}
		}
		rbTree& operator=(const rbTree& other) {
			if (this != &other) {
				clear();
				_comp = other._comp;
				if (other._root.parent != NULL) {
					_root.parent = _copy(_root.parent, &_root);
					_root.left = rbNode<Val>::minimum(_root.parent);
					_root.right = rbNode<Val>::maximum(_root.parent);
					_size = other._size;
				}
				else {
					_root.clr = red;
					_size = other._size;
					_root.parent = 0;
					_root.left = &_root;
					_root.right = &_root;
				}
			}
		}
		~rbTree() {
			_erase(_root.parent);
		}
		iterator begin() {
			return iterator(_root.left);
		}
		const_iterator begin() const {
			return const_iterator(_root.left);
		}
		void clear() {
			_erase(_root.parent);
			_root.left = &_root;
			_root.parent = NULL;
			_root.right = &_root;
			_size = 0;
		}
		size_type count(const key_type& k) const {
			if (find(k) == end())
				return 0;
			return 1;
		}
		iterator end() {
			return iterator(&_root);
		}
		const_iterator end() const {
			return const_iterator(&_root);
		}
		void erase(iterator position);
		void erase(iterator first, iterator last);
		size_type erase(const key_type & key);
		ft::pair<iterator, iterator> equal_range(const key_type& k) {
			rb_node x = _root.parent;
			rb_node y = &_root;
			while (x != 0) {
				if (_comp(KeyOfValue()(x->val), k))
					x = x->right;
				else if (_comp(k, KeyOfValue()(x->val))) {
					y = x;
					x = x->left;
				}
				else {
					rb_node xu(x);
					rb_node yu(y);
					y = x;
					x = x->left;
					xu = xu->right;
					return ft::pair<iterator, iterator>(_low_help(x, y, k), _up_help(xu, yu, k));
				}
			}
			return ft::pair<iterator, iterator>(iterator(y), iterator(y));
		}
		ft::pair<const_iterator, const_iterator> equal_range(const key_type& k) const {
			const_rb_node x = _root.parent;
			const_rb_node y = &_root;
			while (x != 0) {
				if (_comp(KeyOfValue()(x->val), k))
					x = x->right;
				else if (_comp(k, KeyOfValue()(x->val))) {
					y = x;
					x = x->left;
				}
				else {
					const_rb_node xu(x);
					const_rb_node yu(y);
					y = x;
					x = x->left;
					xu = xu->right;
					return ft::pair<const_iterator, const_iterator>(_low_help(x, y, k), _up_help(xu, yu, k));
				}
			}
			return ft::pair<const_iterator, const_iterator>(const_iterator(y), const_iterator(y));
		}
		iterator find(const key_type& key) {
			iterator j = lower_bound(key);
			return (j == end() || _comp(key, KeyOfValue()(j.node->val))? end() : j);
		}
		const_iterator find(const key_type& key) const {
			const_iterator j = lower_bound(key);
			return (j == end() || _comp(key, KeyOfValue()(j.node->val)) ? end() : j);
		}
		allocator_type get_allocator() {
			return _allocator;
		}
		ft::pair<iterator, bool> insert(const value_type& val) {
			rb_node x = _root.parent;
			rb_node y = &_root;
			bool comp = true;
			while (x != 0) {
				y = x;
				comp = _comp(KeyOfValue()(val), KeyOfValue()(x->val));
				x = comp ? x->left : x->right;
			}
			iterator j = iterator(y);
			if (comp) {
				if (j == begin())
					return ft::pair<iterator, bool>(_insert(x, y, val), true);
				else
					--j;
			}
			if (_comp(KeyOfValue()(j.node->val), KeyOfValue()(val)))
				return ft::pair<iterator, bool>(_insert(x, y, val), true);
			return ft::pair<iterator, bool>(j, false);
		}
		iterator insert(const_iterator position, const value_type& val) {
			if (position == end()) {
				if (_size > 0 && _comp(KeyOfValue()(_root.right->val), KeyOfValue()(val)))
					return _insert(0, _root.right, val);
				else
					return insert(val).first;
			}
			else if (_comp(KeyOfValue()(val), KeyOfValue()(position.node->val))) {
				const_iterator before = position;
				--before;
				if (position.node == _root.left)
					return _insert(_root.left, _root.left, val);
				else if (_comp(KeyOfValue()(before.node->val), KeyOfValue()(val))) {
					if (before.node->right == 0)
						return _insert(0, before.node, val);
					else
						return _insert(position.node, position.node, val);
				}
				else
					return insert(val).first;
			}
			else if (_comp(KeyOfValue()(position.node->val), KeyOfValue()(val))) {
				const_iterator after = position;
				++after;
				if (position.node == _root.right)
					return _insert(0, _root.right, val);
				else if (_comp(KeyOfValue()(val), KeyOfValue()(after.node->val))) {
					if (position.node->right == 0)
						return _insert(0, position.node, val);
					else
						return _insert(after.node, after.node, val);
				}
				else
					return insert(val).first;
			}
			return iterator(const_cast<rb_node>(position.node));
		}
		template<class It>
		void insert(It first, It last) {
			for (; first != last; ++first)
				insert(*first);
		}
		iterator lower_bound(const key_type& key) {
			rb_node x = _root.parent;
			rb_node y = &_root;
			while (x != NULL) {
				if (!_comp(KeyOfValue()(x->val), key))
					y = x, x = x->left;
				else
					x = x->right;
			}
			return iterator(y);
		}
		const_iterator lower_bound(const key_type& key) const {
			const_rb_node x = _root.parent;
			const_rb_node y = &_root;
			while (x != NULL) {
				if (!_comp(KeyOfValue()(x->val), key))
					y = x, x = x->left;
				else
					x = x->right;
			}
			return const_iterator(y);
		}
		size_type max_size() const {
			return _nodeAlloc.max_size();
		}
		reverse_iterator rbegin() {
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin() const {
			return const_reverse_iterator(end());
		}
		reverse_iterator rend() {
			return reverse_iterator(begin());
		}
		const_reverse_iterator rend() const {
			return const_reverse_iterator(begin());
		}
		size_type size() const {
			return _size;
		}
		iterator upper_bound(const key_type& k) {
			rb_node x = _root.parent;
			rb_node y = &_root;
			while (x != 0) {
				if (_comp(k, KeyOfValue()(x->val))) {
					y = x;
					x = x->left;
				}
				else
					x = x->right;
			}
			return iterator(y);
		}
		const_iterator upper_bound(const key_type& k) const {
			const_rb_node x = _root.parent;
			const_rb_node y = &_root;
			while (x != 0) {
				if (_comp(k, KeyOfValue()(x->val))) {
					y = x;
					x = x->left;
				}
				else
					x = x->right;
			}
			return const_iterator(y);
		}
		void balance() {
			bool is = is_balanced(_root.parent);
			std::cout << "RB Tree is " << (!is ? "not " : "") << "balanced" << std::endl;
		}
		void printRBT()
		{
			_printRBT(_root.parent, 10);
		}
	private:
		rbNode<value_type>	_root;
		size_type			_size;
		allocator_type 		_allocator;
		node_allocator		_nodeAlloc;
		Compare				_comp;

		void _printRBT(rb_node p, int indent)
		{
			if (p != NULL)
			{
				if (p->right)
					_printRBT(p->right, indent + 4);
				if (indent)
					std::cout << std::setw(indent) << ' ';
				if (p->right)
					std::cout<<" /\n" << std::setw(indent) << ' ';
				std::cout << (p->clr == red ? "\033[1;38;5;9m" : "\033[1;38;5;247m") <<  p->val.first << "\033[0m" << std::endl;
				if(p->left)
				{
					std::cout << std::setw(indent) << ' ' <<" \\\n";
					_printRBT(p->left, indent + 4);
				}
			}
		}
		void _leftRotation(rb_node x) {
			rb_node y = x->right;
			x->right = y->left;
			if (y->left != NULL)
				y->left->parent = x;
			y->parent = x->parent;
			if (x == _root.parent)
				_root.parent = y;
			else if (x == x->parent->left)
				x->parent->left = y;
			else
				x->parent->right = y;
			y->left = x;
			x->parent = y;
		}
		void _rightRotation(rb_node x) {
			rb_node y = x->left;
			x->left = y->right;
			if (y->right != NULL)
				y->right->parent = x;
			y->parent = x->parent;
			if (x == _root.parent)
				_root.parent = y;
			else if (x == x->parent->right)
				x->parent->right = y;
			else
				x->parent->left = y;
			y->right = x;
			x->parent = y;
		}
		rb_node _clone_node(const_rb_node x) {
			rb_node tmp = _nodeAlloc.allocate(1);
			_allocator.construct(&tmp->val, x->val);
			tmp->clr = x->clr;
			tmp->right = NULL;
			tmp->left = NULL;
			return tmp;
		}
		rb_node _copy(rb_node x, rb_node y) {
			rb_node top = _clone_node(x);
			top->parent = y;
			if (x->right)
				top->right = _copy(x->right, top);
			y = top;
			x = x->left;
			while (x != NULL) {
				rb_node clone = _clone_node(x);
				y->left = clone;
				clone->parent = y;
				if (x->right)
					clone->right = _copy(x->right, clone);
				y = clone;
				x = x->left;
			}
			return top;
		}
		void _erase(rb_node x) {
			while (x != NULL) {
				_erase(x->right);
				rb_node y = x->left;
				_allocator.destroy(&x->val);
				_nodeAlloc.deallocate(x, 1);
				x = y;
			}
		}
		rb_node _rebalance_for_erase(rb_node z) {
			rb_node y = z;
			rb_node x = 0;
			rb_node xp = 0;
			if (y->left == NULL)
				x = y->right;
			else {
				if (y->right == NULL)
					x = y->left;
				else {
					y = y->right;
					while (y->left != 0)
						y = y->left;
					x = y->right;
				}
			}
			if (y != z) {
				z->left->parent = y;
				y->left = z->left;
				if (y != z->right) {
					xp = y->parent;
					if (x)
						x->parent = y->parent;
					y->parent->left = x;
					y->right = z->right;
					z->right->parent = y;
				} else
					xp = y;
				if (_root.parent == z)
					_root.parent = y;
				else if (z->parent->left == z)
					z->parent->left = y;
				else
					z->parent->right = y;
				y->parent = z->parent;
				std::swap(y->clr, z->clr);
				y = z;
			} else {
				xp = y->parent;
				if (x)
					x->parent = y->parent;
				if (_root == z)
					_root = x;
				else {
					if (z->parent->left == z)
						z->parent->left = x;
					else
						x->parent->right = x;
				}
				if (_root.left == z) {
					if (z->right == NULL)
						_root.left = z->parent;
					else
						_root.left = rbNode<value_type>::minimum(x);
				}
				if (_root.right == z) {
					if (z->left == NULL)
						_root.right = z->parent;
					else
						_root.right = rbNode<value_type>::maximum(x);
				}
			}
			if (y->clr != red) {
				while (x != _root.parent && (x != NULL || x->clr == black)) {
					if (x == xp->left) {
						rb_node w = xp->right;
						if (w->clr == red) {
							w->clr = black;
							xp->clr = red;
							_leftRotation(xp);
							w = xp->right;
						}
						if ((w->left == 0 || w->left->clr == black) && (w->right == 0 || w->right->clr == black)) {
							w->clr = red;
							x = xp;
							xp = xp->parent;
						}
						else {
							if (w->right == 0 || w->right->clr == black) {
								w->left->clr = black;
								w->clr = red;
								_rightRotation(w);
								w = xp->right;
							}
							w->clr = xp->clr;
							xp->clr = black;
							if (w->right)
								w->right->clr = black;
							_leftRotation(xp);
							break;
						}
					}
					else {
						rb_node w = xp->left;
						if (w->clr == red) {
							w->clr = black;
							xp->clr = red;
							_rightRotation(xp);
							w = xp->left;
						}
						if ((w->right == 0 || w->right->clr == black) && (w->left == 0 || w->left->clr == black)) {
							w->clr = red;
							x = xp;
							xp = xp->parent;
						}
						else {
							if (w->left == 0 || w->left->clr == black) {
								w->right->clr = black;
								w->clr = red;
								_leftRotation(w);
								w = xp->left;
							}
							w->clr = xp->clr;
							xp->clr = black;
							if (w->left)
								w->left->clr = black;
							_rightRotation(xp);
							break;
						}
					}
				}
				if (x)
					x->clr = black;
			}
			return y;
		}
		rb_node _create_node(const value_type& x) {
			rb_node tmp = _nodeAlloc.allocate(1);
			_allocator.construct(&tmp->val, x);
			return tmp;
		}
		void _insert_and_rebalance(const bool insert_left, rb_node x, rb_node y) {
			x->parent = y;
			x->left = 0;
			x->right = 0;
			x->clr = red;
			if (insert_left) {
				y->left = x;
				if (y == &_root) {
					_root.parent = x;
					_root.right = x;
				}
				else if (y == _root.left)
					_root.left = x;
			}
			else {
				y->right = x;
				if (y == _root.right)
					_root.right = x;
			}
			while (x != _root.parent && x->parent->clr == red) {
				// the decision to perform a rotation ot a color change is based on the aunt of the considered node
				// if the node has a black aunt we do a rotation
				// if the node has a red aunt we do a color flip
				rb_node xpp = x->parent->parent;
				if (x->parent == xpp->left) {
					rb_node xppr = xpp->right;
					if (xppr && xppr->clr == red) {
						x->parent->clr = black;
						xppr->clr = black;
						xpp->clr = red;
						x = xpp;
					}
						// if the current node is the left child of its grandparent's child
						// we right rotate the grandparent around the parent

						// if the current node is the right child of its grandparent's right child
						// we left rotate the grandparent around the parent

						// If the current node is the right child of its grandparent’s left child
						// we perform a left-right rotation where we rotate the grandparent and the child around the parent

						// If the current node is the left child of its grandparent’s right child
						// we perform a right-left rotation where we rotate the grandparent and the child around the parent

					else {
						if (x == x->parent->right) {
							x = x->parent;
							_leftRotation(x);
						}
						x->parent->clr = black;
						xpp->clr = red;
						_rightRotation(xpp);
					}
				}
				else {
					rb_node xppl = xpp->left;
					if (xppl && xppl->clr == red) {
						x->parent->clr = black;
						xppl->clr = black;
						xpp->clr = red;
						x = xpp;
					}
					else {
						if (x == x->parent->left) {
							x = x->parent;
							_rightRotation(x);
						}
						x->parent->clr = black;
						xpp->clr = red;
						_leftRotation(xpp);
					}
				}
			}
			_root.parent->clr = black;
		}
		iterator _insert(const_rb_node x, const_rb_node y, const value_type& val) {
			bool insert_left = (x != 0 || y == &_root || _comp(KeyOfValue()(val), KeyOfValue()(y->val)));
			rb_node z = _create_node(val);
			_insert_and_rebalance(insert_left, z, const_cast<rb_node>(y));
			++_size;
			return iterator(z);
		}
		int max(int a, int b) {
			return (a >= b) ? a : b;
		}
		int height(rb_node root) {
			if (root == NULL)
				return 0;
			return 1 + max(height(root->left), height(root->right));
		}
		bool is_balanced(rb_node root) {
			int lh;
			int rh;

			if (root == NULL)
				return true;
			lh = height(root->left);
			rh = height(root->right);
			if (abs(lh - rh) <= 1 && is_balanced(root->left) && is_balanced(root->right))
				return true;
			return false;
		}
		iterator _low_help(rb_node x, rb_node y, const key_type& k) {
			while (x != 0) {
				if (_comp(KeyOfValue()(x->val), k)) {
					y = x;
					x = x->left;
				}
				else
					x = x->right;
			}
			return iterator(y);
		}
		const_iterator _low_help(const_rb_node x, const_rb_node y, const key_type& k) const {
			while (x != 0) {
				if (_comp(KeyOfValue()(x->val), k)) {
					y = x;
					x = x->left;
				}
				else
					x = x->right;
			}
			return const_iterator(y);
		}
		iterator _up_help(rb_node x, rb_node y, const key_type& k) {
			while (x != 0) {
				if (_comp(k, KeyOfValue()(x->val))) {
					y = x;
					x = x->left;
				}
				else
					x = x->right;
			}
			return iterator(y);
		}
		const_iterator _up_help(const_rb_node x, const_rb_node y, const key_type& k) const {
			while (x != 0) {
				if (_comp(k, KeyOfValue()(x->val))) {
					y = x;
					x = x->left;
				}
				else
					x = x->right;
			}
			return const_iterator(y);
		}


	};
}

#endif