To run the game, please go to the Zork directory, which is under Assignemnt 3 folder

```
cd Assessment3/ZOOrk/
```

Then you want to compile them you can use

```
g++ -std=c++11 -o zork Character.cpp GameObject.cpp Item.cpp Location.cpp main.cpp NPC.cpp NullCommand.cpp NullPassage.cpp NullRoom.cpp Passage.cpp PassageDefaultEnterCommand.cpp Player.cpp Room.cpp RoomDefaultEnterCommand.cpp ZOOrkEngine.cpp
```

then you want to run 
```
./zork
``` 
for mac or 
```
./zork.exe
``` 
for windows.

---

If you are using **macOS**, make sure to change the file directory in ZOOrkEngine to 
```
"title.txt"
```
and 
```
"help.txt"
```
---
For **windows** change it to 
```
"../title.txt"
```
and 
```
"../help.txt"
```
