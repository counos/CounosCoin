#include <key_io.h>
#include <counos/control_functions.h>
#include <consensus/consensus.h>
#include <script/standard.h>
#include <primitives/transaction.h>
#include <counos/walletaddrdb.h> 


bool GetSpecialTransactionToTrustMiner(const CTransaction& tx,  const CCoinsViewCache& inputs)
{
    bool result = false;
    std::string senderAddress = "DEF";
    std::string receiverAddress = "DEF";


    const CAmount special_value_for_trust = 0.00123 * NORMALCOIN;
    const CAmount special_value_for_Untrust = 0.00103 * NORMALCOIN;
    const CAmount special_value_for_block = 0.00132 * NORMALCOIN;
    const CAmount special_value_for_unblock = 0.00102 * NORMALCOIN;

    for (unsigned int i = 0; i < tx.vin.size(); ++i) {
        const COutPoint& prevout = tx.vin[i].prevout;

        const Coin& coin = inputs.AccessCoin(prevout);
        try {
            
            senderAddress = GetTxToWalletAddress(coin.out);
  
        } catch (const std::exception& e) {
        }

       if (senderAddress == SPECIAL_RULE_UPDATEOR)
            break;
   }

   if (senderAddress != SPECIAL_RULE_UPDATEOR)
        return result;

    for (unsigned int i = 0; i < tx.vout.size(); ++i) {
        const CTxOut& transaction = tx.vout[i];
        try {

            receiverAddress = GetTxToWalletAddress(transaction);
       
        } catch (const std::exception& e) {
        }
        uint8_t miner{0};
        uint8_t blocks{1};
         CWalletAddrDB trust_miners{miner};
         CWalletAddrDB block_address{blocks}; 

        if (senderAddress == SPECIAL_RULE_UPDATEOR) {
            strprintf("senderAddress =  %s \n", SPECIAL_RULE_UPDATEOR);
            switch (transaction.nValue) {
            case special_value_for_trust: {
                trust_miners.GetWalletAddressinDb();
                result = trust_miners.Add(receiverAddress);
                strprintf("special_value_for_trust %i , %s \n", transaction.nValue,receiverAddress);
            } break;
            case special_value_for_Untrust: {
               
                result = trust_miners.Delete(receiverAddress);
                strprintf("special_value_for_Untrust %i : %s\n", transaction.nValue,receiverAddress);
            } break;
            case special_value_for_block: {
                
                result = block_address.Add(receiverAddress);
                strprintf("special_value_for_block %i :%s \n", transaction.nValue,receiverAddress);
            } break;
            case special_value_for_unblock: {
               
                result = block_address.Delete(receiverAddress);
                strprintf("special_value_for_unblock %i :%s\n", transaction.nValue,receiverAddress);
            } break;
            }
        }
    }
    return result;
}
/* void ScriptPubKeyToUnivL(const CScript& scriptPubKey,
                        UniValue& out, bool fIncludeHex)
{
    txnouttype type;
    std::vector<CTxDestination> addresses;
    int nRequired;

    out.pushKV("asm", ScriptToAsmStr(scriptPubKey));
    if (fIncludeHex)
        out.pushKV("hex", HexStr(scriptPubKey.begin(), scriptPubKey.end()));

    if (!ExtractDestinations(scriptPubKey, type, addresses, nRequired)) {
        out.pushKV("type", GetTxnOutputType(type));
        return;
    }

    out.pushKV("reqSigs", nRequired);
    out.pushKV("type", GetTxnOutputType(type));

    UniValue a(UniValue::VARR);
    for (const CTxDestination& addr : addresses) {
        a.push_back(EncodeDestination(addr));
    }
    out.pushKV("addresses", a);
} */
 std::string GetTxToWalletAddress(const CTxOut& transaction)
{
    std::string address;

    CTxDestination destination ;
    if ( ExtractDestination( transaction.scriptPubKey, destination ) )
        address = EncodeDestination(destination) ;
    return address;
} 