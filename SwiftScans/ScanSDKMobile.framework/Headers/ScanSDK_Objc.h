#import <Foundation/Foundation.h>

#ifndef ScanSDK_Objc_h
#define ScanSDK_Objc_h

//! Error codes.
typedef NS_ENUM(NSInteger, SCErrorCode) {
    SCErrorCodeNoErrors = 0,          //!< Success.
    
    // General
    SCErrorCodeOtherFailure = 100,    //!< An error occurred during scanning. Please try your scan again.
    SCErrorCodeInvalidArgument,       //!< Argument is invalid.
    SCErrorCodeInvalidOperationProcedure, //!< The operation procedure is incorrect.
    SCErrorCodeScanningInProgress,    //!< Other operations can not be performed because scanning is in progress.
    SCErrorCodeNotFoundDevice,        //!< Device is not found.
    SCErrorCodeInvalidParameters,     //!< Scan parameter is invalid. Please check the reference.
    SCErrorCodeNoDeviceResponse,      //!< It's failed to connect to the device.

    // DeviceError
    SCErrorCodeOtherDeviceError = 200,    //!< Other device error.
    SCErrorCodePaperJam,              //!< A document is jammed in the ADF.
    SCErrorCodePaperDoubleFeed,       //!< Multifeed Detected.
    SCErrorCodeCoverOpen,             //!< Cover is open. Close the ADF Cover.
    SCErrorCodeSecureFunctionLock,    //!< Scan is restricted by Secure Function Lock.
    SCErrorCodeNoPaper,               //!< No document is set in ADF.
    SCErrorCodeBusy,                  //!< The device is busy. After the current scanning operation is completed, please try again.
    SCErrorCodeDeviceMemoryFull,            //!< If the device has some jobs stored in memory please wait until these jobs are completed or delete any remaining jobs and then try again.
    SCErrorCodePullScanLock,          //!< Scanning has been restricted from PCs and mobile devices, you may be able to scan from the device.
    SCErrorCodeInvalidParametersInCurrentDeviceState,    //!< Unacceptable parameters in the current device state.
    SCErrorCodeOtherPaperFeedError,   //!< Other paper feed error.
    SCErrorCodeOverLoaded,            //!< Tray is overloaded.
    SCErrorCodeNonSeparableMode,      //!< Separation switch is in non separable mode.

    // SaveImage
    SCErrorCodeFailedToSave = 300,    //!< Failed to save image.

    // ScanError
    SCErrorCodeLowMemory = 400,       //!< There is not enough memory in your PC.

    // Path
    SCErrorCodePathTooLong = 500,     //!< File path is too long.
};

//! Resolution.  
//! 400dpi or higher, the memory full error rate increases.
typedef NS_ENUM(NSInteger, SCResolution) {
    SCResolution100dpi = 0,    //!< 100dpi
    SCResolution150dpi,        //!< 150dpi
    SCResolution200dpi,        //!< 200dpi
    SCResolution300dpi,        //!< 300dpi
    SCResolution400dpi,        //!< 400dpi
    SCResolution600dpi,        //!< 600dpi
    SCResolution1200dpi,       //!< 1200dpi
    SCResolution2400dpi,       //!< 2400dpi
    SCResolution4800dpi,       //!< 4800dpi
    SCResolution9600dpi,       //!< 9600dpi
    SCResolution19200dpi,      //!< 19200dpi
};

