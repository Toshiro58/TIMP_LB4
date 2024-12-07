/** @file
 *  @author Пономарев А.А
 *  @version 1.0
 *  @date 04.12.2024
 *  @copyright ИБСТ ПГУ
 *  @warning Данный модуль реализует шифр модифицированного алфавита.
 *  @brief Заголовочный файл для класса modAlphaCipher, реализующего шифрование и расшифровку текста.
 */

#pragma once
#include <map>
#include <string>
#include <vector>
#include <stdexcept>
#include <cwctype>
#include <codecvt>
#include <locale>

/** 
 *  @class modAlphaCipher
 *  @brief Класс для шифрования и расшифровки текста с использованием модифицированного алфавитного шифра.
 *  
 *  @details Данный класс реализует шифр, который использует русский алфавит и ключ для шифрования и 
 *  расшифровки текстов. Он включает методы для преобразования текста в числовой формат и обратно, 
 *  а также для проверки валидности ключа и текста.
 */
class modAlphaCipher
{
private:
    std::wstring numAlpha = L"АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ"; ///< Русский алфавит в виде строки.
    std::map<char, int> alphaNum; ///< Отображение символов алфавита на их числовые значения.
    std::vector<int> key; ///< Ключ для шифрования/расшифровки.
    
    /** 
     *  @brief Преобразует строку в вектор чисел.
     *  @param s Строка для преобразования.
     *  @return Вектор целых чисел, соответствующий символам строки.
     */
    std::vector<int> convert(const std::wstring& s);

    /** 
     *  @brief Преобразует вектор чисел обратно в строку.
     *  @param v Вектор целых чисел для преобразования.
     *  @return Строка, соответствующая вектору чисел.
     */
    std::wstring convert(const std::vector<int>& v);

    /** 
     *  @brief Проверяет валидность ключа.
     *  @param s Ключ для проверки.
     *  @return Валидный ключ в виде строки.
     *  @throw cipher_error Если ключ не валиден.
     */
    std::wstring getValidKey(const std::wstring& s);

    /** 
     *  @brief Проверяет валидность открытого текста.
     *  @param ws Открытый текст для проверки.
     *  @return Валидный открытый текст в виде строки.
     *  @throw cipher_error Если текст не валиден.
     */
    std::wstring getValidOpenText(const std::wstring & ws);

    /** 
     *  @brief Проверяет валидность зашифрованного текста.
     *  @param ws Зашифрованный текст для проверки.
     *  @return Валидный зашифрованный текст в виде строки.
     *  @throw cipher_error Если текст не валиден.
     */
    std::wstring getValidCipherText(const std::wstring & ws);

public:
    /** 
     *  @brief Конструктор класса modAlphaCipher (удален).
     *  @details Конструктор не может быть вызван без параметров. Необходимо передать ключ.
     */
    modAlphaCipher() = delete;

    /** 
     *  @brief Конструктор класса modAlphaCipher с заданным ключом.
     *  @param skey Ключ для шифрования/расшифровки.
     *  @throw cipher_error Если ключ не валиден.
     */
    modAlphaCipher(const std::wstring& skey);

    /** 
     *  @brief Шифрует открытый текст.
     *  @param open_text Открытый текст для шифрования.
     *  @return Зашифрованный текст в виде строки.
     */
    std::wstring encrypt(const std::wstring& open_text);

    /** 
     *  @brief Расшифровывает зашифрованный текст.
     *  @param cipher_text Зашифрованный текст для расшифровки.
     *  @return Открытый текст в виде строки.
     */
    std::wstring decrypt(const std::wstring& cipher_text);
};

/** 
 *  @class cipher_error
 *  @brief Исключение для обработки ошибок шифрования.
 *
 *  @details Данный класс расширяет std::invalid_argument и используется для обработки ошибок,
 *  возникающих при работе с классом modAlphaCipher. 
 */
class cipher_error : public std::invalid_argument
{
public:
    /** 
     *  @brief Конструктор исключения с сообщением об ошибке.
     *  @param what_arg Сообщение об ошибке.
     */
    explicit cipher_error(const std::string& what_arg)
        : std::invalid_argument(what_arg)
    {
    }

    /** 
     *  @brief Конструктор исключения с сообщением об ошибке (C-строка).
     *  @param what_arg Сообщение об ошибке (C-строка).
     */
    explicit cipher_error(const char* what_arg)
        : std::invalid_argument(what_arg)
    {
    }
};
