#include "PmergeMe.hpp"
#include <iostream>
#include <stdexcept>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <positive integer sequence>" << std::endl;
        return 1;
    }

    try {
        // PmergeMe 객체 생성 (입력값 검증 및 저장)
        PmergeMe sorter(argc, argv);

        // 정렬 전 데이터 출력
        sorter.printArr(BEFORE_SORT);

        // 벡터(Vector) 정렬
        sorter.sortVector();

        // 덱(Deque) 정렬
        sorter.sortDeque();

        // 정렬 후 데이터 출력
        sorter.printArr(AFTER_SORT);
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}
