// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2018 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOIN_POLICY_FEERATE_H
#define BITCOIN_POLICY_FEERATE_H

#include <amount.h>
#include <serialize.h>

#include <string>

extern const std::string CURRENCY_UNIT;

/**
 * Fee rate in satoshis per kilobyte: CAmount / 100kB
 */
class CFeeRate
{
private:
    CAmount nSatoshisPer100K; // unit is satoshis-per-1,000-bytes

public:
    /** Fee rate of 0 satoshis per kB */
    CFeeRate() : nSatoshisPer100K(0) { }
    template<typename I>
    CFeeRate(const I _nSatoshisPer100K): nSatoshisPer100K(_nSatoshisPer100K) {
        // We've previously had bugs creep in from silent double->int conversion...
        static_assert(std::is_integral<I>::value, "CFeeRate should be used without floats");
    }
    /** Constructor for a fee rate in satoshis per kB. The size in bytes must not exceed (2^63 - 1)*/
    CFeeRate(const CAmount& nFeePaid, size_t nBytes);
    /**
     * Return the fee in satoshis for the given size in bytes.
     */
    CAmount GetFee(size_t nBytes) const;
    /**
     * Return the fee in satoshis for a size of 1000 bytes
     */
    CAmount GetFeePerK() const { return GetFee(1000); }
    friend bool operator<(const CFeeRate& a, const CFeeRate& b) { return a.nSatoshisPer100K < b.nSatoshisPer100K; }
    friend bool operator>(const CFeeRate& a, const CFeeRate& b) { return a.nSatoshisPer100K > b.nSatoshisPer100K; }
    friend bool operator==(const CFeeRate& a, const CFeeRate& b) { return a.nSatoshisPer100K == b.nSatoshisPer100K; }
    friend bool operator<=(const CFeeRate& a, const CFeeRate& b) { return a.nSatoshisPer100K <= b.nSatoshisPer100K; }
    friend bool operator>=(const CFeeRate& a, const CFeeRate& b) { return a.nSatoshisPer100K >= b.nSatoshisPer100K; }
    friend bool operator!=(const CFeeRate& a, const CFeeRate& b) { return a.nSatoshisPer100K != b.nSatoshisPer100K; }
    CFeeRate& operator+=(const CFeeRate& a) { nSatoshisPer100K += a.nSatoshisPer100K; return *this; }
    std::string ToString() const;

    ADD_SERIALIZE_METHODS;

    template <typename Stream, typename Operation>
    inline void SerializationOp(Stream& s, Operation ser_action) {
        READWRITE(nSatoshisPer100K);
    }
};

#endif //  BITCOIN_POLICY_FEERATE_H
