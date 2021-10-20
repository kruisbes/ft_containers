#ifndef GET_FIRST_HPP
#define GET_FIRST_HPP

namespace ft {
	template <class Pair>
	struct get_first {
		typename Pair::first_type& operator()(Pair& x) {
			return x.first;
		}
		const typename Pair::first_type& operator()(const Pair& x) const {
			return x.first;
		}
	};
}

#endif