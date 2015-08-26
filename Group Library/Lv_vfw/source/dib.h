// dib.h : header file
//
// CDIB class
//
// This is from the "basicdib" example on the MSDN Library CD.  
// I have made only a couple of small modifications.
//

#ifndef __DIB__
#define __DIB__

#define BOOL int

class CDIB
{
public:
	virtual BOOL ChangeTo(BITMAPINFO* info, BYTE* bits);
    CDIB();
    ~CDIB();

    BITMAPINFO* GetBitmapInfoAddress()
        {return m_pBMI;}                        // Pointer to bitmap info
    int GetBitsPerPixel()
        {return m_pBMI->bmiHeader.biBitCount;}
    BYTE* GetBitsAddress()
        {return m_pBits;}                       // Pointer to the bits
    RGBQUAD* GetClrTabAddress()
        {return (LPRGBQUAD)(((BYTE *)(m_pBMI)) 
            + sizeof(BITMAPINFOHEADER));}       // Pointer to color table

    virtual BOOL Create(int width, int height); // Create a new DIB
    virtual BOOL Load(FILE* fp);                // Load from file

protected:
    BITMAPINFO* m_pBMI;         // Pointer to BITMAPINFO struct
    BYTE* m_pBits;              // Pointer to the bits

public:
    int DibWidth()
        {return m_pBMI->bmiHeader.biWidth;}
    int DibHeight() 
        {return m_pBMI->bmiHeader.biHeight;}
};

#endif // __DIB__
