#ifndef STACK_HPP
#define STACK_HPP

#include "../vector/vector.hpp"

namespace ft {
    template <class T, class Container = ft::vector<T> > class stack {
    public:

        // DEF

        typedef Container							container_type;
        typedef typename Container::value_type		value_type;
        typedef typename Container::size_type		size_type;
        typedef typename Container::reference		reference;
        typedef typename Container::const_reference	const_reference;

		// OVERLOADS

		template <typename T1, typename Container1>
		friend bool operator==(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
		template <typename T1, typename Container1>
		friend bool operator!=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
		template <typename T1, typename Container1>
		friend bool operator<(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
		template <typename T1, typename Container1>
		friend bool operator<=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
		template <typename T1, typename Container1>
		friend bool operator>(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);
		template <typename T1, typename Container1>
		friend bool operator>=(const stack<T1, Container1> & lhs, const stack<T1, Container1> & rhs);

		// CONSTRUCTOR + DESTRUCTOR

        explicit stack(const Container & cont = Container()) : c(cont) {}
        ~stack() {}
        stack & operator=(const stack & other) {
            this->c = other.c;
            return *this;
        }

        // MEMBER FUNCTIONS

        bool empty() const {
            return c.empty();
        }
        void pop() {
            c.pop_back();
        }
        void push(const value_type & val) {
            c.push_back(val);
        }
        size_type size() const {
            return c.size();
        }
        value_type & top() {
            return c.back();
        }
        const value_type & top() const {
            return c.back();
        }

    protected:
        Container c;
    };

	template<typename T1, typename Container1>
	bool operator==(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs) {
		return lhs.c == rhs.c;
	}
	template<typename T1, typename Container1>
	bool operator!=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs) {
		return lhs.c != rhs.c;
	}
	template<typename T1, typename Container1>
	bool operator<(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs) {
		return lhs.c < rhs.c;
	}
	template<typename T1, typename Container1>
	bool operator<=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs) {
		return lhs.c <= rhs.c;
	}
	template<typename T1, typename Container1>
	bool operator>(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs) {
		return lhs.c > rhs.c;
	}
	template<typename T1, typename Container1>
	bool operator>=(const stack<T1, Container1> &lhs, const stack<T1, Container1> &rhs) {
		return lhs.c >= rhs.c;
	}
}

#endif