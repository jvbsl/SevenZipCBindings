#pragma once

#define MY_ADDREF_RELEASE_LEAKING()     STDMETHOD_(ULONG, AddRef)() throw() { return ++__m_RefCount; } \
STDMETHOD_(ULONG, Release)() { \
if (--__m_RefCount != 0) return __m_RefCount; \
return 0; \
}

#define IMPLEMENT_IPROGRESS() \
public:\
    LONG SetTotal(UInt64 total) final {\
        return IProgress_Wrapper_Implementation.SetTotal(total);\
    }\
    \
    LONG SetCompleted(const UInt64 *completeValue) final {\
        return IProgress_Wrapper_Implementation.SetCompleted(completeValue);\
    }                         \
private:\
    IProgress_Wrapper IProgress_Wrapper_Implementation;\
public:

#define IMPLEMENT_STREAM_READ() \
public:\
    LONG Read(void *data, UInt32 size, UInt32 *processedSize) override{ \
        return IStreamIn_Wrapper_Implementation.Read(data, size, processedSize); \
    } \
private:\
    ISequentialInStream_Wrapper IStreamIn_Wrapper_Implementation;\
public:


#define IMPLEMENT_STREAM_WRITE() \
public:\
    LONG Write(const void *data, UInt32 size, UInt32 *processedSize) override{ \
        return IStreamOut_Wrapper_Implementation.Write(data, size, processedSize); \
    } \
private:\
    ISequentialOutStream_Wrapper IStreamOut_Wrapper_Implementation;\
public:


class IProgress_Wrapper : public IProgress, public CMyUnknownImp {
public:
	MY_QUERYINTERFACE_BEGIN2(IProgress)MY_QUERYINTERFACE_END

		MY_ADDREF_RELEASE_LEAKING()

		IProgress_Wrapper(IProgress_ThisCallback_SetTotal setTotal,
			IProgress_ThisCallback_SetCompleted setCompleted)
		: SetTotal_Implementation(setTotal),
		SetCompleted_Implementation(setCompleted) {

	}

	LONG SetTotal(UInt64 total) final;

	LONG SetCompleted(const UInt64* completeValue) final;

private:
	IProgress_ThisCallback_SetTotal SetTotal_Implementation;
	IProgress_ThisCallback_SetCompleted SetCompleted_Implementation;
};

class IArchiveOpenCallback_Wrapper final : public IArchiveOpenCallback, public ICryptoGetTextPassword, public IArchiveOpenVolumeCallback, public CMyUnknownImp {
public:
	MY_QUERYINTERFACE_BEGIN2(IArchiveOpenCallback)
		MY_QUERYINTERFACE_ENTRY(ICryptoGetTextPassword)
		MY_QUERYINTERFACE_ENTRY(IArchiveOpenVolumeCallback)
		MY_QUERYINTERFACE_END

		MY_ADDREF_RELEASE_LEAKING()

		IArchiveOpenCallback_Wrapper(IArchiveOpenCallback_Wrapper_ThisCallback setTotal,
			IArchiveOpenCallback_Wrapper_ThisCallback setCompleted,
			IArchiveOpenCallback_Wrapper_ThisCallback_GetPassword getPassword,
			IArchiveOpenCallback_ThisCallback_GetStream getStream,
			IArchiveOpenCallback_ThisCallback_GetProperty getProperty)
		: SetTotal_Implementation(setTotal), SetCompleted_Implementation(setCompleted), GetPassword_Implementation(getPassword),
		GetStream_Implementation(getStream),
		GetProperty_Implementation(getProperty) {

	}

	virtual ~IArchiveOpenCallback_Wrapper() = default;

	LONG SetTotal(const UInt64* files, const UInt64* bytes) override;

	LONG SetCompleted(const UInt64* files, const UInt64* bytes) override;

	LONG CryptoGetTextPassword(BSTR* password) override;