//! Paper size.
typedef NS_ENUM(NSInteger, SCPaperType) {
    SCPaperTypeAutoSize = 0,  //!< Detect the paper size automatically.
    SCPaperTypeA3,            //!< A3: 297x420 mm. This is only available A3 supporting models.
    SCPaperTypeLedger,        //!< Ledger: 279.4x431.8 mm (11x17 in.). This is only available A3 supporting models.
    SCPaperTypeJISB4,         //!< JIS B4: 257x364 mm. This is only available A3 supporting models.
    SCPaperTypeA4,            //!< A4: 210x297 mm
    SCPaperTypeJISB5,         //!< JIS B5: 182x257 mm
    SCPaperTypeLetter,        //!< Letter: 215.9x279.4 mm (8.5x11 in.)
    SCPaperTypeLegal,         //!< Legal:  215.9x355.6 mm (8.5x14 in.)
    SCPaperTypeA5,            //!< A5: 148x210 mm
    SCPaperTypeJISB6,         //!< JIS B6: 128x182 mm
    SCPaperTypeA6,            //!< A6: 105x148 mm
    SCPaperTypeExecutive,     //!< Exective: 184.1x266.7 mm (7.25x10.5 in.)
    SCPaperTypePhoto,         //!< Photo: 101.6x152.4 mm (4x6 in.)
    SCPaperTypeIndexCard,     //!< Index Card: 127x203.2 mm (5x8 in.)
    SCPaperTypePhotoL,        //!< Photo L: 89x127 mm
    SCPaperTypePhoto2L,       //!< Photo 2L: 127x178 mm
    SCPaperTypePostcard,      //!< Post Card 1: 100x148 mm
    SCPaperTypePostcard2,     //!< Post Card 2: 148x200 mm
    SCPaperTypeBusinessCard90X60, //!< Business Card (Horizontal): 90x60 mm
    SCPaperTypeBusinessCard60X90, //!< Business Card (Vertical) : 60x90 mm
    SCPaperTypeFolio,         //!< Folio: 215.9x330.2 mm (8.5x13 in.)
    SCPaperTypeMexicanLegal,  //!< Mexican Legal: 215.9x339.85 mm (8.5x13.38 in.)
    SCPaperTypeIndiaLegal,    //!< India Legal: 215x345mm (8.46x13.58 in.)
    SCPaperTypeLongPaper_NarrowWidth, //!< LongPaper (Narrow width). Width: 107.9 mm (4.25in.), Height: Documentt length.
    SCPaperTypeLongPaper_NomalWidth,  //!< LongPaper (Normal width). Width: 215.9 mm (8.5in.), Height: Documentt length.
    SCPaperTypeCustomSize,    //!< Custom size.
};

//! Color type.
typedef NS_ENUM(NSInteger, SCColorType) {
    SCColorTypeAutoColor = 0,     //!< Distinguishes the type of image automatically.
    SCColorTypeBlackAndWhite,     //!< 1bit Monochrome.
    SCColorTypeErrorDiffusion,    //!< 1bit Monochrome (Error diffusion).
    SCColorTypeTrueGray,          //!< 8bit gray.
    SCColorTypeColor24bit,        //!< 24bit color.
};

//! Paper size.  
//! The unit is 1/100 mm. If the value is 1000 it means 10 mm.
typedef struct SCSize {
    uint32_t x;
    uint32_t y;
} SCSize;

//! Supported color type. 
typedef struct SCSupportColorType
{
    BOOL autoColor;        //!< Distinguishes the type of image automatically.
    BOOL blackAndWhite;    //!< 1bit monochrome.
    BOOL errorDiffusion;   //!< 1bit monochrome (Error diffusion).
    BOOL trueGray;         //!< 8bit gray.
    BOOL color24bit;       //!< 24bit color.
} SCSupportColorType;

//! The maximum paper size of each paper source.
typedef struct SCSupportScanSize {
    SCSize flatbed;        //!< When scanning from a flatbed.
    SCSize simplex;        //!< When scanning from ADF with simplex (one side scanning).
    SCSize duplex;         //!< When scanning from ADF with duplex (2-sided scanning).
} SCSupportScanSize;

//! The limitation for long paper mode.  
//! Depending on the resolution, the maximum size may be smaller than this value.  
//! The unit is 1/100 mm. If the value is 1000 it means 10 mm.
typedef struct SCLongPaper {
    uint32_t maxSimplexLength;  //!< Maximum length for simplex.
    uint32_t maxDuplexLength;   //!< Maximum length for duplex.
    uint32_t maxResolution;     //!< Maximum resolution when LongPaper is selected.(There is no limit when this value is 0.)
} SCLongPaper;

//! The margin size when the device reads the document.  
//! The scan result will be smaller by this margin size than the paper type you selected.  
//! The unit is 1/100 mm. If the value is 1000 it means 10 mm.
typedef struct SCDeviceReadMargin {
    int32_t left;          //!< Margin size of left.
    int32_t top;           //!< Margin size of top.
    int32_t right;         //!< Margin size of right.
    int32_t bottom;        //!< Margin size of bottom.
} SCDeviceReadMargin;

//! Supported paper source.
typedef struct SCSupportPaperSource {
    BOOL flatbed;          //!< Flatbed
    BOOL adf;              //!< ADF (Automatic Document Feeder)
    BOOL cardslot;         //!< Cardslot
} SCSupportPaperSource;

//! Capability of auto deskew.
typedef struct SCSupportAutoDeskew {
    BOOL support;                       //!< Capability.
    SCSupportPaperSource paperSource;   //!< Supported paper source. If the document is scanned from an unsupported paper source, Auto Deskew will not work.
} SCSupportAutoDeskew;

