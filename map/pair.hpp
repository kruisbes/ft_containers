#ifndef PAIR_HPP
#define PAIR_HPP

namespace ft {
	template<class T1, class T2>
	struct pair {

		// DEF

		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

		// CONSTRUCTORS

		pair() : first(), second() {}
		pair(const T1& x, const T2& y) : first(x), second(y) {}
		template<class U1, class U2>
		pair(const pair<U1, U2>& p);

		// OPERATOR

		pair& operator=(const pair& other);
	};

	// NON-MEMBER FUNCTIONS
	template<class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 t, T2 u);
	template<class T1, class T2>
	bool operator==(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs);
	template<class T1, class T2>
	bool operator!=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs);
	template<class T1, class T2>
	bool operator<(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs);
	template<class T1, class T2>
	bool operator<=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs);
	template<class T1, class T2>
	bool operator>(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs);
	template<class T1, class T2>
	bool operator>=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs);
}

#endif