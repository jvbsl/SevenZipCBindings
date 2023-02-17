#pragma once

#include <cstdint>

class IProgress_Wrapper;
class IArchiveOpenCallback_Wrapper;
class ICryptoGetTextPassword_Wrapper;
class ICryptoGetTextPassword2_Wrapper;
class IArchiveExtractCallback_Wrapper;
class IArchiveUpdateCallback_Wrapper;
class IArchiveOpenVolumeCallback_Wrapper;
class ISequentialInStream_Wrapper;
class ISequentialOutStream_Wrapper;
class IInStream_Wrapper;
class IOutStream_Wrapper;
class IInArchive_Wrapper;
class IOutArchive_Wrapper;
class ISetProperties_Wrapper;

#ifdef __cplusplus
extern "C" {
#endif

    typedef LONG (*IProgress_ThisCallback_SetCompleted)(const IProgress* that, const UInt64 *completeValue);
    typedef LONG (*IProgress_ThisCallback_SetTotal)(const IProgress* that, UInt64 total);

    typedef LONG (*IArchiveOpenCallback_Wrapper_ThisCallback)(const IArchiveOpenCallback* that, const UInt64* files, const UInt64* bytes);
    typedef LONG (*IArchiveOpenCallback_Wrapper_ThisCallback_GetPassword)(const IArchiveOpenCallback* that, BSTR *password);
    typedef LONG (*IArchiveOpenCallback_ThisCallback_GetStream)(const IArchiveOpenCallback* that, BSTR name, IInStream **inStream);
    typedef LONG (*IArchiveOpenCallback_ThisCallback_GetProperty)(const IArchiveOpenCallback* that, PROPID propID, PROPVARIANT *value);

    typedef LONG (*ICryptoGetTextPassword_Wrapper_ThisCallback)(const ICryptoGetTextPassword* that, BSTR *password);
    typedef LONG (*ICryptoGetTextPassword2_Wrapper_ThisCallback)(const ICryptoGetTextPassword2* that, int32_t *passwordIsDefined, BSTR *password);

    typedef LONG (*IArchiveExtractCallback_ThisCallback_SetOperationResult)(const IArchiveExtractCallback* that, Int32 opRes);
    typedef LONG (*IArchiveExtractCallback_ThisCallback_PrepareOperation)(const IArchiveExtractCallback* that, Int32 askExtractMode);
    typedef LONG (*IArchiveExtractCallback_ThisCallback_GetStream)(const IArchiveExtractCallback* that, UInt32 index, ISequentialOutStream **outStream, Int32 askExtractMode);
    typedef LONG (*IArchiveExtractCallback_Wrapper_ThisCallback_GetPassword)(const IArchiveExtractCallback* that, BSTR *password);

    typedef LONG (*IArchiveUpdateCallback_ThisCallback_SetOperationResult)(const IArchiveUpdateCallback* that, Int32 opRes);
    typedef LONG (*IArchiveUpdateCallback_ThisCallback_GetStream)(const IArchiveUpdateCallback* that, UInt32 index, ISequentialInStream **outStream);
    typedef LONG (*IArchiveUpdateCallback_ThisCallback_GetUpdateItemInfo)(const IArchiveUpdateCallback* that, UInt32 index, Int32 *newData, Int32 *newProps, UInt32 *indexInArchive);
    typedef LONG (*IArchiveUpdateCallback_ThisCallback_GetProperty)(const IArchiveUpdateCallback* that, UInt32 index, PROPID propID, PROPVARIANT *value);
    typedef LONG (*IArchiveUpdateCallback_ThisCallback_CryptoGetTextPassword2)(const IArchiveUpdateCallback* that, Int32 *passwordIsDefined, BSTR *password);


    typedef LONG (*IArchiveOpenVolumeCallback_ThisCallback_GetStream)(const IArchiveOpenVolumeCallback* that, const wchar_t *name, IInStream **inStream);
    typedef LONG (*IArchiveOpenVolumeCallback_ThisCallback_GetProperty)(const IArchiveOpenVolumeCallback* that, PROPID propID, PROPVARIANT *value);

    typedef LONG (*ISequentialInStream_Wrapper_ThisCallback)(const ISequentialInStream* that, void *data, UInt32 size, UInt32 *processedSize);

    typedef LONG (*ISequentialOutStream_Wrapper_ThisCallback)(const ISequentialOutStream* that, const void *data, UInt32 size, UInt32 *processedSize);

    typedef LONG (*IInStream_ThisCallback_Seek)(const IInStream* that, Int64 offset, UInt32 seekOrigin, UInt64 *newPosition);
    typedef LONG (*IOutStream_ThisCallback_Seek)(const IOutStream* that, Int64 offset, UInt32 seekOrigin, UInt64 *newPosition);
    typedef LONG (*IOutStream_ThisCallback_SetSize)(const IOutStream* that, UInt64 newSize);

    typedef LONG (*IInArchive_ThisCallback_GetNumberOfItems)(IInArchive* that, UInt32 *numItems);
    typedef LONG (*IInArchive_ThisCallback_Open)(IInArchive* that, IInStream *stream, const UInt64 *maxCheckStartPosition, IArchiveOpenCallback *openCallback);
    typedef LONG (*IInArchive_ThisCallback_GetArchivePropertyInfo)(IInArchive* that, UInt32 index, BSTR *name, PROPID *propID, VARTYPE *varType);
    typedef LONG (*IInArchive_ThisCallback_GetNumberOfProperties)(IInArchive* that, UInt32 *numProps);
    typedef LONG (*IInArchive_ThisCallback_Close)(IInArchive* that);
    typedef LONG (*IInArchive_ThisCallback_Extract)(IInArchive* that, const UInt32 *indices, UInt32 numItems, Int32 testMode, IArchiveExtractCallback *extractCallback);
    typedef LONG (*IInArchive_ThisCallback_GetNumberOfArchiveProperties)(IInArchive* that, UInt32 *numProps);
    typedef LONG (*IInArchive_ThisCallback_GetArchiveProperty)(IInArchive* that, PROPID propID, PROPVARIANT *value);
    typedef LONG (*IInArchive_ThisCallback_GetProperty)(IInArchive* that, UInt32 index, PROPID propID, PROPVARIANT *value);
    typedef LONG (*IInArchive_ThisCallback_GetPropertyInfo)(IInArchive* that, UInt32 index, BSTR *name, PROPID *propID, VARTYPE *varType);

    typedef LONG (*IOutArchiveOutThisCallback_UpdateItems)(IOutArchive* that, ISequentialOutStream *outStream, UInt32 numItems, IArchiveUpdateCallback *updateCallback);
    typedef LONG (*IOutArchiveOutThisCallback_GetFileTimeType)(IOutArchive* that, UInt32 *type);
    typedef LONG (*ISetProperties_Wrapper_ThisCallback)(ISetProperties* that, const wchar_t *const *names, const PROPVARIANT *values, UInt32 numProps);

    IArchiveOpenCallback_Wrapper* CreateIArchiveOpenCallback(IArchiveOpenCallback_Wrapper_ThisCallback setTotal, IArchiveOpenCallback_Wrapper_ThisCallback setCompleted,
                                                             IArchiveOpenCallback_Wrapper_ThisCallback_GetPassword getPassword,
                                                             IArchiveOpenCallback_ThisCallback_GetStream getStream,
                                                             IArchiveOpenCallback_ThisCallback_GetProperty getProperty);
    void ReleaseIArchiveOpenCallback(IArchiveOpenCallback_Wrapper* archiveOpenCallback);

    ICryptoGetTextPassword_Wrapper* CreateICryptoGetTextPassword(ICryptoGetTextPassword_Wrapper_ThisCallback getTextPassword);
    void ReleaseICryptoGetTextPassword(ICryptoGetTextPassword_Wrapper* getTextPassword);

    ICryptoGetTextPassword2_Wrapper* CreateICryptoGetTextPassword2(ICryptoGetTextPassword2_Wrapper_ThisCallback getTextPassword2);
    void ReleaseICryptoGetTextPassword2(ICryptoGetTextPassword2_Wrapper* getTextPassword2);

    IArchiveExtractCallback_Wrapper *
    CreateIArchiveExtractCallback(IProgress_ThisCallback_SetTotal setTotal,
                                  IProgress_ThisCallback_SetCompleted setCompleted,
                                  IArchiveExtractCallback_ThisCallback_SetOperationResult setOperationResult,
                                  IArchiveExtractCallback_ThisCallback_PrepareOperation prepareOperation,
                                  IArchiveExtractCallback_ThisCallback_GetStream getStream,
                                  IArchiveExtractCallback_Wrapper_ThisCallback_GetPassword getPassword);
    void ReleaseIArchiveExtractCallback(IArchiveExtractCallback_Wrapper *archiveExtractCallback);

    IArchiveUpdateCallback_Wrapper *
    CreateIArchiveUpdateCallback(IProgress_ThisCallback_SetTotal setTotal,
                                 IProgress_ThisCallback_SetCompleted setCompleted,
                                 IArchiveUpdateCallback_ThisCallback_SetOperationResult setOperationResult,
                                 IArchiveUpdateCallback_ThisCallback_GetStream getStream,
                                 IArchiveUpdateCallback_ThisCallback_GetUpdateItemInfo getUpdateItemInfo,
                                 IArchiveUpdateCallback_ThisCallback_GetProperty getProperty,
                                 IArchiveUpdateCallback_ThisCallback_CryptoGetTextPassword2 getPassword2);
    void ReleaseIArchiveUpdateCallback(IArchiveUpdateCallback_Wrapper *archiveExtractCallback);

    IArchiveOpenVolumeCallback_Wrapper *
    CreateIArchiveOpenVolumeCallback(IArchiveOpenVolumeCallback_ThisCallback_GetStream getStream,
                                     IArchiveOpenVolumeCallback_ThisCallback_GetProperty getProperty);
    void ReleaseIArchiveOpenVolumeCallback(IArchiveOpenVolumeCallback_Wrapper *openVolumeCallback);

    ISequentialInStream_Wrapper *
    CreateISequentialInStream(ISequentialInStream_Wrapper_ThisCallback read);
    void ReleaseISequentialInStream(ISequentialInStream_Wrapper *stream);

    ISequentialOutStream_Wrapper *
    CreateISequentialOutStream(ISequentialOutStream_Wrapper_ThisCallback write);
    void ReleaseISequentialOutStream(ISequentialOutStream_Wrapper *stream);

    IInStream_Wrapper *
    CreateIInStream(ISequentialInStream_Wrapper_ThisCallback read, IInStream_ThisCallback_Seek seek);
    void ReleaseIInStream(ISequentialInStream_Wrapper *stream);

    IOutStream_Wrapper *
    CreateIOutStream(ISequentialOutStream_Wrapper_ThisCallback write, IOutStream_ThisCallback_Seek seek, IOutStream_ThisCallback_SetSize setSize);
    void ReleaseIOutStream(IOutStream_Wrapper *archive);

    IInArchive_Wrapper *
    CreateIInArchive(IInArchive_ThisCallback_GetNumberOfItems getNumberOfItems,
                     IInArchive_ThisCallback_Open open,
                     IInArchive_ThisCallback_GetArchivePropertyInfo getArchivePropertyInfo,
                     IInArchive_ThisCallback_GetNumberOfProperties getNumberOfProperties,
                     IInArchive_ThisCallback_Close close,
                     IInArchive_ThisCallback_Extract extract,
                     IInArchive_ThisCallback_GetNumberOfArchiveProperties getNumberOfArchiveProperties,
                     IInArchive_ThisCallback_GetArchiveProperty getArchiveProperty,
                     IInArchive_ThisCallback_GetProperty getProperty,
                     IInArchive_ThisCallback_GetPropertyInfo getPropertyInfo);
    void ReleaseIInArchive(IInArchive_Wrapper *archive);

    IOutArchive_Wrapper *
    CreateIOutArchive(IOutArchiveOutThisCallback_UpdateItems updateItems,
                      IOutArchiveOutThisCallback_GetFileTimeType getFileTimeType);
    void ReleaseIOutArchive(IOutArchive_Wrapper *archive);


    ISetProperties_Wrapper *CreateISetProperties(ISetProperties_Wrapper_ThisCallback setProperties);
    void ReleaseISetProperties(IOutArchive_Wrapper *setProperties);


    LONG IInArchive_GetNumberOfItems(IInArchive* that, UInt32 *numItems);
    LONG IInArchive_Open(IInArchive* that, IInStream *stream, const UInt64 *maxCheckStartPosition, IArchiveOpenCallback *openCallback);
    LONG IInArchive_GetArchivePropertyInfo(IInArchive* that, UInt32 index, BSTR *name, PROPID *propID, VARTYPE *varType);
    LONG IInArchive_GetNumberOfProperties(IInArchive* that, UInt32 *numProps);
    LONG IInArchive_Close(IInArchive* that);
    LONG IInArchive_Extract(IInArchive* that, const UInt32 *indices, UInt32 numItems, Int32 testMode, IArchiveExtractCallback *extractCallback);
    LONG IInArchive_GetNumberOfArchiveProperties(IInArchive* that, UInt32 *numProps);
    LONG IInArchive_GetArchiveProperty(IInArchive* that, PROPID propID, PROPVARIANT *value);
    LONG IInArchive_GetProperty(IInArchive* that, UInt32 index, PROPID propID, PROPVARIANT *value);
    LONG IInArchive_GetPropertyInfo(IInArchive* that, UInt32 index, BSTR *name, PROPID *propID, VARTYPE *varType);

    LONG IOutArchive_UpdateItems(IOutArchive* that, ISequentialOutStream* stream, UInt32 numItems, IArchiveUpdateCallback* callback);
    LONG IOutArchive_GetFileTimeType(IOutArchive* that, UInt32* type);

    LONG ISetProperties_SetProperties(ISetProperties* that, const wchar_t * const *names, const PROPVARIANT *values, UInt32 numProps);

    ISetProperties* Cast_IOutArchive(IOutArchive* outArchive);
    ISetProperties* Cast_IInArchive(IInArchive* inArchive);
    ISequentialOutStream* Cast_IOutStream(IOutStream* outStream);
    ISequentialInStream* Cast_IInStream(IInStream* inStream);
    IInArchive* Cast_IOutArchive_IInArchive(IOutArchive* archive);
    IOutArchive* Cast_IInArchive_IOutArchive(IInArchive* archive);

    LONG CreatePseudoCOMObject(const GUID *clsID, const GUID *iid, void **outObject);
#ifdef __cplusplus
}
#endif