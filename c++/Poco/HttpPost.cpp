#include <iostream>
#include <string>
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/StreamCopier.h"
#include "Poco/Net/NetException.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/URI.h"

int main()
{
    try{
        URI url("http://test.xheart.cn/xheartdevelop05/user/login/validate");
        HTTPClientSession session(url.getHost(),url.getPort());
        HTTPRequest request(HTTPRequest::HTTP_POST,url.getPath(),HTTPRequest::HTTP_1_1);
        HTMLForm form;
        form.add("userName", "1220002");
        form.add("password", "1234567");
        form.prepareSubmit(request);
        form.write(session.sendRequest(request));
        HTTPResponse res;
        std::istream & is = session.receiveResponse(res);
        StreamCopier::copyStream(is, std::cout);
    }
    catch(NetException & ex){
        std::cout << ex.displayText(); 
    }
}

