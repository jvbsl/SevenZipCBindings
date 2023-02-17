#include "7zip/IPassword.h"
#include "7zip/Archive/IArchive.h"
#include "Common/MyCom.h"
#include "binding.h"
#include <iostream>

#ifndef __FUNCTION_NAME__
#ifdef WIN32   //WINDOWS
#define __FUNCTION_NAME__   __FUNCTION__
#else          //*NIX
#define __FUNCTION_NAME__   __func__
#endif
#endif

#include "wrappers.h"
STDAPI CreateObject(const GUID *clsid, const GUID *iid, void **outObject);
extern "C" {

IArchiveOpenCallback_Wrapper *
CreateIArchiveOpenCallback(IArchiveOpenCallback_Wrapper_ThisCallback setTotal,
                           IArchiveOpenCallback_Wrapper_ThisCallback setCompleted,
                           IArchiveOpenCallback_Wrapper_ThisCallback_GetPassword getPassword,
                           IArchiveOpenCallback_ThisCallback_GetStream getStream,
                           IArchiveOpenCallback_ThisCallback_GetProperty getProperty) {

    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = new IArchiveOpenCallback_Wrapper(setTotal, setCompleted, getPassword, getStream, getProperty);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
void ReleaseIArchiveOpenCallback(IArchiveOpenCallback_Wrapper *archiveOpenCallback) {
    delete archiveOpenCallback;
}

ICryptoGetTextPassword_Wrapper *
CreateICryptoGetTextPassword(ICryptoGetTextPassword_Wrapper_ThisCallback getTextPassword) {
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = new ICryptoGetTextPassword_Wrapper(getTextPassword);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
void ReleaseICryptoGetTextPassword(ICryptoGetTextPassword_Wrapper *getTextPassword) {
    delete getTextPassword;
}

ICryptoGetTextPassword2_Wrapper *
CreateICryptoGetTextPassword2(ICryptoGetTextPassword2_Wrapper_ThisCallback getTextPassword2) {
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = new ICryptoGetTextPassword2_Wrapper(getTextPassword2);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
void ReleaseICryptoGetTextPassword2(ICryptoGetTextPassword2_Wrapper *getTextPassword2) {
    delete getTextPassword2;
}

IArchiveExtractCallback_Wrapper *
CreateIArchiveExtractCallback(IProgress_ThisCallback_SetTotal setTotal,
                              IProgress_ThisCallback_SetCompleted setCompleted,
                              IArchiveExtractCallback_ThisCallback_SetOperationResult setOperationResult,
                              IArchiveExtractCallback_ThisCallback_PrepareOperation prepareOperation,
                              IArchiveExtractCallback_ThisCallback_GetStream getStream,
                              IArchiveExtractCallback_Wrapper_ThisCallback_GetPassword getPassword) {
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = new IArchiveExtractCallback_Wrapper(setTotal,
                                               setCompleted,
                                               setOperationResult,
                                               prepareOperation,
                                               getStream,
                                               getPassword);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
void ReleaseIArchiveExtractCallback(IArchiveExtractCallback_Wrapper *archiveExtractCallback) {
    delete archiveExtractCallback;
}


IArchiveUpdateCallback_Wrapper *
CreateIArchiveUpdateCallback(IProgress_ThisCallback_SetTotal setTotal,
                             IProgress_ThisCallback_SetCompleted setCompleted,
                             IArchiveUpdateCallback_ThisCallback_SetOperationResult setOperationResult,
                             IArchiveUpdateCallback_ThisCallback_GetStream getStream,
                             IArchiveUpdateCallback_ThisCallback_GetUpdateItemInfo getUpdateItemInfo,
                             IArchiveUpdateCallback_ThisCallback_GetProperty getProperty,
                             IArchiveUpdateCallback_ThisCallback_CryptoGetTextPassword2 getPassword2) {
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = new IArchiveUpdateCallback_Wrapper(setTotal,
                                                  setCompleted,
                                                  setOperationResult,
                                                  getStream,
                                                  getUpdateItemInfo,
                                                  getProperty,
                                                  getPassword2);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
void ReleaseIArchiveUpdateCallback(IArchiveUpdateCallback_Wrapper *archiveExtractCallback) {
    delete archiveExtractCallback;
}


IArchiveOpenVolumeCallback_Wrapper *
CreateIArchiveOpenVolumeCallback(IArchiveOpenVolumeCallback_ThisCallback_GetStream getStream,
                                 IArchiveOpenVolumeCallback_ThisCallback_GetProperty getProperty) {
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = new IArchiveOpenVolumeCallback_Wrapper(getStream, getProperty);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
void ReleaseIArchiveOpenVolumeCallback(IArchiveOpenVolumeCallback_Wrapper *openVolumeCallback) {
    delete openVolumeCallback;
}


ISequentialInStream_Wrapper *
CreateISequentialInStream(ISequentialInStream_Wrapper_ThisCallback read) {
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = new ISequentialInStream_Wrapper(read);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
void ReleaseISequentialInStream(ISequentialInStream_Wrapper *stream) {
    delete stream;
}

ISequentialOutStream_Wrapper *
CreateISequentialOutStream(ISequentialOutStream_Wrapper_ThisCallback write) {
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = new ISequentialOutStream_Wrapper(write);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
void ReleaseISequentialOutStream(ISequentialOutStream_Wrapper *stream) {
    delete stream;
}

IInStream_Wrapper *
CreateIInStream(ISequentialInStream_Wrapper_ThisCallback read, IInStream_ThisCallback_Seek seek) {
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = new IInStream_Wrapper(read, seek);
    res->AddRef();
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
void ReleaseIInStream(ISequentialInStream_Wrapper *stream) {
    delete stream;
}

IOutStream_Wrapper *
CreateIOutStream(ISequentialOutStream_Wrapper_ThisCallback write, IOutStream_ThisCallback_Seek seek, IOutStream_ThisCallback_SetSize setSize) {
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = new IOutStream_Wrapper(write, seek, setSize);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
void ReleaseIOutStream(IOutStream_Wrapper *stream) {
    delete stream;
}


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
                 IInArchive_ThisCallback_GetPropertyInfo getPropertyInfo) {
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = new IInArchive_Wrapper(getNumberOfItems,
                                  open,
                                  getArchivePropertyInfo,
                                  getNumberOfProperties,
                                  close,
                                  extract,
                                  getNumberOfArchiveProperties,
                                  getArchiveProperty,
                                  getProperty,
                                  getPropertyInfo);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
void ReleaseIInArchive(IInArchive_Wrapper *archive) {
    delete archive;
}



IOutArchive_Wrapper *
CreateIOutArchive(IOutArchiveOutThisCallback_UpdateItems updateItems,
                  IOutArchiveOutThisCallback_GetFileTimeType getFileTimeType) {
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = new IOutArchive_Wrapper(updateItems, getFileTimeType);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
void ReleaseIOutArchive(IOutArchive_Wrapper *archive) {
    delete archive;
}

ISetProperties_Wrapper *CreateISetProperties(ISetProperties_Wrapper_ThisCallback setProperties) {
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = new ISetProperties_Wrapper(setProperties);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
void ReleaseISetProperties(IOutArchive_Wrapper *setProperties) {
    delete setProperties;
}



LONG IInArchive_GetNumberOfItems(IInArchive* that, UInt32 *numItems)
{
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = that->GetNumberOfItems(numItems);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
LONG IInArchive_Open(IInArchive* that, IInStream *stream, const UInt64 *maxCheckStartPosition, IArchiveOpenCallback *openCallback)
{
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = that->Open(stream, maxCheckStartPosition, openCallback);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
LONG IInArchive_GetArchivePropertyInfo(IInArchive* that, UInt32 index, BSTR *name, PROPID *propID, VARTYPE *varType)
{
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = that->GetArchivePropertyInfo(index, name, propID, varType);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
LONG IInArchive_GetNumberOfProperties(IInArchive* that, UInt32 *numProps)
{
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = that->GetNumberOfProperties(numProps);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
LONG IInArchive_Close(IInArchive* that)
{
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = that->Close();
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
LONG IInArchive_Extract(IInArchive* that, const UInt32 *indices, UInt32 numItems, Int32 testMode, IArchiveExtractCallback *extractCallback)
{
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = that->Extract(indices, numItems, testMode, extractCallback);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
LONG IInArchive_GetNumberOfArchiveProperties(IInArchive* that, UInt32 *numProps)
{
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = that->GetNumberOfArchiveProperties(numProps);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
LONG IInArchive_GetArchiveProperty(IInArchive* that, PROPID propID, PROPVARIANT *value)
{
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = that->GetArchiveProperty(propID, value);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
LONG IInArchive_GetProperty(IInArchive* that, UInt32 index, PROPID propID, PROPVARIANT *value)
{
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = that->GetProperty(index, propID, value);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}
LONG IInArchive_GetPropertyInfo(IInArchive* that, UInt32 index, BSTR *name, PROPID *propID, VARTYPE *varType)
{
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = that->GetPropertyInfo(index, name, propID, varType);
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}

LONG IOutArchive_UpdateItems(IOutArchive* that, ISequentialOutStream* stream, UInt32 numItems, IArchiveUpdateCallback* callback) {
    auto res = that->UpdateItems(stream, numItems, callback);
    return res;
}

LONG IOutArchive_GetFileTimeType(IOutArchive* that, UInt32* type) {
    auto res = that->GetFileTimeType(type);
    return res;
}

LONG ISetProperties_SetProperties(ISetProperties* that, const wchar_t * const *names, const PROPVARIANT *values, UInt32 numProps) {
    auto res = that->SetProperties(names, values, numProps);

    return res;
}

ISetProperties* Cast_IOutArchive(IOutArchive* outArchive)
{
    return dynamic_cast<ISetProperties*>(outArchive);
}

ISetProperties* Cast_IInArchive(IInArchive* inArchive)
{
    return dynamic_cast<ISetProperties*>(inArchive);
}
ISequentialOutStream* Cast_IOutStream(IOutStream* outStream)
{
    return dynamic_cast<ISequentialOutStream*>(outStream);
}
ISequentialInStream* Cast_IInStream(IInStream* inStream)
{
    return dynamic_cast<ISequentialInStream*>(inStream);
}

IInArchive* Cast_IOutArchive_IInArchive(IOutArchive* archive)
{
    return dynamic_cast<IInArchive*>(archive);
}
IOutArchive* Cast_IInArchive_IOutArchive(IInArchive* archive)
{
    return dynamic_cast<IOutArchive*>(archive);
}
LONG CreatePseudoCOMObject(const GUID *clsID, const GUID *iid, void **outObject)
{
    std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
    auto res = CreateObject(clsID, iid, outObject);
    if (*outObject) {
        //((IUnknown*)*outObject)->AddRef();
    }
    std::cout << "After " << __FUNCTION_NAME__ << " - " << res << std::endl;
    return res;
}

}