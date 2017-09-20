package com.ljy.nlib;

public class TcNativeLib {
    static {
        System.loadLibrary("demolib");
    }
    public static native int add(int a);

}
