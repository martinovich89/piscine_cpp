#include "MutantStack.hpp"

template <class T>
void const_iterator_test(const MutantStack<T> &cmstack)
{
	MutantStack<int>::citerator cit = cmstack.begin();
	MutantStack<int>::criterator crit = cmstack.rbegin();

	std::cout << "----->with const_iterator<-----" << std::endl;

	for (; cit != cmstack.end(); cit++)
	{
		std::cout << *cit << std::endl;
	}
	
	std::cout << "----->with const_reverse_iterator<-----" << std::endl;

	for (; crit != cmstack.rend(); crit++)
	{
		std::cout << *crit << std::endl;
	}
}

int main()
{
	std::cout << "=====>OG main with list<=====" << std::endl << std::endl;

	{
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}

	std::cout << std::endl << "=====>OG main with MutantStack<=====" << std::endl << std::endl;

	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		//[...]
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << std::endl << "=====> MY main.cpp <=====" << std::endl << std::endl;

	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::riterator rit = mstack.rbegin();

		std::cout << "----->with iterator<-----" << std::endl;

		for (; it != mstack.end(); it++)
		{
			std::cout << *it << std::endl;
		}

		std::cout << "----->with reverse_iterator<-----" << std::endl;

		for (; rit != mstack.rend(); rit++)
		{
			std::cout << *rit << std::endl;
		}

		const_iterator_test(mstack);
	}
}
