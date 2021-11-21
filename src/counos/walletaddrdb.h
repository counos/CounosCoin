#ifndef BITCOIN_WALLETADDRDB_H
#define BITCOIN_WALLETADDRDB_H

#include <addrdb.h>
#include <string>

class CWalletAddrDB
{
    private:
        CWallAddDb walletAdddb;

    public :
        CWalletAddrDB(uint8_t wallet_type) :  walletAdddb {wallet_type}
        {

        };
        bool Add(const std::string& walletAddress);
        
        bool Delete(const std::string& walletAddress);

        bool Find(const std::string& walletAddress);
        
        bool Reset();

        std::string GetWalletAddressinDb();
        
};
#endif // BITCOIN_WALLETADDRDB_H