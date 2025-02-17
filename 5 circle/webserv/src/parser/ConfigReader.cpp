#include "ConfigReader.hpp"

// 파일 경로(filepath)를 입력 -> 파일의 내용을 읽어 반환.
// 파일을 열 수 없거나 파일이 비어 있는 경우 빈 문자열을 반환.
std::string ConfigReader::ReadFile(std::string filepath)
{
    // 파일 스트림 생성
    std::ifstream config_file(filepath.c_str());

    // 파일 열기에 실패한 경우
    if (!config_file.is_open())
    {
        // 에러 메시지 출력
        std::cerr << "Cannot open : " << filepath << std::endl;
        
        // 빈 문자열 반환
        return ("");
    }

    // 파일 내용을 읽어 content에 저장
    std::string content((std::istreambuf_iterator<char>(config_file)), std::istreambuf_iterator<char>());

    // 파일이 비어 있는 경우
    if (content.empty())
    {
        // 에러 메시지 출력
        std::cerr << "File is empty : " << filepath << std::endl;

        // 빈 문자열 반환
        return ("");
    }

    // 파일 내용 반환
    return (content);
}

// 생성자
// 기본 설정 파일 경로를 설정
ConfigReader::ConfigReader()
{
    // 기본 설정 파일 경로 설정
    default_conf_path = "./default.conf";
}

// 기본 설정 파일 경로를 반환.
std::string ConfigReader::GetDefaultPath()
{
    return (default_conf_path);
}