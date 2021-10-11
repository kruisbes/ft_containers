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
		T			key;
	};
}

#endif
