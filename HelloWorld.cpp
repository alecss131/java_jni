#include <iostream>
#include "HelloWorld.h"

JNIEXPORT void JNICALL Java_HelloWorld_print(JNIEnv *, jobject) {
    std::cout << "Hello, World!" << std::endl;
}

JNIEXPORT jint JNICALL Java_HelloWorld_sum(JNIEnv *, jobject, jint a, jint b) {
    return a + b;
}