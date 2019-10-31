CounosCoin Core integration/staging tree
=====================================

[![Build Status](https://travis-ci.org/counoscoin-project/counoscoin.svg?branch=master)](https://travis-ci.org/counoscoin-project/counoscoin)

https://www.counos.io

License
-------

CounosCoin Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

What is CounosCoin?
----------------

CounosCoin is an experimental digital currency that enables instant payments to
anyone, anywhere in the world. CounosCoin uses peer-to-peer technology to operate
with no central authority: managing transactions and issuing money are carried
out collectively by the network. CounosCoin Core is the name of open source
software which enables the use of this currency.

For more information, as well as an immediately useable, binary version of
the CounosCoin Core software, see [https://www.counos.io](https://www.counos.io).


Counos Coin (CCA) version 0.15.3 
--------------------------------
From the block 98500, 1.5 reward coins will only be given to trusted nodes.
Trusted nodes are those nodes that have at least 500,000 CCA.
Any node that can meet this condition will be added to the list of the trusted nodes through an agreement with Counos Platform and by submitting a wallet address to which mining reward will be sent.
The block creation time window is still in consideration, such that the 1.5 reward coins are for those blocks that are created 7.5 minutes after the previous block, and if the time window is less than that, the reward would be divided by 10000. And now the added rule is that after the block 98500, if the node is a trusted node and the block is created in the desirable time window, it will get the 1.5 reward coins and the rest of the nodes will receive the reward divided by 10000.
And, the transaction fees will be given to all node, as it used to be so.
Other Changes in new Release of CCA :
- Coin base maturity priod  will be increase to 100,000 Blocks, it means that all reward for new blocks will be spendable after large amount of blocks confirm that. So its not easy to earn and spend CCA trough mining process. Its very important for mining pools and miners which like to send Hashes to CCA network.
- Also there are some other changes in PoW rules, normally blocks must create every 10 minutes, but based on current difficulty and network hash, the time maybe changed, by new PoW rules, 
  -- if more than 30 minutes left from last block  creation time, and no new block created, Required work will be decrease to 1000 * PowLimit, 
  -- and if last 25 blocks created in less than 50 minutes (‌each block in 2 minutes) network will increase Require work 4 * last known work required. 

All mining pools which verified as a Trust node, will be indicated by a Trust node Logo, 

Counos Coin (CCA) version 0.15.3.2
----------------------------------

From block 144457, only valid miners will be able to mine new blocks. A valid miner is a miner who has a balance of 10,000 coins.

Also, from block 164457, the time window between two created blocks should at least be 7.5 minutes. In other words, if a block is created in less than 7.5 minutes after the creation of the previous block, it will not be valid.


How to setup node?
----------------

Please check doc/build-unix.md for more details, there is all commands need to be run

  	sudo apt-get install build-essential libtool autotools-dev automake pkg-config libssl-dev libevent-dev bsdmainutils libcurl4-openssl-dev
 	sudo apt-get install libboost-all-dev
	
  	sudo apt-get install software-properties-common
	
	sudo add-apt-repository ppa:bitcoin/bitcoin
	
	sudo apt-get update
	
	sudo apt-get install libdb4.8-dev libdb4.8++-dev
	

	sudo apt-get install libzmq3-dev



	./autogen.sh
	./configure --disable-tests --disable-bench --without-gui
	make


Block Explorer
--------------

CCA block explorere can be found at http://blockex.csc.counos.org

It's very important to check transaction status on this block explorere. and also by this exploere you can be sure that your are on correct chain.

Official nodes
----------

Please make sure that you are connected to correct and up-to-date nodes, there is a list of valid and official nodes, if  you find any contradiction between your local chain and what you find on these nodes, please check block explorer to make sure you are on correct chain.

	51.89.161.144
	51.89.161.145
	95.216.122.133
	95.216.122.135
	95.216.122.136
	95.216.122.138
	95.216.122.137
	95.216.122.142
	
