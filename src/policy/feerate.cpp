// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <policy/feerate.h>
#include <logging.h>

#include <tinyformat.h>

const std::string CURRENCY_UNIT = "CCA";

CFeeRate::CFeeRate(const CAmount& nFeePaid, size_t nBytes_)
{
    assert(nBytes_ <= uint64_t(std::numeric_limits<int64_t>::max()));
    int64_t nSize = int64_t(nBytes_);

    if (nSize > 0)
        nSatoshisPer100K = nFeePaid * 1000 / nSize;
    else
        nSatoshisPer100K = 0;
}

CAmount CFeeRate::GetFee(size_t nBytes_) const
{
    assert(nBytes_ <= uint64_t(std::numeric_limits<int64_t>::max()));
    int64_t nSize = int64_t(nBytes_);

    CAmount nFee = nSatoshisPer100K * nSize / 100000;

    if (nFee == 0 && nSize != 0) {
        if (nSatoshisPer100K > 0)
            nFee = CAmount(1);
        if (nSatoshisPer100K < 0)
            nFee = CAmount(-1);
    }
 

    return nFee;
}

std::string CFeeRate::ToString() const
{
    return strprintf("%d.%08d %s/kB", nSatoshisPer100K / COIN, nSatoshisPer100K % COIN, CURRENCY_UNIT);
}
