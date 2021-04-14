Notice: These two files may contains some errors. Check before using them.

max_heap.cpp:

此程式使用heap的方式來儲存哪排的空位最多，一開始即排序使其遵循maxheap規則，使得根的值為整棵樹所有元素的最大值，每賣出一次票時僅須對根減一，並檢查是否少於兩個子元素，如成立則交換兩者位置，並繼續往下判斷，直至再次滿足maxheap，如此一來即可找出所能賣出的最高票價。

//===============================
height_union.cpp:
此程式使用collapsing find的規則，使得搜尋過一次之後，往後速度可以加快。
collapsing find讓從節點p走訪至根時所經過的所有節點(包含p)都連到根，使得往後查詢這些曾經經過的節點的根只需走一次即能找到。此程式的輸出為在尋找節點p時，共走訪和重設路徑幾次，可以看到重複查詢一個相同節點時，第二次僅需走訪一次即能尋得其根，也不須重設任何路徑。


-weightedUnion v.s. heightUnion
現有兩棵樹，其根為i與j，
weightedUnion: 若樹i的節點數少於樹j，則設j為樹i的parent(make j the parent of i)
heightUnion: 若樹i的layer數少於樹j，則設j為樹i的parent(make j the parent of i)

由於在使用collapsingFind時，根到節點p中所有layer都會有一個節點路徑遭重置，因此當layer越少，需要走訪與重設路線的次數也較少。heightUnion即是以層數作為union判定標準，故效能上應是heightunion優於weightedunion。

//===============================