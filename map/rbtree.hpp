#ifndef RBTREE_HPP
#define RBTREE_HPP

#include <iostream>
#include "pair.hpp"

namespace ft {
	enum rbColor {black = false, red = true};
	template <typename Val>
	struct rbNode {
		typedef rbNode<Val>* pointer;
		typedef const rbNode<Val>* const_pointer;
		typedef
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
	template<typename Key, typename Val, typename KeyOfValue, typename Compare = std::less<Val>, typename Alloc = std::allocator<Val> >
	class rbTree {
		typedef typename Alloc::template rebind<rbNode<Val> >::other node_allocator;
	public:

		typedef Val										value_type;
		typedef Compare									value_compare;
		typedef Alloc									allocator_type;
		typedef Key										key_type;
		typedef value_type*								pointer;
		typedef const value_type*						const_pointer;
		typedef value_type&								reference;
		typedef const value_type&						const_reference;
		typedef rbNode<Val>*							link_type;
		typedef const rbNode<Val>*						const_link_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef rb_iterator<value_type>					iterator;
		typedef rb_const_iterator<value_type>			const_iterator;

		rbTree();
		rbTree(const rbTree& other);
		rbTree& operator=(const rbTree& other);
		~rbTree();

	protected:
		typedef rbNode<value_type>* node;
		typedef const rbNode<value_type>* constNode;
	private:
		rbNode<value_type>	*root;
		size_type			_size;
		Alloc				_allocator;
		node_allocator		_nodeAlloc;
		Compare				_comp;
//		typedef Key									key_type;
//		typedef T									mapped_type;
//		typedef ft::pair<const Key, T>				value_type;
		void makeNode() {

		}
		void insert() {

		}

	};
}

#endif
