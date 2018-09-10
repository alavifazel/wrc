#include "http.h"

void HTTP::connect(const std::string url){
  if(curl) {

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // to disable console output:
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

    res = curl_easy_perform(curl);
    if(res != CURLE_OK){
      throw curl_easy_strerror(res);
    }
  }
}

HTTP::HTTP(){
  curl = curl_easy_init();
}

HTTP::~HTTP(){
  curl_easy_cleanup(curl);
}

size_t HTTP::write_data(void *buffer, size_t size, size_t nmemb, void *userp) {
   return size * nmemb;
}
