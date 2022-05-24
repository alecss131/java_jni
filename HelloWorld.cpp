#include <iostream>
#include "HelloWorld.h"

JNIEXPORT void JNICALL Java_HelloWorld_print(JNIEnv *, jobject) {
    std::cout << "Hello, World!" << std::endl;
}