#ifndef __CLIENT_H
#define __CLIENT_H

#include "precompiled.h"

class Client {
private:
    static uint32_t s_obj_count;
    int m_code;
    std::string m_name;

public:
    static uint32_t get_obj_count();
    
    Client(int t_code, const char* t_name);
    ~Client();
    int get_code();
    const std::string& get_name();
};

#endif//__CLIENT_H
