#include <iostream>
#include <string>
#include "HelloWorld.h"

JNIEXPORT void JNICALL Java_HelloWorld_print(JNIEnv *, jobject) {
    std::cout << "Hello, World!" << std::endl;
}

JNIEXPORT jint JNICALL Java_HelloWorld_sum(JNIEnv *, jobject, jint a, jint b) {
    return a + b;
}

JNIEXPORT jstring JNICALL Java_HelloWorld_getLine(JNIEnv *env, jobject, jstring promt){
    std::string str(env->GetStringLength(promt), 0); //allocate C++ string
    env->GetStringUTFRegion(promt, 0, static_cast<int>(str.size()), str.data()); //copy Java String to C++ string
    std::cout << str << std::endl; //print C++ string to cmd
    std::cin >> str; //read C++ string from cmd
    return env->NewStringUTF(str.c_str()); //create Java String from C++ string and return
}