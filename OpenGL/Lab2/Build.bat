@echo Building application...
g++ -c -I./include src/*.cpp
@echo Compilation complete, proceeding to linking...
g++ -o app.exe *.o -L. -lopengl32 -lgdi32 -lglu32 -lsfml-graphics -lsfml-audio -lsfml-window -lsfml-system
@echo Linking complete, running application...
.\app
