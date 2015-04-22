# Crypto-Ticker
A price ticker for crypto-currencies.
The ticker is a simple Linux desktop widget with built in alarm that triggers at a set threshold. It also has basic price plotting and potentially supports any cryptocurrency exchange with a public ticker api.     
The curl wrapper class is intended to be reused for other purposes.   
The ticker still requires a relatively stable internet line, since it queries the exchange APIs as often as it can and therefore performs best with a stable internet connection.   

___

The ticker currently supports:  
[OkCoin] (https://www.okcoin.cn/api/ticker.do)  
[BTCChina] (https://data.btcchina.com/data/ticker)  
[Bitstamp] (https://www.bitstamp.net/api/ticker/)   
[BitFinex] (https://api.bitfinex.com/v1/pubticker/BTCUSD)   

___

Dependencies:

qt4.8  
liburl   
c++11    
 
