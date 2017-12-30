#ifndef __D3DVideoRender_H__
#define __D3DVideoRender_H__

#include <WinSock2.h>
#include <d3d9.h>
#pragma comment(lib, "d3d9.lib")       // located in DirectX SDK
#include <common/typedefs.h>

class DLL_EXPORT D3DVideoRender
{
public:
    D3DVideoRender();

    virtual ~D3DVideoRender();

    int32_t Open(int32_t width, int32_t height, const void * hwnd = NULL);

    int32_t Start();

    int32_t Stop();

    int32_t Close();

    int32_t Render(int32_t w, int32_t h, uint8_t* data, int32_t size);

private:
    int32_t _Destroy();

    int32_t _Resize(int32_t w, int32_t h);

private:
    bool    m_bOpen;
    HWND    m_hwnd;
    int32_t m_iWidth;   
    int32_t m_iHeight;

    IDirect3D9 *             m_pIDirect3D9;
    IDirect3DDevice9*        m_pD3DDevice;
    IDirect3DTexture9 *      m_pTexture;
    IDirect3DVertexBuffer9*  m_pVertexBuffer;
};

#endif // !__D3DVideoRender_H__