	LONG GetProperty(PROPID propID, PROPVARIANT* value) override;
	LONG GetStream(const wchar_t* name, IInStream** inStream) override;

private:
	IArchiveOpenCallback_Wrapper_ThisCallback SetTotal_Implementation;
	IArchiveOpenCallback_Wrapper_ThisCallback SetCompleted_Implementation;
	IArchiveOpenCallback_Wrapper_ThisCallback_GetPassword GetPassword_Implementation;
	IArchiveOpenCallback_ThisCallback_GetStream GetStream_Implementation;
	IArchiveOpenCallback_ThisCallback_GetProperty GetProperty_Implementation;
};

class ICryptoGetTextPassword_Wrapper final : public ICryptoGetTextPassword, public CMyUnknownImp {
public:
	MY_QUERYINTERFACE_BEGIN2(ICryptoGetTextPassword)MY_QUERYINTERFACE_END

		MY_ADDREF_RELEASE_LEAKING()

		explicit ICryptoGetTextPassword_Wrapper(ICryptoGetTextPassword_Wrapper_ThisCallback getPasswordText)
		: GetPasswordText_Implementation(getPasswordText) {

	}

	virtual ~ICryptoGetTextPassword_Wrapper() = default;

	LONG CryptoGetTextPassword(BSTR* password) override;

private:
	ICryptoGetTextPassword_Wrapper_ThisCallback GetPasswordText_Implementation;
};

class ICryptoGetTextPassword2_Wrapper final : public ICryptoGetTextPassword2, public CMyUnknownImp {
public:
	MY_QUERYINTERFACE_BEGIN2(ICryptoGetTextPassword2)MY_QUERYINTERFACE_END

		MY_ADDREF_RELEASE_LEAKING()

		explicit ICryptoGetTextPassword2_Wrapper(ICryptoGetTextPassword2_Wrapper_ThisCallback getPasswordText)
		: GetPasswordText2_Implementation(getPasswordText) {

	}

	virtual ~ICryptoGetTextPassword2_Wrapper() = default;

	LONG CryptoGetTextPassword2(Int32* passwordIsDefined, BSTR* password) override;

private:
	ICryptoGetTextPassword2_Wrapper_ThisCallback GetPasswordText2_Implementation;
};

class IArchiveExtractCallback_Wrapper final : public IArchiveExtractCallback, public ICryptoGetTextPassword, public CMyUnknownImp {
public:
	MY_QUERYINTERFACE_BEGIN2(IArchiveExtractCallback)
		MY_QUERYINTERFACE_ENTRY(ICryptoGetTextPassword)
		MY_QUERYINTERFACE_END

		MY_ADDREF_RELEASE_LEAKING()

		IArchiveExtractCallback_Wrapper(IProgress_ThisCallback_SetTotal setTotal,
			IProgress_ThisCallback_SetCompleted setCompleted,
			IArchiveExtractCallback_ThisCallback_SetOperationResult setOperationResult,
			IArchiveExtractCallback_ThisCallback_PrepareOperation prepareOperation,
			IArchiveExtractCallback_ThisCallback_GetStream getStream,
			IArchiveExtractCallback_Wrapper_ThisCallback_GetPassword getPassword)
		: IProgress_Wrapper_Implementation(setTotal, setCompleted),
		SetOperationResult_Implementation(setOperationResult),
		PrepareOperation_Implementation(prepareOperation),
		GetStream_Implementation(getStream),
		GetPassword_Implementation(getPassword) {

	}

	IMPLEMENT_IPROGRESS()

		LONG SetOperationResult(Int32 opRes) override;

	LONG PrepareOperation(Int32 askExtractMode) override;

	LONG GetStream(UInt32 index, ISequentialOutStream** outStream, Int32 askExtractMode) override;
	LONG CryptoGetTextPassword(BSTR* password) override;

	virtual ~IArchiveExtractCallback_Wrapper() = default;

private:
	IArchiveExtractCallback_ThisCallback_SetOperationResult SetOperationResult_Implementation;
	IArchiveExtractCallback_ThisCallback_PrepareOperation PrepareOperation_Implementation;
	IArchiveExtractCallback_ThisCallback_GetStream GetStream_Implementation;
	IArchiveExtractCallback_Wrapper_ThisCallback_GetPassword GetPassword_Implementation;
};

