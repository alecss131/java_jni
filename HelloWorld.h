/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class HelloWorld */

#ifndef _Included_HelloWorld
#define _Included_HelloWorld
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     HelloWorld
 * Method:    print
 * Signature: ()V
 */
JNIEXPORT void JNICALL Java_HelloWorld_print
  (JNIEnv *, jobject);

/*
 * Class:     HelloWorld
 * Method:    sum
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_HelloWorld_sum
  (JNIEnv *, jobject, jint, jint);

/*
 * Class:     HelloWorld
 * Method:    getLine
 * Signature: (Ljava/lang/String;)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_HelloWorld_getLine
  (JNIEnv *, jobject, jstring);

/*
 * Class:     HelloWorld
 * Method:    sort
 * Signature: ([I)[I
 */
JNIEXPORT jintArray JNICALL Java_HelloWorld_sort
  (JNIEnv *, jobject, jintArray);

#ifdef __cplusplus
}
#endif
#endif
