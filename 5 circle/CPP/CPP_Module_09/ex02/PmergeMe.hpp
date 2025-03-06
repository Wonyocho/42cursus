#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <cstdlib>
#include <cmath>
#include <ctime>

#define BEFORE_SORT 0
#define AFTER_SORT 1

class PmergeMe {
private:
    typedef std::pair<int, int> Pair;
    std::vector<int> vec;
    std::deque<int> deq;

    PmergeMe();
    PmergeMe(const PmergeMe& rhs);
    PmergeMe& operator=(const PmergeMe& rhs);

    bool isNumber(const std::string& number) const;
    size_t jacobsthalNum(size_t n);

    void mergeSortVec(std::vector<int>& container);
    void mergeSortDeq(std::deque<int>& container);

public:
    PmergeMe(int ac, char** av);
    ~PmergeMe();

    void sortVector();
    void sortDeque();
    void printArr(int state) const;
};

#endif
