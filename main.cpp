#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct HttpRequest{
    std::string method;
    std::string path;
    std::string version;
    std::vector<std::pair<std::string, std::string>> headers;
};

std::string trim(const std::string& s){
    //Whitespace is one of: space, tab, carriage return, 
    //line feed, form feed, or vertical tab.
    const char* whitespace = " \t\n\r\v\f";
    size_t begin = s.find_first_not_of(whitespace);
    if (begin == std::string::npos){
        return std::string{};
    }
    size_t end = s.find_last_not_of(whitespace);
    return std::string{s.substr(begin, end - begin +1)};
}

int main(){
    HttpRequest request;
    std::ifstream file("http.txt");
    std::string s1;
    std::string s2;

    //parse the request line
    std::getline(file, s1);
    std::stringstream ss(s1);
    ss >> request.method;
    ss >> request.path;
    ss >> request.version;
    std::cout << request.method << std::endl;
    std::cout << request.path << std::endl;
    std::cout << request.version << std::endl;
    
    //parse the headers
    while(std::getline(file, s2)){
        size_t pos = s2.find(':'); //οταν συνανταει την κενη γραμμη γίνεται 18446744073709551615
        if (pos == std::string::npos){
            break;
        }
        request.headers.emplace_back(s2.substr(0,pos), trim(s2.substr(pos + 1)));
    }
    file.close();
    for (auto& pair : request.headers){
        std::cout << pair.first << " " << pair.second << std::endl;
    }
    return 0;
}
