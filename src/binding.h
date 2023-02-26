#pragma once

#include <cstdint>

#ifdef WIN32
#define DLL_EXPORT __declspec(dllexport)
#else
#define DLL_EXPORT
#endif

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

	typedef LONG(*IProgress_ThisCallback_SetCompleted)(const IProgress* that, const UInt64* completeValue);
	typedef LONG(*IProgress_ThisCallback_SetTotal)(const IProgress* that, UInt64 total);

	typedef LONG(*IArchiveOpenCallback_Wrapper_ThisCallback)(const IArchiveOpenCallback* that, const UInt64* files, const UInt64* bytes);
	typedef LONG(*IArchiveOpenCallback_Wrapper_ThisCallback_GetPassword)(const IArchiveOpenCallback* that, BSTR* password);
	typedef LONG(*IArchiveOpenCallback_ThisCallback_GetStream)(const IArchiveOpenCallback* that, BSTR name, IInStream** inStream);
	typedef LONG(*IArchiveOpenCallback_ThisCallback_GetProperty)(const IArchiveOpenCallback* that, PROPID propID, PROPVARIANT* value);

	typedef LONG(*ICryptoGetTextPassword_Wrapper_ThisCallback)(const ICryptoGetTextPassword* that, BSTR* password);
	typedef LONG(*ICryptoGetTextPassword2_Wrapper_ThisCallback)(const ICryptoGetTextPassword2* that, int32_t* passwordIsDefined, BSTR* password);

	typedef LONG(*IArchiveExtractCallback_ThisCallback_SetOperationResult)(const IArchiveExtractCallback* that, Int32 opRes);
	typedef LONG(*IArchiveExtractCallback_ThisCallback_PrepareOperation)(const IArchiveExtractCallback* that, Int32 askExtractMode);
	typedef LONG(*IArchiveExtractCallback_ThisCallback_GetStream)(const IArchiveExtractCallback* that, UInt32 index, ISequentialOutStream** outStream, Int32 askExtractMode);
	typedef LONG(*IArchiveExtractCallback_Wrapper_ThisCallback_GetPassword)(const IArchiveExtractCallback* that, BSTR* password);

	typedef LONG(*IArchiveUpdateCallback_ThisCallback_SetOperationResult)(const IArchiveUpdateCallback* that, Int32 opRes);
	typedef LONG(*IArchiveUpdateCallback_ThisCallback_GetStream)(const IArchiveUpdateCallback* that, UInt32 index, ISequentialInStream** outStream);
	typedef LONG(*IArchiveUpdateCallback_ThisCallback_GetUpdateItemInfo)(const IArchiveUpdateCallback* that, UInt32 index, Int32* newData, Int32* newProps, UInt32* indexInArchive);
	typedef LONG(*IArchiveUpdateCallback_ThisCallback_GetProperty)(const IArchiveUpdateCallback* that, UInt32 index, PROPID propID, PROPVARIANT* value);
	typedef LONG(*IArchiveUpdateCallback_ThisCallback_CryptoGetTextPassword2)(const IArchiveUpdateCallback* that, Int32* passwordIsDefined, BSTR* password);


	typedef LONG(*IArchiveOpenVolumeCallback_ThisCallback_GetStream)(const IArchiveOpenVolumeCallback* that, const wchar_t* name, IInStream** inStream);
	typedef LONG(*IArchiveOpenVolumeCallback_ThisCallback_GetProperty)(const IArchiveOpenVolumeCallback* that, PROPID propID, PROPVARIANT* value);

	typedef LONG(*ISequentialInStream_Wrapper_ThisCallback)(const ISequentialInStream* that, void* data, UInt32 size, UInt32* processedSize);

	typedef LONG(*ISequentialOutStream_Wrapper_ThisCallback)(const ISequentialOutStream* that, const void* data, UInt32 size, UInt32* processedSize);

	typedef LONG(*IInStream_ThisCallback_Seek)(const IInStream* that, Int64 offset, UInt32 seekOrigin, UInt64* newPosition);
	typedef LONG(*IOutStream_ThisCallback_Seek)(const IOutStream* that, Int64 offset, UInt32 seekOrigin, UInt64* newPosition);
	typedef LONG(*IOutStream_ThisCallback_SetSize)(const IOutStream* that, UInt64 newSize);

	typedef LONG(*IInArchive_ThisCallback_GetNumberOfItems)(IInArchive* that, UInt32* numItems);
	typedef LONG(*IInArchive_ThisCallback_Open)(IInArchive* that, IInStream* stream, const UInt64* maxCheckStartPosition, IArchiveOpenCallback* openCallback);
	typedef LONG(*IInArchive_ThisCallback_GetArchivePropertyInfo)(IInArchive* that, UInt32 index, BSTR* name, PROPID* propID, VARTYPE* varType);
	typedef LONG(*IInArchive_ThisCallback_GetNumberOfProperties)(IInArchive* that, UInt32* numProps);
	typedef LONG(*IInArchive_ThisCallback_Close)(IInArchive* that);
	typedef LONG(*IInArchive_ThisCallback_Extract)(IInArchive* that, const UInt32* indices, UInt32 numItems, Int32 testMode, IArchiveExtractCallback* extractCallback);
	typedef LONG(*IInArchive_ThisCallback_GetNumberOfArchiveProperties)(IInArchive* that, UInt32* numProps);
	typedef LONG(*IInArchive_ThisCallback_GetArchiveProperty)(IInArchive* that, PROPID propID, PROPVARIANT* value);
	typedef LONG(*IInArchive_ThisCallback_GetProperty)(IInArchive* that, UInt32 index, PROPID propID, PROPVARIANT* value);
	typedef LONG(*IInArchive_ThisCallback_GetPropertyInfo)(IInArchive* that, UInt32 index, BSTR* name, PROPID* propID, VARTYPE* varType);

	typedef LONG(*IOutArchiveOutThisCallback_UpdateItems)(IOutArchive* that, ISequentialOutStream* outStream, UInt32 numItems, IArchiveUpdateCallback* updateCallback);
	typedef LONG(*IOutArchiveOutThisCallback_GetFileTimeType)(IOutArchive* that, UInt32* type);
	typedef LONG(*ISetProperties_Wrapper_ThisCallback)(ISetProperties* that, const wchar_t* const* names, const PROPVARIANT* values, UInt32 numProps);

	DLL_EXPORT IArchiveOpenCallback_Wrapper* CreateIArchiveOpenCallback(IArchiveOpenCallback_Wrapper_ThisCallback setTotal, IArchiveOpenCallback_Wrapper_ThisCallback setCompleted,
		IArchiveOpenCallback_Wrapper_ThisCallback_GetPassword getPassword,
		IArchiveOpenCallback_ThisCallback_GetStream getStream,
		IArchiveOpenCallback_ThisCallback_GetProperty getProperty);
	DLL_EXPORT void ReleaseIArchiveOpenCallback(IArchiveOpenCallback_Wrapper* archiveOpenCallback);

	DLL_EXPORT ICryptoGetTextPassword_Wrapper* CreateICryptoGetTextPassword(ICryptoGetTextPassword_Wrapper_ThisCallback getTextPassword);
	DLL_EXPORT void ReleaseICryptoGetTextPassword(ICryptoGetTextPassword_Wrapper* getTextPassword);

	DLL_EXPORT ICryptoGetTextPassword2_Wrapper* CreateICryptoGetTextPassword2(ICryptoGetTextPassword2_Wrapper_ThisCallback getTextPassword2);
	DLL_EXPORT void ReleaseICryptoGetTextPassword2(ICryptoGetTextPassword2_Wrapper* getTextPassword2);

	DLL_EXPORT IArchiveExtractCallback_Wrapper*
		 CreateIArchiveExtractCallback(IProgress_ThisCallback_SetTotal setTotal,
			IProgress_ThisCallback_SetCompleted setCompleted,
			IArchiveExtractCallback_ThisCallback_SetOperationResult setOperationResult,
			IArchiveExtractCallback_ThisCallback_PrepareOperation prepareOperation,
			IArchiveExtractCallback_ThisCallback_GetStream getStream,
			IArchiveExtractCallback_Wrapper_ThisCallback_GetPassword getPassword);
	DLL_EXPORT void ReleaseIArchiveExtractCallback(IArchiveExtractCallback_Wrapper* archiveExtractCallback);

	DLL_EXPORT IArchiveUpdateCallback_Wrapper*
		CreateIArchiveUpdateCallback(IProgress_ThisCallback_SetTotal setTotal,
			IProgress_ThisCallback_SetCompleted setCompleted,
			IArchiveUpdateCallback_ThisCallback_SetOperationResult setOperationResult,
			IArchiveUpdateCallback_ThisCallback_GetStream getStream,
			IArchiveUpdateCallback_ThisCallback_GetUpdateItemInfo getUpdateItemInfo,
			IArchiveUpdateCallback_ThisCallback_GetProperty getProperty,
			IArchiveUpdateCallback_ThisCallback_CryptoGetTextPassword2 getPassword2);
	DLL_EXPORT void ReleaseIArchiveUpdateCallback(IArchiveUpdateCallback_Wrapper* archiveExtractCallback);

	DLL_EXPORT IArchiveOpenVolumeCallback_Wrapper*
		CreateIArchiveOpenVolumeCallback(IArchiveOpenVolumeCallback_ThisCallback_GetStream getStream,
			IArchiveOpenVolumeCallback_ThisCallback_GetProperty getProperty);
	DLL_EXPORT void ReleaseIArchiveOpenVolumeCallback(IArchiveOpenVolumeCallback_Wrapper* openVolumeCallback);

	DLL_EXPORT ISequentialInStream_Wrapper*
		CreateISequentialInStream(ISequentialInStream_Wrapper_ThisCallback read);
	DLL_EXPORT void ReleaseISequentialInStream(ISequentialInStream_Wrapper* stream);

	DLL_EXPORT ISequentialOutStream_Wrapper*
		CreateISequentialOutStream(ISequentialOutStream_Wrapper_ThisCallback write);
	DLL_EXPORT void ReleaseISequentialOutStream(ISequentialOutStream_Wrapper* stream);

	DLL_EXPORT IInStream_Wrapper*
		CreateIInStream(ISequentialInStream_Wrapper_ThisCallback read, IInStream_ThisCallback_Seek seek);
	DLL_EXPORT void ReleaseIInStream(ISequentialInStream_Wrapper* stream);

	DLL_EXPORT IOutStream_Wrapper*
		CreateIOutStream(ISequentialOutStream_Wrapper_ThisCallback write, IOutStream_ThisCallback_Seek seek, IOutStream_ThisCallback_SetSize setSize);
	DLL_EXPORT void ReleaseIOutStream(IOutStream_Wrapper* archive);

	DLL_EXPORT IInArchive_Wrapper*
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
	DLL_EXPORT void ReleaseIInArchive(IInArchive_Wrapper* archive);

	DLL_EXPORT IOutArchive_Wrapper*
		CreateIOutArchive(IOutArchiveOutThisCallback_UpdateItems updateItems,
			IOutArchiveOutThisCallback_GetFileTimeType getFileTimeType);
	DLL_EXPORT void ReleaseIOutArchive(IOutArchive_Wrapper* archive);


	DLL_EXPORT ISetProperties_Wrapper* CreateISetProperties(ISetProperties_Wrapper_ThisCallback setProperties);
	DLL_EXPORT void ReleaseISetProperties(IOutArchive_Wrapper* setProperties);


	DLL_EXPORT LONG IInArchive_GetNumberOfItems(IInArchive* that, UInt32* numItems);
	DLL_EXPORT LONG IInArchive_Open(IInArchive* that, IInStream* stream, const UInt64* maxCheckStartPosition, IArchiveOpenCallback* openCallback);
	DLL_EXPORT LONG IInArchive_GetArchivePropertyInfo(IInArchive* that, UInt32 index, BSTR* name, PROPID* propID, VARTYPE* varType);
	DLL_EXPORT LONG IInArchive_GetNumberOfProperties(IInArchive* that, UInt32* numProps);
	DLL_EXPORT LONG IInArchive_Close(IInArchive* that);
	DLL_EXPORT LONG IInArchive_Extract(IInArchive* that, const UInt32* indices, UInt32 numItems, Int32 testMode, IArchiveExtractCallback* extractCallback);
	DLL_EXPORT LONG IInArchive_GetNumberOfArchiveProperties(IInArchive* that, UInt32* numProps);
	DLL_EXPORT LONG IInArchive_GetArchiveProperty(IInArchive* that, PROPID propID, PROPVARIANT* value);
	DLL_EXPORT LONG IInArchive_GetProperty(IInArchive* that, UInt32 index, PROPID propID, PROPVARIANT* value);
	DLL_EXPORT LONG IInArchive_GetPropertyInfo(IInArchive* that, UInt32 index, BSTR* name, PROPID* propID, VARTYPE* varType);

	DLL_EXPORT LONG IOutArchive_UpdateItems(IOutArchive* that, ISequentialOutStream* stream, UInt32 numItems, IArchiveUpdateCallback* callback);
	DLL_EXPORT LONG IOutArchive_GetFileTimeType(IOutArchive* that, UInt32* type);

	DLL_EXPORT LONG ISetProperties_SetProperties(ISetProperties* that, const wchar_t* const* names, const PROPVARIANT* values, UInt32 numProps);

	DLL_EXPORT ISetProperties* Cast_IOutArchive(IOutArchive* outArchive);
	DLL_EXPORT ISetProperties* Cast_IInArchive(IInArchive* inArchive);
	DLL_EXPORT ISequentialOutStream* Cast_IOutStream(IOutStream* outStream);
	DLL_EXPORT ISequentialInStream* Cast_IInStream(IInStream* inStream);
	DLL_EXPORT IInArchive* Cast_IOutArchive_IInArchive(IOutArchive* archive);
	DLL_EXPORT IOutArchive* Cast_IInArchive_IOutArchive(IInArchive* archive);

	DLL_EXPORT LONG CreatePseudoCOMObject(const GUID* clsID, const GUID* iid, void** outObject);
#ifdef __cplusplus
}
#endif