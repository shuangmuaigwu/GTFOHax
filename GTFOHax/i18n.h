#pragma once

#include <cstddef>
#include <string>

namespace I18n
{
    enum class Language : int
    {
        ZhCN = 0,
        EnUS = 1
    };

    struct LanguageOption
    {
        Language lang;
        const char* code;
        const char* labelZh;
        const char* labelEn;
    };

    void Init();

    const char* Tr(const char* key);
    const char* Tr(const std::string& key);

    Language GetLanguage();
    void SetLanguage(Language lang);

    int GetLanguageIndex();
    void SetLanguageByIndex(int index);

    const char* const* GetLanguageLabels();
    const LanguageOption* GetLanguageOptions(std::size_t& count);

    const char* GetLanguageCode(Language lang);
    Language LanguageFromCode(const std::string& code);
}
