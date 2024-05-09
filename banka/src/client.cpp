#include "include/client.h"

uint32_t Client::s_obj_count = 0;

uint32_t Client::get_obj_count() {
    return Client::s_obj_count;
}

Client::Client(int t_code, const char* t_name)
    : m_code(t_code), m_name(t_name) 
{
    Client::s_obj_count += 1;
}

Client::~Client() {
    if(DBG)printf("INFO: %s\n", __PRETTY_FUNCTION__);
    Client::s_obj_count -= 1;
}

int Client::get_code() {
    return this->m_code;
}

const std::string& Client::get_name() {
    return this->m_name;
}