//! Capability of margin settings.  
//! The unit is 1/100 mm. If the value is 1000 it means 10 mm.
typedef struct SCSupportMarginSettings {
    BOOL support;          //!< Capability.
    int32_t maxMargin;     //!< Maximum value that can adjust the document margin. It is the same value on the left, top, right and bottom.
    int32_t minMargin;     //!< Minimum value that can adjust the document margin. It is the same value on the left, top, right and bottom.
    BOOL isAutoSizeOnly;   //!< If this is true, Margin Settings will work only if you specify **AutoSize** as **PaperType**.
} SCSupportMarginSettings;

//! Capability of continuous scan.
typedef struct SCSupportContinuousScan {
    BOOL support;               //!< Capability.
    uint32_t minTimeoutMinutes; //!< Minimum value of continuous scan timeout period. The unit is minutes.
    uint32_t maxTimeoutMinutes; //!< Maximum value of continuous scan timeout period. The unit is minutes.
    uint32_t minFeedDelaySec;   //!< Minimum time between the time document is set in the feeder and the time feed starts. The unit is seconds.
    uint32_t maxFeedDelaySec;   //!< Maximum time between the time document is set in the feeder and the time feed starts. The unit is seconds.
} SCSupportContinuousScan;

//! @cond INTERNAL_USE_ONLY
typedef struct SCColorToneItem {
    bool isEnabled;
    int32_t brightness;
    int32_t contrast;
    uint32_t highlight;
    uint32_t shadow;
    uint32_t gamma;
} SCColorToneItem;

typedef struct SCColorToneDefault {
    SCColorToneItem trueGrayDocument;
    SCColorToneItem trueGrayPhoto;
    SCColorToneItem colorDocument;
    SCColorToneItem colorPhoto;
} SCColorToneDefault;
//! @endcond

//! Paper source.
typedef NS_ENUM(NSInteger, SCPaperSourceType) {
    SCPaperSourceTypeAuto = 0,  //!< If paper is inserted in the ADF or card slot, it will be scanned from there. Otherwise it will be scanned from the flatbed.
    SCPaperSourceTypeFlatbed,   //!< From the flatbed.
    SCPaperSourceTypeADF,       //!< From the ADF (Automatic Document Feeder) or card slot. Whether scanning from ADF or card slot depends on the setting of device.
};

//! Duplex type.
typedef NS_ENUM(NSInteger, SCDuplexType) {
    SCDuplexTypeSimplex = 0,    //!< Scanning only one side.
    SCDuplexTypeLongBinding,    //!< The images to be scanned are viewed in book form, flipping each page from left to right or right to left.
    SCDuplexTypeShortBinding,   //!< The images to be scanned are viewed in fanfold paper style, flipping each page up or down.
};

//! Scanning status.
typedef NS_ENUM(NSInteger, SCScanStatus) {
    SCScanStatusStandby = 0,        //!< Before scan start.
    SCScanStatusScanning,           //!< Scanning.
    SCScanStatusAllEnd,             //!< Scan complete (successed).
    SCScanStatusCanceled,           //!< Scan complete (canceled).
    SCScanStatusError,              //!< Scan complete (error occurred).
    SCScanStatusWaitingInsertion,   //!< Waiting document insertion for continuous scan.
};

//! Scanning area.
//! The unit is 1/100 mm. If the value is 1000 it means 10 mm.
typedef struct SCArea {
    uint32_t offsetX;           //!< The x coordinate of the offset.
    uint32_t offsetY;           //!< The y coordinate of the offset.
    uint32_t width;             //!< width.
    uint32_t height;            //!< height.
} SCArea;

//! Structure to specify the level of image processing.
typedef struct SCImageProcessing {
    BOOL execute;               //!< If true, it will be executed.
    uint32_t level;             //!< The value range varies depending on the type of image processing.
} SCImageProcessing;

//! Document type and scanning area.
typedef struct SCScanArea {
    SCPaperType paperType;      //!< Type of document size.
    SCSize customSize;          //!< Specify the size of the document when **CustomSize** is selected as **PaperType**. If other **PaperType** is selected, this value is ignored.
    BOOL isSelected;            //!< Limit the scanning area.
    SCArea selectedArea;        //!< Specify the scanning area when *isSelected* is true, otherwise this value is ignored.
} SCScanArea;