class IArchiveUpdateCallback_Wrapper final : public IArchiveUpdateCallback, public ICryptoGetTextPassword2, public CMyUnknownImp {
public:
	MY_QUERYINTERFACE_BEGIN2(IArchiveUpdateCallback)
		MY_QUERYINTERFACE_ENTRY(ICryptoGetTextPassword2)
		MY_QUERYINTERFACE_END

		MY_ADDREF_RELEASE_LEAKING()

		IArchiveUpdateCallback_Wrapper(IProgress_ThisCallback_SetTotal setTotal,
			IProgress_ThisCallback_SetCompleted setCompleted,
			IArchiveUpdateCallback_ThisCallback_SetOperationResult setOperationResult,
			IArchiveUpdateCallback_ThisCallback_GetStream getStream,
			IArchiveUpdateCallback_ThisCallback_GetUpdateItemInfo getUpdateItemInfo,
			IArchiveUpdateCallback_ThisCallback_GetProperty getProperty,
			IArchiveUpdateCallback_ThisCallback_CryptoGetTextPassword2 getPassword2)
		: IProgress_Wrapper_Implementation(setTotal, setCompleted),
		SetOperationResult_Implementation(setOperationResult),
		GetStream_Implementation(getStream),
		GetUpdateItemInfo_Implementation(getUpdateItemInfo),
		GetProperty_Implementation(getProperty),
		GetPassword2_Implementation(getPassword2)
	{

	}

	IMPLEMENT_IPROGRESS()

		LONG SetOperationResult(Int32 opRes) override;

	LONG GetStream(UInt32 index, ISequentialInStream** inStream) override;

	LONG GetUpdateItemInfo(UInt32 index, Int32* newData, Int32* newProps, UInt32* indexInArchive) override;

	LONG GetProperty(UInt32 index, PROPID propID, PROPVARIANT* value) override;

	LONG CryptoGetTextPassword2(Int32* passwordIsDefined, BSTR* password) override;

	virtual ~IArchiveUpdateCallback_Wrapper() = default;

private:
	IArchiveUpdateCallback_ThisCallback_SetOperationResult SetOperationResult_Implementation;
	IArchiveUpdateCallback_ThisCallback_GetStream GetStream_Implementation;
	IArchiveUpdateCallback_ThisCallback_GetUpdateItemInfo GetUpdateItemInfo_Implementation;
	IArchiveUpdateCallback_ThisCallback_GetProperty GetProperty_Implementation;
	IArchiveUpdateCallback_ThisCallback_CryptoGetTextPassword2 GetPassword2_Implementation;
};

class IArchiveOpenVolumeCallback_Wrapper final : public IArchiveOpenVolumeCallback, public CMyUnknownImp {
public:
	MY_QUERYINTERFACE_BEGIN2(IArchiveOpenVolumeCallback)MY_QUERYINTERFACE_END

		MY_ADDREF_RELEASE_LEAKING()

		IArchiveOpenVolumeCallback_Wrapper(IArchiveOpenVolumeCallback_ThisCallback_GetStream getStream,
			IArchiveOpenVolumeCallback_ThisCallback_GetProperty getProperty)
		: GetStream_Implementation(getStream), GetProperty_Implementation(getProperty) {

	}

	virtual ~IArchiveOpenVolumeCallback_Wrapper() = default;

	LONG GetStream(const wchar_t* name, IInStream** inStream) override;

	LONG GetProperty(PROPID propID, PROPVARIANT* value) override;

private:
	IArchiveOpenVolumeCallback_ThisCallback_GetStream GetStream_Implementation;
	IArchiveOpenVolumeCallback_ThisCallback_GetProperty GetProperty_Implementation;
};

class ISequentialInStream_Wrapper final : public ISequentialInStream, public CMyUnknownImp {
public:
	MY_QUERYINTERFACE_BEGIN2(ISequentialInStream)MY_QUERYINTERFACE_END

		MY_ADDREF_RELEASE_LEAKING()

		explicit ISequentialInStream_Wrapper(ISequentialInStream_Wrapper_ThisCallback read)
		: Read_Implementation(read) {

	}

