#ifndef RBTREE_HPP
#define RBTREE_HPP

namespace ft {
	enum rbColor {black = false, red = true};
	template <typename T>
	struct rbNode {
		rbColor		clr;
		rbNode*		parent;
		rbNode*		left;
		rbNode*		right;
		T			val;
		// minimum
		// maximum
	};
	template<typename Key, typename Val, typename KeyOfValue, typename Compare, typename Alloc = std::allocator<Val> >
	class rbTree {
		typedef typename Alloc::template rebind<rbNode<Val> >::other node_allocator;
//		typedef typename std::allocator<rbNode<Val> > node_all;
	protected:
		typedef rbNode* _ptr;
		typedef const rbNode* _constPtr;
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
		typedef rbTreeIterator<value_type>				iterator;
		typedef rbTreeConstIterator<value_type>			const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;


	private:
		rbNode<value_type> *root;
		size_type _size;
		node_allocator _nodeAlloc;
	};
}

#endif