//! Parameter of margin settings.  
//! The unit of an integer is 1/100mm. If the value is 100 it means 1 mm.
typedef struct SCMarginSettings {
    BOOL execute;               //!< If true, it will be executed.
    int32_t left;               //!< Value range: -300 to 300 (= -3 to 3mm)
    int32_t top;                //!< Value range: -300 to 300 (= -3 to 3mm)
    int32_t right;              //!< Value range: -300 to 300 (= -3 to 3mm)
    int32_t bottom;             //!< Value range: -300 to 300 (= -3 to 3mm)
} SCMarginSettings;

//! Parameter of continuous scan.
typedef struct SCContinuousScan {
    BOOL execute;               //!< If true, it will be executed.
    uint32_t timeoutMinutes;    //!< The time from scan to the end of accepting rescan. Value range: 5 to 30 (minutes).
    uint32_t feedDelaySec;      //!< The time between the time document is set in the feeder and the time feed starts. Value range: 0 to 5 (seconds).
} SCContinuousScan;

//! Scan parameter.
typedef struct SCScanParameter {
    //! Source that sets documents.
    SCPaperSourceType paperSource;
    //! Set the scanning resolution. Higher resolutions can achieve a finer scanned image, but take more memory and transfer time.
    SCResolution resolution;
    //! Set the color type for scanning.
    SCColorType colorType;
    //! Set the paper size for the document to be scanned. 
    SCScanArea scanArea;
    //! Set the brightness for the document to be scanned. Value range: -50 to 50.
    int32_t brightness;
    //! Set the contrast for the document to be scanned. Value range: -50 to 50.
    int32_t contrast;
    //! Both sides of the document can be scanned automatically from the ADF.
    SCDuplexType duplex;
    //! Correct the skew of the scanned data.
    BOOL autoDeskew;
    //! Specify the margin size of each side of the scanned image.
    SCMarginSettings marginSettings;
    //! Remove blank pages from your scanned image. Value range: 0 to 10.
    SCImageProcessing skipBlankPage;
    //! You can scan the following documents using a Carrier Sheet.
    BOOL carrierSheetMode;
    //! Single paper Scan will feed one page at a time from the ADF regardless of the number of pages in the ADF.
    BOOL singlePaperScan;
    //! Repeat the scan. Scanning will resume automatically when you set documents in ADF after scanning.  
    //! Repeat until you call AbortScanning() or timeout comes.
    SCContinuousScan continuousScan;
    //! Detect the multifeed of the document by ultrasonic sensor.
    BOOL multifeedDetection;
    //! Change image quality when using a copy function.
    BOOL copyScan; 
    //! Change image quality when using CD label copy function.
    BOOL labelCopyScan;
} SCScanParameter;


NS_ASSUME_NONNULL_BEGIN

@interface SCCapability : NSObject
@property (assign) SCSupportScanSize maxDocSize;                //!< Maximum size of scannable documents. If you specify over this value as custom size, It will be scanned with this size.
@property (assign) SCSupportScanSize minDocSize;                //!< Minimum size of scannable documents. If you specify under this value as custom size, It will be scanned with this size.
@property (assign) SCLongPaper longPaper;                       //!< The maximum paper length and resolution for long paper mode. If you specify **LongPaper** as **PaperType**, you can scan documents up to this length and resolution.
@property (assign) uint32_t autoSizeMaxResolution;              //!< Maximum resolution when AutoSize is selected. If you specify **AutoSize** as **PaperType**, you can scan up to this resolution.(There is no limit when this value is 0.)
@property (assign) SCDeviceReadMargin readMargin;               //!< Margin size when the device reads the document.
@property (assign) SCSupportPaperSource paperSource;            //!< Supported paper source.
@property (strong) NSArray* resolutionList;                     //!< Array of supported resolution.
@property (assign) SCSupportColorType colorType;                //!< Supported color type.
@property (strong) NSArray* paperTypeList;                      //!< Array of supported paper type.
@property (assign) BOOL brightness;                             //!< Adjust brightness.
@property (assign) BOOL contrast;                               //!< Adjust contrast.
@property (assign) BOOL duplex;                                 //!< 2-sided scanning.
@property (assign) SCSupportAutoDeskew autoDeskew;              //!< Auto deskew.
@property (assign) SCSupportMarginSettings marginSettings;      //!< Margin settings.
@property (assign) BOOL skipBlankPage;                          //!< Skip blank page.
@property (assign) BOOL carrierSheetMode;                       //!< Scan with charrier sheet.
@property (assign) BOOL singlePaperScan;                        //!< Scan single paper.
@property (assign) SCSupportContinuousScan continuousScan;      //!< Repeat the scan.
@property (assign) BOOL multifeedDetection;                     //!< Detect multifeed.
@property (assign) BOOL hasCopyScan;                            //!< Device has a copy function.
@property (assign) BOOL hasLabelCopyScan;                       //!< Device has CD label copy function.
//! @cond INTERNAL_USE_ONLY
@property (assign) SCColorToneDefault colorToneDefault;
 //! @endcond
