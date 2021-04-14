queue.cpp:
此份作業為queue實作，如遇到認識的人，則插入。
實作方法為：先開啟一個二維vector(groupMembers)，記錄同為friend的一群人，結束之後新建兩個一維vector(inQueue、outQueue)並開始讀取指令。
當讀入ENQUEUE時，會再多讀入一個人(person)，先判斷其有無在groupMembers中，沒有則直接push_back進inQueue，有的話則從頭尋找inQueue中有無其成員，有則在其之前insert，無則push_back。
讀入DEQUEUE時，會先判斷inQueue是否為空，如不為空則將inQueue[0] push_back至outQueue，並將inQueue[0]消除，最後將outQueue從頭開始列印出來，即為離開Queue的人物順序。