	virtual ~ISequentialInStream_Wrapper() = default;


	LONG Read(void* data, UInt32 size, UInt32* processedSize) override;

private:
	ISequentialInStream_Wrapper_ThisCallback Read_Implementation;
};


class ISequentialOutStream_Wrapper final : public ISequentialOutStream, public CMyUnknownImp {
public:
	MY_QUERYINTERFACE_BEGIN2(ISequentialOutStream)MY_QUERYINTERFACE_END

		MY_ADDREF_RELEASE_LEAKING()

		explicit ISequentialOutStream_Wrapper(ISequentialOutStream_Wrapper_ThisCallback write)
		: Write_Implementation(write) {

	}

	virtual ~ISequentialOutStream_Wrapper() = default;

	LONG Write(const void* data, UInt32 size, UInt32* processedSize) override;


private:
	ISequentialOutStream_Wrapper_ThisCallback Write_Implementation;
};


class IInStream_Wrapper final : public IInStream, public CMyUnknownImp {
public:
	MY_QUERYINTERFACE_BEGIN2(IInStream)

		MY_QUERYINTERFACE_ENTRY(ISequentialInStream)
		MY_QUERYINTERFACE_END

		MY_ADDREF_RELEASE_LEAKING()

		IInStream_Wrapper(ISequentialInStream_Wrapper_ThisCallback read, IInStream_ThisCallback_Seek seek)
		: IStreamIn_Wrapper_Implementation(read),
		Seek_Implementation(seek) {

	}

	IMPLEMENT_STREAM_READ()


		virtual ~IInStream_Wrapper() = default;

	LONG Seek(Int64 offset, UInt32 seekOrigin, UInt64* newPosition) override;


private:
	IInStream_ThisCallback_Seek Seek_Implementation;
};


class IOutStream_Wrapper final : public IOutStream, public CMyUnknownImp {
public:
	MY_QUERYINTERFACE_BEGIN2(IOutStream)
		MY_QUERYINTERFACE_ENTRY(ISequentialOutStream)
		MY_QUERYINTERFACE_END

		MY_ADDREF_RELEASE_LEAKING()

		explicit IOutStream_Wrapper(ISequentialOutStream_Wrapper_ThisCallback write,
			IOutStream_ThisCallback_Seek seek,
			IOutStream_ThisCallback_SetSize setSize)
		: IStreamOut_Wrapper_Implementation(write),
		Seek_Implementation(seek),
		SetSize_Implementation(setSize) {

	}

	IMPLEMENT_STREAM_WRITE()

		virtual ~IOutStream_Wrapper() = default;

	LONG Seek(Int64 offset, UInt32 seekOrigin, UInt64* newPosition) override;

	LONG SetSize(UInt64 newSize) override;


private:
	IOutStream_ThisCallback_Seek Seek_Implementation;
	IOutStream_ThisCallback_SetSize SetSize_Implementation;
};

class IInArchive_Wrapper final : public IInArchive, public CMyUnknownImp {
public:
	MY_QUERYINTERFACE_BEGIN2(IInArchive)MY_QUERYINTERFACE_END

		MY_ADDREF_RELEASE_LEAKING()

		explicit IInArchive_Wrapper(IInArchive_ThisCallback_GetNumberOfItems getNumberOfItems,
			IInArchive_ThisCallback_Open open,
			IInArchive_ThisCallback_GetArchivePropertyInfo getArchivePropertyInfo,
			IInArchive_ThisCallback_GetNumberOfProperties getNumberOfProperties,
			IInArchive_ThisCallback_Close close,
			IInArchive_ThisCallback_Extract extract,
			IInArchive_ThisCallback_GetNumberOfArchiveProperties getNumberOfArchiveProperties,
			IInArchive_ThisCallback_GetArchiveProperty getArchiveProperty,
			IInArchive_ThisCallback_GetProperty getProperty,
			IInArchive_ThisCallback_GetPropertyInfo getPropertyInfo)
		: GetNumberOfItems_Implementation(getNumberOfItems),
		Open_Implementation(open),
		GetArchivePropertyInfo_Implementation(getArchivePropertyInfo),
		GetNumberOfProperties_Implementation(getNumberOfProperties),
		Close_Implementation(close),
		Extract_Implementation(extract),
		GetNumberOfArchiveProperties_Implementation(getNumberOfArchiveProperties),
		GetArchiveProperty_Implementation(getArchiveProperty),
		GetProperty_Implementation(getProperty),
		GetPropertyInfo_Implementation(getPropertyInfo) {

	}

