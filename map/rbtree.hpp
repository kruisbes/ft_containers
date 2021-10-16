#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <iostream>
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

		rb_const_iterator() : node() {}
		explicit rb_const_iterator(const rbNode<T>* x) : node(x) {}
		explicit rb_const_iterator(const rb_iterator<T>& iter) {
			node(iter.node);
		}

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
	template<typename Key, typename Val, typename Compare = std::less<Val>, typename Alloc = std::allocator<Val> >
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
		}
		rbTree& operator=(const rbTree& other) { // 926
			if (this != &other) {
				clear();
				_comp = other._comp;
				if (other._root.parent != NULL) {
					_root.parent = _copy(_root.parent, &_root);
					_root.left = rbNode<Val>::minimum(_root.parent);
					_root.right = rbNode<Val>::maximum(_root.parent);
					_size = other._size;
				}
			}
		}
		~rbTree() {
			_erase(_root.parent);
		}
		value_compare key_comp() const {
			return _comp;
		}
		iterator begin() {
			return iterator(_root.left);
		}
		const_iterator begin() const {
			return const_iterator(_root.left);
		}
		iterator end() {
			return iterator(&_root);
		}
		const_iterator end() const {
			return const_iterator(&_root);
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
		size_type max_size() const {
			return _nodeAlloc.max_size();
		}
		allocator_type get_allocator() {
			return _allocator;
		}
		void clear() {
			_erase(_root.parent);
			_root.left = &_root;
			_root.parent = NULL;
			_root.right = &_root;
			_size = 0;
		}
// root=parent begin=parent end=...
// insert unique w it + value_type + pos/val
	protected:
		typedef rbNode<value_type>* node; // _Base_ptr
		typedef const rbNode<value_type>* constNode; // _Const_Base_ptr
	private:
		rbNode<value_type>	_root;
		rbNode<value_type>	_end;
		size_type			_size;
		allocator_type 		_allocator;
		node_allocator		_nodeAlloc;
		Compare				_comp;

		rb_node _clone_node(const_rb_node x) {
			rb_node tmp = _nodeAlloc.allocate(1);
			_allocator().construct(&tmp->val, x->val);
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
			while (x) {
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

	};
}

#endif
