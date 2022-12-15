#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <string_view>
#include <vector>

struct bool_bit {
    bool value;
};

struct bool_byte {
    bool_bit bits[8];

    constexpr unsigned char decode() {
        unsigned char decoded = 0x0;

        for (int i = 0; i < 8; i++)
            decoded |= bits[i].value << (7 - i);

        return decoded;
    }

    constexpr std::string to_binary() {
        std::string ret;

        for (int i = 0; i < 8; i++)
            ret = std::to_string((int)bits[i].value) + ret;

        return ret;
    }
};

struct bool_int {
    bool_byte bytes[4];

    constexpr unsigned int decode() {
        unsigned int decoded = 0;

        for (int i = 0; i < 32; i++)
            decoded |= bytes[i / 8].bits[i % 8].value << (31 - i);

        return decoded;
    }

    constexpr std::string to_binary() {
        std::string ret;

        for (int i = 0; i < 32; i++)
            ret = std::to_string((int)bytes[i / 8].bits[i].value) + ret;

        return ret;
    }
};

struct bool_string {
    std::vector<bool_byte> str = { };

    constexpr std::string decode() {
        std::string retval;

        for (bool_byte b : str) {
            retval += b.decode();
        }

        return retval;
    }

    constexpr bool_string(std::initializer_list<bool_byte> bytes) {
        decltype(bytes)::iterator itr;

        for (itr = bytes.begin(); itr != bytes.end(); itr++) {
            str.push_back(*itr);
        }
    }
};

constexpr bool_byte encode(const char byte) {
    bool_byte bb = { };

    for (int i = 0; i < 8; i++)
        bb.bits[i].value = (byte >> (7 - i)) & !!1;

    return bb;
}

constexpr bool_byte encode(const unsigned char byte) {
    bool_byte bb = { };

    for (int i = 0; i < 8; i++)
        bb.bits[i].value = (byte >> (7 - i)) & !!1;

    return bb;
}

constexpr bool_int encode(const int bytes) {
    bool_int bi = { };

    for (int i = 0; i < 32; i++) {
        bi.bytes[i / 8].bits[i % 8].value = (bytes >> (31 - i)) & !!1;
    }

    return bi;
}

constexpr bool_int encode(const unsigned int bytes) {
    bool_int bi = { };

    for (int i = 0; i < 32; i++) {
        bi.bytes[i / 8].bits[i % 8].value = (bytes >> (31 - i)) & !!1;
    }

    return bi;
}

constexpr bool_string encode(const std::string str) {
    bool_string bs = { };

    for (char c : str) {
        bs.str.push_back(encode(c));
    }

    return bs;
}

constexpr std::string byte_to_binary(unsigned char byte) {
    std::string ret;
    for (int i = 0; i < 8; i++)
        ret = std::to_string((byte >> i) & !!1) + ret;

    return ret;
}

constexpr std::string int_to_binary(unsigned int bytes) {
    std::string ret;
    for (int i = 0; i < 32; i++) {
        const int bit = (bytes >> i) & !!1;
        ret = std::to_string(bit) + ret;
    }

    return ret;
}

constexpr std::string byte_to_initializer(unsigned char byte) {
    std::string binary = byte_to_binary(byte);

    std::string retval = "{ ";

    for (int i = 1; i <= binary.length(); i++) {
        char c = binary[i - 1];

        retval += c == '1' ? "true" : "false";

        if (i != binary.length()) {
            retval += ", ";
        }
    }

    retval += " }";

    return retval;
}

constexpr std::string int_to_initializer(unsigned int bytes) {
    std::string binary = int_to_binary(bytes);

    std::string retval = "{\n";

    for (int i = 1; i <= binary.length(); i++) {
        char c = binary[i - 1];

        if (i % 4 == 1) {
            retval += "    ";
        }

        retval += c == '1' ? "true" : "false";

        if (i != binary.length()) {
            retval += ", ";
        }

        if (i % 4 == 0) {
            retval += "\n";
        }
    }

    retval += "\n}";

    return retval;
}

constexpr std::string string_to_initializer(std::string bytes) {
    std::string retval = "{\n";

    for (int i = 1; i <= bytes.length(); i++) {
        char c = bytes[i - 1];

        retval += "    ";
        retval += byte_to_initializer(c);
        
        if (i != bytes.length()) {
            retval += ",\n";
        }
    }

    retval += "\n};";

    return retval;
}