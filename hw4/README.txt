solitaire.cpp:
structure node裡的架構包含一個整數資料與一個指向下一個位子的指標，透過這樣的structure配置完成linked list。當此linked list的頭指向的資料不等於要抽出的牌時，即將linked list的最後一筆資料指向第一筆資料，linked list的頭則改成指向第二筆資料；如果是要抽出的牌，則再宣告一個指標指向頭所指向的資料，將頭改成指向第二筆資料後，把後來宣告的指標指向的空間釋放掉。

本來的solitaire使用array實現，但array一宣告就無法改變空間大小，因此程式執行時所用掉的記憶體一直不變，直至程式執行結束，第一張牌要移至尾巴時也要一併更改每格的數值；這份solitaire使用linked list實現，由於抽出牌時會釋放記憶體，故程式所需記憶體空間隨著時間會越來越小，在第一張牌要移至牌尾時也僅需要改變串接方式即可。
==================================================
costco.cpp:
structure node裡的架構包含一個字串資料與一個指向下一個位子的指標，透過這樣的structure配置完成linked list。在儲存團體資訊時，宣告一個指標陣列，每格都代表不同的團體，在完成團體輸入後，將團員資料存成一個linked list，並讓指標陣列的每個元素指向相對應團體linked list的頭。inQueue與outQueue也使用linked list實現。在判定有沒有同團體的成員時，即從inQueue的頭開始判斷有無與指標陣列指定linked list相同的元素，有則插入(改變串接方式)，無則排至對尾(將inQueue最後一筆資料指向新取得的記憶體)。DEQUEUE時僅需將outQueue的最後一筆資料指向inQueue的頭，並讓inQueue的頭指向第二筆資料，最後讓outQueue的新元素指向NULL即可。結果即把outQueue每個node的字串資料一個一個列印出來。

本來的costco使用vector實現，vector為加強版的陣列，可調整其大小，在使用上也比array方便，但在加入或移除元素時，需要計算要加入或移除的元素位置(vector.begin()+i)，會存取到vector第一筆資料的位子；使用linked list則是只需要存取前後資料的位置即可。