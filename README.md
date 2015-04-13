# Crypto-Ticker
A price ticker for crypto-currencies.
The ticker is a simple Linux desktop widget with built in alarm that triggers at a set threshold and also functions as a Ticker Api reader for potentially any Bitcoin or Cryptocurrency Exchanges.  
The curl wrapper class is intended to be reused for other purposes. 
The ticker still requires a relatively stable internet line, since it queries the exchange APIs every second and performs best when constantly connected.

___

The ticker currently supports:  
[OkCoin] (https://www.okcoin.cn/api/ticker.do)  
[BTCChina] (https://data.btcchina.com/data/ticker)  
[Bitstamp] (https://www.bitstamp.net/api/ticker/)   
[BitFinex] (https://api.bitfinex.com/v1/pubticker/BTCUSD)   

___

Dependencies:

qt4  
c++11  
curl  
