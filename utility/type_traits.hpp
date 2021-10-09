#ifndef TYPE_TRAITS_HPP
#define TYPE_TRAITS_HPP

namespace ft {
	template <typename T>
	struct remove_const {
		typedef T type;
	};
	template <typename T>
	struct remove_const<const T> {
		typedef T type;
	};
	template<typename T>
	struct is_integral_base {
		const static bool value = false;
	};
	template<>
	struct is_integral_base<bool> {
		const static bool value = true;
	};
	template<>
	struct is_integral_base<char> {
		const static bool value = true;
	};
	template<>
	struct is_integral_base<signed char> {
		const static bool value = true;
	};
	template<>
	struct is_integral_base<unsigned char> {
		const static bool value = true;
	};
	template<>
	struct is_integral_base<char16_t> {
		const static bool value = true;
	};
	template<>
	struct is_integral_base<wchar_t> {
		const static bool value = true;
	};
	template<>
	struct is_integral_base<short> {
		const static bool value = true;
	};
	template<>
	struct is_integral_base<int> {
		const static bool value = true;
	};
	template<>
	struct is_integral_base<unsigned int> {
		const static bool value = true;
	};
	template<>
	struct is_integral_base<long> {
		const static bool value = true;
	};
	template<>
	struct is_integral_base<unsigned long> {
		const static bool value = true;
	};
	template<>
	struct is_integral_base<long long> {
		const static bool value = true;
	};
	template<>
	struct is_integral_base<unsigned long long> {
		const static bool value = true;
	};

	template <typename T>
	struct is_integral {
		const static bool value = is_integral_base<typename remove_const<T>::type>::value;
	};

	template<bool B, class T = void>
	struct enable_if {

	};
	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};
}

#endif
