//
// Created by lijiayan on 2017/9/20.
//

#include "jni.h"
#include "Add_B.h"

extern "C" {
JNIEXPORT jint  JNICALL
Java_com_ljy_nlib_TcNativeLib_add(JNIEnv *env, jclass type, jint a_);
}

JNIEXPORT jint  JNICALL
Java_com_ljy_nlib_TcNativeLib_add(JNIEnv *env, jclass type, jint a_) {
    //40 + 75 + 46
    return add_b(a_);
}
