#include "7zip/IPassword.h"
#include "7zip/Archive/IArchive.h"
#include "Common/MyCom.h"
#include "Common/ComTry.h"
#include "binding.h"
#include <iostream>

#include "wrappers.h"
#ifndef __FUNCTION_NAME__
#ifdef WIN32   //WINDOWS
#define __FUNCTION_NAME__   __FUNCTION__
#else          //*NIX
#define __FUNCTION_NAME__   __func__
#endif
#endif


LONG IProgress_Wrapper::SetTotal(UInt64 total) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = SetTotal_Implementation(this, total);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IProgress_Wrapper::SetCompleted(const UInt64 *completeValue) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = SetCompleted_Implementation(this, completeValue);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}


LONG IArchiveOpenCallback_Wrapper::SetTotal(const UInt64 *files, const UInt64 *bytes) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = SetTotal_Implementation(this, files, bytes);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IArchiveOpenCallback_Wrapper::SetCompleted(const UInt64 *files, const UInt64 *bytes) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = SetCompleted_Implementation(this, files, bytes);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IArchiveOpenCallback_Wrapper::CryptoGetTextPassword(BSTR *password) {
    COM_TRY_BEGIN
    auto res = GetPassword_Implementation(this, password);
    return res;
    COM_TRY_END
}
LONG IArchiveOpenCallback_Wrapper::GetProperty(PROPID propID, PROPVARIANT *value) {
    COM_TRY_BEGIN
    auto res = GetProperty_Implementation(this, propID, value);
    return res;
    COM_TRY_END
}
LONG IArchiveOpenCallback_Wrapper::GetStream(const wchar_t *name, IInStream **inStream) {
    COM_TRY_BEGIN
    auto bstr = ::SysAllocString(name);
    auto res = GetStream_Implementation(this, bstr, inStream);
    return res;
    COM_TRY_END
}


LONG ICryptoGetTextPassword_Wrapper::CryptoGetTextPassword(BSTR *password) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = GetPasswordText_Implementation(this, password);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}


LONG ICryptoGetTextPassword2_Wrapper::CryptoGetTextPassword2(Int32 *passwordIsDefined, BSTR *password) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = GetPasswordText2_Implementation(this, passwordIsDefined, password);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}


LONG IArchiveExtractCallback_Wrapper::SetOperationResult(Int32 opRes) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = SetOperationResult_Implementation(this, opRes);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IArchiveExtractCallback_Wrapper::PrepareOperation(Int32 askExtractMode) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = PrepareOperation_Implementation(this, askExtractMode);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IArchiveExtractCallback_Wrapper::GetStream(UInt32 index, ISequentialOutStream **outStream, Int32 askExtractMode) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = GetStream_Implementation(this, index, outStream, askExtractMode);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IArchiveExtractCallback_Wrapper::CryptoGetTextPassword(BSTR *password) {
    auto res = GetPassword_Implementation(this, password);
    return res;
}


LONG IArchiveUpdateCallback_Wrapper::SetOperationResult(Int32 opRes) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = SetOperationResult_Implementation(this, opRes);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IArchiveUpdateCallback_Wrapper::GetStream(UInt32 index, ISequentialInStream **inStream) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = GetStream_Implementation(this, index, inStream);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IArchiveUpdateCallback_Wrapper::GetUpdateItemInfo(UInt32 index, Int32 *newData, Int32 *newProps,
                                                       UInt32 *indexInArchive) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = GetUpdateItemInfo_Implementation(this, index, newData, newProps, indexInArchive);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IArchiveUpdateCallback_Wrapper::GetProperty(UInt32 index, PROPID propID, PROPVARIANT *value) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = GetProperty_Implementation(this, index, propID, value);
        if (propID == 3) {
            std::cout << "BSTR in C;";
            for (int i = 0;i<*((int*)value->bstrVal-1);i++)
                std::cout << std::hex << (int)*((uint8_t*)(value->bstrVal) + i) << " ";
            std::cout << std::endl;
        }
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}
LONG IArchiveUpdateCallback_Wrapper::CryptoGetTextPassword2(Int32 *passwordIsDefined, BSTR *password) {
    COM_TRY_BEGIN
        auto res = GetPassword2_Implementation(this, passwordIsDefined, password);
        return res;
    COM_TRY_END
}


