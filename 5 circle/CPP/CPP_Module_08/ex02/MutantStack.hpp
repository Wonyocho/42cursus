#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>

// stack은 iterator를 사용할 수 없다. 그래서 deque를 사용한다.
// T: 저장할 요소의 타입. / F: 내부 컨테이너의 타입.(기본값은 deque)
template <typename T, typename F = std::deque<T> >  
class MutantStack : public std::stack<T, F>
{
	public:
		MutantStack() : std::stack<T, F>() {}
		MutantStack(const MutantStack& rhs) : std::stack<T, F> (rhs) {}
		MutantStack& operator=(const MutantStack& rhs)
		{
			if (this != &rhs)
			{
				std::stack<T, F>::operator=(rhs);
			}
			return (*this);
		}
		~MutantStack() {}


		// 내부 컨테이너(덱)의 반복자를 MutantStack에서도 사용할 수 있도록 정의.
		typedef typename F::iterator iterator; // 일반 반복자.
        typedef typename F::const_iterator const_iterator; // 상수 반복자.(읽기 전용)
        typedef typename F::reverse_iterator reverse_iterator; // 역방향 반복자
        typedef typename F::const_reverse_iterator const_reverse_iterator; // 상수 역방향 반복자.

		// default
		iterator begin() { return (this->c.begin()); } // c: std::stack에서 사용하는 내부 컨테이너.
		iterator end() { return (this->c.end()); }
		const_iterator begin() const { return (this->c.begin()); }
		const_iterator end() const { return (this->c.end()); }

		// reverse
		reverse_iterator rbegin() { return (this->c.rbegin()); }
		reverse_iterator rend() { return (this->c.rend()); }
		const_reverse_iterator rbegin() const { return (this->c.rbegin()); }
		const_reverse_iterator rend() const { return (this->c.rend()); }
};

#endif