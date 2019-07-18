#include <eosiolib/eosio.hpp>

using namespace eosio;

CONTRACT addressbook: public contract {
    public:
        ACTION upsert() {}
        ACTION erase() {}

    private:
        TABLE person {
            name user;
            std::string first_name;
            std::string last_name;
            uint32_t age;
            uint64_t primary_key() const { return key.value; }
        };
        
        typedef multi_index<"people"_n, person> address_index;
};
