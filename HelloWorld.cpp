#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
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

/*
 * string allocate alternative
JNIEXPORT jstring JNICALL Java_HelloWorld_getLine(JNIEnv *env, jobject, jstring promt){
    const char* cstr{env->GetStringUTFChars(promt, nullptr)}; //allocate memory for cstring
    if (!cstr) {
        std::cerr << "cant allocate memory for c-string" << std::endl;
        return nullptr;
    }
    std::string str{cstr}; //create C++ string from cstring
    env->ReleaseStringUTFChars(promt, cstr); //free memory for cstring
    std::cout << str << std::endl; //print C++ string to cmd
    std::cin >> str; //read C++ string from cmd
    return env->NewStringUTF(str.c_str()); //create Java String from C++ string and return
}*/

JNIEXPORT jintArray JNICALL Java_HelloWorld_sort(JNIEnv *env, jobject obj, jintArray arr) {
    int len{env->GetArrayLength(arr)}; //get array length
    std::vector<jint> vec(len, 0); //allocate vector
    env->GetIntArrayRegion(arr, 0, len, vec.data()); //copy array to vector
    std::sort(vec.begin(), vec.end(), std::less()); //sort vector
    jintArray res{env->NewIntArray(len)}; //create new Java array
    env->SetIntArrayRegion(res, 0, len, vec.data()); //copy vector to Java array
    return res;
}