@end

//! Scanned image data info.
@interface SCScanDataInfo : NSObject
//! Whether the back side image should be rotated 180 degrees when duplex scan.  
//! This information can only be used when you position the long edge first for landscape documents.  
@property (assign) BOOL shouldDxRotate;
@end

@interface ScanSDKObjc : NSObject
//! You can change working path.
//! \param[in] path : Specifies a directory that will temporarily emit files during scanning.
- (id)initWith:(NSString*)path;
//! Select the device to scan.
//! \param[in] ipAddress : IP Address of the device you want to connect.
//! \return Error code.
-(SCErrorCode)selectDevice: (NSString*)ipAddress;
//! Check whether documents is inserted in ADF.  
//! Please call this function after selecting the device.
//! \param[out] exit : Whether the document is inserted in ADF.
//! If documents is inserted, this function returns true.
//! \return Error code.  
-(SCErrorCode)checkDocumentExist: (BOOL*)exist;
//! Get device specification and available SCScanParameter from the device.  
//! Call this function before scanning and check the SCCapability.  
//! Please call this function after selecting the device.
//! \param[out] capability : Device specification and available SCScanParameter of connected device.
//! \return Error code.
-(SCErrorCode)queryCapabilities: (SCCapability*)capability;
//! Set parameters for scanning.  
//! If not set, scan with the default parameters for each device.  
//! When you call selectDevice(), ScanParameter changes to the default.  
//! Please call this function each time you select a device.
//! \param[in] parameter : Scan settings you want.
//! Please refer to SCCapability and exclusive table in SDK Documentation and set available parameters.  
//! If you set a parameter that is not available, the scan result is undefined.  
//! You can easily set valid parameters by changing parameters returned by getScanParameter().
//! \return Error code.
-(SCErrorCode)setScanParameter: (SCScanParameter)parameter;
//! Get the ScanParameter you set.  
//! Please call this function after selecting the device.  
//! \param[out] parameter : Scan settings you set.
//! If not set, it returns the default parameters of the selected device.  
//! \return Error code.
-(SCErrorCode)getScanParameter: (SCScanParameter*)parameter;
//! Scan with asynchronous processing.  
//! Operation returns when scanning starts.  
//! Please check the return value of getScanStatus() to see if the scan is completed.  
//! You can not rescan until scanning is complete.  
//! \return Error code.
-(SCErrorCode)scanAsync;
//! Cancel during the asynchronous scan.  
//! Images scanned before cancellation are saved, but later images are discarded.  
//! When cancel processing is completed, **Canceled** is returned by getScanStatus().  
//! If you call this function just before scanning is completed, scanning may complete without being canceled.  
//! \return Success or failure.
-(BOOL)abortScanning;
//! Get the information of the scanned image.  
//! When a new scan is started, the memory block of the previous scan data is freed.  
//! \param[out] scanDataInfo : Scanned image data.  
//! \param[in] pageNo : Page number to get.  
//! \param[in] dir : Output directory path.  
//! \param[in] fileNamePrefix : Prefix for a output file.  
//! \return Error code.  
-(nullable NSString*)getScanData: (NSInteger)pageNo into: (NSString*)dir fileNamePrefix: (NSString*)prefix scanDataInfo: (SCScanDataInfo*)scanDataInfo;
//! Checks whether scan data of the specified number of pages can be acquired. Use when **ScanStatus** is **Scanning** or **AllEnd**.  
//! \param[in] pageNo : Page number to check.  
//! \return Whether ScanData can be acquired. 
-(BOOL)hasScanData: (NSInteger)pageNo;
//! Get the status of the scan.  
//! By using this function, you can know when the asynchronous scan is completed.  
//! \return Scan status.
//! If scanning is completed, this function returns **AllEnd** or **Canceled** or **Error**.
-(SCScanStatus)getScanStatus;
//! If scanning is completed with **Error**, you can get the detail of error.  
//! \return Details of the error when an error occurred during scanning.
-(SCErrorCode)getScanError;
//! Finalyze.  
//! Normally finalization is called automatically, so you do not need to call this function.  
//! Please call only when you want to explicitly execute termination processing.  
-(void)clean;
@end

NS_ASSUME_NONNULL_END

#endif /* ScanSDK_Objc_h */
