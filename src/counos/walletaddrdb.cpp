#include <counos/walletaddrdb.h>
#include <addrdb.h>
#include <string>
#include <core_io.h>
#include <counos/walletaddrman.h>




bool CWalletAddrDB::Add(const std::string& walletAddress)
{
  
    CWalletAddrMan service;
    if (walletAdddb.Read(service)) {
         if (service.walletAddressList.find(walletAddress) == std::string::npos) {
            service.walletAddressList += walletAddress + ",";
         }
    }

    
    return walletAdddb.Write(service);
}
bool CWalletAddrDB::Reset()
{
    CWalletAddrMan service;
    if (walletAdddb.Read(service)) {
         service.walletAddressList = "";
    }
    return walletAdddb.Write(service);
}
bool CWalletAddrDB::Delete(const std::string& walletAddress)
{
    CWalletAddrMan service;
    if (walletAdddb.Read(service)) {
         if (service.walletAddressList.find(walletAddress) != std::string::npos) {

            service.walletAddressList.replace(service.walletAddressList.find(walletAddress),walletAddress.size()+1,"");
         }
    }

    
    return walletAdddb.Write(service);
}
bool CWalletAddrDB::Find(const std::string& walletAddress)
{
    CWalletAddrMan service;
    if (walletAdddb.Read(service)) {
        //LogPrintf("List Of saved Wallet %i \n", service.walletAddressList);
         if (service.walletAddressList.find(walletAddress) != std::string::npos) {

            return true;
         }
    }

    
    return false;
}
std::string CWalletAddrDB::GetWalletAddressinDb()
{
   CWalletAddrMan service;
    if (walletAdddb.Read(service)) {
         return service.walletAddressList;
    }
    return "";
}
