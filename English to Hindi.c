#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

#define TRANSLATE_URL "https://translate.google.com/m?sl=en&tl=hi&ie=UTF-8&prev=_m&q="

struct MemoryStruct {
    char *memory;
    size_t size;
};

size_t WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;

    mem->memory = realloc(mem->memory, mem->size + realsize + 1);
    if (mem->memory == NULL) {
        printf("Not enough memory (realloc returned NULL)\n");
        return 0;
    }

    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = '\0';

    return realsize;
}

int main() {
    CURL *curl;
    CURLcode res;

    struct MemoryStruct chunk;
    chunk.memory = malloc(1);
    chunk.size = 0;

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl) {
        char word[50];
        printf("Enter an English word: ");
        scanf("%s", word);

        char url[200];
        sprintf(url, "%s%s", TRANSLATE_URL, word);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&chunk);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        } else {
            // Parsing the translation from the retrieved HTML content
            char *translation_start = strstr(chunk.memory, "class=\"result-container\"");
            if (translation_start != NULL) {
                translation_start = strchr(translation_start, '>') + 1;
                char *translation_end = strchr(translation_start, '<');
                if (translation_end != NULL) {
                    *translation_end = '\0';
                    printf("Hindi translation: %s\n", translation_start);
                } else {
                    printf("Translation not found.\n");
                }
            } else {
                printf("Translation not found.\n");
            }
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
    free(chunk.memory);

    return 0;
}
