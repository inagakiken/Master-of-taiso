/* ----------------------------------------------------------------------------
 * This file was automatically generated by SWIG (http://www.swig.org).
 * Version 2.0.0
 *
 * Do not make changes to this file unless you know what you are doing--modify
 * the SWIG interface file instead.
 * ----------------------------------------------------------------------------- */


using System;
using System.Runtime.InteropServices;

public class aiTextureVector : IDisposable, System.Collections.IEnumerable
#if !SWIG_DOTNET_1
    , System.Collections.Generic.IList<aiTexture>
#endif
 {
  private HandleRef swigCPtr;
  protected bool swigCMemOwn;

  internal aiTextureVector(IntPtr cPtr, bool cMemoryOwn) {
    swigCMemOwn = cMemoryOwn;
    swigCPtr = new HandleRef(this, cPtr);
  }

  internal static HandleRef getCPtr(aiTextureVector obj) {
    return (obj == null) ? new HandleRef(null, IntPtr.Zero) : obj.swigCPtr;
  }

  ~aiTextureVector() {
    Dispose();
  }

  public virtual void Dispose() {
    lock(this) {
      if (swigCPtr.Handle != IntPtr.Zero) {
        if (swigCMemOwn) {
          swigCMemOwn = false;
          AssimpPINVOKE.delete_aiTextureVector(swigCPtr);
        }
        swigCPtr = new HandleRef(null, IntPtr.Zero);
      }
      GC.SuppressFinalize(this);
    }
  }

  public aiTextureVector(System.Collections.ICollection c) : this() {
    if (c == null)
      throw new ArgumentNullException("c");
    foreach (aiTexture element in c) {
      this.Add(element);
    }
  }

  public bool IsFixedSize {
    get {
      return false;
    }
  }

  public bool IsReadOnly {
    get {
      return false;
    }
  }

  public aiTexture this[int index]  {
    get {
      return getitem(index);
    }
    set {
      setitem(index, value);
    }
  }

  public int Capacity {
    get {
      return (int)capacity();
    }
    set {
      if (value < size())
        throw new ArgumentOutOfRangeException("Capacity");
      reserve((uint)value);
    }
  }

  public int Count {
    get {
      return (int)size();
    }
  }

  public bool IsSynchronized {
    get {
      return false;
    }
  }

#if SWIG_DOTNET_1
  public void CopyTo(System.Array array)
#else
  public void CopyTo(aiTexture[] array)
#endif
  {
    CopyTo(0, array, 0, this.Count);
  }

#if SWIG_DOTNET_1
  public void CopyTo(System.Array array, int arrayIndex)
#else
  public void CopyTo(aiTexture[] array, int arrayIndex)
#endif
  {
    CopyTo(0, array, arrayIndex, this.Count);
  }

#if SWIG_DOTNET_1
  public void CopyTo(int index, System.Array array, int arrayIndex, int count)
#else
  public void CopyTo(int index, aiTexture[] array, int arrayIndex, int count)
#endif
  {
    if (array == null)
      throw new ArgumentNullException("array");
    if (index < 0)
      throw new ArgumentOutOfRangeException("index", "Value is less than zero");
    if (arrayIndex < 0)
      throw new ArgumentOutOfRangeException("arrayIndex", "Value is less than zero");
    if (count < 0)
      throw new ArgumentOutOfRangeException("count", "Value is less than zero");
    if (array.Rank > 1)
      throw new ArgumentException("Multi dimensional array.", "array");
    if (index+count > this.Count || arrayIndex+count > array.Length)
      throw new ArgumentException("Number of elements to copy is too large.");
    for (int i=0; i<count; i++)
      array.SetValue(getitemcopy(index+i), arrayIndex+i);
  }

#if !SWIG_DOTNET_1
  System.Collections.Generic.IEnumerator<aiTexture> System.Collections.Generic.IEnumerable<aiTexture>.GetEnumerator() {
    return new aiTextureVectorEnumerator(this);
  }
#endif

  System.Collections.IEnumerator System.Collections.IEnumerable.GetEnumerator() {
    return new aiTextureVectorEnumerator(this);
  }

  public aiTextureVectorEnumerator GetEnumerator() {
    return new aiTextureVectorEnumerator(this);
  }

  // Type-safe enumerator
  /// Note that the IEnumerator documentation requires an InvalidOperationException to be thrown
  /// whenever the collection is modified. This has been done for changes in the size of the
  /// collection but not when one of the elements of the collection is modified as it is a bit
  /// tricky to detect unmanaged code that modifies the collection under our feet.
  public sealed class aiTextureVectorEnumerator : System.Collections.IEnumerator
#if !SWIG_DOTNET_1
    , System.Collections.Generic.IEnumerator<aiTexture>
#endif
  {
    private aiTextureVector collectionRef;
    private int currentIndex;
    private object currentObject;
    private int currentSize;

    public aiTextureVectorEnumerator(aiTextureVector collection) {
      collectionRef = collection;
      currentIndex = -1;
      currentObject = null;
      currentSize = collectionRef.Count;
    }

    // Type-safe iterator Current
    public aiTexture Current {
      get {
        if (currentIndex == -1)
          throw new InvalidOperationException("Enumeration not started.");
        if (currentIndex > currentSize - 1)
          throw new InvalidOperationException("Enumeration finished.");
        if (currentObject == null)
          throw new InvalidOperationException("Collection modified.");
        return (aiTexture)currentObject;
      }
    }

    // Type-unsafe IEnumerator.Current
    object System.Collections.IEnumerator.Current {
      get {
        return Current;
      }
    }

    public bool MoveNext() {
      int size = collectionRef.Count;
      bool moveOkay = (currentIndex+1 < size) && (size == currentSize);
      if (moveOkay) {
        currentIndex++;
        currentObject = collectionRef[currentIndex];
      } else {
        currentObject = null;
      }
      return moveOkay;
    }

    public void Reset() {
      currentIndex = -1;
      currentObject = null;
      if (collectionRef.Count != currentSize) {
        throw new InvalidOperationException("Collection modified.");
      }
    }

#if !SWIG_DOTNET_1
    public void Dispose() {
        currentIndex = -1;
        currentObject = null;
    }
#endif
  }

  public void Clear() {
    AssimpPINVOKE.aiTextureVector_Clear(swigCPtr);
  }

  public void Add(aiTexture x) {
    AssimpPINVOKE.aiTextureVector_Add(swigCPtr, aiTexture.getCPtr(x));
  }

  private uint size() {
    uint ret = AssimpPINVOKE.aiTextureVector_size(swigCPtr);
    return ret;
  }

  private uint capacity() {
    uint ret = AssimpPINVOKE.aiTextureVector_capacity(swigCPtr);
    return ret;
  }

  private void reserve(uint n) {
    AssimpPINVOKE.aiTextureVector_reserve(swigCPtr, n);
  }

  public aiTextureVector() : this(AssimpPINVOKE.new_aiTextureVector__SWIG_0(), true) {
  }

  public aiTextureVector(aiTextureVector other) : this(AssimpPINVOKE.new_aiTextureVector__SWIG_1(aiTextureVector.getCPtr(other)), true) {
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public aiTextureVector(int capacity) : this(AssimpPINVOKE.new_aiTextureVector__SWIG_2(capacity), true) {
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  private aiTexture getitemcopy(int index) {
    IntPtr cPtr = AssimpPINVOKE.aiTextureVector_getitemcopy(swigCPtr, index);
    aiTexture ret = (cPtr == IntPtr.Zero) ? null : new aiTexture(cPtr, false);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  private aiTexture getitem(int index) {
    IntPtr cPtr = AssimpPINVOKE.aiTextureVector_getitem(swigCPtr, index);
    aiTexture ret = (cPtr == IntPtr.Zero) ? null : new aiTexture(cPtr, false);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  private void setitem(int index, aiTexture val) {
    AssimpPINVOKE.aiTextureVector_setitem(swigCPtr, index, aiTexture.getCPtr(val));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public void AddRange(aiTextureVector values) {
    AssimpPINVOKE.aiTextureVector_AddRange(swigCPtr, aiTextureVector.getCPtr(values));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public aiTextureVector GetRange(int index, int count) {
    IntPtr cPtr = AssimpPINVOKE.aiTextureVector_GetRange(swigCPtr, index, count);
    aiTextureVector ret = (cPtr == IntPtr.Zero) ? null : new aiTextureVector(cPtr, true);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Insert(int index, aiTexture x) {
    AssimpPINVOKE.aiTextureVector_Insert(swigCPtr, index, aiTexture.getCPtr(x));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public void InsertRange(int index, aiTextureVector values) {
    AssimpPINVOKE.aiTextureVector_InsertRange(swigCPtr, index, aiTextureVector.getCPtr(values));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public void RemoveAt(int index) {
    AssimpPINVOKE.aiTextureVector_RemoveAt(swigCPtr, index);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public void RemoveRange(int index, int count) {
    AssimpPINVOKE.aiTextureVector_RemoveRange(swigCPtr, index, count);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public static aiTextureVector Repeat(aiTexture value, int count) {
    IntPtr cPtr = AssimpPINVOKE.aiTextureVector_Repeat(aiTexture.getCPtr(value), count);
    aiTextureVector ret = (cPtr == IntPtr.Zero) ? null : new aiTextureVector(cPtr, true);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
    return ret;
  }

  public void Reverse() {
    AssimpPINVOKE.aiTextureVector_Reverse__SWIG_0(swigCPtr);
  }

  public void Reverse(int index, int count) {
    AssimpPINVOKE.aiTextureVector_Reverse__SWIG_1(swigCPtr, index, count);
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public void SetRange(int index, aiTextureVector values) {
    AssimpPINVOKE.aiTextureVector_SetRange(swigCPtr, index, aiTextureVector.getCPtr(values));
    if (AssimpPINVOKE.SWIGPendingException.Pending) throw AssimpPINVOKE.SWIGPendingException.Retrieve();
  }

  public bool Contains(aiTexture value) {
    bool ret = AssimpPINVOKE.aiTextureVector_Contains(swigCPtr, aiTexture.getCPtr(value));
    return ret;
  }

  public int IndexOf(aiTexture value) {
    int ret = AssimpPINVOKE.aiTextureVector_IndexOf(swigCPtr, aiTexture.getCPtr(value));
    return ret;
  }

  public int LastIndexOf(aiTexture value) {
    int ret = AssimpPINVOKE.aiTextureVector_LastIndexOf(swigCPtr, aiTexture.getCPtr(value));
    return ret;
  }

  public bool Remove(aiTexture value) {
    bool ret = AssimpPINVOKE.aiTextureVector_Remove(swigCPtr, aiTexture.getCPtr(value));
    return ret;
  }

}
