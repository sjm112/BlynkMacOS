#ifndef GAMMARAMP_H_
#define GAMMARAMP_H_

// Qt:

#ifdef Q_OS_WIN
#include <windows.h>
#elif defined (Q_OS_OSX)
#include <CoreGraphics/CoreGraphics.h>
#endif

#include <QVector>
#include <QColor>

// Application:
#include "gammaramp_global.h"

class GAMMARAMPSHARED_EXPORT GammaRamp
{
public:
    // Constructor:
    GammaRamp();

    // Destructor:
    ~GammaRamp();

    // Set blue light parameters:
    bool createColorPalette(const QColor &startColor, const QColor &stopColor);

#ifdef Q_OS_WIN
private:
    // Load library:
    BOOL loadLibrary();

    // Free library:
    void freeLibrary();

    // Load library if needed:
    BOOL loadLibraryIfNeeded();

    // Set device gamma ramp:
    BOOL setDeviceGammaRamp(HDC hDC, LPVOID lpRamp);

    // Get device gamma ramp:
    BOOL getDeviceGammaRamp(HDC hDC, LPVOID lpRamp);

    // Set color palette:
    bool setColorPalette(HDC, const std::vector<int> &vRed, const std::vector<int> &vGreen, const std::vector<int> &vBlue);

protected:
    HMODULE hGDI32;
    HDC hScreenDC;
    typedef BOOL (WINAPI *Type_SetDeviceGammaRamp)(HDC hDC, LPVOID lpRamp);
    Type_SetDeviceGammaRamp pGetDeviceGammaRamp;
    Type_SetDeviceGammaRamp pSetDeviceGammaRamp;
#elif defined(Q_OS_OSX)
private:
    bool setColorPalette(const std::vector<int> &vRed, const std::vector<int> &vGreen, const std::vector<int> &vBlue);
#endif
};
#endif
