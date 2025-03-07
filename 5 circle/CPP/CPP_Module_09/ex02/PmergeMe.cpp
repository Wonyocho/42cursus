#include "PmergeMe.hpp"

// 받은 인자들을 각 컨테이너에 저장한다.
PmergeMe::PmergeMe(int ac, char** av)
{
    for (int i = 1; i < ac; i++)
    {
        std::string arg = av[i];
        if (!isNumber(arg))
        {
            throw std::logic_error("Error: not a number: " + arg);
        }

        long number = std::atol(av[i]);
        if (number > 2147483647 || number < 0)
        {
            throw std::logic_error("Error: number out of int range: " + arg);
        }

        vec.push_back(static_cast<int>(number));
        deq.push_back(static_cast<int>(number));
    }
}

PmergeMe::~PmergeMe() {}

// 문자열이 숫자로만 이루어져 있는지 검사.
bool PmergeMe::isNumber(const std::string& number) const
{
    for (size_t i = 0; i < number.size(); i++)
    {
        if (!isdigit(number[i]))
        {
            return false;
        }
    }
    return true;
}

// merge-insertion sort를 사용할 때, Jacobsthal 수열을 이용하여
size_t PmergeMe::jacobsthalNum(size_t n)
{
    return ((pow(2, n) - pow(-1, n)) / 3);
}

// merge sort를 사용하여 정렬한다.
void PmergeMe::mergeSortVec(std::vector<int>& container)
{
    if (container.size() <= 1)
    {
        return;
    }

    size_t mid = container.size() / 2;
    std::vector<int> left(container.begin(), container.begin() + mid);
    std::vector<int> right(container.begin() + mid, container.end());

    mergeSortVec(left);
    mergeSortVec(right);

    container.clear(); // clear()를 사용하여 기존의 데이터를 삭제한다.
    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            container.push_back(left[i++]);
        }
        else
        {
            container.push_back(right[j++]);
        }
    }
    while (i < left.size())
    {
        container.push_back(left[i++]);
    }
    while (j < right.size())
    {
        container.push_back(right[j++]);
    }
}

void PmergeMe::mergeSortDeq(std::deque<int>& container)
{
    if (container.size() <= 1)
    {
        return;   
    }

    size_t mid = container.size() / 2;
    std::deque<int> left(container.begin(), container.begin() + mid);
    std::deque<int> right(container.begin() + mid, container.end());

    mergeSortDeq(left);
    mergeSortDeq(right);

    container.clear();
    size_t i = 0, j = 0;
    while (i < left.size() && j < right.size())
    {
        if (left[i] < right[j])
        {
            container.push_back(left[i++]);
        }
        else
        {
            container.push_back(right[j++]);
        }
    }
    while (i < left.size())
    {
        container.push_back(left[i++]);
    }
    while (j < right.size())
    {
        container.push_back(right[j++]);
    }
}

void PmergeMe::sortVector()
{
    clock_t start = clock();
    mergeSortVec(vec);
    clock_t end = clock();

    std::cout << "Vector sort time: "
              << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000
              << " us" << std::endl;
}

void PmergeMe::sortDeque()
{
    clock_t start = clock();
    mergeSortDeq(deq);
    clock_t end = clock();

    std::cout << "Deque sort time: "
              << static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000
              << " us" << std::endl;
}

void PmergeMe::printArr(int state) const
{
    if (state == BEFORE_SORT)
    {
        std::cout << "Before: ";
    }
    else if (state == AFTER_SORT)
    {
        std::cout << "After: ";
    }

    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}
