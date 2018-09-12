#include "http.h"

std::string HTTP::connect(const std::string url){
  std::string content;
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

    // to disable console output:
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data);

    // to save content to string
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &content);
    res = curl_easy_perform(curl);
    if(res != CURLE_OK){
      throw curl_easy_strerror(res);
    }
  }
  return content;
}

HTTP::HTTP(){
  curl = curl_easy_init();
}

HTTP::~HTTP(){
  curl_easy_cleanup(curl);
}

size_t HTTP::write_data(void *content, size_t size, size_t nmemb, void *userp) {
  ((std::string*)userp)->append((char*)content, size * nmemb);
  return size * nmemb;
}
