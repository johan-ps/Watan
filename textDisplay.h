 #ifndef TEXTDISPLAY_H
 #define TEXTDISPLAY_H

 #include <vector>

 class TextDisplay {
     std::vector<std::vector<char>> display;
     public:
     TextDisplay();
     void drawBoard();
 };

 #endif
