#include "inc/MemberManager.h"

MemberManager::MemberManager() = default;

MemberManager::~MemberManager() = default;

std::shared_ptr<Member> MemberManager::addMember(int keyID, std::shared_ptr<Member> member)
{
    return this->member_list.emplace(keyID, std::move(member)).first->second;
}

std::shared_ptr<Member> MemberManager::addBasicMember(int keyID, const std::string& forename, const std::string& surname)
{
    this->member_list.emplace(keyID, std::make_shared<BasicMember>(keyID, forename, surname));
    return this->member_list.at(keyID);
}

std::shared_ptr<Member> MemberManager::addPremiumMember(int keyID, const std::string& forename, const std::string& surname, int bonusPoints)
{
    this->member_list.emplace(keyID, std::make_shared<PremiumMember>(bonusPoints, keyID, forename, surname));
    return this->member_list.at(keyID);
}

std::shared_ptr<Member> MemberManager::getMember(int keyID)
{
    return this->member_list.at(keyID);
}

std::string MemberManager::toStr(int tabSize)
{
    std::stringstream ss;

    ss << tabs(tabSize) << "Member Manager " << "{" << std::endl;

    for(auto m : this->member_list) {
        auto bm = dynamic_cast<BasicMember*>(m.second.get());
        if(bm) {
            ss << bm->toStr(tabSize+1) << std::endl;
        }

        auto pm = dynamic_cast<PremiumMember*>(m.second.get());
        if(pm) {
            ss << pm->toStr(tabSize+1) << std::endl;
        }
    }

    ss << tabs(tabSize) << "}";

    return ss.str();
}