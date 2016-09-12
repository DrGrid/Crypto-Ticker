#include <string>
#include <curl/curl.h>
#include "curl_wrapper_class.h"

CppCurl::CppCurl()
{
    m_handle = curl_easy_init();
}

void CppCurl::settings(const char * url)
{
    m_url=url;
    SetOptions();
}

std::string CppCurl::fetch()
{
    SendGetRequest();
    return m_data;
}

void CppCurl::data_cleanup()
{
    m_data.clear();
}

CppCurl::~CppCurl()
{
    curl_easy_cleanup(m_handle);
}