	virtual ~IInArchive_Wrapper() final = default;

	LONG GetNumberOfItems(UInt32* numItems) override;

	LONG Open(IInStream* stream, const UInt64* maxCheckStartPosition, IArchiveOpenCallback* openCallback) override;

	LONG GetArchivePropertyInfo(UInt32 index, BSTR* name, PROPID* propID, VARTYPE* varType) override;

	LONG GetNumberOfProperties(UInt32* numProps) override;

	LONG Close() override;

	LONG
		Extract(const UInt32* indices, UInt32 numItems, Int32 testMode, IArchiveExtractCallback* extractCallback) override;

	LONG GetNumberOfArchiveProperties(UInt32* numProps) override;

	LONG GetArchiveProperty(PROPID propID, PROPVARIANT* value) override;

	LONG GetProperty(UInt32 index, PROPID propID, PROPVARIANT* value) override;

	LONG GetPropertyInfo(UInt32 index, BSTR* name, PROPID* propID, VARTYPE* varType) override;


private:
	IInArchive_ThisCallback_GetNumberOfItems GetNumberOfItems_Implementation;
	IInArchive_ThisCallback_Open Open_Implementation;
	IInArchive_ThisCallback_GetArchivePropertyInfo GetArchivePropertyInfo_Implementation;
	IInArchive_ThisCallback_GetNumberOfProperties GetNumberOfProperties_Implementation;
	IInArchive_ThisCallback_Close Close_Implementation;
	IInArchive_ThisCallback_Extract Extract_Implementation;
	IInArchive_ThisCallback_GetNumberOfArchiveProperties GetNumberOfArchiveProperties_Implementation;
	IInArchive_ThisCallback_GetArchiveProperty GetArchiveProperty_Implementation;
	IInArchive_ThisCallback_GetProperty GetProperty_Implementation;
	IInArchive_ThisCallback_GetPropertyInfo GetPropertyInfo_Implementation;
};

class IOutArchive_Wrapper : public IOutArchive, public CMyUnknownImp {
public:
	MY_QUERYINTERFACE_BEGIN2(IOutArchive)MY_QUERYINTERFACE_END

		MY_ADDREF_RELEASE_LEAKING()

		IOutArchive_Wrapper(IOutArchiveOutThisCallback_UpdateItems updateItems,
			IOutArchiveOutThisCallback_GetFileTimeType getFileTimeType) :
		UpdateItems_Implementation(updateItems),
		GetFileTimeType_Implementation(getFileTimeType) {

	}

	virtual ~IOutArchive_Wrapper() final = default;

	LONG UpdateItems(ISequentialOutStream* outStream, UInt32 numItems, IArchiveUpdateCallback* updateCallback) override;

	LONG GetFileTimeType(UInt32* type) override;

private:
	IOutArchiveOutThisCallback_UpdateItems UpdateItems_Implementation;
	IOutArchiveOutThisCallback_GetFileTimeType GetFileTimeType_Implementation;
};


class ISetProperties_Wrapper : public ISetProperties, public CMyUnknownImp {
public:
	MY_QUERYINTERFACE_BEGIN2(ISetProperties)MY_QUERYINTERFACE_END

		MY_ADDREF_RELEASE_LEAKING()

		explicit ISetProperties_Wrapper(ISetProperties_Wrapper_ThisCallback setProperties) :
		SetProperties_Implementation(setProperties) {
	}

	virtual ~ISetProperties_Wrapper() final = default;

	LONG SetProperties(const wchar_t* const* names, const PROPVARIANT* values, UInt32 numProps) override;


private:
	ISetProperties_Wrapper_ThisCallback SetProperties_Implementation;
};