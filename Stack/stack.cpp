#include "stack.h"

template <typename T, typename Container>
g3::stack<T, Container>::stack() : ob() {}

template <typename T, typename Container>
g3::stack<T, Container>::stack(const stack& rhv) : ob(rhv.ob) {}

template <typename T, typename Container>
g3::stack<T, Container>::stack(stack&& rhv) : ob(std::move(rhv.ob)) {}

template <typename T, typename Container>
g3::stack<T, Container>::stack(std::initializer_list<value_type> init) :ob(init) {}

template <typename T, typename Container>
template <typename InputIt>
g3::stack<T, Container>::stack(InputIt first, InputIt last) : ob(first, last) {}

template <typename T, typename Container>
g3::stack<T, Container>::~stack() {}

template <typename T, typename Container>
const g3::stack<T, Container>& g3::stack<T, Container>::operator=(const stack& rhv)
{
	if (this != &rhv) {
		ob = rhv.ob;
	}
	return *this;
}

template <typename T, typename Container>
const g3::stack<T, Container>& g3::stack<T, Container>::operator=(stack&& rhv) 
{
	if (this != &rhv) {
		ob = std::move(rhv.ob);
	} 
	return *this;
}


template <typename T, typename Container>
typename g3::stack<T, Container>::reference g3::stack<T, Container>::top()
{
	return ob.back();
}

template <typename T, typename Container>
typename g3::stack<T, Container>::const_reference g3::stack<T, Container>::top() const
{
	return ob.back();
}

template <typename T, typename Container>
bool g3::stack<T, Container>::empty() const 
{
	return ob.empty();
}

template <typename T, typename Container>
typename g3::stack<T, Container>::size_type g3::stack<T, Container>::size() const
{
	return ob.size(); // return the numbers of eleements
}

template <typename T, typename Container>
void g3::stack<T, Container>::push(const_reference val)
{
	return ob.push_back(val); //add an element to the top of the stack
}	

template <typename T, typename Container>
void g3::stack<T, Container>::pop()
{
	ob.pop_back(); //removing the top element
}

template <typename T, typename Container>
bool g3::stack<T, Container>::operator==(const stack& other)
{
	return ob == other.ob;
}

template <typename T, typename Container>
bool g3::stack<T, Container>::operator!=(const stack& other)
{
	return !(*this == other);
}

template <typename T, typename Container>
bool g3::stack<T, Container>::operator<(const stack& other)
{
	return ob < other.ob;
}

template <typename T, typename Container>
bool g3::stack<T, Container>::operator<=(const stack& other)
{
	return !(other < *this);
}

template <typename T, typename Container>
bool g3::stack<T, Container>::operator>(const stack& other)
{ 
        return other < *this; 
}

template <typename T, typename Container>
bool g3::stack<T, Container>::operator>=(const stack& other)
{
	return !(*this < other);
}
