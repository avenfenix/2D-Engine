#include "engine_window.h"


int main(int argc, char* argv[]){

    Engine engine = *(new Engine("Probando imagen", 256, 240));
    engine.Start();

    return 0;
}