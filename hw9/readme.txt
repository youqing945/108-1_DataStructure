aoe.cpp:
邊工作網路(AOE, Activity on Edge Network):
一個有向圖形中以邊代表Activity，以頂點代表Event，稱為AOE-Network。
條件是不能有迴路，且單一起點單一終點。
可以用來分析一個計劃中從開始到結束至少需要多少時間完成，還有哪些是Critical Activity，此份程式碼即在找出所有Event可最早開始與最晚必須開始的時間，以及哪些屬於Critical Activity。