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
		pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}

		// OPERATOR

		pair& operator=(const pair& other) {
			first = other.first;
			second = other.second;
			return *this;
		}
	};

	// NON-MEMBER FUNCTIONS
	template<class T1, class T2>
	ft::pair<T1, T2> make_pair(T1 t, T2 u) {
		return ft::pair<T1, T2>(t, u);
	}
	template<class T1, class T2>
	bool operator==(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}
	template<class T1, class T2>
	bool operator!=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return !(lhs == rhs);
	}
	template<class T1, class T2>
	bool operator<(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return (lhs.first < rhs.first) || (!(rhs.first < lhs.first) && lhs.first < rhs.first);
	}
	template<class T1, class T2>
	bool operator<=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return !(rhs < lhs);
	}
	template<class T1, class T2>
	bool operator>(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return (rhs < lhs);
	}
	template<class T1, class T2>
	bool operator>=(const ft::pair<T1, T2>& lhs, const ft::pair<T1, T2>& rhs) {
		return !(lhs < rhs);
	}
}

#endif
