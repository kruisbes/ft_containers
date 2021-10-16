#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "iterator_traits.hpp"
#include <iostream>
#include <cstddef>

namespace ft
{
	template <typename T> class ConstRanIt;
	template <typename T> class RanItIt
	{
	public:
		typedef T value_type;
		typedef ptrdiff_t difference_type;
		typedef T* pointer;
		typedef T& reference;
		typedef std::random_access_iterator_tag iterator_category;

		pointer base() const {
			return ptr;
		}
		RanItIt() { this->ptr = NULL; }
		RanItIt(const RanItIt & rhs) {
			*this = rhs;
		}
		RanItIt(pointer rhs)
		{
			this->ptr = rhs;
		}
		~RanItIt() {}
		RanItIt & operator=(const RanItIt & rhs) {
			this->ptr = rhs.base();
			return *this;
		}
		bool operator==(const RanItIt & rhs) const {
			return this->ptr == rhs.base();
		}
		bool operator==(const ConstRanIt<T> & rhs) const {
			return this->ptr == rhs.base();
		}
		bool operator!=(const RanItIt & rhs) const {
			return this->ptr != rhs.base();
		}
		bool operator!=(const ConstRanIt<T> & rhs) const {
			return this->ptr != rhs.base();
		}
		bool operator<(const RanItIt & rhs) {
			return this->ptr < rhs.base();
		}
		bool operator<(const ConstRanIt<T> & rhs){
			return this->ptr < rhs.base();
		}
		bool operator<=(const RanItIt & rhs) {
			return this->ptr <= rhs.base();
		}
		bool operator<=(const ConstRanIt<T> & rhs){
			return this->ptr <= rhs.base();
		}
		bool operator>(const RanItIt & rhs) {
			return this->ptr > rhs.base();
		}
		bool operator>(const ConstRanIt<T> & rhs){
			return this->ptr > rhs.base();
		}
		bool operator>=(const RanItIt & rhs) {
			return this->ptr >= rhs.base();
		}
		bool operator>=(const ConstRanIt<T> & rhs){
			return this->ptr >= rhs.base();
		}
		RanItIt & operator++() {
			++this->ptr;
			return *this;
		}
		RanItIt operator++(int) {
			RanItIt tmp = *this;
			++this->ptr;
			return tmp;
		}
		RanItIt & operator--() {
			--this->ptr;
			return *this;
		}
		RanItIt operator--(int) {
			RanItIt tmp = *this;
			--this->ptr;
			return tmp;
		}
		RanItIt operator+(difference_type a) const {
			return this->ptr + a;
		}

		template<typename L>
		friend RanItIt<L> operator+(typename RanItIt<L>::difference_type a, const RanItIt<L> & iter);

		RanItIt operator-(difference_type a) const {
			return this->ptr - a;
		}
		difference_type operator-(const RanItIt b) const {
			return this->ptr - b.base();
		}
		difference_type operator-(const ConstRanIt<T> &b) const {
			return this->ptr - b.base();
		}
		RanItIt & operator+=(difference_type a) {
			this->ptr += a;
			return *this;
		}
		RanItIt & operator-=(difference_type a) {
			this->ptr -= a;
			return *this;
		}

		pointer operator->()
		{
			return this->ptr;
		}
		value_type & operator*() {
			return *ptr;
		}
		reference operator[](difference_type n) const {
			return (*(this->ptr + n));
		}
	private:
		pointer ptr;
	};
	template <typename T> class ConstRanIt
	{
	public:
		typedef const T value_type;
		typedef ptrdiff_t difference_type;
		typedef const T* pointer;
		typedef const T& reference;
		typedef std::random_access_iterator_tag iterator_category;

		pointer base() const {
			return ptr;
		}
		ConstRanIt() { this->ptr = NULL; }
		ConstRanIt(const ConstRanIt & rhs) {
			*this = rhs;
		}
		ConstRanIt(const RanItIt<T> & rhs) {
			*this = rhs;
		}
		ConstRanIt(pointer rhs)
		{
			this->ptr = rhs;
		}
		~ConstRanIt() {}
		ConstRanIt & operator=(const ConstRanIt & rhs) {
			this->ptr = rhs.base();
			return *this;
		}
		ConstRanIt & operator=(const RanItIt<T> & rhs) {
			this->ptr = rhs.base();
			return *this;
		}
		bool operator==(const ConstRanIt & rhs) {
			return this->ptr == rhs.base();
		}
		bool operator!=(const ConstRanIt & rhs) {
			return this->ptr != rhs.base();
		}
		bool operator<(const ConstRanIt & rhs) {
			return this->ptr < rhs.base();
		}
		bool operator<=(const ConstRanIt & rhs) {
			return this->ptr <= rhs.base();
		}
		bool operator>(const ConstRanIt & rhs) {
			return this->ptr > rhs.base();
		}
		bool operator>=(const ConstRanIt & rhs) {
			return this->ptr >= rhs.base();
		}
		ConstRanIt & operator++() {
			++this->ptr;
			return *this;
		}
		ConstRanIt operator++(int) {
			ConstRanIt tmp = *this;
			++this->ptr;
			return tmp;
		}
		ConstRanIt & operator--() {
			--this->ptr;
			return *this;
		}
		ConstRanIt operator--(int) {
			ConstRanIt tmp = *this;
			--this->ptr;
			return tmp;
		}
		ConstRanIt operator+(difference_type a) const {
			return this->ptr + a;
		}
		ConstRanIt operator-(difference_type a) const {
			return this->ptr - a;
		}
		difference_type operator-(const RanItIt<T>& a) const {
			return this->ptr - a.base();
		}
		difference_type operator-(const ConstRanIt<T>& a) const {
			return this->ptr - a.base();
		}
		ConstRanIt & operator+=(difference_type a) {
			this->ptr += a;
			return *this;
		}
		ConstRanIt & operator-=(difference_type a) {
			this->ptr -= a;
			return *this;
		}
		pointer operator->()
		{
			return this->ptr;
		}
		value_type & operator*() {
			return *ptr;
		}
		reference operator[](difference_type n) const {
			return (*(this->ptr + n));
		}
	private:
		pointer ptr;
	};
	template <typename L>
	RanItIt<L> operator+(typename RanItIt<L>::difference_type a, const RanItIt<L> & iter){
		return iter.base() + a;
	}


}

#endif

