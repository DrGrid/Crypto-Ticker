#include <string>
#include <curl/curl.h>

class CppCurl
{
private:
private:
   void SetOptions()
   {
      //set the url
      curl_easy_setopt(m_handle, CURLOPT_URL, m_url.c_str());
      //progress bar is not require
      curl_easy_setopt(m_handle, CURLOPT_NOPROGRESS, 1L);
      //set the callback function
      curl_easy_setopt(m_handle, CURLOPT_WRITEFUNCTION, CppCurl::WriteDataCallback);
      //set pointer in call back function
      curl_easy_setopt(m_handle, CURLOPT_WRITEDATA, this);
   }
   void SendGetRequest()
   {
      curl_easy_perform(m_handle);
   }

   static size_t WriteDataCallback(void *ptr, size_t size, size_t nmemb, void* pInstance)
   {
      return (static_cast<CppCurl*>(pInstance))->write_data(ptr, size, nmemb);
   }

   size_t write_data(void* ptr, size_t size, size_t nmemb)
   {
      size_t numOfBytes = size * nmemb;
      char *iter = (char*)ptr;
      char *iterEnd = iter + numOfBytes;
      m_data += std::string(iter, iterEnd);
      return numOfBytes;
   }
   CURL *m_handle;
   std::string m_url;
   std::string m_data;

public:
   CppCurl();
   void settings(std::string url);
   std::string Fetch();
   void data_cleanup();
   ~CppCurl();
};
