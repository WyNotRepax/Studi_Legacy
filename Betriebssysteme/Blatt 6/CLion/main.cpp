#include <iostream>
#include "web_request.hpp"



int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
    WebRequest webRequest(argc,argv);
    const std::string url("https://google.de");
    const std::string file("test.txt");
    webRequest.download(url,file);
    return 0;
}