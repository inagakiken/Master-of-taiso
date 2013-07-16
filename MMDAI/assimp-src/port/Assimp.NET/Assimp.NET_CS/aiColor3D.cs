/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.0
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


using System;
using System.Runtime.InteropServices;

public class aiColor3D : IDisposable {
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal aiColor3D(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(aiColor3D obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~aiColor3D() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          AssimpPINVOKE.delete_aiColor3D(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }

  public aiColor3D() : this(AssimpPINVOKE.new_aiColor3D__SWIG_0(), true) {
  }

  public aiColor3D(float _r, float _g, float _b) : this(AssimpPINVOKE.new_aiColor3D__SWIG_1(_r, _g, _b), true) {
  }

  public aiColor3D(float _r) : this(AssimpPINVOKE.new_aiColor3D__SWIG_2(_r), true) {
  }

  public aiColor3D(aiColor3D o) : this(AssimpPINVOKE.new_aiColor3D__SWIG_3(aiColor3D.getCPtr(o)), true) {
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public bool __equal__(aiColor3D other) {
    bool ret = AssimpPINVOKE.aiColor3D___equal__(swigCPtr, aiColor3D.getCPtr(other));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public bool __nequal__(aiColor3D other) {
    bool ret = AssimpPINVOKE.aiColor3D___nequal__(swigCPtr, aiColor3D.getCPtr(other));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public aiColor3D __add__(aiColor3D c) {
    aiColor3D ret = new aiColor3D(AssimpPINVOKE.aiColor3D___add__(swigCPtr, aiColor3D.getCPtr(c)), true);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public aiColor3D __sub__(aiColor3D c) {
    aiColor3D ret = new aiColor3D(AssimpPINVOKE.aiColor3D___sub__(swigCPtr, aiColor3D.getCPtr(c)), true);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public aiColor3D __mul__(aiColor3D c) {
    aiColor3D ret = new aiColor3D(AssimpPINVOKE.aiColor3D___mul____SWIG_0(swigCPtr, aiColor3D.getCPtr(c)), true);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public aiColor3D __mul__(float f) {
    aiColor3D ret = new aiColor3D(AssimpPINVOKE.aiColor3D___mul____SWIG_1(swigCPtr, f), true);
    return ret;
  }

  public float __idx__(uint i) {
    float ret = AssimpPINVOKE.aiColor3D___idx____SWIG_0(swigCPtr, i);
    return ret;
  }

  public bool IsBlack() {
    bool ret = AssimpPINVOKE.aiColor3D_IsBlack(swigCPtr);
    return ret;
  }

  public float r {
    set {
      AssimpPINVOKE.aiColor3D_r_set(swigCPtr, value);
    } 
    get {
      float ret = AssimpPINVOKE.aiColor3D_r_get(swigCPtr);
      return ret;
    } 
  }

  public float g {
    set {
      AssimpPINVOKE.aiColor3D_g_set(swigCPtr, value);
    } 
    get {
      float ret = AssimpPINVOKE.aiColor3D_g_get(swigCPtr);
      return ret;
    } 
  }

  public float b {
    set {
      AssimpPINVOKE.aiColor3D_b_set(swigCPtr, value);
    } 
    get {
      float ret = AssimpPINVOKE.aiColor3D_b_get(swigCPtr);
      return ret;
    } 
  }

}
