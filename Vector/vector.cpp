#include "vector.h"

//constructors
template <typename T, typename Allocator>
g3::vector<T, Allocator>::vector()
	: size_ {} 
       	, cap {}
	, arr_ {nullptr}
	, allocator_(allocator_type()) 
{}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::vector(const vector& rhv)
	: size_(rhv.size_)
	, cap(rhv.cap)
	, allocator(rhv.allocator)
{
	arr_ = allocator.allocate(cap);
	for (size_type i = 0; i < size_; ++i) {
		allocator.construct (&arr_[i], rhv.arr_[i]);
	}
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::vector(vector&& rhv) noexcept
	: size_(rhv.size_)
	, cap(rhv.cap)
	, arr_(rhv.arr_)
	, allocator(std::move(rhv.allocator))
{
	rhv.size_ = 0;
	rhv.cap = 0;
	rhv.arr_ = nullptr;
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::vector(std::initializer_list<value_type> init)
	: size_ (init.size())
	, cap (init.size())
	, allocator (allocator_type())
{
	arr_ = allocator.allocate(cap);
	std::uninitializer_copy(init.begin(), init.end(), arr_);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::vector(size_type size, const_reference val)
	: size_ (size)
	, cap (size)
	, allocator (allocator_type())
{
	arr_ = allocator.allocate(cap);
	for (size_type i = 0; i < size_; ++i) {
		allocator.construct (&arr_[i], val);
	}
}

template <typename T, typename Allocator>
template <typename InputIt>
g3::vector<T, Allocator>::vector(InputIt first, InputIt last)
	: size_ (std::distance(first, last))
	, cap (size)
	, allocator (allocator_type())
{
	arr_ = allocator.allocate (cap);
	std::uninitializer_copy (firat, last, arr_);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::~vector() 
{
	clear();
	if (arr_) {
		allocator.deallocate (arr_, cap);
	}
}

template <typename T, typename Allocator>
const g3::vector<T, Allocator>& g3::vector<T, Allocator>::operator=(const vector& rhv)
{
	if (this != &rhv) {
		clear();
		if (cap < rhv.size_) {
			allocator.deallocate (arr_, cap);
			cap = rhv.size;
			arr_ = allocator.allocate (cap);
		}
		size_ = rhv.size;
		for (size_type i = 0; i < size_; ++i) {
			allocator.construct (&arr_[i], rhv.arr_[i]);
		}
	}
	return *this;
}

template <typename T, typename Allocator>
const g3::vector<T, Allocator>& g3::vector<T, Allocator>::operator=(vector&& rhv) noexcept
{
	if (this != &rhv) {
		clear();
		if (arr_) {
			allocator.deallocate (arr_, cap);
		}
		size_ = rhv.size_;
		cap = rhv.cap;
		arr_ = rhv.arr_;
		allocator = std::move (rhv.allocator);
		rhv.size_ = 0;
		rhv.cap = 0;
		rhv.arr_ = nullptr;
	}
	return *this;
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::allocator_type g3::vector<T, Allocator>::get_allocator() const
	return allocator;
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::reference g3::vector<T, Allocator>::at(size_type pos) {
	check_range (pos);
	return arr_(pos);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::const_reference g3::vector<T, Allocator>::at(size_type pos) const {
	check_range (pos);
	return arr_[pos];
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::reference g3::vector<T, Allocator>::operator[](size_type pos) {
	return arr_[pos];
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::const_reference g3::vector<T, Allocator>::operator[](size_type pos) const {
	return arr_[pos];
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::reference g3::vector<T, Allocator>::front() {
	return arr_[0];
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::const_reference g3::vector<T, Allocator>::front() const {
	return arr_[0];
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::reference g3::vector<T, Allocator>::back() {
	return [size_ - 1];
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::const_reference g3::vector<T, Allocator>::back() const {
	return [size_ - 1];
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::iterator g3::vector<T, Allocator>::begin() {
	return iterator (arr_);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::const_iterator g3::vector<T, Allocator>::begin() const {
	return const_iterator (arr_);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::const_iterator g3::vector<T, Allocator>::cbegin() const {
	return const_iterator (arr_);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::iterator g3::vector<T, Allocator>::end() {
	return iterator (arr_ + size_);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::const_iterator g3::vector<T, Allocator>::end() const {
	return const_iterator (arr_ + size_);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::const_iterator g3::vector<T, Allocator>::cend() const {
	return const_iterator (arr_ + size_);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::iterator g3::vector<T, Allocator>::rbegin() {
	return iterator (arr_ + size_ - 1);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::const_iterator g3::vector<T, Allocator>::rbegin() const {
	return const_iterator (arr_ + size_ - 1);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::const_iterator g3::vector<T, Allocator>::crbegin() const {
	return const_iterator (arr_ + size_ - 1);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::iterator g3::vector<T, Allocator>::rend() {
	return iterator (arr_ - 1);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::const_iterator g3::vector<T, Allocator>::rend() const {
	return const_iterator (arr_ - 1);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::const_iterator g3::vector<T, Allocator>::crend() const {
	return const_iterator(arr_ - 1);
}

template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::empty() const {
{
	return size_ == 0;
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::size_type g3::vector<T, Allocator>::size() const {
	return size_;
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::size_type g3::vector<T, Allocator>::capacity() const {
	return cap;
}

template <typename T, typename Allocator>
void g3::vector<T, Allocator>::reserve(size_type new_cap) {
	if (new_cap > cap) {
		reallocate(new_cap);
	}
}

template <typename T, typename Allocator>
void g3::vector<T, Allocator>::clear() noexcept {
	for (size_type i = 0; i < size_; ++i) {
   	     allocator_.destroy(&arr_[i]);
        }
    size_ = 0;
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::iterator g3::vector<T, Allocator>::insert(const_iterator pos, const_reference val) {
	return insert (pos, 1, val);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::iterator g3::vector<T, Allocator>::insert(const_iterator pos, size_type count, const_reference val) {
	size_type index = pos - cbegin();
  		  if (size_ + count > cap) {
   			     reallocate(size_ + count);
 	          }
   	 for (size_type i = size_; i > index; --i) {
      		  allocator_.construct(&arr_[i + count - 1], std::move(arr_[i - 1]));
     	          allocator_.destroy(&arr_[i - 1]);
         }
        for (size_type i = 0; i < count; ++i) {
      		  allocator_.construct(&arr_[index + i], val);
        }
    size_ += count;
    return iterator(arr_ + index);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::iterator g3::vector<T, Allocator>::insert(const_iterator pos, std::initializer_list<value_type> init) {
   	 return insert(pos, init.begin(), init.end());
}

template <typename T, typename Allocator>
template <typename InputIt>
g3::vector<T, Allocator>::iterator g3::vector<T, Allocator>::insert(const_iterator pos, InputIt first, InputIt last) {
    size_type index = pos - cbegin();
    size_type count = std::distance(first, last);
    if (size_ + count > cap) {
        reallocate(size_ + count);
    }
    for (size_type i = size_; i > index; --i) {
        allocator_.construct(&arr_[i + count - 1], std::move(arr_[i - 1]));
        allocator_.destroy(&arr_[i - 1]);
    }
    std::uninitialized_copy(first, last, arr_ + index);
    size_ += count;
    return iterator(arr_ + index);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::iterator g3::vector<T, Allocator>::erase(const_iterator pos) {
  	  return erase(pos, pos + 1);
}

template <typename T, typename Allocator>
g3::vector<T, Allocator>::iterator g3::vector<T, Allocator>::erase(const_iterator first, const_iterator last) {
    size_type index_first = first - cbegin();
    size_type index_last = last - cbegin();
    for (size_type i = index_first; i < index_last; ++i) {
        allocator_.destroy(&arr_[i]);
    }
    for (size_type i = index_last; i < size_; ++i) {
        allocator_.construct(&arr_[i - (index_last - index_first)], std::move(arr_[i]));
        allocator_.destroy(&arr_[i]);
    }
    size_ -= index_last - index_first;
    return iterator(arr_ + index_first);
}

template <typename T, typename Allocator>
void g3::vector<T, Allocator>::push_back(const_reference val) {
    if (size_ == cap) {
        reallocate(cap == 0 ? 1 : 2 * cap);
    }
    allocator_.construct(&arr_[size_], val);
    ++size_;
}

template <typename T, typename Allocator>
void g3::vector<T, Allocator>::pop_back() {
    if (size_ > 0) {
        allocator_.destroy(&arr_[size_ - 1]);
        --size_;
    }
}

template <typename T, typename Allocator>
void g3::vector<T, Allocator>::resize(size_type new_size, const_reference val) {
    if (new_size > size_) {
        reserve(new_size);
        for (size_type i = size_; i < new_size; ++i) {
            allocator_.construct(&arr_[i], val);
        }
    } else {
        for (size_type i = new_size; i < size_; ++i) {
            allocator_.destroy(&arr_[i]);
        }
    }
    size_ = new_size;
}

template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::operator==(const vector& other) const {
    if (size_ != other.size_) {
        return false;
    }
    for (size_type i = 0; i < size_; ++i) {
        if (!(arr_[i] == other.arr_[i])) {
            return false;
        }
    }
    return true;
}

template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::operator!=(const vector& other) const {
    return !(*this == other);
}

template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::operator<(const vector& other) const {
    return compare(other) < 0;
}

template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::operator<=(const vector& other) const {
    return compare(other) <= 0;
}

template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::operator>(const vector& other) const {
    return compare(other) > 0;
}

template <typename T, typename Allocator>
bool g3::vector<T, Allocator>::operator>=(const vector& other) const {
    return compare(other) >= 0;
}

template <typename T, typename Allocator>
int g3::vector<T, Allocator>::compare(const vector& other) const {
    size_type min_size = std::min(size_, other.size_);
    for (size_type i = 0; i < min_size; ++i) {
        if (arr_[i] < other.arr_[i]) {
            return -1;
        } else if (arr_[i] > other.arr_[i]) {
            return 1;
        }
    }
    if (size_ < other.size_) {
        return -1;
    } else if (size_ > other.size_) {
        return 1;
    } else {
        return 0;
    }
}

template <typename T, typename Allocator>
void g3::vector<T, Allocator>::check_range(size_type pos) const {
    if (pos >= size_) {
        throw std::out_of_range("vector::at: index out of range");
    }
}

template <typename T, typename Allocator>
void g3::vector<T, Allocator>::reallocate(size_type new_cap) {
    pointer new_arr = allocator_.allocate(new_cap);
    for (size_type i = 0; i < size_; ++i) {
        allocator_.construct(&new_arr[i], std::move(arr_[i]));
        allocator_.destroy(&arr_[i]);
    }
    if (arr_) {
        allocator_.deallocate(arr_, cap);
    }
    arr_ = new_arr;
    capacity_ = new_cap;
}

} //namespace

#endif // VECTOR_H
