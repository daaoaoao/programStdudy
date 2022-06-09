#include "Poco/JSON/Parser.h"
#include "Poco/JSON/ParseHandler.h"
#include "Poco/JSON/JSONException.h"
#include "Poco/StreamCopier.h"
#include "Poco/Dynamic/Var.h"
#include "Poco/JSON/Query.h"
#include "Poco/JSON/PrintHandler.h"
#include "Poco/Net/HTTPClientSession.h"
#include "Poco/Net/HTTPRequest.h"
#include "Poco/Net/HTTPResponse.h"
#include "Poco/StreamCopier.h"
#include "Poco/Net/NetException.h"
#include "Poco/Net/HTMLForm.h"
#include "Poco/URI.h"
#include <iostream>
using namespace Poco::Dynamic;
using namespace Poco;
using std::string;
using namespace Poco::JSON;
using namespace Poco::Net;
int main()
{
    try {
        std::string strUrl("http://10.0.1.77:8999/blacklist?id=132623198111196400");
        Poco::URI uri(strUrl);
        HTTPClientSession session(uri.getHost(), uri.getPort());
        HTTPRequest request(HTTPRequest::HTTP_GET, uri.getPathAndQuery());
        session.sendRequest(request);
        HTTPResponse response;
        std::istream &is = session.receiveResponse(response);
        const HTTPResponse::HTTPStatus &status = response.getStatus();
        if (HTTPResponse::HTTPStatus::HTTP_OK == status) {
            std::string result;
            StreamCopier::copyToString(is, result);
            std::cout << result << result.size() << std::endl;
        } else {
            std::cout << status << std::endl;
        }
    } catch (Poco::Exception &e) {
        std::cout << e.message() << std::endl;
}

    return 0;
}