LONG IArchiveOpenVolumeCallback_Wrapper::GetStream(const wchar_t *name, IInStream **inStream) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = GetStream_Implementation(this, name, inStream);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IArchiveOpenVolumeCallback_Wrapper::GetProperty(PROPID propID, PROPVARIANT *value) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = GetProperty_Implementation(this, propID, value);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}


LONG ISequentialInStream_Wrapper::Read(void *data, UInt32 size, UInt32 *processedSize) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = Read_Implementation(this, data, size, processedSize);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}


LONG ISequentialOutStream_Wrapper::Write(const void *data, UInt32 size, UInt32 *processedSize) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = Write_Implementation(this, data, size, processedSize);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}


LONG IInStream_Wrapper::Seek(Int64 offset, UInt32 seekOrigin, UInt64 *newPosition) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = Seek_Implementation(this, offset, seekOrigin, newPosition);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IOutStream_Wrapper::Seek(Int64 offset, UInt32 seekOrigin, UInt64 *newPosition) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = Seek_Implementation(this, offset, seekOrigin, newPosition);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IOutStream_Wrapper::SetSize(UInt64 newSize) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = SetSize_Implementation(this, newSize);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}


LONG IInArchive_Wrapper::GetNumberOfItems(UInt32 *numItems) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = GetNumberOfItems_Implementation(this, numItems);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG
IInArchive_Wrapper::Open(IInStream *stream, const UInt64 *maxCheckStartPosition, IArchiveOpenCallback *openCallback) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = Open_Implementation(this, stream, maxCheckStartPosition, openCallback);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IInArchive_Wrapper::GetArchivePropertyInfo(UInt32 index, BSTR *name, PROPID *propID, VARTYPE *varType) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = GetArchivePropertyInfo_Implementation(this, index, name, propID, varType);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IInArchive_Wrapper::GetNumberOfProperties(UInt32 *numProps) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = GetNumberOfProperties_Implementation(this, numProps);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IInArchive_Wrapper::Close() {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = Close_Implementation(this);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IInArchive_Wrapper::Extract(const UInt32 *indices, UInt32 numItems, Int32 testMode,
                                 IArchiveExtractCallback *extractCallback) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = Extract_Implementation(this, indices, numItems, testMode, extractCallback);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IInArchive_Wrapper::GetNumberOfArchiveProperties(UInt32 *numProps) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = GetNumberOfArchiveProperties_Implementation(this, numProps);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IInArchive_Wrapper::GetArchiveProperty(PROPID propID, PROPVARIANT *value) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = GetArchiveProperty_Implementation(this, propID, value);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IInArchive_Wrapper::GetProperty(UInt32 index, PROPID propID, PROPVARIANT *value) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = GetProperty_Implementation(this, index, propID, value);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IInArchive_Wrapper::GetPropertyInfo(UInt32 index, BSTR *name, PROPID *propID, VARTYPE *varType) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = GetPropertyInfo_Implementation(this, index, name, propID, varType);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IOutArchive_Wrapper::UpdateItems(ISequentialOutStream *outStream, UInt32 numItems,
                                      IArchiveUpdateCallback *updateCallback) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = UpdateItems_Implementation(this, outStream, numItems, updateCallback);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG IOutArchive_Wrapper::GetFileTimeType(UInt32 *type) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = GetFileTimeType_Implementation(this, type);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}

LONG ISetProperties_Wrapper::SetProperties(const wchar_t *const *names, const PROPVARIANT *values, UInt32 numProps) {
    COM_TRY_BEGIN
        std::cout << "Before " << __FUNCTION_NAME__ << std::endl;
        auto res = SetProperties_Implementation(this, names, values, numProps);
        std::cout << "After " << __FUNCTION_NAME__ << std::endl;
        return res;
    COM_TRY_END
}