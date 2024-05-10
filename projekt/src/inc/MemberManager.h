#ifndef __LIBRARY_MEMBER_MANAGING_MODULE_H
#define __LIBRARY_MEMBER_MANAGING_MODULE_H

#include "StringOutput.h"
#include "Member.h"

class MemberManager : public StringOutput
{
    private:
        std::map<int, std::shared_ptr<Member>> member_list;

    public:
        MemberManager();
        ~MemberManager() override;

        std::shared_ptr<Member> addMember(int keyID, std::shared_ptr<Member> member);

        std::shared_ptr<Member> addBasicMember(int keyID, const std::string& forename, const std::string& surname);

        std::shared_ptr<Member> addPremiumMember(int keyID, const std::string& forename, const std::string& surname, int bonusPoints);

        std::shared_ptr<Member> getMember(int keyID);

        std::string toStr(int tabSize) override;
};

#endif//__LIBRARY_MEMBER_MANAGING_MODULE_H