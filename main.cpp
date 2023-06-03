#include <iostream>
#include <string>
#include <cpr/cpr.h>

int main() {
    // the address of the page from which we will extract information
    const std::string url1 = "http://httpbin.org/html";

    //-------------------------------------------------------------------------------------------------
    // we make an appropriate request
    std::cout << "A request is being made. Wait..." << std::endl;
    cpr::Response r = cpr::Get(
        cpr::Url(url1),
        cpr::Header({
            {"user-agent", "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/104.0.0.0 Safari/537.36"},
            {"Accept", "text/html"}
        })
    );

    //-------------------------------------------------------------------------------------------------
    // completing a task

    // getting an html page in text form
    std::string txt = r.text;
    // calculating the position of tags
    std::size_t
        pos1 = txt.find("<h1>"),
        pos2 = txt.find("</h1>", pos1);
    // checking the correct search
    if( (pos1 == std::string::npos) || (pos2 == std::string::npos) ) {
        std::cout << "Tag(s) not found." << std::endl;
        return 0;
    }
    // extracting the title text
    std::string Caption = txt.substr(pos1 + 4, pos2 - pos1 - 4);

    //-------------------------------------------------------------------------------------------------
    // output of the result
    std::cout
        << "\nResult:\n"
        << "\tCaption: '" << Caption << "'\n";

    //-------------------------------------------------------------------------------------------------
    // program shutdown
    std::cout << "\nEnd of program." << std::endl;
    return 0;
}
