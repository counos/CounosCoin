#ifndef BITCOIN_CONTROL_FUNCTIONS_H
#define BITCOIN_CONTROL_FUNCTIONS_H

#include <coins.h>
#include <primitives/transaction.h>
#include <string>

std::string GetTxToWalletAddress(const CTxOut& transaction);
bool GetSpecialTransactionToTrustMiner(const CTransaction& tx,  const CCoinsViewCache& inputs);

#endif // BITCOIN_CONTROL_FUNCTIONS_H